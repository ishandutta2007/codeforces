#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n){
                if(n & 1){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

int n;
int k;
char c[N];
long long p[N];
long long s[N];
long long fac[N];

long long C(int n, int k)
{
        if(k > n || k < 0){
                return 0;
        }
        return fac[n] * pw(fac[n - k] * fac[k] % mod, mod - 2) % mod;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }

        fac[0] = p[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = fac[i - 1] * i % mod;
                p[i] = p[i - 1] * 10 % mod;
        }

        for(int i = 0; i + 1 < N; i++){
                s[i] += C(n - i - 2, k - 1) * p[i] % mod;
                s[i] %= mod;
                s[i + 1] = s[i];
        }

        long long res = 0;
        for(int i = 1; i <= n; i++){
                if(k > 0 && i < n){
                        res += s[n - i - 1] * (c[i] - '0') % mod;
                        res %= mod;
                }

                res += C(i - 1, k) * (c[i] - '0') % mod * p[n - i] % mod;
                res %= mod;
        }

        cout << res << "\n";
}