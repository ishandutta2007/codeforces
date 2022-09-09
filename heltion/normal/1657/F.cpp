#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;   
}
vector<int> kosaraju(int n, const vector<pair<int, int>>& edges){
    vector<int> vis(n), p, res(n);
    vector<vector<int>> G(n), Gt(n);
    for (auto [a, b] : edges) {
        G[a].push_back(b);
        Gt[b].push_back(a);
    }
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int v : G[u]) if(not vis[v]) dfs(v);
        p.push_back(u);
    };
    int scc = 0;
    function<void(int)> dfst = [&](int u){
        vis[u] = 0;
        res[u] = scc;
        for(int v : Gt[u]) if(vis[v]) dfst(v);
    };
    for(int i = 0; i < n; i += 1) if(not vis[i]) dfs(i);
    reverse(p.begin(), p.end());

    for(int i : p) if(vis[i]) {
        scc += 1;
        dfst(i);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n + 1);
    for (int i = 1, u, v; i < n; i += 1) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> p(n + 1), d(n + 1);
    function<void(int)> DFS = [&](int u) {
        for (int v : G[u]) if (v != p[u]) {
            p[v] = u;
            d[v] = d[u] + 1;
            DFS(v);
        }
    };
    DFS(1);
    vector<vector<int>> path(q);
    vector<string> s(q);
    for (int i = 0, x, y; i < q; i += 1) {
        cin >> x >> y >> s[i];
        vector<int> fx, fy;
        if (d[x] < d[y]) swap(x, y);
        while (d[x] > d[y]) {
            fx.push_back(x);
            x = p[x];
        }
        while (x != y) {
            fx.push_back(x);
            fy.push_back(y);
            x = p[x];
            y = p[y];
        }
        fx.push_back(x);
        ranges::reverse(fy);
        for (int x : fx) path[i].push_back(x);
        for (int y : fy) path[i].push_back(y);
        assert(path[i].size() == s[i].size());
    }
    auto no = [&]() {
        cout << "NO\n";
        exit(0);
    };
    vector ch(n + 1, vector<char>(2));
    vector<vector<int>> g((n + 1) << 2);
    for (int i = 0; i < q; i += 1) {
        //for (int x : path[i]) cout << x << " ";
        //cout << s[i] << "\n";
        int m = path[i].size();
        for (int j = 0; j < m; j += 1) {
            int x = path[i][j];
            char a = s[i][j], b = s[i][m - 1 - j];
            if (ch[x][0]) continue;
            ch[x][0] = a;
            if (a != b) ch[x][1] = b;
        }
    }
    for (int i = 1; i <= n; i += 1) if (not ch[i][1]) g[i * 2 + 1].push_back(i * 2);
    for (int i = 0; i < q; i += 1) {
        int m = path[i].size();
        for (int j = 0; j < m; j += 1) {
            int x = path[i][j];
            char a = s[i][j], b = s[i][m - 1 - j];
            if (a == b) {
                if (ch[x][0] != a and ch[x][1] != a) no();
                if (ch[x][0] == a) g[x * 2 + 1].push_back(x * 2);
                else g[x * 2].push_back(x * 2 + 1);
            }
        }
        vector<int> pa, pb;
        int oka = 1, okb = 1;
        for (int j = 0; j < m; j += 1) {
            int x = path[i][j];
            char a = s[i][j], b = s[i][m - 1 - j];
            if (a == b) continue;
            if (ch[x][0] != a and ch[x][1] != a) oka = 0;
            else pa.push_back(x * 2 + (ch[x][1] == a));
            if (ch[x][0] != b and ch[x][1] != b) okb = 0;
            else pb.push_back(x * 2 + (ch[x][1] == b));
        }
        if (not oka and not okb) no();
        if (okb) for (int i = 0; i < pb.size(); i += 1) 
                g[pb[i]].push_back(pb[(i + 1) % pb.size()]);
        else for (int i = 0; i < pa.size(); i += 1)
            g[pa[i] ^ 1].push_back(pa[i]);
        if (oka) for (int i = 0; i < pa.size(); i += 1) 
                g[pa[i]].push_back(pa[(i + 1) % pa.size()]);
        else for (int i = 0; i < pb.size(); i += 1)
            g[pb[i] ^ 1].push_back(pb[i]);
    }
    vector<pair<int, int>> edges;
    for (int i = 2; i <= 2 * n + 1; i += 1)
        for (int j : g[i]) edges.emplace_back(i, j);
    auto res = kosaraju(2 * n + 2, edges);
    for (int i = 1; i <= n; i += 1) {
        //cout << i << " " << ch[i][0] << " " << ch[i][1] << " " << res[i * 2] << " " << res[i * 2 + 1] << "\n";
    }
    for (int i = 1; i <= n; i += 1) if (res[i * 2] == res[i * 2 + 1]) no();
    vector<char> c(n + 1);
    for (int i = 1; i <= n; i += 1) c[i] = ch[i][res[i * 2 + 1] > res[i * 2]];
    cout << "YES\n";
    for (int i = 1; i <= n; i += 1) if (not c[i]) c[i] = 'a';
    for (int i = 1; i <= n; i += 1) cout << c[i];
    return 0;
}