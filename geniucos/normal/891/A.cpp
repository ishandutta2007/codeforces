#include<bits/stdc++.h>

using namespace std;

int N, a[2017], dp[2017][2017];

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), dp[i][i] = a[i];
for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N;j++)
        dp[i][j] = gcd (dp[i][j - 1], a[j]);
for (int l=1; l<=N; l++)
{
    bool ok = 0;
    for (int i=1; i+l-1<=N;i++)
        if (dp[i][i+l-1]==1)
        {
            ok = 1;
            break;
        }
    if (ok)
    {
        if (l == 1)
        {
            int ans = 0;
            for (int i=1; i<=N; i++)
                ans += (a[i] != 1);
            printf ("%d\n", ans);
        }
        else printf ("%d\n", l - 1 + N - 1);
        exit (0);
    }
}
printf ("-1\n");
return 0;
}