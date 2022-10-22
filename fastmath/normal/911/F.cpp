#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n;
vector <int> g[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

pair <int, int> dfs(int u, int parent) {
    pair <int, int> ans = {0, u};
    for (int v : g[u]) {
        if (v == parent) continue;
        auto t = dfs(v, u);
        ans = max(ans, {t.first + 1, t.second});
    }
    return ans;
}

vector <int> st;
bool dfs1(int u, int parent, int want) {
    st.push_back(u);
    if (u == want) return 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        if (dfs1(v, u, want)) return 1;
    }
    st.pop_back();
    return 0;
}

int d1[MAXN], d2[MAXN];

void dfs2(int u, int parent, int depth, int *arr) {
    arr[u] = depth;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs2(v, u, depth + 1, arr);
    }
}

struct KEK {
    int a, b, c;
    KEK(int a_, int b_, int c_) {
        a = a_; b = b_; c = c_;
    }
};

bool del[MAXN];
int pw[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    auto t = dfs(0, 0);
    int a = t.second;
    t = dfs(a, a);
    int b = t.second;

    dfs1(a, a, b);
    set <int> ms;
    for (int e : st) ms.insert(e);

    dfs2(a, a, 0, d1);
    dfs2(b, b, 0, d2);
    
    for (int i = 0; i < n; ++i) {
        pw[i] = g[i].size();
    }

    int ans = 0;
    vector <KEK> l;
    set <pair <int, int> > s;
    for (int i = 0; i < n; ++i) {
        if (ms.find(i) == ms.end()) {
            s.insert({pw[i], i});
        }
    }

    while (s.size()) {
        int u = s.begin()->second;
        if (s.begin()->first > 1) exit(1);
        s.erase(s.begin());

        if (d2[u] < d1[u]) {
            ans += d1[u];
            l.push_back(KEK(a + 1, u + 1, u + 1));
        }
        else {
            ans += d2[u];
            l.push_back(KEK(b + 1, u + 1, u + 1));
        }

        del[u] = 1;
        for (int v : g[u]) {
            if (del[v]) continue;
            if (ms.find(v) != ms.end()) continue;
            s.erase({pw[v], v});
            --pw[v];
            s.insert({pw[v], v});
        }
    }
    
    for (int i = 0; i < (int)st.size() - 1; ++i) {
        ans += d2[st[i]];
        l.push_back(KEK(b + 1, st[i] + 1, st[i] + 1));
    }
    
    cout << ans << '\n';
    for (KEK e : l) cout << e.a << ' ' << e.b << ' ' << e.c << '\n';

    return 0;
}