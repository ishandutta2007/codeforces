#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n > 0){
                if(n & 1) res = res * x % mod;
                x = x * x % mod;
                n >>= 1;
        }
        return res;
}

long long D;
long long fac[N];
long long inv[N];
vector < long long > p;

long long solve(long long x, long long y)
{
        if(x == y){
                return 1;
        }
        x /= y;

        int sum = 0;
        long long res = 1;
        for(auto g: p){
                if(x % g){
                        continue;
                }
                int cur = 0;
                while(x % g == 0){
                        x /= g;
                        cur += 1;
                }
                sum += cur;
                res = res * inv[cur] % mod;
        }
        res = res * fac[sum] % mod;
        return res;
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        fac[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = fac[i - 1] * i % mod;
        }
        inv[N - 1] = pw(fac[N - 1], mod - 2);
        for(int i = N - 2; i >= 0; i--){
                inv[i] = inv[i + 1] * (i + 1) % mod;
        }

        scanf("%lld", &D);

        long long d = sqrt(D);
        while(d * d > D) d--;
        while((d + 1) * (d + 1) <= D) d++;

        for(long long i = 2; i <= d; i++){
                if(D % i){
                        continue;
                }
                p.push_back(i);
                while(D % i == 0){
                        D /= i;
                }
        }
        if(D > 1){
                p.push_back(D);
        }

        int q;
        scanf("%d", &q);
        while(q--){
                long long x, y;
                scanf("%lld%lld", &x, &y);
                long long g = __gcd(x, y);

                printf("%lld\n", solve(x, g) * solve(y, g) % mod);
        }
}