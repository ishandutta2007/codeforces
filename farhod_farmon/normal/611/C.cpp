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

int n, m, q, i, j, h, x, y, cnt, d1[555][555], d2[555][555];
char c[555][555];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> c[i][j];
            d1[i][j] = d1[i][j - 1];
            d2[i][j] = d2[i - 1][j];
            if( j > 1 && c[i][j] == '.' && c[i][j - 1] == '.' )d1[i][j]++;
            if( i > 1 && c[i][j] == '.' && c[i - 1][j] == '.' )d2[i][j]++;
        }
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            d1[i][j] += d1[i - 1][j];
            d2[i][j] += d2[i][j - 1];
        }
    }
    cin >> q;
    for( i = 1; i <= q; i++ ){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cnt = d1[x2][y2] - d1[x2][y1] - d1[x1 - 1][y2] + d1[x1 - 1][y1];
        cnt += d2[x2][y2] - d2[x2][y1 - 1] - d2[x1][y2] + d2[x1][y1 - 1];
        cout << cnt << endl;
    }
}