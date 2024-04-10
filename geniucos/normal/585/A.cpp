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

int N, ans[4009], v[4009], d[4009], nr, ap[4009];
long long p[4009];

void cry (int pos, int v)
{
    long long val = v;
    for (int i=pos; i<=N; i++)
        if (ap[i])
        {
            p[i] -= val;
            if (p[i] < 0) ap[i] = 0, val += d[i];
        }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d %I64d", &v[i], &d[i], &p[i]), ap[i] = 1;

for (int i=1; i<=N; i++)
    if (p[i] >= 0 && ap[i])
    {
        ans[++nr] = i;
        int val = v[i];
        for (int j=i + 1; j<=N; j++)
        if (ap[j])
        {
            if (p[j] >= 0) p[j] -= val;
            val --;
            if (val < 0) break;
        }
        for (int j=i+1; j<=N; j++)
            if (ap[j] && p[j] < 0)
            {
                ap[j] = 0;
                cry (j + 1, d[j]);
                break;
            }
    }
printf ("%d\n", nr);
for (int i=1; i<=nr; i++)
    printf ("%d ", ans[i]);
return 0;
}