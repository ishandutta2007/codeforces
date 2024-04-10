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

using namespace std;

int dp[1001], i, j, h, k, a, b, c, d, c0, d0, ans, n, m;
bool used[1001];

int main()
{
    used[0] = true;
    cin >> m >> n >> c0 >> d0;
    for( i = 1; i <= n; i++ ){
        cin >> a >> b >> c >> d;
        for( h = 1; h <= a / b; h++ ){
            for( j = m; j >= 1; j-- ){
                if( j < c || !used[j - c] )continue;
                dp[j] = max(dp[j], dp[j - c] + d);
                used[j] = true;
            }
        }
    }
    for( i = 0; i <= m; i++ )ans = max(ans, dp[i] + ((m - i) / c0) * d0);
    cout << ans << endl;
}