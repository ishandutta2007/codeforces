#include <bits/stdc++.h>
#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "odd.in", "r", stdin );
#define fout freopen( "odd.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli ans, n, m, x, d[11], i, j;

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        d[x]++;
    }
    for( i = 1; i <= m; i++ ){
        for( j = i + 1; j <= m; j++ )ans += d[i] * d[j];
    }
    cout << ans << endl;
}