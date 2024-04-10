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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli n, m, b, mod, i, j, h, k, d[555][555], a[551], ans;

int main ()
{
    cin >> n >> m >> b >> mod;
    for( i = 1; i <= n; i++ )cin >> a[i];
    sort( a + 1, a + n + 1 );
    d[0][0] = 1;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            for( h = a[i]; h <= b; h++ ){
                d[j][h] = (d[j][h] + d[j - 1][h - a[i]]) % mod;
            }
        }
    }
    for( h = 0; h <= b; h++ )ans = (ans + d[m][h]) % mod;
    cout << ans;
}