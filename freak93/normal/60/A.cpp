#include <cstdio>
#include <cstring>

using namespace std;

int n, m, i, p, x, rez, j, mark[5000];
char s[5000];

int main() {
    
    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= m; ++i) {
        fgets(s, sizeof(s), stdin);
        p = 0;
        while (s[p] < '0' || s[p] > '9')
            ++p;
        x = 0;
        while (s[p] >= '0' && s[p] <= '9')
            x = x * 10 + s[p] - '0', ++p;

        if (s[7] == 'l')
            for (j = x; j <= n; ++j)
                mark[j] = 1;
        else
            for (j = 1; j <= x; ++j)
                mark[j] = 1;
    }

    rez = 0;
    for (i = 1; i <= n; ++i)
        rez += (mark[i] == 0);
    if (rez == 0)
        rez = -1;
    printf("%d", rez);
}