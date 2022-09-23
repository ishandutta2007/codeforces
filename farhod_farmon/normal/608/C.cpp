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

int l, r, x, y, i, j, h, d[100001], m, n, ans = 1e9;
pair < int, int > p[100001];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> p[i].fi >> p[i].se;
    sort( p + 1, p + n + 1 );
    for( i = 2; i <= n; i++ ){
        l = 1;
        r = i - 1;
        x = p[i].fi - p[i].se;
        while( l < r ){
            m = (l + r) / 2;
            if( x > p[m].fi )l = m + 1;
            else r = m;
        }
        if( p[l].fi >= x )l--;
        d[i] = d[l] + i - l - 1;
        ans = min(ans, d[i] + n - i);
    }
    cout << min(ans, n - 1) << endl;
}