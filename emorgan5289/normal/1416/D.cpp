#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct unionfind {

    vector<int> p, sz;

    unionfind(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a != b) p[b] = a, sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

struct segtree {

    using node = array<int, 2>;

    node combine(node x, node y) {
        return max(x, y);
    }

    constexpr static node identity = {-1, -1};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<node>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void set(int i, node x) {
        tree[n+i] = x;
        for (i = (n+i)/2; i > 0; i /= 2)
            tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

const int N = 5e5;
int p[N], ve[N], l[2*N], r[2*N], rep[2*N], rt[2*N], vis[2*N];
array<int, 2> e[N], qry[2*N];
unionfind uf(N);
int vin[2*N], vout[2*N], t = 0;
int n, m, q;

void dfs(int i) {
    vin[i] = t++;
    if (i >= n) dfs(l[i-n]), dfs(r[i-n]);
    vout[i] = t-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < m; i++)
        cin >> e[i][0] >> e[i][1], e[i][0]--, e[i][1]--;
    for (int i = 0; i < q; i++) {
        cin >> qry[i][0] >> qry[i][1], qry[i][1]--;
        if (qry[i][0] == 2) ve[qry[i][1]] = 1;
    }
    for (int i = 0; i < m; i++)
        if (!ve[i]) qry[q++] = {2, i};
    iota(rep, rep+n, 0);
    for (int i = q-1; i >= 0; i--) {
        if (qry[i][0] == 1) {
            rt[i] = rep[uf.rep(qry[i][1])];
        } else {
            auto [x, y] = e[qry[i][1]];
            if (uf.query(x, y)) continue;
            l[i] = rep[uf.rep(x)], r[i] = rep[uf.rep(y)];
            uf.unite(x, y);
            rep[uf.rep(x)] = n+i;
        }
    }
    for (int i = 0; i < n; i++)
        if (!vis[rep[uf.rep(i)]]) {
            dfs(rep[uf.rep(i)]);
            vis[rep[uf.rep(i)]] = 1;
        }
    vector<array<int, 2>> v(2*N, {-1, -1});
    for (int i = 0; i < n; i++)
        v[vin[i]] = {p[i], i};
    segtree s(v);
    for (int i = 0; i < q; i++)
        if (qry[i][0] == 1) {
            int x = vin[rt[i]], y = vout[rt[i]];
            auto node = s.query(x, y);
            cout << node[0] << "\n";
            s.set(vin[node[1]], {0, node[1]});
        }
}