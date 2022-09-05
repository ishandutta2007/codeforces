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

long long N;
int dx[] = {-1, -2, -1, +1, +2, +1};
int dy[] = {+2, +0, -2, -2, +0, +2};

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d", &N);
if (N == 0)
{
    printf ("0 0\n");
    return 0;
}
int p = 1, u = 6e8, mij, k;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (3LL * mij * (mij + 1) >= N) k = mij, u = mij - 1;
    else p = mij + 1;
}
if (3LL * k * (k + 1) == N)
{
    printf ("%d 0\n", 2 * k);
    return 0;
}
long long steps = N - 3LL * (k - 1) * k, x = 2LL * k, y = 0;
for (int i=0; i<6; i++)
{
    if (steps <= k)
    {
        printf ("%I64d %I64d\n", x + 1LL * dx[i] * steps, y + 1LL * dy[i] * steps);
        return 0;
    }
    x += 1LL * dx[i] * k;
    y += 1LL * dy[i] * k;
    steps -= k;
}
return 0;
}