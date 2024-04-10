#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, i, j, h, d[300011], s, x, y, z[300011], INF = 999999999999999999ll, p[300011], sum;
vector < pair < lli, pair < lli, lli > > > v[300011];
set < pair < lli, lli > > q;

int main()
{
    sc("%I64d%I64d", &a, &b);
    for( i = 1; i <= b; i++ ){
        sc("%I64d%I64d%I64d", &x, &y, &z[i]);
        v[x].pb(mp(i, mp(y, z[i])));
        v[y].pb(mp(i, mp(x, z[i])));
    }
    sc("%I64d", &s);
    for( i = 1; i <= a; i++ )d[i] = INF;
    d[s] = 0;
    q.insert(mp(d[s], s));
    while( !q.empty() ){
        int x1 = q.begin()->se;
        q.erase(q.begin());
        for( i = 0; i < v[x1].size(); i++ ){
            lli to = v[x1][i].se.fi, len = v[x1][i].se.se;
            if( d[x1] + len < d[to] || d[x1] + len == d[to] && z[p[to]] > z[v[x1][i].fi] ){
                q.erase( mp(d[to], to) );
                sum -= z[p[to]];
                d[to] = d[x1] + len;
                p[to] = v[x1][i].fi;
                sum += z[p[to]];
                q.insert( mp(d[to], to) );
            }
        }
    }
    pr( "%I64d\n", sum );
    for( i = 1; i <= a; i++ ){
        if( i != s )pr( "%I64d ", p[i] );
    }
}