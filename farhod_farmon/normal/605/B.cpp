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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, m, g = 1, x[101101], y[101101];
pair < int, pair < int, int > > p[101101];
pair < int, int > ans[101101];

int main()
{
    int i, j, h = 0;
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> p[i].fi >> p[i].se.fi;
        p[i].se = mp(-p[i].se.fi, i);
    }
    for( i = 3; i <= n; i++ ){
        for( j = 2; j < i; j++ ){
            x[++h] = j;
            y[h] = i;
            if( h == m )break;
        }
        if( h == m )break;
    }
    h = 0;
    sort( p + 1, p + m + 1 );
    for( i = 1; i <= m; i++ ){
        if( p[i].se.fi == -1 ) ans[p[i].se.se] = mp(1, ++g);
        else{
            h++;
            if( y[h] > g ){
                cout << -1 << endl;
                return 0;
            }
            ans[p[i].se.se] = mp(x[h], y[h]);
        }
    }
    for( i = 1; i <= m; i++ )cout << ans[i].fi << " " << ans[i].se << endl;
}