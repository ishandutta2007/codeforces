#include<cstdio>
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

int N, M, K, x[300009], y[300009], d[300009], ap[100009];
long long INF, dp[100009];

vector < pair < int , int > > v[100009];
priority_queue < pair < long long , int > , vector < pair < long long , int > > , greater < pair < long long , int > > > PQ;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);

for (int i=1; i<=M; i++)
{
    scanf ("%d %d %d", &x[i], &y[i], &d[i]);
    v[x[i]].push_back (make_pair (y[i], d[i]));
    v[y[i]].push_back (make_pair (x[i], d[i]));
}

for (int i=1; i<=K; i++)
{
    int s, d;
    scanf ("%d %d", &s, &d);
    v[1].push_back (make_pair (s, d));
}

INF = 1LL << 53;
for (int i=1; i<=N; i++)
    dp[i] = INF;

PQ.push (make_pair (0, 1));
while (!PQ.empty ())
{
    pair < long long , int > tp = PQ.top ();
    PQ.pop ();
    if (dp[tp.second] != INF)
        continue;
    dp[tp.second] = tp.first;
    for (vector < pair < int , int > > :: iterator it = v[tp.second].begin(); it != v[tp.second].end(); it ++)
        if (dp[it->first] > tp.first + it->second)
            PQ.push (make_pair (tp.first + it->second, it->first));
}

for (int i=1; i<=M; i++)
{
    if (dp[x[i]] + d[i] == dp[y[i]])
        ap[y[i]] = 1;
    if (dp[y[i]] + d[i] == dp[x[i]])
        ap[x[i]] = 1;
}

int tre = 0;
for (int i=2; i<=N; i++)
    if (ap[i] == 0)
        tre ++;
printf ("%d\n", K - tre);

return 0;
}