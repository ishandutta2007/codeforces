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

int N, M, nr, Nr, a[1000009], ap[1000009], dp[1000009];
bool known[1000009];
pair < int , int > b[1000009];
vector < int > v[1000009], h[1000009], e[1000009];

void dfs (int nod)
{
    ap[nod] = Nr;
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (ap[*it] == 0)
            dfs (*it);
}

void calc (int nod)
{
    if (known[nod]) return ;
    known[nod] = 1, dp[nod] = 0;
    for (vector < int > :: iterator it = e[nod].begin (); it != e[nod].end (); it ++)
    {
        calc (*it);
        if (dp[*it] > dp[nod]) dp[nod] = dp[*it];
    }
    dp[nod] ++;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
        scanf ("%d", &a[nr ++]);
for (int i=0; i<N; i++)
{
    int l = 0;
    for (int j=0; j<M; j++)
        b[++l] = make_pair (a[i * M + j], i * M + j);
    sort (b + 1, b + l + 1);
    for (int j=2; j<=l; j++)
    {
        if (b[j].first == b[j - 1].first) h[b[j].second].push_back (b[j - 1].second), h[b[j - 1].second].push_back (b[j].second);
        else v[b[j].second].push_back (b[j - 1].second);
    }
}
for (int j=0; j<M; j++)
{
    int l = 0;
    for (int i=0; i<N; i++)
        b[++l] = make_pair (a[i * M + j], i * M + j);
    sort (b + 1, b + l + 1);
    for (int j=2; j<=l; j++)
    {
        if (b[j].first == b[j - 1].first) h[b[j].second].push_back (b[j - 1].second), h[b[j - 1].second].push_back (b[j].second);
        else v[b[j].second].push_back (b[j - 1].second);
    }
}
for (int i=0; i<nr; i++)
    if (ap[i] == 0) ++Nr, dfs (i);
for (int i=0; i<nr; i++)
    for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
        e[ap[i]].push_back (ap[*it]);
for (int i=1; i<=Nr; i++)
    calc (i);
for (int i=0; i<nr; i++)
{
    printf ("%d", dp[ap[i]]);
    if ((i + 1) % M == 0) printf ("\n");
    else printf (" ");
}
return 0;
}