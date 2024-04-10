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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, x, i, j, ans[1000];
vector < pair < int, pair < int, int > > > v;

int main()
{
    cin >> a;
    a *= 2;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j < i; j++ ){
            cin >> x;
            v.pb({x, {i, j}});
        }
    }
    sort( v.begin(), v.end() );
    for( i = v.size() - 1; i >= 0; i-- ){
        if( ans[v[i].se.fi] || ans[v[i].se.se] )continue;
        ans[v[i].se.fi] = v[i].se.se;
        ans[v[i].se.se] = v[i].se.fi;
    }
    for( i = 1; i <= a; i++ )cout << ans[i] << " ";
}