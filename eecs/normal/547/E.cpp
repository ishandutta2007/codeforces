#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, maxq = 500010;
int n, q, tot = 1, ch[maxn][26], fail[maxn], ans[maxq];
int tim, dfn[maxn], sz[maxn], c[maxn];
vector<int> G[maxn], V[maxn];
vector<tuple<int, int, int>> Q[maxn];
char s[maxn];

void add(int p) {
    for (; p <= tot; p += p & -p) c[p]++;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int len = strlen(s + 1), cur = 1;
        for (int j = 1; j <= len; j++) {
            int c = s[j] - 'a';
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            V[i].push_back(cur = ch[cur][c]);
        }
    }
    auto build = [&]() {
        fill(ch[0], ch[0] + 26, 1);
        queue<int> Q; Q.push(1);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int c = 0; c < 26; c++) {
                if (ch[v][c]) fail[ch[v][c]] = ch[fail[v]][c], Q.push(ch[v][c]);
                else ch[v][c] = ch[fail[v]][c];
            }
        }
    };
    build();
    for (int i = 2; i <= tot; i++) {
        G[fail[i]].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        dfn[v] = ++tim, sz[v] = 1;
        for (int u : G[v]) dfs(u), sz[v] += sz[u];
    };
    dfs(1);
    for (int i = 1, l, r, k; i <= q; i++) {
        scanf("%d %d %d", &l, &r, &k);
        Q[l - 1].emplace_back(k, i, -1);
        Q[r].emplace_back(k, i, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : V[i]) add(dfn[j]);
        for (auto p : Q[i]) {
            int x = V[get<0>(p)].back();
            ans[get<1>(p)] += get<2>(p) * (sum(dfn[x] + sz[x] - 1) - sum(dfn[x] - 1));
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}