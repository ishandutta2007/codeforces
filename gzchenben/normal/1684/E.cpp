#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, t, a[100005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int Now = -1, pos = n + 1, tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == Now)
                continue;
            while (Now + 1 < a[i] && k)
            {
                Now++;
                tmp++;
                k--;
            }
            if (Now + 1 == a[i])
                Now++;
            else
            {
                pos = i;
                break;
            }
        }
        vector<int> cnt;
        int num = 0;
        a[n + 1] = -1;
        for (int i = pos; i <= n; i++)
        {
            if (a[i] == a[i + 1])
                num++;
            else
            {
                cnt.push_back(num + 1);
                num = 0;
            }
        }
        sort(cnt.begin(), cnt.end());
        int res = tmp, ans = cnt.size();
        for (auto &p : cnt)
        {
            if (res < p)
                break;
            res -= p;
            ans--;
        }
        printf("%d\n", ans);
    }
}