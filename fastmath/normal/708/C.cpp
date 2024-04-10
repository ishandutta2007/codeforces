#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 7;
const int LG = 20;

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

int go[MAXN][LG];
int cnt[MAXN], par[MAXN];
void dfs1(int u, int parent) {
    go[u][0] = parent;
    for (int i = 1; i < LG; ++i) {
        go[u][i] = go[go[u][i - 1]][i - 1];
    }

    cnt[u] = 1;
    par[u] = parent;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
    }
}

int dp[MAXN];
void dfs2(int u, int parent) {
    dp[u] = -1;
    if (cnt[u] <= n / 2) dp[u] = cnt[u];
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs2(v, u);
        dp[u] = max(dp[u], dp[v]);
    }
}

int up[MAXN];
void dfs3(int u, int parent, int curr) {  
    up[u] = curr;
    multiset <int> ms;
    for (int v : g[u]) {
        if (v == parent) continue;
        ms.insert(dp[v]);
    }
    for (int v : g[u]) {
        if (v == parent) continue;
        ms.erase(ms.find(dp[v]));
        int tmp = -1;
        if (ms.size()) tmp = *ms.rbegin();
        dfs3(v, u, max(curr, tmp));
        ms.insert(dp[v]);
    }
}

int get(int u) {
    int add = -cnt[u];
    for (int i = LG - 1; i >= 0; --i) {
        if (cnt[go[u][i]] + add <= n / 2) u = go[u][i];
    }
    return cnt[u] + add;
}

void solve() {
    dfs1(0, 0);
    dfs2(0, 0);
    dfs3(0, 0, -1);
    for (int i = 0; i < n; ++i) {
        up[i] = max(up[i], get(i));
    }
}

void print() {
    for (int u = 0; u < n; ++u) {
        int mx = -1;
        for (int v : g[u]) {
            if (v == par[u]) continue;
            if (mx == -1 || cnt[mx] < cnt[v]) mx = v;
        }
        if ((mx == -1 || cnt[mx] <= n / 2) && n - cnt[u] <= n / 2) {
            cout << "1 ";
        }
        else if (mx != -1 && cnt[mx] > n / 2) {
            if (cnt[mx] - dp[mx] > n / 2) {
                cout << "0 ";
            }
            else {
                cout << "1 ";
            }
        }
        else if (n - cnt[u] > n / 2) {
            if (n - cnt[u] - up[u] > n / 2) {
                cout << "0 ";
            }
            else {
                cout << "1 ";
            }
        }
    }
    cout << '\n';
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