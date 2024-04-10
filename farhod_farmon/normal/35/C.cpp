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

const int N = 50005;

using namespace std;

int used[2002][2002];
int i, j, h, n, m;
queue < pair < int, int > > q;

bool M( int x, int y )
{
    if( x < 0 || y < 0 || x > n || y > m )return false;
    if( used[x][y] )return false;
    return true;
}

int main()
{
    fin
    fout
    int x, y, k;
    cin >> n >> m >> k;
    for( i = 1; i <= k; i++ ){
        cin >> x >> y;
        q.push(mp(x, y));
        used[x][y] = 1;
    }
    while( !q.empty() ){
        x = q.front().fi; y = q.front().se;
        q.pop();
        if( M(x - 1, y) ){
            used[x - 1][y] = used[x][y] + 1;
            q.push(mp(x - 1, y));
        }
        if( M(x + 1, y) ){
            used[x + 1][y] = used[x][y] + 1;
            q.push(mp(x + 1, y));
        }
        if( M(x, y - 1) ){
            used[x][y - 1] = used[x][y] + 1;
            q.push(mp(x, y - 1));
        }
        if( M(x, y + 1) ){
            used[x][y + 1] = used[x][y] + 1;
            q.push(mp(x, y + 1));
        }
    }
    x = y = 1;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            if( used[i][j] > used[x][y] )x = i, y = j;
        }
    }
    cout << x << " " << y << endl;
}