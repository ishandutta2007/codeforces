#include <cstdio>
#include <cstring>

const int N = 100000;
const int MOD = (int)1e9 + 7;

int two[N + 1], deg[N];

int main()
{
    two[0] = 1;
    for (int i = 1; i <= N; ++ i) {
        two[i] = two[i - 1] * 2 % MOD;
    }
    int n;
    while (scanf("%d", &n) == 1) {
        memset(deg, 0, sizeof(*deg) * n);
        for (int i = 1; i < n; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            deg[a] ++;
            deg[b] ++;
        }
        int lv = 0;
        for (int i = 0; i < n; ++ i) {
            lv += deg[i] == 1;
        }
        printf("%d\n", (int)(((long long)lv * two[n - lv + 1] + (long long)(n - lv) * two[n - lv]) % MOD));
    }
}