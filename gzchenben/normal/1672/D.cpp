#include <cstdio>
#include <vector>
using namespace std;
int n, t, a[200005], b[200005], cnt[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            cnt[i] = 0;
        }
        a[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        int Now = 1;
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[Now] == b[i])
            {
                Now++;
                continue;
            }
            if (b[i] == b[i - 1] && cnt[b[i]])
            {
                cnt[b[i]]--;
                continue;
            }
            while (Now <= n && a[Now] != b[i])
            {
                cnt[a[Now]]++;
                Now++;
            }
            if (Now == n + 1)
            {
                flag = false;
                break;
            }
            Now++;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
}