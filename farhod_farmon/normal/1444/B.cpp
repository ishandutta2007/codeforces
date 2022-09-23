#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 222;
const int mod = 998244353;

using namespace std;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

const int Q = 500500;
int pw(int x, int n)
{
        int res = 1;
        for(; n > 0; n >>= 1){
                if(n & 1){
                        res = 1ll * res * x % mod;
                }
                x = 1ll * x * x % mod;
        }
        return res;
}

int fac[Q], inv[Q];

void make()
{
        fac[0] = 1;
        for(int i = 1; i < Q; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
        inv[Q - 1] = pw(fac[Q - 1], mod - 2);
        for(int i = Q - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int C(int n, int k)
{
        if(k < 0 || k > n) return 0;
        return 1ll * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        make();

        int n;
        cin >> n;
        vector < int > a(2 * n);
        for(int i = 0; i < 2 * n; i++){
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
                res -= a[i];
        }
        for(int i = n; i < 2 * n; i++){
                res += a[i];
        }
        res %= mod;

        cout << res * 1ll * C(2 * n, n) % mod << "\n";
}