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
#define fin freopen( "bet.in", "r", stdin );
#define fout freopen( "bet.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, l, r, x, i, j, ans, c[50];
vector < pair < int, vector < int > > > v;
int main()
{
    cin >> a >> l >> r >> x;
    for( i = 1; i <= a; i++ )cin >> c[i];
    sort( c + 1, c + a + 1 );
    for( i = 1; i <= a; i++ ){
        for( j = v.size() - 1; j >= 0; j-- ){
            vector < int > g = v[j].se;
            g.pb(c[i]);
            v.pb(mp(v[j].fi + c[i], g));
        }
        vector < int > g;
        g.pb(c[i]);
        v.pb(mp(c[i], g));
    }
    for( i = 0; i < v.size(); i++ ){
        if( v[i].fi >= l && v[i].fi <= r && v[i].se.back() - v[i].se[0] >= x )ans++;
    }
    cout << ans;
}