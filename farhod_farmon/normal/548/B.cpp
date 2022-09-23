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
int main()
{
    int a, b, i, j, c[600][600], h, k, x, y, d[600], cnt, ans;
    cin >> a >> b >> k;
    for( i = 1; i <= a; i++ ){
        for( j = 1, cnt = 0; j <= b; j++ ){
            cin >> c[i][j];
            if( c[i][j] )cnt++;
            else cnt = 0;
            d[i] = max(d[i], cnt);
        }
    }
    for( i = 1; i <= k; i++ ){
        cin >> x >> y;
        cnt = ans = d[x] = 0;
        c[x][y] = 1 - c[x][y];
        for( j = 1; j <= b; j++ ){
            if( c[x][j] )cnt++;
            else cnt = 0;
            d[x] = max(d[x], cnt);
        }
        for( j = 1; j <= a; j++ )ans = max(ans, d[j]);
        cout << ans << endl;
    }
}