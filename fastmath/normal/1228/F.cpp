#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
const int N = 2e5 + 7;
int P, n, pw[N], cnt[N];
vector <int> g[N], ans;
bool check(int u, int p, int h) {
    vector <int> to;
    for (int v : g[u]) if (v != p) to.app(v);
    if (h == 0) return to.empty();
    if (to.size() != 2) return 0;
    else return check(to[0], u, h - 1) && check(to[1], u, h - 1);
}   
bool check_del(int u, int p, int h, int del) {
    if (u == del) return 1;
    vector <int> to;
    for (int v : g[u]) if (v != p) to.app(v);
    if (h == 0) return to.empty();
    if (to.size() != 2) return 0;
    else return check_del(to[0], u, h - 1, del) && check_del(to[1], u, h - 1, del);
}   
int geth(int u, int p) {
    int ans = 0;
    for (int v : g[u]) if (v != p) ans = max(ans, geth(v, u) + 1);
    return ans; 
}   
bool haveroot(int u, int p) {
    if (pw[u] == 2) return 1;
    for (int v : g[u]) if (v != p && haveroot(v, u)) return 1;
    return 0;
}   
void solve4() {
    int u = -1;
    for (int i = 1; i <= n; ++i) if (pw[i] == 4) u = i;
    vector <int> a = g[u];
    for (int i = 0; i < 4; ++i) {
        if (haveroot(a[i], u)) {
            swap(a[0], a[i]);
            break;
        }   
    }   
    if (!haveroot(a[0], u)) return;
    int mx = 0;
    for (int i = 1; i < 4; ++i) mx = max(mx, geth(a[i], u));
    for (int i = 1; i < 4; ++i) {
        if (geth(a[i], u) == mx) {
            swap(a[1], a[i]); break;
        }   
    }   
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (pw[i] == 2) {
            root = i;
            break;
        }   
    }   
    /*
    cout << root << ' ' << P - 1 << ' ' << u << '\n';
    cout << check(a[1], u, mx) << ' ' << check(a[2], u, mx - 1) << ' ' <<  check(a[3], u, mx - 1) << ' ' << check_del(root, root, P - 1, u) << '\n';
    */
    if (check(a[1], u, mx) && check(a[2], u, mx - 1) && check(a[3], u, mx - 1) && check_del(root, root, P - 1, u)) ans.app(u);
}
void dfs(int u, int p) {
    cnt[u] = 1;
    for (int v : g[u]) if (v != p) { dfs(v, u); cnt[u] += cnt[v]; }
}   
bool check(int u, int v) {
    return check(u, v, P - 2) && check(v, u, P - 2);
}   
void solve() {
    dfs(1, 1);
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            if (cnt[v] == n / 2 && check(u, v)) {
                ans = {u, v};
                return;
            }   
        }   
    }   
}   
ii jfs(int u, int p, int h) {
    vector <int> to;
    for (int v : g[u]) if (v != p) to.app(v);
    if (h == 1 && to.size() == 1 && check(to[0], u, 0)) return {1, u};
    if (h == 0) {
        if (to.empty()) return {0, -1};
        else return {2, -1};
    }   
    if (to.size() != 2) return {2, -1};
    auto l = jfs(to[0], u, h - 1), r = jfs(to[1], u, h - 1);    
    if (l.f == 0 && r.f == 0) return {0, -1};
    if (l.f == 1 && r.f == 0) return {1, l.s};
    if (r.f == 1 && l.f == 0) return {1, r.s};
    return {2, -1};
}   
void mem() {
    vector <int> r;
    for (int i = 1; i <= n; ++i) if (pw[i] == 2) r.app(i);
    if (r.size() != 2) return;           
    for (int root : r) {
        auto t = jfs(root, root, P - 1);
        if (t.f == 1) ans.app(t.s);
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> P; n = (1 << P) - 2;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
        ++pw[u]; ++pw[v];
    }   
    int mx = 0;
    for (int i = 1; i <= n; ++i) mx = max(mx, pw[i]);
    if (mx > 4) {
        cout << "0\n";
        exit(0);
    }   
    else if (mx == 4) solve4();
    else {
        solve();
        mem();
    }
    sort(all(ans)); ans.resize(unique(all(ans)) - ans.begin());
    cout << ans.size() << '\n';
    for (int e : ans) cout << e << ' '; cout << '\n';
}