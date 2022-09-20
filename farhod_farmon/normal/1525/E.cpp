#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 50000;
const int mod = 998244353;

int n, m;
int c[N];
int a[20][N];

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

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;

        int all = 1;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                }
                all = 1ll * all * (i + 1) % mod;
        }

        int res = 1ll * all * m % mod;
        for(int i = 0; i < m; i++){
                for(int j = 0; j <= n; j++){
                        c[j] = 0;
                }
                for(int j = 0; j < n; j++){
                        c[n + 1 - a[j][i]] += 1;
                }
                int cur = 1;
                for(int j = 0; j < n; j++){
                        cur = 1ll * cur * (c[j] - j) % mod;
                        c[j + 1] += c[j];
                }

                add(res, mod - cur);
        }

        cout << 1ll * res * pw(all, mod - 2) % mod << "\n";
}