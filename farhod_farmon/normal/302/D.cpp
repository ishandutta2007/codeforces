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

int n, x[101], y[101], d, a[101];

int l( int i, int j )
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

bool f( int kol )
{
    int i, j, h;
    int dp[101];
    for( i = 2; i <= n; i++ )dp[i] = 0;
    dp[1] = kol;
    for( h = 1; h <= n; h++ ){
        for( i = 1; i <= n; i++ ){
            if( dp[i] == 0 )continue;
            for( j = 1; j <= n; j++ ){
                if( i == j )
                    continue;
                if( d * l(i, j) > dp[i] )
                    continue;
                dp[j] = max(dp[j], a[j] + dp[i] - d * l(i, j));
            }
        }
    }
    return dp[n] > 0;
}

int main()
{
    int l = 0, r = 1e9, i, j, h;
    cin >> n >> d;
    for( i = 2; i <= n - 1; i++ )
        cin >> a[i];
    for( i = 1; i <= n; i++ )
        cin >> x[i] >> y[i];
    while( l < r ){
        int m = (l + r) / 2;
        if( !f(m) )l = m + 1;
        else r = m;
    }
    cout << l - 1 << endl;
}