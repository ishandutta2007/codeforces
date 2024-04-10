#include<bits/stdc++.h>

using namespace std;

int N, s[60], dp[60], x[60];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &x[i]);
dp[N] = x[N], s[N] = x[N];
for (int i=N - 1; i>=1; i--)
    s[i] = s[i + 1] + x[i];
for (int i=N - 1; i>=1; i--)
    dp[i] = max (x[i] + s[i + 1] - dp[i + 1], dp[i + 1]);
printf ("%d %d\n", s[1] - dp[1], dp[1]);
return 0;
}