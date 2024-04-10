#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, t;
long long F[100005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int Maxn = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            F[i] = 0;
            for (int j = 1; j <= m; j++)
            {
                long long tmp = 0;
                scanf("%lld", &tmp);
                F[i] += tmp * j;
            }
            if (F[i] > F[Maxn])
                Maxn = i;
        }
        printf("%d %lld\n", Maxn, F[Maxn] - min(F[1], F[2]));
    }
}