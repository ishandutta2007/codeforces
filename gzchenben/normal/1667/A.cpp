#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long a[5005], ans = 1e18;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) // b[i] = 0;
    {
        long long Now = 0, res = 0;
        for (int j = i + 1; j <= n; j++)
        {
            long long tmp = Now / a[j] + 1;
            res += tmp;
            Now = tmp * a[j];
        }
        Now = 0;
        for (int j = i - 1; j > 0; j--)
        {
            long long tmp = Now / a[j] + 1;
            res += tmp;
            Now = tmp * a[j];
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
}