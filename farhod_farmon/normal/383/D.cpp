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

const int L = 10000, N = 1001;

using namespace std;

lli mod = 1e9 + 7, i, j, ans, d[N][L + L + L], n, a[N];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> a[i];
        d[i][a[i] + L] = d[i][-a[i] + L] = 1;
        for( j = -L + a[i]; j <= L - a[i]; j++ ){
            d[i][j + L] = (d[i][j + L] + d[i - 1][j + L - a[i]] + d[i - 1][j + L + a[i]]) % mod;
        }
        ans = (ans + d[i][L]) % mod;
    }
    cout << ans << endl;
}