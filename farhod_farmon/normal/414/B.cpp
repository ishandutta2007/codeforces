#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2020;

using namespace std;

int d[N][N], mod = 1e9 + 7, n, k;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        d[1][i] = 1;
    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= n; j++){
            for(int h = 1; h * h <= j; h++){
                if(j % h)
                    continue;
                d[i][j] = (d[i][j] + d[i - 1][h]) % mod;
                if(j / h != h)
                    d[i][j] = (d[i][j] + d[i - 1][j / h]) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans + d[k][i]) % mod;
    cout << ans << endl;
}