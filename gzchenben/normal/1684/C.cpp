#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, m, ord[200005];
long long sum[200005], tmp[200005];
bool cmp(int x, int y) { return sum[x] < sum[y]; }
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        vector<vector<int>> a;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            a[i].resize(m + 1);
        for (int i = 1; i <= m; i++)
            sum[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                sum[j] += a[i][j];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            tmp[i] = sum[i];
            ord[i] = i;
        }
        sort(tmp + 1, tmp + m + 1);
        sort(ord + 1, ord + m + 1, cmp);
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (a[i][ord[j]] > a[i][ord[j + 1]])
                    flag = true;
            }
        }
        if (flag)
        {
            printf("-1\n");
            continue;
        }
        vector<int> ans;
        for (int i = 1; i <= m; i++)
        {
            if (tmp[i] != sum[i])
                ans.push_back(i);
        }
        if (ans.size() == 0)
            printf("1 1\n");
        else if (ans.size() == 2)
            printf("%d %d\n", ans[0], ans[1]);
        else
            printf("-1\n");
    }
}