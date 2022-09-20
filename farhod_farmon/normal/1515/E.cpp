#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 444;

using namespace std;

int n;
int mod;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int pw(int x, int n)
{
        int res = 1;
        while(n > 0){
                if(n & 1){
                        res = 1ll * res * x % mod;
                }
                n /= 2;
                x = 1ll * x * x % mod;
        }
        return res;
}

int d[N];
int f[N][N];
int fac[N];
int inv[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> mod;

        d[1] = fac[1] = inv[1] = 1;
        for(int i = 2; i < N; i++){
                d[i] = d[i - 1];
                add(d[i], d[i]);

                fac[i] = 1ll * fac[i - 1] * i % mod;
                inv[i] = pw(fac[i], mod - 2);
        }

        for(int i = 1; i <= n; i++){
                f[i][i] = d[i] * 1ll * inv[i] % mod;
                for(int h = 0; h <= n; h++){
                        for(int j = i - 1; j >= 1 && h + i - j <= n; j--){
                                add(f[i][h + i - j], f[j - 1][h] * 1ll * d[i - j] % mod * inv[i - j] % mod);
                        }
                }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                add(res, 1ll * f[n][i] * fac[i] % mod);
        }
        cout << res << "\n";
}