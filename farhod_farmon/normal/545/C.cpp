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
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, x[100001], h[100001], i, j, dp[100001][3];
int main()
{
    sc("%d", &a);
    for( i = 1; i <= a; i++ ){
        sc("%d%d", &x[i], &h[i]);
    }
    dp[1][1] = 1;
    x[a + 1] = 9999999999999999ll;
    x[0] = -99999999999999999ll;
    if( x[1] + h[1] < x[2] )dp[1][2] = 1;
    for( i = 2; i <= a; i++ ){
        if( x[i] - h[i] > x[i - 1] )dp[i][1] = dp[i - 1][1] + 1;
        else dp[i][1] = dp[i - 1][1];
        if( x[i] - h[i] > x[i - 1] + h[i - 1] )dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
        else dp[i][1] = max(dp[i][1], dp[i - 1][2]);
        if( x[i] + h[i] < x[i + 1] )dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
        else dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }
    cout << max(dp[a][1], dp[a][2]);
}