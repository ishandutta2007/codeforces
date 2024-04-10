#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
bool pr[N];
void prec() {
    for (int i = 2; i < N; ++i) pr[i] = 1;
    for (int i = 2; i < N; ++i) {
        if (pr[i]) {
            for (int j = 2 * i; j < N; j += i) pr[j] = 0;
        }   
    }
}   
int n;
int a[N];
vector <int> g[N], ng[N];
vector <int> vert[N];
bool used[N];
pair <int, int> dfs(int u, int p) {
    used[u] = 1;
    pair <int, int> ans = {1, u};
    for (int v : ng[u]) {
        if (p == v) continue;
        auto t = dfs(v, u);
        ++t.first;
        ans = max(ans, t);
    }   
    return ans;
}   
int get(int p) {
    vector <int> v;
    for (int i = p; i < N; i += p) {
        for (int e: vert[i]) v.push_back(e);
    }   
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        ng[i].clear();
    }   
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int u = v[i];
        for (int t : g[u]) {
            int p = lower_bound(v.begin(), v.end(), t) - v.begin();
            if (0 <= p && p < v.size() && v[p] == t) {
                ng[i].push_back(p);
            }   
        }   
    }   
    for (int i = 0; i < n; ++i) used[i] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            auto t = dfs(i, i);
            t = dfs(t.second, t.second);
            ans = max(ans, t.first);
        }   
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    prec();
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    for (int i = 0; i < n; ++i) vert[a[i]].push_back(i);
    int ans = 0;
    for (int p = 2; p < N; ++p) {
        if (pr[p]) {
            ans = max(ans, get(p));
        }
    }   
    cout << ans << '\n';
}