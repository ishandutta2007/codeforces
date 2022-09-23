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

int n, m, ans, r, c, x, y;
bool used[11][11];

bool istrue( int a, int b, int c, int d )
{
    int i, j, cnt = 0;
    for( i = a; i <= c; i++ ){
        for( j = b; j <= d; j++ ){
            cnt += used[i][j];
        }
    }
    return cnt >= m;
}

int main()
{
    int i, j, h, k;
    cin >> r >> c >> n >> m;
    for( i = 1; i <= n; i++ ){
        cin >> x >> y;
        used[x][y] = true;
    }
    for( i = 1; i <= r; i++ ){
        for( j = 1; j <= c; j++ ){
            for( h = i; h <= r; h++ ){
                for( k = j; k <= c; k++ ){
                    if( istrue(i, j, h, k) )ans++;
                }
            }
        }
    }
    cout << ans << endl;
}