#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000, V = 5100000;
int n, q, a[maxn], mn[V], cnt[V], ans[maxn], pos[V][8];
int lst[17], prod[1 << 7], ctz[1 << 7], popcnt[1 << 7];
vector<pair<int, int>> Q[maxn];
vector<int> d[V];
map<int, int> mp;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i < V; i++) if (!mn[i]) {
        for (int j = i; j <= V; j += i) mn[j] = i;
    }
    for (int i = 2; i < V; i++) {
        int j = i, c = 0;
        while (!(j % mn[i])) j /= mn[i], c++;
        cnt[i] = cnt[j], d[i] = d[j];
        if (c & 1) cnt[i]++, d[i].push_back(mn[i]);
        assert(d[i].size() <= 7);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, l, r; i <= q; i++) {
        scanf("%d %d", &l, &r), Q[r].emplace_back(l, i);
    }
    mp[0] = 0, mp[n] = INT_MAX;
    auto upd = [&](int p, int v) {
        auto it = mp.lower_bound(p);
        if (it->second <= v) return;
        mp[p] = v;
        while (1) {
            it = --mp.lower_bound(p);
            if (it->second <= v) break;
            mp.erase(it);
        }
    };
    for (int i = 1; i < 1 << 7; i++) {
        ctz[i] = __builtin_ctz(i);
        popcnt[i] = __builtin_popcount(i);
    }
    memset(pos, -1, sizeof(pos));
    for (int i = 1; i <= n; i++) {
        memset(lst, 0x3f, sizeof(lst));
        for (int j = 0; j < 1 << d[a[i]].size(); j++) {
            if (!j) prod[j] = 1;
            else prod[j] = prod[j ^ (1 << ctz[j])] * d[a[i]][ctz[j]];
            for (int k = 0; k <= 7; k++) if (~pos[prod[j]][k]) {
                upd(pos[prod[j]][k], k + popcnt[((1 << d[a[i]].size()) - 1) ^ j]);
            }
        }
        for (auto p : Q[i]) {
            ans[p.second] = mp.lower_bound(p.first)->second;
        }
        for (int j = 0; j < 1 << d[a[i]].size(); j++) {
            pos[prod[j]][popcnt[((1 << d[a[i]].size()) - 1) ^ j]] = i;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}