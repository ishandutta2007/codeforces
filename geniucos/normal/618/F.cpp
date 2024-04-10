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

int N, ap[1000009], getj[1000009];
long long sa[1000009], sb[1000009];

void Print_Segm (int i, int j)
{
    printf ("%d\n", j - i);
    for (int k=i + 1; k<=j; k++)
        printf ("%d ", k);
    printf ("\n");
}

void Print (int x, int y, int z, int t, bool rev)
{
    if (rev == 0) Print_Segm (x, y), Print_Segm (z, t);
    else Print_Segm (z, t), Print_Segm (x, y);
}

void solve (bool rev)
{
    ///sb[N] <= sa[N]
    int j = 0;
    for (int i=1; i<=N; i++)
    {
        while (sb[j + 1] <= sa[i] && j < N) j ++;
        if (sb[j] == sa[i])
        {
            Print (0, i, 0, j, rev);
            return ;
        }
        if (ap[sa[i] - sb[j]])
        {
            ///sa[i2] - sb[j2] = sa[i1] - sb[j1], i2 > i1
            ///sa[i2] - sa[i1] = sb[j2] - sb[j1] -> [i1, i2] = [j1, j2]
            int i2 = i, j2 = j, i1 = ap[sa[i] - sb[j]], j1 = getj[i1];
            Print (i1, i2, j1, j2, rev);
            return ;
        }
        ap[sa[i] - sb[j]] = i;
        getj[i] = j;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai), sa[i] = sa[i - 1] + ai;
}
for (int i=1; i<=N; i++)
{
    int bi;
    scanf ("%d", &bi), sb[i] = sb[i - 1] + bi;
}
if (sa[N] >= sb[N]) solve (0);
else
{
    for (int i=1; i<=N; i++)
        swap (sa[i], sb[i]);
    solve (1);
}
return 0;
}