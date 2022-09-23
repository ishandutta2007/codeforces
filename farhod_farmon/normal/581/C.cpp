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
int a, k, i, j, h, ans;
pair < int, int > p[100001];

int main()
{
    sc( "%d%d", &a, &k );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &p[i].se );
        p[i].fi = 10 - p[i].se % 10;
    }
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ){
        if( p[i].se == 100 )continue;
        int g = min(p[i].fi, k);
        if( g == p[i].fi ){
            p[i].se += g;
            k -= g;
        }
    }
    for( i = 1; i <= a; i++ ){
        int g = min(k, 100 - p[i].se);
        p[i].se += g;
        k -= g;
        ans += (p[i].se / 10);
    }
    cout << ans;
}