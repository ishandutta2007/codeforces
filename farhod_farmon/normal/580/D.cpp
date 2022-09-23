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
lli d[300000][30], i, j, h, c[20][20], x, y, z, b[20], n, m, k, g, ans;

int main()
{
    cin >> n >> m >> k;
    for( i = 0; i < n; i++ ){
        cin >> b[i];
        d[1 << i][i] = b[i];
    }
    for( i = 1; i <= k; i++ ){
        cin >> x >> y >> z;
        c[x - 1][y - 1] = z;
    }
    for( i = 1; i < (1 << n); i++ ){
        for( j = 0; j < n; j++ ){
            if( !(i & (1 << j)) )continue;
            for( h = 0; h < n; h++ ){
                if( i & (1 << h) )continue;
                d[i | (1 << h)][h] = max(d[i | (1 << h)][h], d[i][j] + b[h] + c[j][h]);
            }
        }
    }
    for( i = 1; i < (1 << n); i++ ){
        g = 0;
        for( j = 0; j < n; j++ ){
            if( i & (1 << j) )g++;
        }
        if( g == m ){
            for( j = 0; j < n; j++ )ans = max(ans, d[i][j]);
        }
    }
    cout << ans << endl;
}