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

int nr2, N, M, cnt, nr, ap[2016], dp[2016], niv[2016], vol[2016], v2[2016], pot[2016];
bool bridge[2016][2016];
vector < int > v[2016], h[2016];

void dfs (int nod, int tata)
{
    dp[nod] = niv[nod];
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (niv[*it] == 0)
        {
            niv[*it] = niv[nod] + 1, dfs (*it, nod);
            if (dp[*it] > niv[nod]) bridge[nod][*it] = bridge[*it][nod] = 1;///critical edge
        }
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != tata && dp[*it] < dp[nod])
            dp[nod] = dp[*it];
}

void fill (int nod)
{
    ap[nod] = nr, vol[nr] ++;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0 && !bridge[nod][*it])
            fill (*it);
}

void df2 (int nod, int tata, int sum_vol, int &s)
{
    v2[nr2] += vol[nod], s += vol[nod] * sum_vol;
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (*it != tata)
            df2 (*it, nod, sum_vol + vol[*it], s);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y), v[y].push_back (x);
}
dfs (1, -1);
for (int i=1; i<=N; i++)
    if (ap[i] == 0) nr ++, fill (i);

for (int i=1; i<=N; i++)
    for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
        if (bridge[i][*it]) h[ap[i]].push_back (ap[*it]);

int maxi = 0;
for (int root = 1; root <= nr; root ++)
{
    int curr = vol[root] * vol[root];
    nr2 = 0;
    for (vector < int > :: iterator it = h[root].begin (); it != h[root].end (); it ++)
        v2[++nr2] = 0, df2 (*it, root, vol[root] + vol[*it], curr);
    for (int i=1; i<=N; i++)
        pot[i] = 0;
    pot[0] = 1;
    for (int i=1; i<=nr2; i++)
        for (int j=N - v2[i]; j>=0; j--)
            if (pot[j]) pot[j + v2[i]] |= 1;
    int curr2 = 0;
    for (int i=1; i<=N; i++)
        if (pot[i])
        {
            int in = i, out = N - in - vol[root];
            if (in * out > curr2) curr2 = in * out;
        }
    if (curr2 + curr > maxi) maxi = curr + curr2;
}
printf ("%d\n", maxi);

return 0;
}