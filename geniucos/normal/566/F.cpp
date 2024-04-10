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

int N, maxi, ap[1000009], dp[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai);
    if (ai > maxi) maxi = ai;
    ap[ai] ++;
}
int ans = 1;
for (int i=1; i<=maxi; i++)
{
    dp[i] += ap[i];
    for (int j=i + i; j<=maxi; j+=i)
        if (dp[i] > dp[j])
            dp[j] = dp[i];
    if (dp[i] > ans) ans = dp[i];
}
printf ("%d\n", ans);
return 0;
}