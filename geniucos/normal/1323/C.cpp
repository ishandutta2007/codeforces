#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, dp[maxN], s[maxN];
char sir[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
scanf ("%s", sir + 1);
for (int i=1; i<=N; i++)
    if (sir[i] == '(') s[i] = s[i - 1] + 1;
    else s[i] = s[i - 1] - 1;
if (s[N] != 0)
{
    printf ("-1\n");
    return 0;
}
int curr = 0;
for (int i=1; i<=N; i++)
{
    if (s[i] < 0)
        dp[i] = 2 * N + 10;
    else
        dp[i] = min (dp[i - 1], curr + i);
    ///dp[i] = min (dp[j] + reorder j + 1, i)
    curr = min (curr, dp[i] - i);
}
printf ("%d\n", dp[N]);
return 0;
}