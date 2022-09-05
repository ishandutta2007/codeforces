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

int N, aib[200009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int sol = 0;
for (int i=1; i<=N; i++)
{
    int x, dp;
    scanf ("%d", &x);
    dp = aib[x - 1] + 1;
    if (dp > sol) sol = dp;
    aib[x] = dp;
}
printf ("%d\n", N - sol);

return 0;
}