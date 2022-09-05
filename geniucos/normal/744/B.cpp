#include<bits/stdc++.h>

using namespace std;

int N, dp[20][2][1009], v[1009], ans[1009];
int a[1009][1009];
bool Deb = 0;

void Prep ()
{
    if (!Deb) return ;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            scanf ("%d", &a[i][j]);
}

void ansQ (int nr, int pos, bool val)
{
    for (int i=1; i<=N; i++)
    {
        dp[pos][val][i] = 1e9 + 1;
        for (int j=1; j<=nr; j++)
            if (a[i][v[j]] < dp[pos][val][i])
                dp[pos][val][i] = a[i][v[j]];
    }
}

void Build (int pos, bool val)
{
    int nr = 0;
    for (int j=1; j<=N; j++)
    {
        bool real_val = ((j & (1 << pos)) > 0);
        if (val == real_val) v[++nr] = j;
    }
    if (Deb) ansQ (nr, pos, val);
    else
    {
        if (nr == 0)
        {
            for (int i=1; i<=N; i++)
                dp[pos][val][i] = 1e9;
            return ;
        }
        printf ("%d\n", nr);
        for (int i=1; i<=nr; i++)
            printf ("%d ", v[i]);
        fflush (stdout);
        for (int i=1; i<=N; i++)
            scanf ("%d", &dp[pos][val][i]);
        fflush (stdout);
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
Prep ();
for (int i=0; i<10; i++)
    for (int j=0; j<2; j++)
        Build (i, j);
for (int i=1; i<=N; i++)
{
    ans[i] = 1e9;
    for (int j=0; j<10; j++)
    {
        bool bit = ((i & (1 << j)) > 0);
        if (dp[j][bit ^ 1][i] < ans[i]) ans[i] = dp[j][bit ^ 1][i];
    }
}
printf ("-1\n");
for (int i=1; i<=N; i++)
    printf ("%d ", ans[i]);
fflush (stdout);

return 0;
}