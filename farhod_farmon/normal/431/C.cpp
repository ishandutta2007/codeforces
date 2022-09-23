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

int n, k, d, dp[101][101], mod = 1e9 + 7, i, j, h;

int main()
{
    cin >> n >> k >> d;
    for( i = 1; i <= k; i++ )dp[0][i] = 1;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= k; j++ ){
            for( h = 1; h <= min(i, j); h++ ){
                dp[i][j] = (dp[i][j] + dp[i - h][j]) % mod;
            }
        }
    }
    cout << (dp[n][k] + mod - dp[n][d - 1]) % mod << endl;
}