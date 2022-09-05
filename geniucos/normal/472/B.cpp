#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int n, k, a[2009], ma[2009][2009], dp[2009];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &n);
scanf ("%d", &k);
for (int i=1; i<=n; i++)
{
    scanf ("%d", &a[i]);
    a[i]--;
}
sort (a+1, a+n+1);

for (int i=n; i>=1; i--)
{
    ma[i][i] = a[i];
    for (int j=i+1; j<=n; j++)
        ma[i][j] = max(ma[i][j-1], a[j]);
}

dp[0]=0;
for (int i=1; i<=n; i++)
{
    dp[i] = 1000000000;
    for (int j=max(i-k, 0); j<i; j++)
        if (dp[j] + ma[j+1][i]*2 < dp[i])
            dp[i] = dp[j] + ma[j+1][i]*2;
}

printf ("%d\n", dp[n]);
return 0;
}