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

int N, mini, dp[100009];
pair < int, int > a[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i].first, &a[i].second);
sort (a + 1, a + N + 1);
mini = N + 4;
for (int i=1; i<=N; i++)
{
   // if (i == 3)
     //   i = 3;
    int p = 1, u = i - 1, mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (a[mij].first < a[i].first - a[i].second) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    dp[i] = dp[ras] + (i - ras - 1);
    if (dp[i] + N - i < mini) mini = dp[i] + N - i;
}
printf ("%d\n", mini);

return 0;
}