#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 998244353;

using namespace std;

long long pw(long long x, long long n)
{
        x %= mod;
        long long res = 1;
        while(n){
                if(n % 2){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

int n;
long long a[N];
long long d[N];
long long inv[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x] += 1;

                inv[i] = pw(i, mod - 2);
        }

        for(int i = 1; i <= n; i++){
                d[i] = inv[n] * a[i] % mod;
        }

        long long res = 0;
        for(int i = 1; i < n; i++){
                long long sum = 0;
                for(int j = 1; j <= n; j++){
                        if(a[j] == 0){
                                continue;
                        }
                        res += inv[n - i] * (a[j] - 1) % mod * d[j] % mod;
                        res %= mod;

                        long long pre = d[j];
                        d[j] = sum * (inv[n - i] * a[j] % mod) % mod;

                        sum += pre;
                        sum %= mod;
                }
        }

        cout << res << "\n";
}