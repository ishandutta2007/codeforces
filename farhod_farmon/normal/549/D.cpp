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
int a, b, i, j, cnt, d[111][111], h, k, x;
char c[111][111];

int main()
{
    cin >> a >> b;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            cin >> c[i][j];
        }
    }
    for( i = a; i >= 1; i-- ){
        for( j = b; j >= 1; j-- ){
            if( c[i][j] == 'B' && d[i][j] != 1 ){
                x = 1 - d[i][j];
                for( h = 1; h <= i; h++ ){
                    for( k = 1; k <= j; k++ ){
                        d[h][k] += x;
                    }
                }
                cnt++;
            }
            if( c[i][j] == 'W' && d[i][j] != -1 ){
                x = -1 - d[i][j];
                for( h = 1; h <= i; h++ ){
                    for( k = 1; k <= j; k++ ){
                        d[h][k] += x;
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt;
}