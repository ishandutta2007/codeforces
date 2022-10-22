#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<long long, long long>> p1, p2;
int t, n, m, k, a[50005], b[50005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        p1.clear();
        p2.clear();
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            long long tmp1 = a[i], tmp2 = 1;
            while (tmp1 % k == 0)
            {
                tmp1 /= k;
                tmp2 *= k;
            }
            if (!p1.empty() && p1.back().second == tmp1)
            {
                p1.back().first += tmp2;
            }
            else
            {
                p1.push_back({tmp2, tmp1});
            }
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
            long long tmp1 = b[i], tmp2 = 1;
            while (tmp1 % k == 0)
            {
                tmp1 /= k;
                tmp2 *= k;
            }
            if (!p2.empty() && p2.back().second == tmp1)
            {
                p2.back().first += tmp2;
            }
            else
            {
                p2.push_back({tmp2, tmp1});
            }
        }
        if (p1 == p2)
            printf("Yes\n");
        else
            printf("No\n");
    }
}