#include<bits/stdc++.h>

using namespace std;

int ans = 0, N, B, c[5009], d[5009], t[5009], dp[5009][5009], fara[5009][5009], vol[5009], old[5009];
vector < int > v[5009];

void df1 (int nod)
{
    vol[nod] = 1, fara[nod][0] = 0, fara[nod][1] = c[nod];
    for (auto it : v[nod])
    {
        df1 (it);
        for (int j=0; j<=vol[nod]; j++)
            old[j] = fara[nod][j];
        for (int j=0; j<=vol[nod] + vol[it]; j++)
            fara[nod][j] = B + 1;
        for (int j=0; j<=vol[nod]; j++)
            for (int k=0; k<=vol[it]; k++)
                if (old[j] + fara[it][k] < fara[nod][j + k])
                    fara[nod][j + k] = old[j] + fara[it][k];
        vol[nod] += vol[it];
    }
}

void solve (int nod)
{
    vol[nod] = 1;
    dp[nod][0] = B + 1, dp[nod][1] = c[nod] - d[nod];
    for (auto it : v[nod])
    {
        solve (it);
        for (int j=0; j<=vol[nod]; j++)
            old[j] = dp[nod][j];
        for (int j=2; j<=vol[nod] + vol[it]; j++)///2 e baza
            dp[nod][j] = B + 1;
        for (int j=1; j<=vol[nod]; j++)///1 e baza
            for (int k=0; k<=vol[it]; k++)
                if (old[j] + min (fara[it][k], dp[it][k]) < dp[nod][j + k])
                    dp[nod][j + k] = old[j] + min (fara[it][k], dp[it][k]);
        vol[nod] += vol[it];
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &B);
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &c[i], &d[i]);
    if (i >= 2) scanf ("%d", &t[i]), v[t[i]].push_back (i);
}
df1 (1);
solve (1);
for (int i=0; i<=N; i++)
{
    int curr = min (dp[1][i], fara[1][i]);
    if (curr <= B)
        ans = i;
}
printf ("%d\n", ans);

return 0;
}