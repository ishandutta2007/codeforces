#include <cstdio>
using namespace std;
int n, k, t, f[200005], ans[200005];
char a[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf(" %c", &a[i]);
        }
        int Now = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] == '0' && k % 2 == 1) || (a[i] == '1' && k % 2 == 0))
            {
                if (i == n && (Now % 2) != (k % 2))
                    f[i] = 1, ans[i] = 0;
                else
                    f[i] = 0, ans[i] = 1;
                Now += f[i];
            }
            else
            {
                if (i == n && (Now % 2) == (k % 2))
                    f[i] = 0, ans[i] = 0;
                else if (Now == k)
                    f[i] = 0, ans[i] = 0;
                else
                    f[i] = 1, ans[i] = 1;
                Now += f[i];
            }
        }
        f[1] += k - Now;
        for (int i = 1; i <= n; i++)
            printf("%d", ans[i]);
        printf("\n");
        for (int i = 1; i <= n; i++)
            printf("%d ", f[i]);
        printf("\n");
    }
}