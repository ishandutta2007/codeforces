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

lli d[36][36], i, j, h, n, k, ans, l;

int main()
{
    cin >> n >> k;
    d[0][0] = 1;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            for( h = 1; h <= i; h++ ){
                for( l = 0; l < j; l++ )d[i][j] += d[h - 1][j - 1] * d[i - h][l];
                for( l = 0; l < j - 1; l++ )d[i][j] += d[h - 1][l] * d[i - h][j - 1];
            }
        }
    }
    for( i = k; i <= n; i++ )ans += d[n][i];
    cout << ans << endl;
}