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
map < pair < lli, lli >, lli > pm, mm;
lli x, i, a, k;
lli ans;

int main()
{
    sc( "%I64d%I64d", &a, &k );
    for( i = 1; i <= a; i++ ){
        sc( "%I64d", &x );
        if( x > 0 ){
            if( x % (k * k) == 0 ) ans += pm[{x / k, 2}];
            if( x % k == 0 )pm[{x, 2}] += pm[{x / k, 1}];
            pm[{x, 1}]++;
        }
        else if( x < 0 ){ x = - x;
            if( x % (k * k) == 0 ) ans += mm[{x / k, 2}];
            if( x % k == 0 )mm[{x, 2}] += mm[{x / k, 1}];
            mm[{x, 1}]++;
        }
        else{
            ans += (pm[{x, 1}] * (pm[{x, 1}] - 1)) / 2;
            pm[{x, 1}]++;
        }
    }
    pr( "%I64d", ans );
}