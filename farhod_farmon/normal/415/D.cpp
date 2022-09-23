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
int n, k, i, j, h, mod = 1000000007, dp[2001][2001], ans;
vector < int > v[2001];

int main()
{
    cin >> n >> k;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j * j <= i; j++ ){
            if( i % j == 0 ){
                v[i].pb(j);
                if( j != i / j )v[i].pb(i / j);
            }
        }
    }
    //for( i = 1; i <= k; i++ )dp[i][1] = 1;
    for( i = 1; i <= n; i++ ){
        dp[i][1] = 1;
        for( j = 2; j <= k; j++ ){
            for( h = 0; h < v[i].size(); h++ ){
                //cout << i << " " << v[i][h] << endl;
                dp[i][j] = (dp[i][j] + dp[v[i][h]][j - 1]) % mod;
            }
        }
    }
    for( i = 1; i <= n; i++ )ans = (ans + dp[i][k]) % mod;
    cout << ans;
}