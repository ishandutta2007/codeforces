#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

const int N = 1e5 + 7;
const int K = 20;

vector <int> g[N];
int go[K][N];
int tin[N], tout[N];

int timer = 0;

void dfs(int u, int p = 0) {
    tin[u] = timer++;
    go[0][u] = p;
    for (int i = 1; i < K; ++i) {
        go[i][u] = go[i - 1][go[i - 1][u]];
    }
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (anc(a, b)) return a;
    if (anc(b, a)) return b;
    for (int i = K - 1; i >= 0; --i) {
        if (!anc(go[i][a], b)) {
            a = go[i][a];
        }
    }
    return go[0][a];
}

int f[N];

void modify(int x, int val) {
    for (int i = x; i < N; i |= (i + 1)) f[i] += val;
}

int get(int r) {
    int res = 0;
    for (int i = r; i >= 0; i &= i + 1, --i) {
        res += f[i];
    }
    return res;
}

void add(int x) {
    modify(tin[x], 1);
    modify(tout[x], -1);
}

void del(int x) {
    modify(tin[x], -1);
    modify(tout[x], 1);
}

int sum(int x) {
    return get(tin[x]);
}

int get(int x, int root) {
    int a = lca(x, root);
    return sum(x) + sum(root) - sum(a) - (go[0][a] == a ? 0 : sum(go[0][a])) - 1;
}

int h[N];
const int M = 307;

int dp[N][M];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    while (q--) {
        int k, m, r;
        cin >> k >> m >> r;
        --r;
        vector <int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            --a[i];
            add(a[i]);
        }

        for (int i = 0; i < k; ++i) h[a[i]] = get(a[i], r);
        sort(a.begin(), a.end(), [&] (int i, int j) {
            return h[i] < h[j];
        });

        dp[0][0] = 1;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = 0;
                add(dp[i][j], mul(dp[i - 1][j], j - h[a[i - 1]]));
                add(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        int ans = 0;
        for (int j = 1; j <= m; ++j) add(ans, dp[k][j]);
        cout << ans << '\n';

        for (int i = 0; i < k; ++i) {
            del(a[i]);
        }
    }
}