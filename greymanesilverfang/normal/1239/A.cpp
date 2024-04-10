#include <cstdio>
const int INF = 1e9+7, N = 1e5;
long long f[N+1] = {1, 1};

int main()
{
    for (int i = 2; i <= N; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % INF;
    int n, m; scanf("%d%d", &n, &m);
    printf("%d\n", (f[n] + f[m] - 1) * 2 % INF);
}