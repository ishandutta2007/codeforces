#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int m, n, tot = 1, head[maxn], from[maxn];
bool vis[maxn], mark[maxn];
array<int, 4> eid[maxn];
vector<array<int, 2>> V[maxn];
map<int, int> mp;
map<int, vector<array<int, 2>>> id;
string ans[maxn];
struct edge { int to, nxt; } e[maxn];

void add_edge(int u, int v) {
    e[++tot] = (edge){v, head[u]}, head[u] = tot;
}

int main() {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &n), ans[i].resize(n);
        for (int j = 0, x; j < n; j++) {
            scanf("%d", &x);
            mp[x]++, V[i].push_back({x, j});
        }
    }
    for (auto &p : mp) {
        if (p.second % 2) puts("NO"), exit(0);
    }
    for (int i = 1; i <= m; i++) {
        sort(V[i].begin(), V[i].end());
        for (int j = 0, k; j < V[i].size(); j = k) {
            for (k = j; k < V[i].size() && V[i][j][0] == V[i][k][0]; k++);
            while (j + 1 < k) {
                ans[i][V[i][j][1]] = 'L', ans[i][V[i][j + 1][1]] = 'R';
                j += 2;
            }
            if (j < k) id[V[i][j][0]].push_back({i, V[i][j][1]});
        }
    }
    for (auto &p : id) {
        auto &vec = p.second;
        assert(vec.size() % 2 == 0);
        for (int i = 0; i < vec.size(); i += 2) {
            add_edge(vec[i][0], vec[i + 1][0]);
            add_edge(vec[i + 1][0], vec[i][0]);
            eid[tot / 2] = {vec[i][0], vec[i][1], vec[i + 1][0], vec[i + 1][1]};
        }
    }
    vector<int> st;
    function<void(int)> dfs = [&](int u) {
        mark[u] = 1;
        for (int &i = head[u]; i; i = e[i].nxt) if (!vis[i / 2]) {
            int o = i / 2;
            vis[i / 2] = 1, dfs(e[i].to);
            from[o] = u, st.push_back(o);
        }
    };
    for (int i = 1; i <= m; i++) {
        if (!mark[i]) st.clear(), dfs(i);
    }
    for (int i = 1; i <= tot; i++) {
        if (from[i] == eid[i][0]) {
            ans[eid[i][0]][eid[i][1]] = 'L', ans[eid[i][2]][eid[i][3]] = 'R';
        } else {
            assert(from[i] == eid[i][2]);
            ans[eid[i][0]][eid[i][1]] = 'R', ans[eid[i][2]][eid[i][3]] = 'L';
        }
    }
    puts("YES");
    for (int i = 1; i <= m; i++) {
        int s = 0;
        for (auto ch : ans[i]) {
            if (ch == 'L') s++;
            else s--;
        }
        assert(s % 2 == 0);
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}