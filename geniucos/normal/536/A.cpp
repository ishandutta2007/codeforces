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

int A, B, M, l, t, m;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &A, &B, &M);
while (M)
{
    M --;
    scanf ("%d %d %d", &l, &t, &m);
    int p, u, mij, ras = -1;
    p = l;
    u = 2000000;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if ((long long) 1LL * t * m * 2LL / (mij - l + 1) >= (long long) 1LL * A * 2 + 1LL * B * (mij + l - 2) && (long long) A + 1LL * B * (mij - 1) <= t)
            ras = mij, p = mij + 1;
        else
            u = mij - 1;
    }
    printf ("%d\n", ras);
}

return 0;
}