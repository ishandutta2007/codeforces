#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
const long long mod = 998244353;
using namespace std;
int n, m, t, rt, In1[1005], In2[1005];
long long a[1005], tmp[1005];
vector<int> Edge1[1005], Edge2[1005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            In1[i] = In2[i] = 0;
            Edge1[i].clear();
            Edge2[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            Edge1[y].push_back(x);
            Edge2[x].push_back(y);
            In1[x]++;
            In2[y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!In1[i])
                rt = i;
        }
        bool End = false;
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int j = 1; j <= n; j++)
            {
                tmp[j] = a[j];
                if (tmp[j])
                    flag = false;
            }
            if (flag)
            {
                printf("%d\n", i - 1);
                End = true;
                break;
            }
            for (int j = 1; j <= n; j++)
            {
                if (tmp[j] == 0)
                    continue;
                a[j]--;
                for (auto &p : Edge2[j])
                    a[p]++;
            }
            // printf("After %d steps\n", i);
            // for (int i = 1; i <= n; i++)
            //     printf("%d ", a[i]);
            // printf("\n");
        }
        if (End)
            continue;

        queue<int> Q;
        for (int i = 1; i <= n; i++)
        {
            if (In2[i] == 0)
                Q.push(i);
        }
        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for (auto &p : Edge2[cur])
            {
                a[p] = (a[p] + a[cur]) % mod;
                In2[p]--;
                if (In2[p] == 0)
                    Q.push(p);
            }
        }
        printf("%lld\n", (a[rt] + n) % mod);
    }
}