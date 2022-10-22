#include <cstdio>
using namespace std;
int n, t, a[5005], cntA[5005][5005], cntD[5005][5005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                cntA[i][j] = cntD[i][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            cntA[i][a[i]]++;
            cntD[i][a[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cntA[i][j] += cntA[i][j - 1];
                cntD[i][j] += cntD[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cntA[i][j] += cntA[i - 1][j];
            }
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = n; j >= 1; j--)
            {
                cntD[i][j] += cntD[i + 1][j];
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans += cntA[i - 1][a[j] - 1] * cntD[j + 1][a[i] - 1];
            }
        }
        printf("%lld\n", ans);
    }
}