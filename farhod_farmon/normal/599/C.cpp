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
#define fin freopen( "division.in", "r", stdin );
#define fout freopen( "division.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, h[100011], d[100011], ans, r1[100011];
bool used[100011];
vector < pair < int, int > > v;

int lb( int x, int g )
{
    int l = 1, r = a, m, g1, i;
    while( l < r ){
        m = (l + r) / 2;
        if( d[m] < x )l = m + 1;
        else r = m;
    }
    g1 = l;
    if( g < g1 ){
        while( used[g1] )g1++;
    }
    else if( g > r1[g1] ){
        g1 = r1[g1];
        while( used[g1] )g1--;
    }
    else{
        for( i = 0; ; i++ ){
            if( g - i >= g1 && !used[g - i] ){
                g1 = g - i;
                break;
            }
            if( g + i <= r1[g1] && !used[g + i] ){
                g1 = g + i;
                break;
            }
        }
    }
    used[g1] = true;
    return g1;
}

int main()
{
    int i, j, l, r, m, x;
    sc( "%d", &a );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &h[i] );
        d[i] = h[i];
    }
    sort( d + 1, d + a + 1 );
    for( i = a; i >= 1; i-- ){
        if( d[i] == d[i + 1] )r1[i] = r1[i + 1];
        else r1[i] = i;
    }
    for( i = 1; i <= a; i++ ){
        x = lb( h[i], i );
        v.pb(mp(min(i, x), max(i, x)));
    }
    sort( v.begin(), v.end() );
    ans = v.size();
    for( i = 1; i < v.size(); i++ ){
        if( v[i].fi <= v[i - 1].se ){
            v[i].se = max(v[i].se, v[i - 1].se);
            ans--;
        }
    }
    pr( "%d", ans );
}