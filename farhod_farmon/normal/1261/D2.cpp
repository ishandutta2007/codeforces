#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

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

int n;
int a[N];
int p[N];
int fac[N];

int C(int n, int k)
{
        return 1ll * fac[n] * pw(1ll * fac[k] * fac[n - k] % mod, mod - 2) % mod;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        a[n + 1] = a[1];
        int shit = 0;
        for(int i = 1; i <= n; i++){
                shit += (a[i] != a[i + 1]);
        }
        int res = 0, inv = pw(2, mod - 2);
        p[0] = fac[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = 1ll * fac[i - 1] * i % mod;
        }
        for(int i = 1; i <= shit; i++){
                p[i] = 2 * p[i - 1];
                if(p[i] >= mod){
                        p[i] -= mod;
                }
                if(i % 2){
                        res += p[i - 1] * 1ll * pw(k - 2, shit - i) % mod * C(shit, i) % mod;
                } else{
                        int cur = p[i];
                        cur -= C(i, i / 2);
                        if(cur < 0){
                                cur += mod;
                        }
                        res += 1ll * cur * inv % mod * pw(k - 2, shit - i) % mod * C(shit, i) % mod;
                }
                if(res >= mod){
                        res -= mod;
                }
        }
        cout << res * 1ll * pw(k, n - shit) % mod << "\n";
}