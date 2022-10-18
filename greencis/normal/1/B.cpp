#include <fstream>
#include <cstdio>
char s[105], *p;
int r,c,z;

int print(int x) {
    if (x) {
        --x;
        print(x / 26);
        printf("%c",(x % 26) + 'A');
    }
    return 0;
}

int main() {
    scanf("%d", &z);
    while (z--) {
        scanf("%s", s);
        if (sscanf(s, "R%dC%d", &r, &c) == 2) {
            print(c);
            printf("%d\n", r);
        } else {
            p = s;
            for (c = 0; *p >= 'A'; ++p)
                c = c*26 + (*p ^ 64);
            printf("R%sC%d\n", p, c);
        }
    }
    return 0;
}