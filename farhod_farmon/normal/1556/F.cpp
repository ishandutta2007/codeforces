#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 14;
const int mod = 1e9 + 7;

using namespace std;

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

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int n;
int a[N];
int w[N][N];
int W[N][1 << N];
int cyc[1 << N];
unordered_map<int, int> d[1 << N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i];

                for(int j = 0; j < i; j++){
                        w[i][j] = 1ll * a[i] * pw(a[i] + a[j], mod - 2) % mod;
                        w[j][i] = 1ll * a[j] * pw(a[i] + a[j], mod - 2) % mod;
                }
        }
        int G = (1 << n);
        for(int i = 0; i < n; i++){
                for(int j = 0; j < G; j++){
                        W[i][j] = 1;
                        for(int h = 0; h < n; h++){
                                if(j & (1 << h)){
                                        W[i][j] = 1ll * W[i][j] * w[i][h] % mod;
                                }
                        }
                }
        }

        for(int i = 0; i < G; i++){
                for(int j = (i - 1) & i; j > 0; j = (j - 1) & i){
                        int cur = 1;
                        for(int h = 0; h < n; h++){
                                if(j & (1 << h)){
                                        cur = 1ll * cur * W[h][i ^ j] % mod;
                                }
                        }
                        add(cyc[i], 1ll * cyc[j] * cur % mod);
                }
                cyc[i] = 1 - cyc[i];
                if(cyc[i] < 0){
                        cyc[i] += mod;
                }
        }

        auto f = [&](int i, int j) -> int
        {
                int res = cyc[i];
                for(int h = 0; h < n; h++){
                        if(i & (1 << h)){
                                res = 1ll * res * W[h][j] % mod;
                        }
                }
                return res;
        };

        for(int i = 1; i < G; i++){
                add(d[i][i], cyc[i]);

                int rem = (G - 1) ^ i, all = 0;
                for(int j = i; j > 0; j = (j - 1) & i){
                        add(all, d[i][j]);
                }
                for(int h = rem; h > 0; h = (h - 1) & rem){
                        add(d[i | h][h], 1ll * all * f(h, i) % mod);
                }
        }
        int res = 0;
        for(int i = 0; i < G; i++){
                add(res, 1ll * __builtin_popcount(i) * d[G - 1][i] % mod);
        }

        cout << res << "\n";
}