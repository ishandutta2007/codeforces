#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans[MN], x[MN], y[MN];
set<pair<int, int>> ev[MN], rev[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    vector<int> xs;
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        ans[i] = -1;
        xs.push_back(x[i]);
        xs.push_back(y[i]);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for(int i = 1; i <= n; i++) {
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
        y[i] = lower_bound(xs.begin(), xs.end(), y[i]) - xs.begin();

        ev[x[i]].insert({y[i], i});
        rev[y[i]].insert({x[i], i});
    }

    set<pair<ll, ll>> cur;
    for(int xx = 0; xx <= 2*n; xx++) {
        for(auto e : ev[xx]) {
            int id = e.second, y = e.first;
            auto best = cur.begin();
            if(best != cur.end() && best->first < y) {
                ans[id] = max(ans[id], best->second);
            }
        }
        for(auto e : ev[xx])
            cur.insert(e);
    }

    cur.clear();
    for(int xx = 0; xx <= 2*n; xx++) {
        for(auto e : ev[xx]) {
            int id = e.second, y = e.first;
            auto best = cur.begin();
            if(best != cur.end() && best->first < y) {
                ans[id] = max(ans[id], best->second);
            }
        }
        for(auto e : rev[xx])
            cur.insert(e);
    }

    for(int i = 1; i <= n; i++) {
        ev[x[i]].clear();
        rev[y[i]].clear();
    }

    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    } puts("");

    if(--t) goto st;
    return 0;
}