#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

double ans;
int n, i, j, h, m, x, y, z, a[505];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ )
        cin >> a[i];
    for( i = 1; i <= m; i++ ){
        cin >> x >> y >> z;
        if( z )
            ans = max(ans, 1.0 * (a[x] + a[y]) / z);
    }
    cout << fixed << setprecision(9) << ans << endl;
}