#include <cstdio>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int mod = 1;
        for (int _ = 0; _ < n && mod <= m; ++ _) {
            mod <<= 1;
        }
        printf("%d\n", m % mod);
    }
}