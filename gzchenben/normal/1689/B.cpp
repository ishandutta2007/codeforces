#include <cstdio>
using namespace std;
int n, t, a[1005], ans[1005];
bool vis[1005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            vis[i] = false;
            ans[i] = 0;
        }
        if (n == 1)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!vis[j] && a[i] != j)
                {
                    ans[i] = j;
                    vis[j] = true;
                    break;
                }
            }
        }
        if (!ans[n])
        {
            ans[n] = ans[n - 1];
            ans[n - 1] = a[n];
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
}