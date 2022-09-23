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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b;
char c1[30], c2[30];
bool used[30][30];

void dfs( int x, int y )
{
    if( x < 1 || y < 1 || x > a || y > b || used[x][y] )return;
    used[x][y] = true;
    if( c1[x] == '>' )dfs(x, y + 1);
    else dfs(x, y - 1);
    if( c2[y] == 'v' )dfs(x + 1, y);
    else dfs(x - 1, y);
}

bool t()
{
    int i, j;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            if( !used[i][j] )return false;
            used[i][j] = false;
        }
    }
    return true;
}

int main()
{
    int i, j;
    cin >> a >> b;
    for( i = 1; i <= a; i++ )cin >> c1[i];
    for( i = 1; i <= b; i++ )cin >> c2[i];
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            dfs(i, j);
            if( !t() ){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}