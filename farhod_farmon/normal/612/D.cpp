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

int x, y, i, j, h, n, k, cnt, l = 1e9 + 1;
vector < pair < int, int > > v, ans;

int main()
{
    sc("%d%d", &n, &k);
    for( i = 0; i < n; i++ ){
        sc("%d%d", &x, &y);
        v.pb(mp(x, -1));
        v.pb(mp(y, 1));
    }
    sort( v.begin(), v.end() );
    for( i = 0; i < 2 * n; i++ ){
        cnt += -v[i].se;
        if( cnt == k && l == 1e9 + 1 )l = v[i].fi;
        else if( cnt < k && l != 1e9 + 1 ){
            ans.pb(mp(l, v[i].fi));
            l = 1e9 + 1;
        }
    }
    if( l != 1e9 + 1 )ans.pb(mp(l, v.back().fi));
    pr("%d\n", ans.size());
    for( i = 0; i < ans.size(); i++ )pr("%d %d\n", ans[i].fi, ans[i].se);
}