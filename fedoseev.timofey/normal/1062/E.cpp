#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
const int K = 20;

int tin[N], tout[N];
int go[K][N];
int h[N];

int timer = 0;

vector <int> g[N];

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void dfs(int u = 0, int p = 0) {
    h[u] = (u == 0 ? 0 : h[p] + 1);
    tin[u] = timer++;
    go[0][u] = p;
    for (int k = 1; k < K; ++k) {
        go[k][u] = go[k - 1][go[k - 1][u]];
    }
    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer++;
}   

int lca(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    if (anc(a, b)) return a;
    for (int k = K - 1; k >= 0; --k) {
        if (!anc(go[k][a], b)) {
            a = go[k][a];
        }
    }
    return go[0][a];
}


struct SparseTable {
    int n, k;
    vector <vector <int>> ST;
    vector <int> lg;
 
    void init(vector <int> a) {
        n = a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
        k = 0;
        while ((1 << k) <= n) ++k;
        ++k;
 
        ST.resize(k, vector <int> (n, -1));
        for (int i = 0; i < n; ++i) {
            ST[0][i] = a[i];
        }
        for (int j = 1; j < k; ++j) {
            for (int i = 0; i < n; ++i) {
                ST[j][i] = ST[j - 1][i];
                if (i + (1 << (j - 1)) < n) {
                    ST[j][i] = lca(ST[j][i], ST[j - 1][i + (1 << (j - 1))]);
                }
            }
        }
    }
    int get(int l, int r) {
        int x = lg[r - l + 1];
        return lca(ST[x][l], ST[x][r - (1 << x) + 1]);
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    dfs();
    vector <int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i;
    SparseTable mem;
    mem.init(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int u = mem.get(l, r);
        int low = l - 1;
        int high = r;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (mem.get(l, mid) == u) high = mid;
            else low = mid;
        }
        int l1 = -1;
        if (high == l) {
            l1 = h[mem.get(l + 1, r)];
        }
        else if (high == r) {
            l1 = h[mem.get(l, r - 1)];
        }
        else {
            l1 = h[lca(mem.get(l, high - 1), mem.get(high + 1, r))];
        }
        int l2 = h[mem.get(l + 1, r)];
        if (l2 > l1) {
            cout << l + 1 << ' ' << l2 << '\n';
        }
        else {
            cout << high + 1 << ' ' << l1 << '\n';
        }
    }
}