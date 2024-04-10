#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 100100
#define MOD 1'000'000'007

int divisor[MN];
vector<int> primes, mobius(MN, -1), phi(MN);

void sieve() {
    for(int i = 1; i < MN; i++) phi[i] = (divisor[i] = i) - 1;
    phi[1] = mobius[1] = 1; 
    for(int i = 2; i < MN; i++) {
        if(divisor[i] == i) primes.push_back(i);
        for (int pj : primes) {
            if (i * pj >= MN) break;
            divisor[i * pj] = pj;
            phi[i * pj] = phi[i] * (pj - !!(i % pj));
            mobius[i * pj] = -mobius[i] * !!(i % pj);
            if(i % pj == 0) break;
        }
    }
}

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}
ll inv_mod(ll a) { return expo(a, MOD - 2); }


ll m, dp[100010], invm;
vector<int> divi[100010];
vector<pair<int, int>> cnt[100010];

int main() {  
    sieve();
    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i)
            divi[j].push_back(i);

    scanf("%lld", &m);
    invm = inv_mod(m);
    
    for (int d = 1; d <= m; d++) {
        for (int x1 = 1; x1 <= m / d; x1++) {
            ll sum = 0;
            for (int g : divi[x1]) {
                sum += mobius[g] * m / d / g;
                if (sum >= MOD) sum -= MOD;
                if (sum < 0) sum += MOD;
            }
            cnt[x1*d].push_back({d, sum * invm % MOD});
        }
    }

    dp[1] = 1;
    ll ans = 1;
    for (int i = 2; i <= m; i++) {
        ll num = 1, denom = 1;
        for (auto tt : cnt[i]) {
            if (tt.first == i) denom = (denom - tt.second + MOD) % MOD;
            else num = (num + dp[tt.first] * tt.second) % MOD;
        }
        dp[i] = num * inv_mod(denom) % MOD;
        ans = (ans + dp[i]) % MOD;
    }

    printf("%lld\n", ans * invm % MOD);
    return 0;
}