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

int N, K, X;
long long a[200009], dp[200009], ans;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &K, &X);
long long P = 1;
while (K --) P *= X;
for (int i=1; i<=N; i++)
{
    int val;
    scanf ("%d", &val);
    a[i] = val;
}
long long curr = 0LL;
for (int i=1; i<=N; i++)
{
    dp[i] = curr | (1LL * a[i] * P);
    curr = curr | a[i];
}
curr = 0;
for (int i=N; i>=1; i--)
{
    dp[i] |= curr;
    curr |= a[i];
}
long long ans = 0;
for (int i=1; i<=N; i++)
    if (dp[i] > ans)
        ans = dp[i];
printf ("%I64d\n", ans);
return 0;
}