#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 1000000007;
int n, K, L, cur, ans, x[maxn], y[maxn], c[maxn], id[maxn];
map<int, int> mp;
multiset<int> pos[maxn];

int main() {
    scanf("%d %d %d", &n, &K, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &c[i]), id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int i, int j) { return x[i] < x[j]; });
    for (int lb = 1; lb <= n; lb++) {
        if (lb > 1 && x[id[lb]] == x[id[lb - 1]]) continue;
        mp.clear(), mp[0] = cur = 0, mp[L] = L;
        auto upd = [&](int p, int v) {
            auto it = --mp.upper_bound(p);
            if (it->second >= v) return;
            cur = (cur + 1LL * (v - it->second) * (next(it)->first - p)) % P;
            while (1) {
                it = mp.upper_bound(p);
                if (it->second >= v) break;
                cur = (cur + 1LL * (v - it->second) * (next(it)->first - it->first)) % P;
                mp.erase(it);
            }
            mp[p] = v;
        };
        for (int i = 1; i <= K; i++) {
            pos[i] = {-1, L};
        }
        for (int i = lb; i <= n; i++) {
            pos[c[id[i]]].insert(y[id[i]]);
        }
        for (int i = 1; i <= K; i++) {
            for (auto it = pos[i].begin(); *it ^ L; it++) {
                upd(*it + 1, *next(it));
            }
        }
        for (int i = n; i >= lb; i--) {
            if (i == n || x[id[i]] ^ x[id[i + 1]]) {
                int t = (1LL * L * L % P - cur + P) % P;
                ans = (ans + 1LL * t * (x[id[lb]] - (lb == 1 ? -1 : x[id[lb - 1]])) % P *
                    ((i == n ? L : x[id[i + 1]]) - x[id[i]])) % P;
            }
            auto it = pos[c[id[i]]].erase(pos[c[id[i]]].find(y[id[i]]));
            upd(*prev(it) + 1, *it);
        }
    }
    printf("%d\n", ans);
    return 0;
}