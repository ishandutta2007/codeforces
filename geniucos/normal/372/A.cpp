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

int nr, N, ap[100009], a[500009];

bool ok (int p)
{
    for (int i=1; i<=p; i++)
        if (a[i] > a[nr - p + i] >> 1)
            return 0;
    return 1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
while (N)
{
    N --;
    int x;
    scanf ("%d", &x);
    ap[x] ++;
}

for (int i=1; i<=100000; i++)
    for (int j=1; j<=ap[i]; j++)
        a[++nr] = i;

int p, u, mij, ras = 0;
p = 1, u = nr >> 1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij))
        ras = mij, p = mij + 1;
    else
        u = mij - 1;
}

printf ("%d\n", nr - ras);

return 0;
}