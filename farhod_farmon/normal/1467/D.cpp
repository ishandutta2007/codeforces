#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k, q;
int a[N];
int c[N];
int nc[N];
int res[N];
int f[N][N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[i] = 1;
                f[k][i] = 1;
        }
        for(int i = k - 1; i >= 0; i--){
                for(int j = 1; j <= n; j++){
                        f[i][j] = f[i + 1][j + 1];
                        add(f[i][j], f[i + 1][j - 1]);
                }
        }
        for(int i = 1; i <= n; i++){
                res[i] = f[0][i];
        }
        for(int i = 1; i <= k; i++){
                for(int j = 1; j <= n; j++){
                        add(nc[j - 1], c[j]);
                        add(nc[j + 1], c[j]);
                }
                for(int j = 1; j <= n; j++){
                        c[j] = nc[j];
                        nc[j] = 0;

                        add(res[j], c[j] * 1ll * f[i][j] % mod);
                }
        }
        int S = 0;
        for(int i = 1; i <= n; i++){
                add(S, 1ll * a[i] * res[i] % mod);
        }

        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;

                add(S, 1ll * (y - a[x]) * res[x] % mod);
                a[x] = y;

                cout << S << "\n";
        }
}