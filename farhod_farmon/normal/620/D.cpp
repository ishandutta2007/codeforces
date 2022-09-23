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
#include <iomanip>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

const int N = 2002;

using namespace std;

lli n, m, i, j, h, a[N], b[N], ans, sa, sb, l, r, tm;
vector < pair < lli, pair < lli, lli > > > v;
vector < pair < lli, lli > > g;

int main()
{
    cin >> n;
    for( i = 1; i <= n; sa += a[i++] )cin >> a[i];
    cin >> m;
    for( i = 1; i <= m; sb += b[i++] )cin >> b[i];
    ans = abs(sa - sb);
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            if( abs(sa - sb + 2 * (b[j] - a[i])) < ans ){
                ans = abs(sa - sb + 2 * (b[j] - a[i]));
                g.clear();
                g.pb(mp(i, j));
            }
        }
    }
    if( m == 1 )goto F;
    for( i = 1; i <= m; i++ ){
        for( j = i + 1; j <= m; j++ )v.pb(mp(2 * (b[i] + b[j]), mp(i, j)));
    }
    sort( v.begin(), v.end() );
    for( i = 1; i <= n; i++ ){
        for( j = i + 1; j <= n; j++ ){
            lli x = sb - sa + 2 * (a[i] + a[j]);
            l = 0;
            r = v.size() - 1;
            while( l < r ){
                tm = (l + r) / 2;
                if( x > v[tm].fi )l = tm + 1;
                else r = tm;
            }
            for( h = -1; h <= 1; h++ ){
                if( tm + h == -1 || tm + h == v.size() )continue;
                if( abs(x - v[tm + h].fi) < ans ){
                    ans = abs(x - v[tm + h].fi);
                    g.clear();
                    g.pb(mp(i, v[tm + h].se.fi));
                    g.pb(mp(j, v[tm + h].se.se));
                }
            }
        }
    }
    F:
    cout << ans << endl << g.size() << endl;
    for( i = 0; i < g.size(); i++ )cout << g[i].fi << " " << g[i].se << endl;
}