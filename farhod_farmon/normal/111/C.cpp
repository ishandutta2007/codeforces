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

lli n, m, d[44][1 << 7][1 << 7], ans = 1e9;

bool istrue( lli x, lli y, lli z )
{
    lli i, cnt = 0;
    for( i = 0; i < n; i++ ){
        if( (1 << i) & x || (1 << i) & y || (1 << i) & z )cnt++;
        else if( i > 0 && (1 << i - 1) & x )cnt++;
        else if( i < n - 1 && (1 << i + 1) & x )cnt++;
    }
    return cnt == n;
}

int main()
{
    lli i, j, h, k;
    cin >> n >> m;
    if( n > m )swap(n, m);
    for( i = 0; i < (1 << n); i++ ){
        d[0][0][i] = __builtin_popcount(i);
        for( j = 1; j < (1 << n); j++ )d[0][j][i] = 1e9;
    }
    for( i = 1; i <= m; i++ ){
        for( j = 0; j < (1 << n); j++ ){
            for( h = 0; h < (1 << n); h++ ){
                d[i][j][h] = 1e9;
                for( k = 0; k < (1 << n); k++ ){
                    if( istrue(j, h, k) )d[i][j][h] = min(d[i][j][h], d[i - 1][k][j] + __builtin_popcount(h));
                }
            }
        }
    }
    for( i = 0; i < (1 << n); i++ )ans = min(ans, d[m][i][0]);
    cout << n * m - ans << endl;
}