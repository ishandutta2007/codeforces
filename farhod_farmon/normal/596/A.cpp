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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, x[5], y[5], i, g = 1;
pair < int, int > p[6];

int main()
{
    x[0] = y[0] = 1e8;
    cin >> a;
    for( i = 1; i <= a; i++ )cin >> p[i].fi >> p[i].se;
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ){
        if( x[g - 1] != p[i].fi && y[g - 1] != p[i].se ){
            x[g] = p[i].fi, y[g] = p[i].se;
            g++;
        }
    }
    if( g < 3 ){
        g = 1;
        for( i = 2; i <= a; i++ ){
            if( x[g - 1] != p[i].fi && y[g - 1] != p[i].se ){
                x[g] = p[i].fi, y[g] = p[i].se;
                g++;
            }
        }
    }
    if( g < 3 )cout << -1;
    else cout << abs(x[1] - x[2]) * abs(y[1] - y[2]);
}