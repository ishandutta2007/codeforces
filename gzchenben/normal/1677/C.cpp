#include <cstdio>
using namespace std;
int n, t, a[100005], b[100005], rev[100005];
bool vis[100005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            rev[a[i]] = i;
            vis[i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            int Now = i, cnt = 0;
            while (!vis[Now])
            {
                vis[Now] = true;
                cnt++;
                Now = rev[b[Now]];
            }
            num += cnt / 2;
        }
        long long ans = 0;
        for (int i = 1; i <= num; i++)
            ans += 2 * ((n - i + 1) - i);
        printf("%lld\n", ans);
    }
}