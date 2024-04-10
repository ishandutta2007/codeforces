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

int N, K, a[200009], ap[200009];

bool ok (int D)
{
    int j = 1, cnt = 0;
    for (int i=1; i<=N; i++)
        ap[i] = 0;
    for (int i=N; i>=1; i--)
    if (ap[i] == 0)
    {
        if (j < i && ap[j] == 0 && a[i] + a[j] <= D) ap[j] = ap[i] = 1, j ++;
        else ap[i] = 1;
        cnt ++;
    }
    return (cnt <= K);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
int p = a[N], u = 2000009, mij, ras;
//ok ((p + u) / 2);
//return 0;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);

return 0;
}