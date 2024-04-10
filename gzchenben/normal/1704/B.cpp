#include <cstdio>
#include <algorithm>
using namespace std;
int t, n, x, a[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &x);
        int Minn = 2e9, Maxn = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            Minn = min(Minn, a[i]);
            Maxn = max(Maxn, a[i]);
            if (Maxn - Minn > 2 * x)
            {
                ans++;
                Maxn = Minn = a[i];
            }
        }
        printf("%d\n", ans);
    }
}