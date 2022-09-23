#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
long long mod;
long long fac[N];

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n > 0){
                if(n & 1){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> mod;
        fac[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = fac[i - 1] * i % mod;
        }
        long long res = 0;
        for(int l = 1; l <= n; l++){
                long long shit = fac[l]  % mod * fac[n - l + 1] % mod;
                res += shit * (n - l + 1) % mod;
        }
        cout << res % mod << "\n";
}