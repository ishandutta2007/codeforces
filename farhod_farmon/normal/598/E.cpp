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
#define fin freopen( "sochi.in", "r", stdin );
#define fout freopen( "sochi.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int t, d[33][33][55];

int f( int n, int m, int k )
{
    if( d[n][m][k] )return d[n][m][k];
    if( !k || n * m == k )return 0;
    int i, j, cnt = 1e9;
    for( i = 1; i <= n - i; i++ ){
        for( j = 0; j <= k; j++ ){
            cnt = min(cnt, f(i, m, j) + f(n - i, m, k - j) + m * m);
        }
    }
    for( i = 1; i <= m - i; i++ ){
        for( j = 0; j <= k; j++ ){
            cnt = min(cnt, f(n, i, j) + f(n, m - i, k - j) + n * n);
        }
    }
    d[n][m][k] = cnt;
    return cnt;
}

int main()
{
    int n, m, k, i;
    cin >> t;    
    for( i = 1; i <= t; i++ ){
        cin >> n >> m >> k;
        cout << f(n, m, k) << endl;
    }
}