#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
int n;
int f[2001][1001];
int main()
{
    f[0][0] = 1;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n * 2 ; i++)
        for (int j = 0; j <= 1000; j ++)
            if (f[i][j])
            {
                if (i & 1)
                {
                    ans += f[i][j];
                    if (ans >= mod) ans -= mod;
                }
                if (j)
                {
                    f[i + 1][j - 1] += f[i][j];
                    if (f[i + 1][j - 1] >= mod) f[i + 1][j - 1] -= mod;
                }
                if (j + 1 <= n * 2 - i - 1)
                {
                    f[i + 1][j + 1] += f[i][j];
                    if (f[i + 1][j + 1] >= mod) f[i + 1][j + 1] -= mod;
                }
            }
    printf("%d\n", ans);
    return 0;
}