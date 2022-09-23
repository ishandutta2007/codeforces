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

const int N = 100100;

using namespace std;

lli n, x1, y1, x2, y2, x[2002], y[2002], ans;

lli f( lli a, lli b, lli c, lli d )
{
    return (c - a) * (c - a) + (d - b) * (d - b);
}

lli solve( lli a )
{
    lli b = 0;
    for( int i = 1; i <= n; i++ )
        if( f(x1, y1, x[i], y[i]) > a )
            b = max(b, f(x2, y2, x[i], y[i]));
    return a + b;
}

int main()
{
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for( int i = 1; i <= n; i++ )
        cin >> x[i] >> y[i];
    ans = solve(0);
    for( int i = 1; i <= n; i++ )
        ans = min(ans, solve(f(x1, y1, x[i], y[i])));
    cout << ans << endl;
}