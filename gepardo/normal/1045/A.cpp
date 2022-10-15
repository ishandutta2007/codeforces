#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5;
const int inf = 1e4;
struct edge {
    int to, flow, lnk;
    edge(int new_to, int new_flow, int new_lnk): to(new_to), lnk(new_lnk), flow(new_flow) {
    }
};
vector<pair<int, int> > seg[N];
int part[N];
int s = 0, t = 1;
int pt[N];
int vr[N], taken[N], lf[N], rg[N], ship[N], cur[N], lnk[N], cnt, q[N], cut[N], mark[N], used[N], d[N], weapon[N];
vector<edge> ed[N];
void add(int u, int v, int flow) {
    ed[u].push_back(edge(v, flow, ed[v].size()));
    ed[v].push_back(edge(u, 0, ed[u].size() - 1));
}
void build(int v, int l, int r, int &cnt) {
    cnt++;
    vr[v] = cnt;
    if (l == r) {
        lnk[l] = cnt;
        ship[cnt] = l;
        add(cnt, t, 1);
        return;
    }
    int mid = (r + l) / 2;
    add(vr[v], cnt + 1, mid - l + 1);
    build(v * 2, l, mid, cnt);
    add(vr[v], cnt + 1, r - mid);
    build(v * 2 + 1, mid + 1, r, cnt);
}
void go(int v, int l, int r, int ll, int rr, int cnt) {
    if (ll <= l && r <= rr) {
        add(cnt, vr[v], 1);
        return;
    }
    int mid = (r + l) / 2;
    if (ll <= mid) go(v * 2, l, mid, ll, rr, cnt);
    if (rr > mid) go(v * 2 + 1, mid + 1, r, ll, rr, cnt);
}
bool bfs(int s, int t) {
    int l = 1;
    int sz = 1;
    q[sz] = s;
    d[s] = 0;
    while (l <= sz) {
        int v = q[l];
        for (auto to: ed[v]) {
            if (to.flow == 0) continue;
            if (d[to.to] > d[v] + 1) {
                d[to.to] = d[v] + 1;
                sz++;
                q[sz] = to.to;
            }
        }
        l++;
    }
    return (d[t] != cnt + 1);
}
int dfs(int v, int t, int flow) {
    if (v == t) return flow;
    for (; cur[v] < ed[v].size(); cur[v]++) {
        auto to = ed[v][cur[v]];
        if (to.flow == 0) continue;
        if (d[to.to] != d[v] + 1) continue;
        int p = dfs(to.to, t, min(flow, to.flow));
        if (p == 0) continue;
        ed[v][cur[v]].flow -= p;
        ed[to.to][ed[v][cur[v]].lnk].flow += p;
        return p;
    }
    return 0;
}
void flow(int s, int t) {
    int sum = 0;
    while (1) {
        for (int i = 0; i <= cnt; i++) d[i] = cnt + 1, cur[i] = 0;
        if (!bfs(s, t)) break;
        int p = dfs(s, t, inf);
        sum += p;
        while (p > 0) {
            p = dfs(s, t, inf);
            sum += p;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cnt = 1;
    build(1, 1, m, cnt);
    for (int i = 1; i <= n; i++) {
        int tp;
        cin >> tp;
        cnt++;
        mark[i] = tp;
        weapon[cnt] = i;
        if (tp == 0) {
            add(s, cnt, 1);
            int sz;
            cin >> sz;
            for (int j = 1; j <= sz; j++) {
                int to;
                cin >> to;
                add(cnt, lnk[to], 1);
            }
        }
        else
        if (tp == 1) {
            int l, r;
            add(s, cnt, 1);
            cin >> l >> r;
            lf[i] = l, rg[i] = r;
            go(1, 1, m, l, r, cnt);
        }
        else {
            int a, b, c;
            cin >> a >> b >> c;
            add(s, cnt, 2);
            add(cnt, lnk[a], 1);
            add(cnt, lnk[b], 1);
            add(cnt, lnk[c], 1);
        }
    }
    flow(s, t);
    for (int i = 0; i <= cnt; i++) used[i] = 0;
    for (int i = 1; i <= cnt; i++) {
        for (auto to: ed[i]) {
            if (to.to == t && to.flow == 0) part[i] = 1;
        }
    }
    for (auto to: ed[0]) {
        if (ed[to.to][to.lnk].flow != 0) used[to.to] = 1;
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i <= cnt; i++)
        if (used[i] == 1) {
            int v = weapon[i];
            if (mark[v] != 2) continue;
            int need = 0;
            for (auto to: ed[i]) {
                if (to.to == 0) continue;
                if (to.flow == 0) {
                    need++;
                    taken[to.to] = 1;
                    ans.push_back(make_pair(v, ship[to.to]));
                }
            }
            if (need == 1) {
                for (auto to: ed[i]) {
                    if (to.to == 0) continue;
                    if (taken[to.to]) continue;
                    if (!part[to.to]) continue;
                    need++;
                    taken[to.to] = 1;
                    ans.push_back(make_pair(v, ship[to.to]));
                    break;
                }
                if (need == 1) ans.pop_back();
            }
        }
    for (int i = 0; i <= cnt; i++)
        if (used[i] == 1) {
            int v = weapon[i];
            if (mark[v] != 0) continue;
            for (auto to: ed[i]) {
                if (to.to == 0) continue;
                if (taken[to.to]) continue;
                if (to.flow == 0) {
                    taken[to.to] = 1;
                    ans.push_back(make_pair(v, ship[to.to]));
                }
            }
        }
    for (int i = 0; i <= cnt; i++)
        if (used[i] == 1) {
            int v = weapon[i];
            if (mark[v] != 1) continue;
            seg[rg[v]].push_back(make_pair(lf[v], v));
        }
    for (int i = 0; i <= cnt; i++) {
        if (taken[i] == 1) continue;
        bool ok = 0;
        for (auto to: ed[i]) {
            if (to.to != t) continue;
            if (to.flow == 0) pt[ship[i]] = 1;
        }
    }
    set<int> s;
    for (int i = 1; i <= m; i++) {
        if (pt[i]) s.insert(i);
        for (auto it: seg[i]) {
            int l = it.first;
            auto nxt = s.lower_bound(l);
            if (s.end() == nxt) continue;
            //    assert(nxt != s.end());
            ans.push_back(make_pair(it.second, *nxt));
            s.erase(nxt);
        }
    }
    cout << ans.size() << "\n";
    for (auto p: ans) cout << p.first << " " << p.second << "\n";
    return 0;
}