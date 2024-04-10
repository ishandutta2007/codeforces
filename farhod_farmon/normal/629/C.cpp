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

const int mod = 1e9 + 7;

using namespace std;

lli n, i, j, ans, b, c, m, d[2002][2002];

lli M( char c )
{
    if( c == '(' )return 1;
    return -1;
}

string s;

int main()
{
    cin >> n >> m >> s;
    for( i = 0; i < m; i++ ){
        b += M(s[i]);
        c = min(c, b);
    }
    d[0][0] = 1;
    for( i = 1; i <= n - m; i++ ){
        for( j = 0; j <= i; j++ ){
            if( j )d[i][j] = d[i - 1][j - 1];
            d[i][j] += d[i - 1][j + 1];
            d[i][j] %= mod;
        }
    }
    for( i = 0; i <= n - m; i++ ){
        for( j = 0; j <= i; j++ ){
            if( j + c < 0 )continue;
            if( j + b <= n - m )ans = (ans + d[i][j] * d[n - m - i][j + b]) % mod;
        }
    }
    cout << ans << endl;
}