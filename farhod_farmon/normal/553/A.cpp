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

lli n, d[1001][1001], i, j, x, sum, ans = 1, mod = 1e9 + 7;

int main()
{
    cin >> n;
    d[0][0] = 1;
    for( i = 1; i <= 1000; i++ ){
        d[i][0] = 1;
        for( j = 1; j <= i; j++ )
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % mod;
    }
    for( i = 1; i <= n; i++ ){
        cin >> x;
        ans = (ans * d[sum + x - 1][x - 1]) % mod;
        sum += x;
    }
    cout << ans << endl;
}