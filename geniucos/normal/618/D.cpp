#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int X, Y, N, ap[209][209], p[209], dp[200009][2];
vector < int > v[200009];

void solve (int nod, int tata)
{
    int sum0 = 0, min1 = N + 4, min2 = N + 4;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    if (*it != tata)
    {
        solve (*it, nod);
        sum0 += dp[*it][0];
        int curr = dp[*it][1] - dp[*it][0];
        if (curr < min1) min2 = min1, min1 = curr;
        else
        if (curr < min2) min2 = curr;
    }
    dp[nod][0] = dp[nod][1] = sum0 + 1;
    if (sum0 + min1 < dp[nod][1]) dp[nod][1] = sum0 + min1;
    if (sum0 + min1 + min2 - 1 < dp[nod][0]) dp[nod][0] = sum0 + min1 + min2 - 1;
    if (dp[nod][1] < dp[nod][0]) dp[nod][0] = dp[nod][1];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &X, &Y);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
solve (1, -1);
int mnpths = min (dp[1][0], dp[1][1]);
if (Y >= X)
{
    printf ("%I64d\n", (long long) 1LL * (mnpths - 1) * Y + 1LL * (N - mnpths) * X);
    return 0;
}
if (N <= 9)
{
    for (int i=1; i<=N; i++)
        for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
            ap[i][*it] = 1;
    int fac = 1;
    for (int i=1; i<=N; i++)
        p[i] = i, fac *= i;
    long long mini = 1LL << 60;
    while (fac --)
    {
        long long curr = 0;
        for (int i=1; i<N; i++)
        {
            if (ap[p[i]][p[i + 1]]) curr = (long long) curr + X;
            else curr = (long long) curr + Y;
        }
        if (curr < mini) mini = curr;
        next_permutation (p + 1, p + N + 1);
    }
    printf ("%I64d\n", mini);
    return 0;
}
int ctx = 0;
for (int i=1; i<=N; i++)
    if (v[i].size () == N - 1) ctx = 1;
printf ("%I64d\n", 1LL * X * ctx + 1LL * Y * (N - 1 - ctx));
return 0;
}