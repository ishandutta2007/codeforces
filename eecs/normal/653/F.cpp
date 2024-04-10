#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, pre[maxn], mx[maxn], pos[maxn * 2], lb[maxn], cnt[maxn];
int tot = 1, lst = 1, fa[maxn * 2], len[maxn * 2], ch[maxn * 2][2];
char s[maxn];
vector<int> G[maxn * 2], V[maxn * 2];

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
    scanf("%d %s", &n, s + 1);
    vector<int> st = {0};
    V[pre[0] + n].push_back(0);
    for (int i = 1; i <= n; i++) {
        ins(s[i] == '('), pos[lst] = i;
        pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
        while (!st.empty() && pre[st.back()] >= pre[i]) st.pop_back();
        if (!st.empty()) lb[i] = st.back();
        st.push_back(i);
        cnt[i] = V[pre[i] + n].size(), V[pre[i] + n].push_back(i);
    }
    for (int i = 2; i <= tot; i++) {
        G[fa[i]].push_back(i);
    }
    long long ans = 0;
    auto calc = [&](int r, int l) {
        auto it = lower_bound(V[pre[r] + n].begin(), V[pre[r] + n].end(), max(l - 1, lb[r]));
        return cnt[r] - (it - V[pre[r] + n].begin());
    };
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) {
            dfs(u), pos[v] = pos[u];
        }
        if (v > 1) {
            ans += calc(pos[v], pos[v] - len[v] + 1);
            ans -= calc(pos[v], pos[v] - len[fa[v]] + 1);
        }
    };
    dfs(1), printf("%lld\n", ans);
    return 0;
}