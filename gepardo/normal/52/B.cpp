#include <cstdio>

using namespace std;

int a[2000], b[2000];
int c[2000][2000];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            while (c[i][j] <= ' ') c[i][j] = getchar();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (c[i][j] == '*') a[i]++, b[j]++;
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (c[i][j] == '*') ans += 1LL * (a[i] - 1) * (b[j] - 1);
    printf("%I64d", ans);
}