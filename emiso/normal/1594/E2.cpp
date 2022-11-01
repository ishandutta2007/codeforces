#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

typedef long long ll;
#define MOD 1'000'000'007

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll f(ll n) {
    return expo(4, (1LL << n) - 2) % MOD;
}

map<ll, array<ll, 6>> possib;
set<ll> proc;

ll m, n, a[MN], c[MN];
char s[MN]; string str;
string ord = "wygbro";

ll ff[66];

int main() {
    for(int i = 1; i <= 60; i++) ff[i] = f(i);

    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; i++) {
        scanf("%lld %s", &a[i], s);
        
        for(int j = 0; j < 6; j++)
            if(ord[j] == s[0]) c[i] = j;

        possib[a[i]][c[i]] = 1;
        proc.insert(a[i]);
    }

    proc.insert(1);
    while(!proc.empty()) {
        ll u = *proc.rbegin(); proc.erase(u);
        if(u < (1LL << (n-1))) {
            int dep = 0;
            for(ll i = u; i < (1LL << (n-1)); dep++, i *= 2LL);

            array<ll, 6> L, R, me;
            if(possib.count(u*2)) L = possib[u*2];
            else for(int i = 0; i < 6; i++) L[i] = ff[dep];
            if(possib.count(u*2+1)) R = possib[u*2+1];
            else for(int i = 0; i < 6; i++) R[i] = ff[dep];

            for(int i = 0; i < 6; i++) me[i] = 0;
            if(!possib.count(u)) {
                for(int i = 0; i < 6; i++) possib[u][i] = 1;
            }

            for(int i = 0; i < 6; i++) {
                if(!possib[u][i]) continue;
                for(int j = 0; j < 6; j++) {
                    if(i / 2 == j / 2) continue;
                    for(int k = 0; k < 6; k++) {
                        if(i / 2 == k / 2) continue;
                        me[i] = (me[i] + L[j] * R[k]) % MOD;
                    }
                }
            }

            possib[u] = me;
        }
        if(u > 1) proc.insert(u / 2);
    }

    ll ans = 0;
    for(int i = 0; i < 6; i++) {
        ans += possib[1][i];
        if(ans >= MOD) ans -= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}