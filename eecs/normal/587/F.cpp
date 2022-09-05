#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 300;
int n, q, tot = 1, ch[maxn][26], fail[maxn], len[maxn], ed[maxn];
int tim, dfn[maxn], sz[maxn], tag[maxn];
long long ans[maxn], sum[maxn];
char s[maxn];
vector<int> V[maxn], G[maxn];
vector<tuple<int, int, int>> Q[maxn], C[maxn];

namespace DS {
int tag1[maxn], tag2[maxn];

void add(int l, int r) {
    int bl = l / SZ, br = r / SZ;
    if (bl == br) {
        for (int i = l; i <= r; i++) tag2[i]++;
    } else {
        for (int i = l; i < (bl + 1) * SZ; i++) tag2[i]++;
        for (int i = bl + 1; i < br; i++) tag1[i]++;
        for (int i = br * SZ; i <= r; i++) tag2[i]++;
    }
}

int calc(int x) {
    return tag1[x / SZ] + tag2[x];
}
}  // namespace DS

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s), len[i] = strlen(s);
        int cur = 1;
        for (int j = 0; j < len[i]; j++) {
            int c = s[j] - 'a';
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            V[i].push_back(cur = ch[cur][c]);
        }
        ed[i] = cur;
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
        if (len[k] <= SZ) {
            Q[l - 1].emplace_back(k, -1, i);
            Q[r].emplace_back(k, 1, i);
        } else {
            C[k].emplace_back(l, r, i);
        }
    }
    for (int i = 1; i <= n; i++) if (len[i] > SZ) {
        memset(tag, 0, sizeof(tag));
        for (int j : V[i]) tag[j]++;
        function<void(int)> dfs = [&](int v) {
            for (int u : G[v]) dfs(u), tag[v] += tag[u];
        };
        dfs(1);
        for (int j = 1; j <= n; j++) {
            sum[j] = sum[j - 1] + tag[ed[j]];
        }
        for (auto p : C[i]) {
            ans[get<2>(p)] = sum[get<1>(p)] - sum[get<0>(p) - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        DS::add(dfn[ed[i]], dfn[ed[i]] + sz[ed[i]] - 1);
        for (auto p : Q[i]) for (int j : V[get<0>(p)]) {
            ans[get<2>(p)] += get<1>(p) * DS::calc(dfn[j]);
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}