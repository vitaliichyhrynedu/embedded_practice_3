#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modify_str(char* str) {
    for (size_t i = 0; str[i] != 0; i++) {
        str[i] = ((i + 1) % 2 == 0) ? tolower(str[i]) : toupper(str[i]);
    }
}

int main() {
    char buf[64] = "";

    printf("Enter string: ");

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "error: failed to read stdin\n");
        return EXIT_FAILURE;
    }

    if (strchr(buf, '\n') == NULL) {
        fprintf(stderr, "error: buffer overflow\n");
        return EXIT_FAILURE;
    }
    buf[strcspn(buf, "\n")] = 0;

    if (buf[0] == 0) {
        fprintf(stderr, "error: no input provided\n");
        return EXIT_FAILURE;
    }

    modify_str(buf);
    printf("%s\n", buf);

    return EXIT_SUCCESS;
}
