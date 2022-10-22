#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2007;

int n, m;
bool used[MAXN];
vector <int> g[MAXN];

vector <int> c;
void getp(int u, int parent, int w, vector <int> &ans) {
    c.push_back(u);
    if (u == w) {
        ans = c;
        return;    
    }   
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }   
        else {
            getp(v, u, w, ans);
        }   
    }   
    c.pop_back();
}   

pair <int, int> dfs(int u, int parent) {
    used[u] = 1;

    pair <int, int> ans = {0, u};
    for (int v : g[u]) {
        if (v == parent) {
            continue;
        }
        else {
            auto t = dfs(v, u);
            ans = max(ans, {t.first + 1, t.second});
        }   
    }   

    return ans;
}   

pair <int, int> get(int u) {
    auto t1 = dfs(u, u);
    auto t2 = dfs(t1.second, t1.second);

    vector <int> path;
    c.clear();
    getp(t1.second, t1.second, t2.second, path);

    return {t2.first, path[path.size() >> 1]};
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   

    vector <pair <int, int> > a;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            a.push_back(get(i));        
        }
    }

    sort(a.begin(), a.end());

    int ans = a.back().first;
    if (a.size() == 1) {
        
    }
    else if (a.size() == 2) {
        ans = max(ans, (a.back().first + 1) / 2 + (a[a.size() - 2].first + 1) / 2 + 1);
    }   
    else {
        ans = max(ans, (a.back().first + 1) / 2 + (a[a.size() - 2].first + 1) / 2 + 1);
        ans = max(ans, (a[a.size() - 3].first + 1) / 2 + (a[a.size() - 2].first + 1) / 2 + 2);
    }

    cout << ans << '\n';
    for (int i = 0; i < (int)a.size() - 1; ++i) {
        cout << a.back().second + 1 << ' ' << a[i].second + 1 << '\n';
    }   

    return 0;
}