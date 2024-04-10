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
#define fin freopen( "sochi.in", "r", stdin );
#define fout freopen( "sochi.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, m, d[444];
vector < int > v[3][444];
bool used[444][444];
queue < int > q;

void bfs( int g )
{
    int x, i;
    d[1] = 0;
    q.push(1);
    while( !q.empty() ){
        x = q.front();
        q.pop();
        for( i = 0; i < v[g][x].size(); i++ ){
            if( d[x] + 1 < d[v[g][x][i]] ){
                q.push(v[g][x][i]);
                d[v[g][x][i]] = d[x] + 1;
            }
        }
    }
}

int main()
{
    int i, j, h, x, y;    
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> x >> y;
        v[1][x].pb(y);
        v[1][y].pb(x);
        used[x][y] = used[y][x] = true;
    }
    for( i = 1; i <= n; i++ ){
        d[i] = 1e9;
        for( j = i + 1; j <= n; j++ ){
            if( !used[i][j] ){
                v[2][i].pb(j);
                v[2][j].pb(i);
            }
        }
    }
    if( used[1][n] )bfs(2);
    else bfs(1);
    if( d[n] == 1e9 )cout << -1 << endl;
    else cout << d[n] << endl;
}