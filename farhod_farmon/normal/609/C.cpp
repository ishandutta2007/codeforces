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
lli n, x[100001], i, cnt, ans, g, sum;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x[i];
        cnt += x[i];
    }
    sort( x + 1, x + n + 1 );
    sum = cnt;
    cnt = cnt / n + 1;
    g = sum - (cnt - 1) * n;
    for( i = n; i >= 1; i--, g-- ){
        if( g == 0 )cnt--;
        ans += max(0ll, x[i] - cnt);
    }
    cout << ans << endl;
}