#include <bits/stdc++.h>

#define MN 1001000
#define MOD 998244353

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN], b[MN], mark[MN], rev[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    set<pair<int, int>> ss;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ss.insert({i, a[i]});
        rev[a[i]] = i;
    }

    for(int i = 0; i < k; i++) {
        scanf("%lld", &b[i]);
        mark[b[i]] = 1;
    }

    ans = 1;
    for(int i = 0; ans && i < k; i++) {
        int w = 0, up = 0, lo = 0;

        auto ub = ss.upper_bound({rev[b[i]], b[i]});
        if(ub != ss.end() && !mark[ub->second]) w++, up++;

        auto lb = ss.lower_bound({rev[b[i]], b[i]});
        if(lb != ss.begin() && !mark[prev(lb)->second]) w++, lo++;

        ans *= w;
        if(ans >= MOD) ans -= MOD;
        if(w) {
            if(up) ss.erase(ub);
            else ss.erase(prev(lb));
        }
        mark[b[i]] = 0;
    }

    for(int i = 0; i < k; i++) {
        mark[b[i]] = 0;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}