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

using namespace std;

int n1, n2, i, j, h, k1, k2, d[111][111][2], mod = 1e8;

int main()
{
    cin >> n1 >> n2 >> k1 >> k2;
    d[0][0][0] = d[0][0][1] = 1;
    for( i = 0; i <= n1; i++ ){
        for( j = 0; j <= n2; j++ ){
            for( h = 1; h <= k1; h++ )d[i + h][j][0] = (d[i + h][j][0] + d[i][j][1]) % mod;
            for( h = 1; h <= k2; h++ )d[i][j + h][1] = (d[i][j + h][1] + d[i][j][0]) % mod;
        }
    }
    cout << (d[n1][n2][0] + d[n1][n2][1]) % mod << endl;
}