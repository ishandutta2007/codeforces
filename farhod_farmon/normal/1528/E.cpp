#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1000011;
const int mod = 998244353;

int n;
int d[N];
int f[N];
int s[N];
int p2, p6;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
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

int g2(int x)
{
        return 1ll * x * (x + 1) % mod * p2 % mod;
}

int g3(int x)
{
        return 1ll * x * (x + 1) % mod * (x + 2) % mod * p6 % mod;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        p2 = pw(2, mod - 2);
        p6 = pw(6, mod - 2);

        cin >> n;
        d[0] = s[0] = 1;
        for(int i = 1; i <= n; i++){
                d[i] = d[i - 1];
                add(d[i], g2(d[i - 1]));
                if(i > 1){
                        add(d[i], 1ll * d[i - 1] * s[i - 2] % mod);
                }

                s[i] = s[i - 1];
                add(s[i], d[i]);
        }

        int res = (2ll * d[n] - 1) % mod;

        add(res, 2ll * g3(d[n - 1]) % mod);
        if(n > 1){
                add(res, g2(d[n - 1]) * 2ll * s[n - 2] % mod);
                add(res, 2ll * d[n - 1] * g2(s[n - 2]) % mod);
        }

        for(int i = 1; i < n; i++){
                //add(res, 1ll * (d[i - 1] - 1) * (d[n - i - 1] - 1) % mod);

                add(res, 1ll * (d[i] - d[i - 1]) * (d[n - i - 1] - 1) % mod);
                //add(res, 1ll * (d[i - 1] - 1) * (d[n - i] - d[n - i - 1]) % mod);
        }

        cout << res << "\n";
}