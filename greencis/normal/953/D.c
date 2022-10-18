#include <stdio.h>

int n;
char s[6][9];

int main() {
    for (int i = 0; i < 6; ++i)
        gets(s[i]);
    if (s[0][4] == '.') s[0][4] = 'P';
    else if (s[0][3] == '.') s[0][3] = 'P';
    else if (s[1][4] == '.') s[1][4] = 'P';
    else if (s[1][3] == '.') s[1][3] = 'P';

    else if (s[0][0] == '.') s[0][0] = 'P';
    else if (s[0][1] == '.') s[0][1] = 'P';
    else if (s[1][0] == '.') s[1][0] = 'P';
    else if (s[1][1] == '.') s[1][1] = 'P';

    else if (s[0][6] == '.') s[0][6] = 'P';
    else if (s[0][7] == '.') s[0][7] = 'P';
    else if (s[1][6] == '.') s[1][6] = 'P';
    else if (s[1][7] == '.') s[1][7] = 'P';

    else if (s[2][4] == '.') s[2][4] = 'P';
    else if (s[2][3] == '.') s[2][3] = 'P';
    else if (s[3][4] == '.') s[3][4] = 'P';
    else if (s[3][3] == '.') s[3][3] = 'P';

    else if (s[2][0] == '.') s[2][0] = 'P';
    else if (s[2][1] == '.') s[2][1] = 'P';
    else if (s[3][0] == '.') s[3][0] = 'P';
    else if (s[3][1] == '.') s[3][1] = 'P';

    else if (s[2][6] == '.') s[2][6] = 'P';
    else if (s[2][7] == '.') s[2][7] = 'P';
    else if (s[3][6] == '.') s[3][6] = 'P';
    else if (s[3][7] == '.') s[3][7] = 'P';

    else if (s[4][4] == '.') s[4][4] = 'P';
    else if (s[4][3] == '.') s[4][3] = 'P';
    else if (s[5][4] == '.') s[5][4] = 'P';
    else if (s[5][3] == '.') s[5][3] = 'P';

    else if (s[4][0] == '.') s[4][0] = 'P';
    else if (s[4][1] == '.') s[4][1] = 'P';
    else if (s[5][0] == '.') s[5][0] = 'P';
    else if (s[5][1] == '.') s[5][1] = 'P';

    else if (s[4][6] == '.') s[4][6] = 'P';
    else if (s[4][7] == '.') s[4][7] = 'P';
    else if (s[5][6] == '.') s[5][6] = 'P';
    else if (s[5][7] == '.') s[5][7] = 'P';

    for (int i = 0; i < 6; ++i)
        puts(s[i]);

    return 0;
}