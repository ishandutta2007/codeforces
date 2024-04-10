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

char c[1002][1002];
int n, m, g = 1, d[1000002], used[1002][1002], cnt;
bool us[1000002];

void dfs( int x, int y, int z )
{
    if( used[x][y] || x < 1 || y < 1 || x > n || y > m || c[x][y] == '*' )return;
    used[x][y] = z;
    cnt++;
    dfs( x + 1, y, z );
    dfs( x - 1, y, z );
    dfs( x, y + 1, z );
    dfs( x, y - 1, z );
}

int F( int x )
{
    if( us[x] )return 0;
    us[x] = true;
    return d[x];
}

void GG( int x )
{
    us[x] = false;
}

int main()
{
    int i, j;
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> c[i][j];
        }
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            if( c[i][j] == '.' && !used[i][j] ){
                cnt = 0;
                dfs(i, j, g);
                d[g++] = cnt;
            }
        }
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            if( c[i][j] == '.' )cout << '.';
            else{
                cnt = (F(used[i - 1][j]) + F(used[i + 1][j]) + F(used[i][j + 1]) + F(used[i][j - 1]) + 1) % 10;
                cout << cnt;
                GG(used[i + 1][j]);
                GG(used[i - 1][j]);
                GG(used[i][j + 1]);
                GG(used[i][j - 1]);
            }
        }
        cout << endl;
    }
}