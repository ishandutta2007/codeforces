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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, d[1001][1001], f[1001], i;
vector < int > v[1001], dd[1001];

void dfs( int x, int g )
{
    if( f[x] == 2 ){
        d[i][x] = max(d[i][x], g);
        return;
    }
    for( int j = 0; j < v[x].size(); j++ )dfs( v[x][j], min(g, dd[x][j]) );
}

int main()
{
    int j, h;
    cin >> a >> b;
    for( i = 1; i <= b; i++ ){
        int x, y, d1;
        cin >> x >> y >> d1;
        f[x] += 1;
        f[y] += 2;
        v[x].pb(y);
        dd[x].pb(d1);
    }
    for( i = 1; i <= a; i++ ){
        for( int j = 1; j <= a; j++ ){
            d[i][j] = -1;
        }
    }
    for( i = 1; i <= a; i++ ){
        if( f[i] == 1 )dfs(i, 999999999);
    }
    int cnt = 0;
    for( i = 1; i <= a; i++ ){
        for( int j = 1; j <= a; j++ ){
            if( d[i][j] > 0 )cnt++;
        }
    }
    cout << cnt << endl;
    for( i = 1; i <= a; i++ ){
        for( int j = 1; j <= a; j++ ){
            if( d[i][j] > 0 )cout << i << " " << j << " " << d[i][j] << endl;
        }
    }
}