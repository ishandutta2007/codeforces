#include<bits/stdc++.h>

using namespace std;

int N, a[100009];
bool dp[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
bool lose = 0;
dp[N] = 1, dp[N + 1] = 0;
for (int i=N - 1; i>=1; i--)
{
    if (a[i] != a[i + 1])
    {
        if (dp[i + 2] == 0)
            lose = 1;
    }
    if (lose == 1 || dp[i + 1] == 0)
        dp[i] = 1;
    else
        dp[i] = 0;
}
if (dp[1] == 1) printf ("Conan\n");
else printf ("Agasa\n");
return 0;
}