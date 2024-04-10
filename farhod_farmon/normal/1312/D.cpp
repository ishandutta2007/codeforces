#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 400400;
const long long mod = 998244353;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n > 0){
                if(n & 1) res = res * x % mod;
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

long long fac[N];
long long inv[N];

long long C(int n, int k)
{
        if(k < 0 || n < k || n < 0) return 0;
        return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        fac[0] = 1;
        for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
        inv[N - 1] = pw(fac[N - 1], mod - 2);
        for(int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

        int n, m;
        cin >> n >> m;
        long long res = 0;
        if(n == 2){
                cout << 0 << "\n";
                return 0;
        }
        long long P = 1;
        for(int i = 1; i <= n - 3; i++) P = P * 2 % mod;
        for(int i = 1; i <= m; i++){
                res += C(i - 2, n - 3) * (i - 1) % mod;
                if(res >= mod) res -= mod;
        }
        cout << res * P % mod << "\n";
}