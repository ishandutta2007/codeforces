#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, P = 998244353;
typedef bitset<maxn> subset;
int n, m, vis[maxn];
subset b[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, q; i <= m; i++) {
        scanf("%d", &q);
        while (q--) {
            int p; scanf("%d", &p);
            b[i][p] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            auto o = b[i] & b[j];
            if (o.any() && o != b[i] && o != b[j]) {
                G[i].push_back(j), G[j].push_back(i);
            }
        }
    }
    function<int(int, vector<subset>&)> solve = [&](int v, vector<subset> &E) {
        vis[v] = 1;
        string inter(E.size(), ' ');
        auto a = b[v];
        for (int i = 0; i < E.size(); i++) {
            auto o = a & E[i];
            if (o.none()) inter[i] = '0';
            else if (o != E[i]) inter[i] = '1';
            else inter[i] = '2';
            a &= ~o;
        }
        bool pre = regex_match(inter, regex("2*1?0*"));
        bool suf = regex_match(inter, regex("0*1?2*"));
        bool interval = regex_match(inter, regex("0*1?2*1?0*"));
        if (!interval) return 0;
        if (!pre && !suf && a.any()) return 0;
        if (!suf && a.any()) {
            reverse(inter.begin(), inter.end());
            reverse(E.begin(), E.end());
        }
        if (a.any()) E.push_back(a), inter.push_back('2');
        for (int i = E.size() - 1; ~i; i--) if (inter[i] == '1') {
            auto o1 = b[v] & E[i], o2 = ~b[v] & E[i];
            E.erase(E.begin() + i);
            if (i && inter[i - 1] ^ '0') swap(o1, o2);
            E.insert(E.begin() + i, o1);
            E.insert(E.begin() + i, o2);
        }
        for (int u : G[v]) if (!vis[u]) {
            if (!solve(u, E)) return 0;
        }
        return 1;
    };
    vector<pair<subset, vector<subset>>> eq;
    for (int i = 1; i <= m; i++) if (!vis[i]) {
        vector<subset> E;
        if (!solve(i, E)) puts("0"), exit(0);
        subset o;
        for (auto &e : E) o |= e;
        eq.emplace_back(o, E);
    }
    subset all;
    for (int i = 1; i <= n; i++) all[i] = 1;
    eq.emplace_back(all, vector<subset>{all});
    sort(eq.begin(), eq.end(), [&](pair<subset, vector<subset>> a, pair<subset, vector<subset>> b) {
        return make_pair(-a.first.count(), a.second.size()) < make_pair(-b.first.count(), b.second.size());
    });
    int ans = 1;
    for (int i = 0; i < eq.size(); i++) {
        if (eq[i].second.size() > 1) (ans *= 2) %= P;
        for (auto o : eq[i].second) {
            int cnt = o.count();
            for (int j = i + 1; j < eq.size(); j++) {
                auto p = eq[j].first;
                if ((o & p) == p) cnt -= p.count() - 1, o &= ~p;
            }
            for (int j = 1; j <= cnt; j++) ans = 1LL * ans * j % P;
        }
    }
    printf("%d\n", ans);
    return 0;
}