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

const int N = 200002;

using namespace std;

bool used[555][555];
vector < int > v;
int x, y, i, j, h, n, m, ans[555];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> x >> y;
        used[x][y] = used[y][x] = true;
    }

    for( i = 1; i <= n; i++ ){
        int cnt = 0;
        for( j = 1; j <= n; j++ ){
            if( used[i][j] )cnt++;
        }
        if( cnt == n - 1 )ans[i] = 2;
    }
    int g = 1;
    while( ans[g] )g++;
    ans[g] = 1;
    for( i = 1; i <= n; i++ ){
        if( ans[i] )continue;
        if( used[i][g] )ans[i] = 1;
        else ans[i] = 3;
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            if( i == j )continue;
            if( (abs(ans[i] - ans[j]) <= 1 && !used[i][j]) || (abs(ans[i] - ans[j]) == 2 && used[i][j]) ){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for( i = 1; i <= n; i++ )cout << char('a' + ans[i] - 1);
}