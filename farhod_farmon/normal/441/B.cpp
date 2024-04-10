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
int a, v, i, j, h, k, ans;
pair < int, int > an[3333], p[3333];

int main()
{
    cin >> a >> v;
    for( i = 1; i <= a; i++ ) cin >> p[i].fi >> p[i].se;
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ) an[p[i].fi].se += p[i].se;
    for( i = 1; i <= 3001; i++ ){
        k = v;
        ans += min(k, an[i].fi);
        k -= min(k, an[i].fi);
        ans += min(k, an[i].se);
        an[i + 1].fi = an[i].se - min(k, an[i].se);
        k -= min(k, an[i].se);
    }
    cout << ans;
}