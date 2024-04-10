#include <cstdio>
using namespace std;
int n, t, a[250005], maxn[250005], minn[250005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        int Now = 1, tmp = (a[1] < a[2] ? 1 : 0), Nxt = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            if (tmp == 0 && a[i] > a[Now])
            {
                Now = Nxt;
                Nxt = i;
                ans++;
                tmp ^= 1;
                continue;
            }
            if (tmp == 1 && a[i] < a[Now])
            {
                Now = Nxt;
                Nxt = i;
                ans++;
                tmp ^= 1;
                continue;
            }
            if (tmp == 0 && a[i] < a[Nxt])
                Nxt = i;
            if (tmp == 1 && a[i] > a[Nxt])
                Nxt = i;
            // printf("i = %d tmp = %d Nxt = %d Now = %d\n", i, tmp, Nxt, Now);
        }
        maxn[n] = minn[n] = n;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[maxn[i + 1]] > a[i])
                maxn[i] = maxn[i + 1];
            else
                maxn[i] = i;
            if (a[minn[i + 1]] < a[i])
                minn[i] = minn[i + 1];
            else
                minn[i] = i;
        }
        while (Now != n)
        {
            ans++;
            if (Now == minn[Now])
            {
                // printf("maxn %d = %d\n", Now, maxn[Now]);
                Now = maxn[Now];
            }
            else
            {
                // printf("minn %d = %d\n", Now, minn[Now]);
                Now = minn[Now];
            }
        }
        printf("%d\n", ans);
    }
}