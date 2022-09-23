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

using namespace std;

int x = 1, ans[200002], a[200002], i, n, m;
pair < int, int > b[200002];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ )cin >> a[i];
    for( i = 1; i <= m; i++ ){
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort( a + 1, a + n + 1 );
    sort( b + 1, b + m + 1 );
    for( i = 1; i <= m; i++ ){
        while( x <= n && a[x] <= b[i].fi )x++;
        ans[b[i].se] = x - 1;
    }
    for( i = 1; i <= m; i++ )cout << ans[i] << " ";
}