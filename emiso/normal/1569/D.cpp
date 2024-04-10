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

ll t = 1, n, m, k, ans, a[MN];

vector<int> xs, ys;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld %lld", &n, &m, &k);

    xs.resize(n); ys.resize(m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &xs[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &ys[i]);
    }

    vector<map<int, ll>> r(n), c(m);
    for(int i = 0, x, y; i < k; i++) {
        scanf("%d %d", &x, &y);
        auto tx = lower_bound(xs.begin(), xs.end(), x);
        auto ty = lower_bound(ys.begin(), ys.end(), y);
        if(*tx == x && *ty == y) continue;
        if(*tx == x) {
            c[ty - ys.begin()][x]++;
        } else {
            r[tx - xs.begin()][y]++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        ll sum = 0;
        for(auto tt : r[i]) {
            ans += tt.second * sum;
            sum += tt.second;
        }
    }
    for(int i = 0; i < m; i++) {
        ll sum = 0;
        for(auto tt : c[i]) {
            ans += tt.second * sum;
            sum += tt.second;
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}