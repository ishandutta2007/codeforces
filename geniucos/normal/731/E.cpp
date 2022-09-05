#include<bits/stdc++.h>

using namespace std;

int N;
long long dp[200009], s[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int val;
    scanf ("%d", &val);
    s[i] = s[i - 1] + val;
}
long long bst = -1LL << 50;
for (int i=N; i>=1; i--)
{
    if (i > 1 && s[i] - dp[i + 1] > bst) bst = s[i] - dp[i + 1];
    dp[i] = bst;
}
printf ("%I64d\n", dp[1]);

return 0;
}