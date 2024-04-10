#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
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
int a[N];
int c[N];
long long d[N];
long long fac[N];

long long C(long long n, long long k)
{
        if(k < 0 || k > n){
                return 0;
        }
        return fac[n] * pw(fac[n - k] * fac[k] % mod, mod - 2) % mod;
}

void add(long long &x, long long y)
{
        x += y;
        x %= mod;
        if(x < 0){
                x += mod;
        }
}

int get(int k)
{
        for(int i = 0; i < N; i++){
                d[i] = 0;
        }

        for(int i = N - 1; i >= 1; i--){
                d[i] = C(c[i], k);
                for(int j = i + i; j < N; j += i){
                        add(d[i], - d[j]);
                }
        }

        return d[1];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long gcd = 0;
        for(int i = 1; i <= n; i++){
                long long x;
                cin >> x;
                a[x]++;
                if(i == 1){
                        gcd = x;
                } else{
                        gcd = __gcd(gcd, x);
                }
        }

        if(gcd > 1){
                cout << -1 << "\n";
                return 0;
        }

        fac[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = fac[i - 1] * i % mod;
                for(int j = i; j < N; j += i){
                        c[i] += a[j];
                }
        }

        int res = 1;
        while(get(res) == 0){
                res++;
        }

        cout << res << "\n";
}