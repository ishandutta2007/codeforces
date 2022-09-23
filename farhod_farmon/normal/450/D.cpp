#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

map < pair < lli, lli >, bool > us;
lli n, m, k, d[N], way[N], i, j, p[N];
vector < pair < lli, lli > > v[N];
vector < lli > g[N];
set < pair < lli, lli > > s;

int main()
{
    sc( "%I64d%I64d%I64d", &n, &m, &k );
    for( i = 1; i <= m; i++ ){
        lli x, y, l;
        sc( "%I64d%I64d%I64d", &x, &y, &l );
        v[x].pb(mp(y, l));
        v[y].pb(mp(x, l));
    }
    for( i = 1; i <= k; i++ ){
        lli x, l;
        sc( "%I64d%I64d", &x, &l );
        g[x].pb(l);
    }
    for( i = 1; i <= n; i++ ){
        d[i] = 1e15;
        sort( g[i].begin(), g[i].end() );
        if( g[i].empty() )
            continue;
        lli l = g[i][0];
        v[1].pb(mp(i, l));
    }
    d[1] = 0;
    way[1] = 1;
    s.insert(mp(0, 1));
    while( !s.empty() ){
        lli x = s.begin()->se;
        s.erase(s.begin());
        for( i = 0; i < v[x].size(); i++ ){
            lli y = v[x][i].fi, l = v[x][i].se;
            if( d[x] + l < d[y] ){
                s.erase(mp(d[y], y));
                d[y] = d[x] + l;
                p[y] = x;
                way[y] = way[x];
                s.insert(mp(d[y], y));
            }
            else if( d[x] + l == d[y] )
                way[y] += way[x];
        }
    }
    for( i = 2; i <= n; i++ ){
        if( g[i].empty() )
            continue;
        if( d[i] == g[i][0] && way[i] == 1 )
            k--;
    }
    pr( "%I64d\n", k );
}