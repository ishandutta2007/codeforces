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

const int N = 300003;

using namespace std;

int n, x, y, i, j, d[N], m, ans, last[N], w;
vector < pair < int, int > > v[N];

int main()
{
    sc( "%d%d", &n, &m );
    for( i = 1; i <= m; i++ ){
        sc( "%d%d%d", &x, &y, &w );
        v[w].pb(mp(x, y));
    }
    for( w = 1; w <= 100000; w++ ){
        for( i = 0; i < v[w].size(); i++ ){
            x = v[w][i].fi;
            y = v[w][i].se;
            d[y] = max(d[y], last[x] + 1);
        }
        for( i = 0; i < v[w].size(); i++ ){
            x = v[w][i].fi;
            y = v[w][i].se;
            last[y] = max(d[y], last[y]);
            ans = max(ans, last[y]);
        }
    }
    pr( "%d", ans );
}