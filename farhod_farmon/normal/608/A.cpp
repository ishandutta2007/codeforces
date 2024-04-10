#include <bits/stdc++.h>

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

int n, i, j, m , x, y, ans, d[1001];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        cin >> x >> y;
        d[x] = max(d[x], y);
    }
    ans = d[m];
    for( i = m - 1; i >= 0; i-- )ans = max(ans + 1, d[i]);
    cout << ans << endl;
}