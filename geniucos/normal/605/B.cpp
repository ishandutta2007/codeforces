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

using namespace std;

int N, M, nr, pos, ls, x[200009], y[200009], c[200009], d[200009];
pair < int , pair < int , int > > a[200009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d", &a[i].first, &a[i].second.first), a[i].second.second = i, a[i].second.first ^= 1;
sort (a + 1, a + M + 1);
for (int i=1; i<=M; i++)
    a[i].second.first ^= 1;
nr = 1, ls = 0, pos = 0;
for (int i=1; i<=M; i++)
{
    int P = a[i].second.second;
    if (a[i].second.first)
    {
        nr ++;
        x[P] = nr, y[P] = 1;
        for (int j=2; j<nr && ls < M; j ++)
            c[++ls] = j, d[ls] = nr;
        continue;
    }
    if (pos + 1 > ls)
    {
        printf ("-1\n");
        return 0;
    }
    pos ++, x[P] = c[pos], y[P] = d[pos];
}

for (int i=1; i<=M; i++)
    printf ("%d %d\n", x[i], y[i]);

return 0;
}