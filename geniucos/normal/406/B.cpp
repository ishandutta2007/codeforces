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

int N, m, S, nr, ap[1000009], y[1000009], z[1000009], ans[1000009], x[1000009];
long long wntd;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), S = 1e6;
for (int i=1; i<=N; i++)
{
    scanf ("%d", &x[i]);
    ap[x[i]] = 1;
}
for (int i=1; i<=N; i++)
    if (ap[S - x[i] + 1] == 0) ans[++nr] = S - x[i] + 1;
    else wntd += x[i];
for (int i=1; i < S - i + 1; i++)
    if (ap[i] == 0 && ap[S - i + 1] == 0)
        y[++m] = i, y[++m] = S - i + 1;
for (int i=m; i>=1; i--)
    if (wntd >= y[i]) ans[++nr] = S - y[i] + 1, wntd -= y[i];
printf ("%d\n", nr);
for (int i=1; i<=nr; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}