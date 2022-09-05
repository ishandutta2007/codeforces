#include<bits/stdc++.h>

using namespace std;

int N, s[1000009], dp[1000009];
char sir[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
scanf ("%s", sir + 1);
for (int i=1; i<=N; i++)
{
    if (sir[i] == '(') sir[i] = +1;
    else sir[i] = -1;
    s[i] = s[i - 1] + sir[i];
}
if (s[N] != 0)
{
    printf ("-1\n");
    return 0;
}
dp[0] = 0;
int mi = 0;
for (int i=1; i<=N; i++)
{
    if (s[i] < 0) dp[i] = 5 * N;
    else
        dp[i] = min (dp[i - 1], mi + i);
    mi = min (mi, dp[i] - i);
}
printf ("%d\n", dp[N]);
return 0;
}