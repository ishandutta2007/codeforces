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
#define fin freopen( "blocks.in", "r", stdin );
#define fout freopen( "blocks.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

lli n, m, i, j, h, d[100001], ans, x, y;
vector < lli > v[100001];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for( i = 1; i <= n; i++ ){
        for( j = 0; j < v[i].size(); j++ ){
            d[v[i][j]] = max(d[v[i][j]], d[i] + 1);
        }
        ans = max(ans, (d[i] + 1) * v[i].size());
    }
    cout << ans << endl;
}