#include<bits/stdc++.h>

using namespace std;

int T, N, ans, dp[109][2016];
vector < int > v[109];

int getK (int i, int K)
{
    if (v[i].empty () || K == 0) return 0;
    if (K > v[i].size ()) return v[i][v[i].size () - 1];
    return v[i][K - 1];
}
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &T);
for (int i=1; i<=N; i++)
{
    int a, b;
    scanf ("%d %d", &a, &b);
    v[a].push_back (b);
}
for (int i=1; i<=T; i++)
{
    sort (v[i].begin (), v[i].end ()), reverse (v[i].begin (), v[i].end ());
    for (int j=1; j<v[i].size (); j++)
        v[i][j] += v[i][j - 1];
}
dp[0][0] = getK (T, 1), dp[0][1] = 0;
for (int i=0; i<T; i++)
{
    int lim = N + 2;
    if (i <= 25 && (1 << i) < lim) lim = 1 << i;
    for (int j=0; j<=lim; j++)
        for (int k=0; k<=v[T - i - 1].size () && k <= 2 * j; k++)
        {
            int curr = dp[i][j] + getK (T - i - 1, k), nj = j * 2 - k;
            if (nj > N + 2) nj = N + 2;
            if (curr > dp[i + 1][nj]) dp[i + 1][nj] = curr;
        }
}
for (int i=0; i<=T; i++)
{
    int lim = N + 2;
    if (i <= 25 && (1 << i) < lim) lim = 1 << i;
    for (int j=0; j<=lim; j++)
        if (dp[i][j] > ans)
            ans = dp[i][j];
}
printf ("%d\n", ans);
return 0;
}