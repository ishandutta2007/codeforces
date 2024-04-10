#include<bits/stdc++.h>

using namespace std;

int N, M, maxi, s[209], dp[209], a[209];

void dfs (int x)
{
    dp[x] = 1;
    for (int y=0; y<=x; y++)
    if (N - y <= M - x)
    {
        int z = x - y + N - y;
        if (z >= 0 && z <= M && dp[z] == 0) dfs (z);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), M = N + N - 1;
for (int i=1; i<=M; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + M + 1);
for (int i=1; i<=M; i++)
    s[i] = s[i - 1] + a[i];
dfs (M), maxi = -1<<27;
/*for (int i=0; i<=M; i++)
    printf ("%d\n", dp[i]);
return 0;*/
for (int i=0; i<=M; i++)
    if (dp[M - i] && s[M] - 2 * s[i] > maxi)
        maxi = s[M] - 2 * s[i];
printf ("%d\n", maxi);
return 0;
}