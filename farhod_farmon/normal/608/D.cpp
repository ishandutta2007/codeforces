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

int n, d[505][505], i, j, h, c[505];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> c[i];
        d[i][i] = 1;
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n - i; j++ ){
            d[j][j + i] = i + 1;
            for( h = j; h < j + i; h++ )d[j][j + i] = min(d[j][j + i], d[j][h] + d[h + 1][j + i]);
            if( c[j] == c[j + i] ){
                if( i == 1 )d[j][j + i] = 1;
                else d[j][j + i] = min(d[j][j + i], d[j + 1][j + i - 1]);
            }
        }
    }
    cout << d[1][n] << endl;
}