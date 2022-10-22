#include <cstdio>
using namespace std;
int n, t;
long long a, b, pos[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld%lld", &n, &a, &b);
        long long Now = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &pos[i]);
            ans += b * (pos[i] - Now);
            if ((n - i) * b > a)
            {
                ans += a * (pos[i] - Now);
                Now = pos[i];
            }
        }
        printf("%lld\n", ans);
    }
}