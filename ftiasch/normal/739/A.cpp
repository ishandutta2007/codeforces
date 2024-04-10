#include <algorithm>
#include <cstdio>

int main()
{
#ifdef LOCAL_JUDGE
    freopen("A.in", "r", stdin);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int result = n;
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            result = std::min(result, b - a + 1);
        }
        printf("%d\n", result);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", i % result, " \n"[i == n - 1]);
        }
    }
}