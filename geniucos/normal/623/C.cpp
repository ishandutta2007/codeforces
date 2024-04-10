#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#define INF 100000001

using namespace std;

int N, ma_p[100009], mi_p[100009], ma_s[100009], mi_s[100009];
pair < int , int > a[100009];

long long sqr (int val)
{
    return 1LL * val * val;
}

int modul (int x)
{
    if (x < 0) return -x;
    return x;
}

bool ok (long long D)
{
    if (sqr (ma_p[N] - mi_p[N]) <= D || sqr (a[N].first - a[1].first) <= D) return 1;
    for (int i=1; i<=N; i++)
    {
        int p = 1, u = i, mij, j;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (sqr (a[i].first - a[mij].first) <= D && modul (a[mij].first) <= modul (a[i].first)) j = mij, u = mij - 1;
            else p = mij + 1;
        }
        int yma = max (ma_p[j - 1], ma_s[i + 1]), ymi = min (mi_p[j - 1], mi_s[i + 1]);
        if (sqr (yma - ymi) <= D && max (sqr (yma), sqr (ymi)) + sqr (a[i].first) <= D) return 1;
    }
    for (int i=N; i>=1; i--)
    {
        int p = i, u = N, mij, j;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (sqr (a[mij].first - a[i].first) <= D && modul (a[mij].first) <= modul (a[i].first)) j = mij, p = mij + 1;
            else u = mij - 1;
        }
        int yma = max (ma_p[i - 1], ma_s[j + 1]), ymi = min (mi_p[i - 1], mi_s[j + 1]);
        if (sqr (yma - ymi) <= D && max (sqr (yma), sqr (ymi)) + sqr (a[i].first) <= D) return 1;
    }
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i].first, &a[i].second);
sort (a + 1, a + N + 1);
mi_p[0] = INF, ma_p[0] = -INF;
for (int i=1; i<=N; i++)
    mi_p[i] = min (mi_p[i - 1], a[i].second), ma_p[i] = max (ma_p[i - 1], a[i].second);
mi_s[0] = INF, ma_s[0] = -INF;
for (int i=N; i>=1; i--)
    mi_s[i] = min (mi_s[i + 1], a[i].second), ma_s[i] = max (ma_s[i + 1], a[i].second);
sort (a + 1, a + N + 1);
long long p = 0, u = sqr (min (a[N].first - a[1].first, ma_p[N] - mi_p[N])), mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%I64d\n", ras);

return 0;
}