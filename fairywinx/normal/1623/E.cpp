#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 2e5 + 228;

int timer = 0;
int tin[N];
int k;
pair<int, int> G[N];
string s;
string val;

void dfs_start(int v) {
    if (G[v].first != -1)
        dfs_start(G[v].first);
    tin[v] = timer++;
    val += s[v];
    if (G[v].second != -1)
        dfs_start(G[v].second);
}

vector<int> nxt;
int pr[N];
string ans;

int dfs_tmp(int v) {
    int res = N;
    if (G[v].first != -1) {
        res = dfs_tmp(G[v].first) + 1;
    }
    if (val[nxt[tin[v]]] > s[v])
        res = 1;
    if (G[v].second != -1)
        dfs_tmp(G[v].second);
    return pr[v] = res;
}

void dfs_ans(int v, bool can = true) {
    if (k >= pr[v] && can) {
        --k;
        if (G[v].first != -1)
            dfs_ans(G[v].first, can);
        ans += s[v];
        ans += s[v];
        if (!k)
            can = false;
        if (G[v].second != -1)
            dfs_ans(G[v].second, can);
    } else {
        if (G[v].first != -1)
            dfs_ans(G[v].first, false);
        ans += s[v];
        if (G[v].second != -1)
            dfs_ans(G[v].second, false);
    }
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[i].first = a - 1, G[i].second = b - 1;
    }
    dfs_start(0);
    val += ('a' - 1);
    nxt.resize(val.size());
    for (int i = (int) nxt.size() - 2; i >= 0; --i) {
        if (val[i] != val[i + 1])
            nxt[i] = i + 1;
        else
            nxt[i] = nxt[i + 1];
    }
    dfs_tmp(0);
    dfs_ans(0);
    cout << ans << '\n';
}