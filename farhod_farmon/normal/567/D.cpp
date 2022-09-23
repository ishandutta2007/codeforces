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
lli n, k, a, i, j, h, x, l, r, cl, m, l1, r1, l2, r2, m1, g;
set < pair < lli, lli > > s;
set < pair < lli, lli > > :: iterator it;

int main()
{
    sc( "%I64d%I64d%I64d", &n, &k, &a );
    sc( "%I64d", &m );
    s.insert( {0, 0} );
    s.insert( {n + 1, n + 1} );
    s.insert( {1, n} );
    cl = n / (a + 1);
    if( cl * a + cl + a <= n )cl++;
    for( i = 1; i <= m; i++ ){
        sc( "%I64d", &x );
        it = s.lower_bound({x, -1});
        if( it->fi > x )it--;
        if( x < it->fi || x > it->se )continue;
        l1 = it->fi;
        r1 = x - 1;
        l2 = x + 1;
        r2 = it->se;
        g = (it->se - it->fi + 1) / (a + 1);
        if( g * a + a + g <= it->se - it->fi + 1 )g++;
        cl -= g;
        s.erase(it);
        if( r1 - l1 + 1 >= a ){
            s.insert({l1, r1});
            g = (r1 - l1 + 1) / (a + 1);
            if( g * a + a + g <= r1 - l1 + 1 )cl++;
            cl += g;
        }
        if( r2 - l2 + 1 >= a ){
            s.insert({l2, r2});
            g = (r2 - l2 + 1) / (a + 1);
            if( g * a + a + g <= r2 - l2 + 1 )cl++;
            cl += g;
        }
        if( cl < k ){
            pr( "%I64d", i );
            return 0;
        }
    }
    pr("-1");
}