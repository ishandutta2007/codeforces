#include <cstdio>
#include <algorithm>
const long long mod = 998244353;
using namespace std;
int n, k, t, a[1000005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = n - k + 1; i <= n; i++)
        {
            if (a[i] > 0)
                ans = 0;
            ans = ans * (n - i + 1) % mod;
        }
        for (int i = 1; i <= n - k; i++)
        {
            if (a[i] >= i)
                ans = 0;
            if (a[i] == -1)
                ans = ans * (i + k) % mod;
            if (a[i] == 0)
                ans = ans * (k + 1) % mod;
        }
        printf("%lld\n", ans);
    }
}