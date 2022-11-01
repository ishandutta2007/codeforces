#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

typedef long long ll;
const ll MOD = 998244353;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) { return expo(a, MOD - 2); }

ll fat[MN], invfat[MN];

void prep() {
    fat[0] = 1;
    for(ll i = 1; i < MN; i++) fat[i] = fat[i-1] * i % MOD;
    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--) invfat[i-1] = i * invfat[i] % MOD;
}

ll nCr(ll n, ll k) {
    if(k < 0 || k > n) return 0;
    return fat[n] * invfat[k] % MOD * invfat[n - k] % MOD;
}

#include<bits/extc++.h>
using namespace __gnu_pbds;
template<typename T, typename cmp = less<T>>
using oset = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

ll t = 1, n, m, ans, x, y, ok[MN];

int main() {
    prep();
    scanf("%lld", &t);

    oset<int> ss;
    for(int i = 1; i <= 200000; i++)
        ss.insert(i);

    for(int T = 1; T <= t; T++) {
        ans = 0;
        scanf("%lld %lld", &n, &m);

        vector<int> tmp, rev;
        for(int i = 0; i < m; i++) {
            scanf("%lld %lld", &x, &y);
            tmp.push_back(y);
        } reverse(tmp.begin(), tmp.end());

        for(int y : tmp) {
            auto tt = ss.find_by_order(y-1);
            rev.push_back(*tt);
            ss.erase(tt);
            auto tt2 = ss.find_by_order(y-1);
            if(ok[*tt2] < T) {
                ans++;
                ok[*tt2] = T;
            }
        }
        
        printf("%lld\n", nCr(2*n-ans-1, n));
        for(int x : rev) ss.insert(x);
    }
    return 0;
}