#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 3e5 + 7;
int n;
map <char, int> g[N << 2];
int h[N];
int cnt[N], add[N], subtree[N];
int add_(int u, int v, int &ptr, vector <int> &st) {
    int ans = 0;
    for (auto e : g[v]) {
        char c = e.first;
        if (g[u].find(c) == g[u].end()) {
            st.push_back(u);
            ++ans;
            g[u][c] = ptr++;
        }   
        ans += add_(g[u][c], g[v][c], ptr, st);
    }   
    return ans;
}   
int get(int u) {
    if (g[u].empty()) {
        return 1;
    }   
    else {
        int mx = -1;
        for (auto e : g[u]) {
            int v = e.second;
            if (mx == -1 || subtree[mx] < subtree[v]) mx = v;
        }   
        int ans = subtree[mx];
        int ptr = n;
        vector <int> st;
        for (auto e : g[u]) {
            int v = e.second;
            if (v != mx) {
                ans += add_(mx, v, ptr, st);
            }   
        }   
        for (int i : st) {
            vector <char> v;
            for (auto e : g[i]) {
                if (e.second >= n) {
                    v.push_back(e.first);
                }
            }   
            for (auto e : v) {
                g[i].erase(e);
            }   
        }   
        return ans;
    }
}   
void dfs(int u, int d) {
    h[u] = d;
    subtree[u] = 1;
    for (auto e : g[u]) {
        int v = e.second;
        dfs(v, d + 1);
        subtree[u] += subtree[v];
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; char c;
        cin >> u >> v >> c;
        --u; --v;
        g[u][c] = v;
    }   
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        cnt[h[i] + 1] += get(i);
    }   
    for (int i = 0; i < n; ++i) {
        add[h[i] + 2]++;
    }   
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr += add[i];
        cnt[i] += curr;
    }   
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (cnt[ans] > cnt[i]) {
            ans = i;
        }   
    }   
    cout << cnt[ans] << ' ' << ans << '\n';
}