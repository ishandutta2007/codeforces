#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

const int Q = 200200;
const int mod = 1e9 + 7;

int pw(int x, long long n)
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

void add(int &x, int y)
{
        x += y;
        if(x >= mod) x -= mod;
}

void sub(int &x, int y)
{
        x -= y;
        if(x < 0) x += mod;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        make();

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                int res = 0;
                int A = 1;
                int c0 = 0;
                for(int i = 0; i < n; i += 2){
                        add(c0, C(n, i));
                }
                for(int i = 0; i < k; i++){
                        int NA = 0;
                        if(n % 2 == 0){
                                add(res, 1ll * A * pw(2, 1ll * n * (k - i - 1)) % mod);
                        } else{
                                NA = A;
                        }
                        A = 1ll * A * c0 % mod;
                        add(A, NA);
                }
                add(res, A);
                cout << res << "\n";
        }
}