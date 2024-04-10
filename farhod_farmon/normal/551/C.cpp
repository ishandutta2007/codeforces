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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, c[100011], d[100011];

bool ch( lli x )
{
    lli i, j, h;
    for( i = 1; i <= a; i++ )d[i] = c[i];
    for( i = j = 1; i <= b && j <= a; i++ ){
        h = x - j;
        while( h > 0 && j <= a ){
            int p = min(h, d[j]);
            h -= p;
            d[j] -= p;
            while( !d[j] && j <= a && h > 0 ){
                j++;
                h--;
            }
        }
    }
    if( j >= a && !d[a] )return true;
    return false;
}

int main()
{
    lli i, j, h, m, l, r;
    sc( "%d%d", &a, &b );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &c[i] );
    }
    while( !c[a] )a--;
    l = 0;
    r = 1000000000000000000ll;
    while( l < r ){
        m = (l + r) / 2;
        if( !ch(m) )l = m + 1;
        else r = m;
    }
    cout << r;
}