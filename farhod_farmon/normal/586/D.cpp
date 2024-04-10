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
int t, a, k;
char c[11][111];
bool used[11][111];

void dfs( int x, int y, int g )
{
    if( y > a || used[x][y] || y + 2 * g <= a && c[x][y + 2 * g] != '.' && c[x][y + 2 * g] != 's' ){
        return;
    }
    used[x][y] = true;
    if( abs(x - 1) <= 1 && (y + 2 * g + 1 > a || (c[x][y + 2 * g + 1] == '.' && c[1][y + 2 * g + 1] == '.')) )dfs(1, y + 1, g + 1);
    if( abs(x - 2) <= 1 && (y + 2 * g + 1 > a || (c[x][y + 2 * g + 1] == '.' && c[2][y + 2 * g + 1] == '.')) )dfs(2, y + 1, g + 1);
    if( abs(x - 3) <= 1 && (y + 2 * g + 1 > a || (c[x][y + 2 * g + 1] == '.' && c[3][y + 2 * g + 1] == '.')) )dfs(3, y + 1, g + 1);
}

int main()
{
    int i, j, h;
    cin >> t;
    for( h = 1; h <= t; h++ ){
        cin >> a >> k;
        for( i = 1; i <= 3; i++ ){
            for( j = 1; j <= a; j++ ){
                cin >> c[i][j];
                used[i][j] = false;
            }
        }
        if( c[1][1] == 's' )dfs(1, 1, 0);
        if( c[2][1] == 's' )dfs(2, 1, 0);
        if( c[3][1] == 's' )dfs(3, 1, 0);
        bool b1 = false;
        for( i = 1; i <= 3; i++ ){
            if( used[i][a] )b1 = true;
        }
        if( b1 )cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}