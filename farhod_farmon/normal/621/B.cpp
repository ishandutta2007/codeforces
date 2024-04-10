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

lli cnt, i, n, x, y, j, h, d[1001][1001], d1[1002][1002];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x >> y;
        d[x][y] = 1;
        d1[x][y] = 1;
    }
    for( i = 1; i <= 1000; i++ ){
        for( j = 1; j <= 1000; j++ ){
            d[i][j] += d[i - 1][j - 1];
        }
        for( j = 1000; j >= 1; j-- ){
            d1[i][j] += d1[i - 1][j + 1];
        }
    }
    for( i = 1; i <= 1000; i++ )cnt += (d[1000][i] * (d[1000][i] - 1)) / 2 + (d[i][1000] * (d[i][1000] - 1)) / 2 + (d1[1000][i] * (d1[1000][i] - 1)) / 2 + (d1[i][1] * (d1[i][1] - 1)) / 2;
    cout << cnt - (d[1000][1000] * (d[1000][1000] - 1)) / 2 - (d1[1000][1] * (d1[1000][1] - 1)) / 2 << endl;
}