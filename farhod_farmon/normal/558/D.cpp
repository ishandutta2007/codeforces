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
lli h, i, j, k, l, r, m, L, R, x, q;
vector < pair < lli, lli > > v;

int main()
{
    sc( "%I64d%I64d", &h, &q );
    l = 1;
    r = 1;
    for( i = 1; i < h; i++ ){
        l = l * 2;
        r = r * 2 + 1;
    }
    for( i = 1; i <= q; i++ ){
        sc( "%I64d%I64d%I64d%I64d", &x, &L, &R, &k );
        for( j = x; j < h; j++ ){
            L = L * 2;
            R = R * 2 + 1;
        }
        if( k ){
            l = max(l, L);
            r = min(r, R);
        }
        else v.pb({L, R});
    }
    sort( v.begin(), v.end() );
    for( i = 0; i < int(v.size()); i++ ){
        if( l >= v[i].fi && l <= v[i].se )l = v[i].se + 1;
    }
    for( i = int(v.size()) - 1; i >= 0; i-- ){
        if( r >= v[i].fi && r <= v[i].se )r = v[i].fi - 1;
    }
    if( r > l )cout << "Data not sufficient!";
    else if( r < l )cout << "Game cheated!";
    else cout << l;
}