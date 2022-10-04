#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1e7 + 11, md = 1e9 + 7;
const int K = 20;
const int L = 1e5 + 7;

vector <int> g[L];
int n, q;
int d[N];
int ans[L], l[L], r[L], qLca[L], val[L];
vector <pair <int, int>> queries[N], nodes[N];
pair <int, int> vert[L];

int go[K][L];

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int t = mpow(a, n / 2);
        return mul(t, t);
    }
    else {
        return mul(a, mpow(a, n - 1));
    }
}

void init() {
    for (int i = 0; i < N; ++i) d[i] = -1;
    for (int i = 2; i * i < N; ++i) {
        if (d[i] == -1) {
            d[i] = i;
            for (int j = i * i; j < N; j += i) if (d[j] == -1) d[j] = i;
        }
    }
    for (int i = 0; i < L; ++i) ans[i] = 1;
}

int timer = 0;

void dfs(int u, int p = 0) {
    go[0][u] = p;
    for (int i = 1; i < K; ++i) {
        go[i][u] = go[i - 1][go[i - 1][u]];
    }
    l[u] = timer++;
    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
    r[u] = timer++;
}

bool anc(int a, int b) {
    return l[a] <= l[b] && r[b] <= r[a];
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

struct fenwick {
    int n;
    vector <int> f;
    fenwick(int nn) {
        n = nn;
        f.resize(n);
    }
    fenwick() {}
    void init(int nn) {
        n = nn;
        f.resize(n);
    }
    int sum(int r) {
        int res = 0;
        for (int i = r; i >= 0; i &= (i + 1), --i) {
            res += f[i];
        }
        return res;
    }
    void modify(int ind, int v) {
        for (int i = ind; i < n; i |= (i + 1)) {
            f[i] += v;
        }
    }
    int get(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void clear() {
        for (int i = 0; i < n; ++i) {
            f[i] = 0;
        }
    }
} f;

int pathSum(int i) {
    int u = vert[i].first, v = vert[i].second, a = qLca[i];
    return f.get(0, l[u]) + f.get(0, l[v]) - 2 * f.get(0, l[a]) + val[a];
}

void vertModify(int u, int x) {
    f.modify(l[u], x);
    f.modify(r[u], -x);
    val[u] += x;
}

void read() {
    cin >> n;
    f.init(2 * n + 228);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    vector <pair <int, int>> f;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (x != 1) {
            int cur = d[x];
            if (f.empty() || f.back().first != cur) {
                f.push_back({cur, 1});
            }
            else {
                ++f.back().second;
            }
            x /= cur;
        }
        for (auto &p : f) {
            nodes[p.first].push_back({p.second, i});
        }
        f.clear();
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        vert[i] = {u, v};
        qLca[i] = lca(u, v);
        while (x != 1) {
            int cur = d[x];
            if (f.empty() || f.back().first != cur) {
                f.push_back({cur, 1});
            }
            else {
                ++f.back().second;
            }
            x /= cur;
        }
        for (auto &p : f) {
            queries[p.first].push_back({p.second, i});
        }
        f.clear();
    }
    for (int i = 0; i < N; ++i) {
        sort(nodes[i].rbegin(), nodes[i].rend());
        sort(queries[i].begin(), queries[i].end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    read();
    for (int i = 0; i < N; ++i) {
        if (!queries[i].empty()) {
            int uk = 0;
            for (int j = 1; j <= queries[i].back().first; ++j) {
                for (int t = 0; t < nodes[i].size() && nodes[i][t].first >= j; ++t) {
                    vertModify(nodes[i][t].second, 1);
                }
                while (uk < queries[i].size() && queries[i][uk].first == j) {
                    ans[queries[i][uk].second] = mul(ans[queries[i][uk].second], mpow(i, pathSum(queries[i][uk].second)));
                    ++uk;
                }
            }
            for (int j = 1; j <= queries[i].back().first; ++j) {
                for (int t = 0; t < nodes[i].size() && nodes[i][t].first >= j; ++t) {
                    vertModify(nodes[i][t].second, -1);
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}