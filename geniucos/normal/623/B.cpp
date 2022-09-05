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

int A, B, N, nr, cr[40009], pr[40009], a[1000009], d[1000009];
long long ans, dp[1000009][3];

void Try (int val)
{
    for (int i=1; i<=N; i++)
    {
        if (a[i] % val == 0) d[i] = 0;
        else
        if ((a[i] - 1) % val == 0 || (a[i] + 1) % val == 0) d[i] = 1;
        else d[i] = 2;
    }
    if (d[N] != 2)
    {
        dp[0][0] = 0;
        for (int i=1; i<=N; i++)
        {
            if (d[i] == 2) dp[i][0] = ans;
            else dp[i][0] = dp[i - 1][0] + B * d[i];
            dp[i][1] = min (dp[i - 1][0], dp[i - 1][1]) + A;
            if (d[i] == 2) dp[i][2] = ans;
            else dp[i][2] = min (dp[i - 1][1], dp[i - 1][2]) + B * d[i];
        }
        long long curr = min (min (dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
        if (d[N] > 0) curr += B;
        if (curr < ans) ans = curr;
    }
    if (d[1] != 2)
    {
        reverse (d + 1, d + N + 1);
        dp[0][0] = 0;
        for (int i=1; i<=N; i++)
        {
            if (d[i] == 2) dp[i][0] = ans;
            else dp[i][0] = dp[i - 1][0] + B * d[i];
            dp[i][1] = min (dp[i - 1][0], dp[i - 1][1]) + A;
            if (d[i] == 2) dp[i][2] = ans;
            else dp[i][2] = min (dp[i - 1][1], dp[i - 1][2]) + B * d[i];
        }
        long long curr = min (min (dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
        if (d[N] > 0) curr += B;
        if (curr < ans) ans = curr;
    }
}

void TTry (int val)
{
    for (int i=1; i<=nr && pr[i] * pr[i] <= val; i++)
        if (val % pr[i] == 0)
        {
            while (val % pr[i] == 0) val /= pr[i];
            Try (pr[i]);
        }
    if (val != 1) Try (val);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &A, &B), ans = 1LL << 50;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=2; i<=32000; i++)
    if (cr[i] == 0)
    {
        for (int j=i*i; j<=32000; j+=i)
            cr[j] = 1;
    }
for (int i=2; i<=32000; i++)
    if (cr[i] == 0) pr[++nr] = i;
TTry (a[1] - 1), TTry (a[1]), TTry (a[1] + 1);
TTry (a[N] - 1), TTry (a[N]), TTry (a[N] + 1);
printf ("%I64d\n", ans);
return 0;
}