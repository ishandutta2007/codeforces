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

int N, a[109];
double ans, aux[109], p[109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
double P = 1.0;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), p[i] = (double) (100 - a[i]) / 100.0, aux[i] = p[i], P *= (1 - aux[i]);

int d = N;
ans = N * P;
while (1)
{
    d ++;
    double bst = 0.0;
    int how;
    for (int i=1; i<=N; i++)
        if ((1.0 - aux[i] * p[i]) / (1.0 - aux[i]) > bst)
            bst = (1.0 - aux[i] * p[i]) / (1.0 - aux[i]), how = i;
    aux[how] *= p[how];
    ans += P * d * (bst - 1), P *= bst;
    if (1 - P < 1e-10) break;
}
printf ("%.12f\n", ans);

return 0;
}