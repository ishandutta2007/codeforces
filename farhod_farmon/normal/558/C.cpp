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
int a, b[200001], i, j, ans, mx = 100000, x, g, g1, d[200001], g2, l;

int main()
{
    ans = mx * 500;
    sc( "%d", &a );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &x );
        g = 0;
        while( x ){
            g1 = g2 = 0;
            while( x % 2 == 0 ) x /= 2, g2++;
            l = 1;
            while( l * x <= mx ){
                b[l * x] += g + abs(g1 - g2);
                d[l * x]++;
                l *= 2;
                g1++;
            }
            x /= 2;
            g += g2 + 1;
        }
    }
    for( i = 1; i <= mx; i++ )ans = d[i] == a ? min(ans, b[i]) : ans;
    pr( "%d", ans );
}