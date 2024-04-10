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
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int ans = 0;
int cnt[MAXN];
int add[MAXN];
int sum0[MAXN], sum1[MAXN];
vector <int> d0[MAXN], d1[MAXN];

void add_(int u, int d) {
    if (d % 2 == add[u] % 2) {
        ans += (d * d0[u].size() + sum0[u]) / 2;
        ans += (d * d1[u].size() + sum1[u] + d1[u].size()) / 2;
    }
    else {
        ans += (d * d0[u].size() + sum0[u] + d0[u].size()) / 2;
        ans += (d * d1[u].size() + sum1[u]) / 2;
    }
}

void upd_(int u, int d) {
    if (d % 2 == add[u] % 2) {
        d0[u].push_back(d - add[u]);
        sum0[u] += d;
    }
    else {
        d1[u].push_back(d - add[u]);
        sum1[u] += d;
    }   
}

void dfs(int u, int parent) {
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    int mx = -1;
    for (int v : g[u]) {
        if (v == parent) continue;
        if (mx == -1 || cnt[mx] < cnt[v]) mx = v;
    }
    if (mx != -1) {
        swap(d0[mx], d0[u]);
        swap(d1[mx], d1[u]);
        swap(sum0[mx], sum0[u]);
        swap(sum1[mx], sum1[u]);
        sum0[u] += d0[u].size();
        sum1[u] += d1[u].size();
        add[u] = add[mx] + 1;
    }
    add_(u, 0);
    upd_(u, 0);
    for (int v : g[u]) {
        if (v == parent || v == mx) continue;
        for (int &e : d0[v]) e += add[v] + 1;
        for (int &e : d1[v]) e += add[v] + 1;
        add[v] = 0;
        for (int e : d0[v]) add_(u, e);
        for (int e : d1[v]) add_(u, e);
        for (int e : d0[v]) upd_(u, e);
        for (int e : d1[v]) upd_(u, e);
    }
}

void solve() {
    dfs(0, 0);
}

void print() {
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}