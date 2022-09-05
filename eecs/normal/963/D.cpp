#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, tot = 1, lst = 1, ans[maxn];
int fa[maxn], len[maxn], ch[maxn][26];
char s[maxn], t[maxn];
vector<int> G[maxn];
set<int> S[maxn];
vector<pair<int, int>> Q[maxn];

void ins(int c) {
    int p = lst, np = lst = ++tot;
    len[np] = len[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) { fa[np] = 1; return; }
    int q = ch[p][c];
    if (len[q] == len[p] + 1) {
        fa[np] = q;
    } else {
        int nq = ++tot; len[nq] = len[p] + 1;
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        fa[nq] = fa[q], fa[q] = fa[np] = nq;
        for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
    }
}

int main() {
    scanf("%s %d", s + 1, &q), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        ins(s[i] - 'a'), S[lst].insert(i);
    }
    for (int i = 2; i <= tot; i++) {
        G[fa[i]].push_back(i);
    }
    for (int i = 1, k; i <= q; i++) {
        scanf("%d %s", &k, t + 1);
        int len = strlen(t + 1), cur = 1;
        bool flag = 1;
        for (int j = 1; j <= len; j++) {
            if (!ch[cur][t[j] - 'a']) { flag = 0; break; }
            cur = ch[cur][t[j] - 'a'];
        }
        if (!flag) ans[i] = -1;
        else ans[i] = len, Q[cur].emplace_back(k, i);
    }
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) {
            dfs(u);
            if (S[u].size() > S[v].size()) swap(S[u], S[v]);
            for (int x : S[u]) S[v].insert(x);
            S[u].clear();
        }
        vector<int> V;
        if (!Q[v].empty()) {
            for (int x : S[v]) V.push_back(x);
        }
        for (auto p : Q[v]) {
            if (V.size() < p.first) {
                ans[p.second] = -1;
            } else {
                int t = INT_MAX;
                for (int i = 0; i + p.first - 1 < V.size(); i++) {
                    t = min(t, V[i + p.first - 1] - V[i]);
                }
                ans[p.second] += t;
            }
        }
    };
    dfs(1);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}