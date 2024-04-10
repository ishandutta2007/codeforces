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
#include <iomanip>

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

int n, k, i, j, d[555][555], g;

int main()
{
    lli ans = 0;
    cin >> n >> k;
    g = n * n;
    for( i = n; i >= 1; i-- ){
        for( j = n; j >= k; j-- ){
            d[i][j] = g;
            g--;
        }
    }
    g = 1;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j < k; j++ ){
            d[i][j] = g;
            g++;
        }
    }
    for( i = 1; i <= n; i++ )ans += d[i][k];
    cout << ans << endl;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ )cout << d[i][j] << " ";
        cout << endl;
    }
}