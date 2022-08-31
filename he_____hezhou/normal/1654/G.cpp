#include <bits/stdc++.h>
using namespace std;
int n, l[200010], h[200010];
vector < int > son[200010];
void dfs1(int cur, int fa) {
    h[cur] = l[cur] ? 0 : n;
    for (auto i : son[cur]) if (i != fa) {
        dfs1(i, cur);
        h[cur] = min(h[cur], h[i] + 1);
    }
}
void dfs2(int cur, int fa) {
    for (auto i : son[cur]) if (i != fa) {
        h[i] = min(h[i], h[cur] + 1);
        dfs2(i, cur);
    }
}
int sze[200010];
int tag[200010];
void dfs3(int cur, int fa) {
    sze[cur] = 1;
    for (auto i : son[cur]) {
        if (tag[i] || i == fa) continue;
        dfs3(i, cur);
        sze[cur] += sze[i];
    }
}
int dfs4(int cur, int fa, int sum) {
    if (sze[cur] * 2 < sum) return 0;
    for (auto i : son[cur]) {
        if (tag[i] || i == fa) continue;
        int tmp = dfs4(i, cur, sum);
        if (tmp) return tmp;
    }
    return cur;
}
vector < pair < int, int > > qwq;
int ans[200010], ttag[200010];
void dfs5(int cur, int fa, int need, int _max, int lst) {
    if (ttag[cur]) lst = min(lst, h[cur]);
    qwq.push_back({_max, lst});
    for (auto i : son[cur]) {
        if (tag[i] || i == fa || h[i] > h[cur]) continue;
        int nxt = need;
        if (h[i] == h[cur]) nxt++;
        else nxt--;
        dfs5(i, cur, nxt, max(_max, nxt), lst);
    }
}
void dfs6(int cur, int fa, int able, int _min, int lst) {
    if (ttag[cur]) lst = min(h[cur], lst);
    if (_min >= 0) {
        auto ite = upper_bound(qwq.begin(), qwq.end(), make_pair(able + 1, -1));
        if (ite != qwq.begin()) ans[cur] = min(ans[cur], min(lst, (ite - 1) -> second));
        else ans[cur] = min(ans[cur], lst);
    }
    for (auto i : son[cur]) {
        if (tag[i] || i == fa || h[i] < h[cur]) continue;
        int nxt = able, nnxt = _min;
        if (h[i] == h[cur]) nxt--, nnxt--;
        else nxt++, nnxt++;
        nnxt = min(nnxt, 0);
        dfs6(i, cur, nxt, nnxt, lst);
    }
}
void solve(int x) {
    if (tag[x]) return;
    dfs3(x, 0);
    x = dfs4(x, 0, sze[x]);
    qwq.clear();
    dfs5(x, 0, 0, 0, n);
    // cerr << "solve " << x << endl;
    // for (auto i : qwq) cerr << i.first << ' ' << i.second << endl;
    sort(qwq.begin(), qwq.end());
    for (int i = 1; i < qwq.size(); i++) qwq[i].second = min(qwq[i].second, qwq[i - 1].second);
    dfs6(x, 0, 0, 0, n);
    tag[x] = 1;
    for (auto i : son[x]) solve(i);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", l + i);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        for (auto j : son[i]) if (h[i] == h[j]) ttag[i] = 1;
    for (int i = 1; i <= n; i++) ans[i] = h[i];//, cerr << h[i] << " \n"[i == n];
    solve(1);
    // for (int i = 1; i <= n; i++) cerr << ans[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) printf("%d%c", h[i] * 2 - ans[i], " \n"[i == n]);
}