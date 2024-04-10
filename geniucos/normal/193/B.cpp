#include<cstdio>
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

int N, U, r, a[40], b[40], k[40], p[40];
long long ans;

void perform (int type, int aux[])
{
    if (type == 0)
    {
        for (int i=1; i<=N; i++)
            a[i] ^= b[i];
    }
    else
    {
        for (int i=1; i<=N; i++)
            a[i] = aux[p[i]] + r;
    }
}

void back (int pos, int last)
{
    if ((U & 1) != (pos & 1))
    {
        long long sum = 0;
        for (int i=1; i<=N; i++)
            sum = sum + 1LL * k[i] * a[i];
        if (sum > ans)
            ans = sum;
    }
    if (pos == U + 1) return ;
    int aux[35];
    for (int i=1; i<=N; i++)
        aux[i] = a[i];
    for (int i=0; i<2; i++)
        if (i != 0 || last != 0)
        {
            perform (i, aux);
            back (pos + 1, i);
            for (int j=1; j<=N; j++)
                a[j] = aux[j];
        }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &U, &r);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &k[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);

ans = -(1LL<<50);
back (1, -1);
printf ("%I64d\n", ans);

return 0;
}