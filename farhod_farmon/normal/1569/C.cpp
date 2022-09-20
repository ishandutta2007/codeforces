#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

const int Q = 400200;
const int mod = 998244353;

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
                int n;
                cin >> n;
                vector<int> a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                int A = 0, B = 0;
                for(int x: a){
                        if(x == a[n - 1]){
                                A += 1;
                        } else if(x == a[n - 1] - 1){
                                B += 1;
                        }
                }
                if(A == n || A > 1){
                        cout << fac[n] << "\n";
                } else{
                        int res = 1ll * fac[n - A - B] * C(n, A + B) % mod;

                        int shit = fac[A + B];
                        sub(shit, 1ll * A * fac[A + B - 1] % mod);
                        res = 1ll * res * shit % mod;

                        cout << res << "\n";
                }
        }
}