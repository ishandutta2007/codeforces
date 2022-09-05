#include<bits/stdc++.h>

using namespace std;

int N, dp[100009], t[100009];
int length[] = {90, 1440};

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &t[i]);
dp[0] = 0;
int j = 0, k = 0;
for (int i=1; i<=N; i++)
{
    dp[i] = dp[i - 1] + 20;
    while (t[j + 1] + length[0] - 1 < t[i]) j ++;
    while (t[k + 1] + length[1] - 1 < t[i]) k ++;
    dp[i] = min (dp[i], dp[j] + 50);
    dp[i] = min (dp[i], dp[k] + 120);
    printf ("%d\n", dp[i] - dp[i - 1]);
}
return 0;
}