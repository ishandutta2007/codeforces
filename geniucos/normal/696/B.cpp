#include<bits/stdc++.h>

using namespace std;

int N, t[100009], vol[100009], dp[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N; i++)
    scanf ("%d", &t[i]);
for (int i=1; i<=N; i++)
    vol[i] = 1;
for (int i=N; i>1; i--)
    vol[t[i]] += vol[i];
dp[1] = 2;
for (int i=2; i<=N; i++)
    dp[i] = 2 + dp[t[i]] + (vol[t[i]] - 1) - vol[i];
for (int i=1; i<=N; i++)
    if (dp[i] % 2 == 0) printf ("%d.0 ", dp[i] / 2);
    else printf ("%d.5 ", dp[i] / 2);
printf ("\n");
return 0;
}