#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 998244353;

using namespace std;

long long n;
long long f[N];
long long d[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        f[0] = 1;
        for(int i = 1; i <= n; i++){
                f[i] = f[i - 1] * i % mod;
        }
        d[n] = n;
        for(int i = n - 1; i >= 1; i--){
                d[i] = d[i + 1] * i % mod;
        }
        long long res = f[n];
        for(int i = n - 1; i > 1; i--){
                res += (f[i] - 1) * d[i + 1] % mod;
                if(res >= mod){
                        res -= mod;
                }
                if(res < 0){
                        res += mod;
                }
        }
        cout << res << "\n";
}