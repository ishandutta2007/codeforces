#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

const int Q = 200200;

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


int n;
string s;

void solve()
{
    cin >> n >> s;
    int rem = n, k = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            continue;
        }
        int cnt = 0;
        while(i < n && s[i] == '1'){
            cnt += 1;
            i += 1;
        }
        rem -= cnt;
        k += cnt / 2;
    }

    cout << C(rem + k, rem) << "\n";
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
        solve();
    }
}