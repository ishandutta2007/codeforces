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

long double n, m, ans, d[100001];

long double pw( long double a, int b )
{
    if( !b )
        return 1;
    if( b % 2 )
        return pw(a, b - 1) * a;
    long double g = pw(a, b / 2);
    return g * g;
}

int main()
{
    cin >> m >> n;
    for( int i = 1; i <= m; i++ )
        d[i] = pow(1.0 * i / m, n);
    for( int i = 1; i <= m; i++ )
        ans += 1.0 * i * (d[i] - d[i - 1]);
    cout << ans << endl;
}