#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 2002;
const ll mod = 998244353;

using namespace std;

int n;
int m;
int k;
int d[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        d[1][0] = m;
        for(int i = 2; i <= n; i++){
                for(int j = 0; j <= k; j++){
                        d[i][j] += d[i - 1][j];
                        d[i][j + 1] += 1ll * d[i - 1][j] * (m - 1) % mod;
                        if(d[i][j] >= mod){
                                d[i][j] -= mod;
                        }
                        if(d[i][j + 1] >= mod){
                                d[i][j + 1] -= mod;
                        }
                }
        }
        cout << d[n][k] << "\n";
}