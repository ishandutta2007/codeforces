#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Flow {
    int S, T, tot;
    vector<pair<int, int>> e;
    vector<vector<int>> eid;
    vector<int> opt;
    Flow() {
        S = 0, T = 1, tot = 2;
        eid.resize(tot);
        opt.resize(tot, 0);
    }
    void addedge(int a, int b, int f) {
        eid[a].emplace_back(e.size()), e.emplace_back(b, f);
        eid[b].emplace_back(e.size()), e.emplace_back(a, 0);
    }
    int newnode(int val) {
        eid.emplace_back();
        opt.emplace_back(0);
        pid[val] = tot;
        return tot++;
    }
    int getnode(int val) {
        if (pid.count(val)) {
            return pid[val];
        }
        return newnode(val);
    }
    map<int, int> pid;
    bool bfs(int x) {
        if (opt[x]) {
            return opt[x] > 0;
        }
        vector<int> dis(tot + 1, -1), fr(tot + 1, -1);
        queue<int> que;
        dis[x] = 0, que.push(x);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i : eid[v]) {
                auto [u, f] = e[i];
                if (f && dis[u] == -1) {
                    dis[u] = dis[v] + 1;
                    fr[u] = i;
                    que.push(u);
                }
            }
        }
        if (dis[T] != -1) {
            opt[x] = 1;
            for (int v = T; v != x; v = e[fr[v] ^ 1].first) {
                --e[fr[v]].second, ++e[fr[v] ^ 1].second;
            }
        } else {
            opt[x] = -1;
        }
        return opt[x] > 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Flow g;
    vector<int> pt(1e6 + 1, 0);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        pt[a[i]] = g.getnode(-a[i]);
        ++cnt[a[i]];
    }
    map<int, vector<int>> dv;
    for (auto [x, c] : cnt) {
        g.addedge(pt[x], g.T, c);
        dv[x].emplace_back(x);
    }
    int tot = n;
    LL ans = 0;
    while (tot > 0 && !dv.empty()) {
        auto [x, val] = *dv.begin();
        dv.erase(dv.begin());
        int v = g.getnode(x);
        for (auto u : val) {
            g.addedge(v, pt[u], 1);
        }
        if (g.bfs(v)) {
            --tot, ans += x;
            for (auto u : val) {
                dv[x + u].emplace_back(u);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}