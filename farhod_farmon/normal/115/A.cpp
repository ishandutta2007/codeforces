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
int a, i, d[10001], ans, b[10001];
vector < int > v[10001];

dfs( int x, int g )
{
    ans = max(ans, g);
    for( int j = 0; j < v[x].size(); j++ )dfs(v[x][j], g + 1);
}

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b[i];
        if( b[i] != -1 )v[b[i]].pb(i);
    }
    for( i = 1; i <= a; i++ ){
        if( b[i] == -1 )dfs( i, 1 );
    }
    cout << ans << endl;
}