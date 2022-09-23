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

const int sqr = sqrt(300000), N = 300003;

using namespace std;

lli n, a[N], ans[N], d[N];
vector < pair < pair < lli, lli >, lli > > v;

int main()
{
    lli m, i, j, h, l, r, g;
    sc( "%I64d", &n );
    for( i = 1; i <= n; i++ )sc( "%I64d", &a[i] );
    sc( "%I64d", &m );
    for( i = 1; i <= m; i++ ){
        sc( "%I64d%I64d", &l, &r );
        if( r <= sqr )v.pb(mp(mp(r, l), i));
        else{
            for( j = l; j <= n; j += r )ans[i] += a[j];
        }
    }
    sort( v.begin(), v.end() );
    for( i = 0; i < v.size(); i++ ){
        l = v[i].fi.se;
        r = v[i].fi.fi;
        g = v[i].se;
        if( !i || v[i].fi.fi != v[i - 1].fi.fi ){
            for( j = n; j >= 1; j-- ){
                d[j] = a[j];
                if( j + r <= n )d[j] += d[j + r];
            }
        }
        ans[g] = d[l];
    }
    for( i = 1; i <= m; i++ )pr( "%I64d\n", ans[i] );
}