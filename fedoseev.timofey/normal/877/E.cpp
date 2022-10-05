# include <iostream>
# include <vector>

using namespace std;

const int Maxn = 200007;
int timer = 1;

int l[Maxn];
int r[Maxn];
vector <int> g[Maxn];
int a[Maxn];

void dfs(int u, int p) {
    l[u] = timer;
    timer++;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    r[u] = timer - 1;
}

struct segment_tree {
    int t[4 * Maxn], mod[4 * Maxn];
    
    void inv(int v, int l, int r) {
        t[v] = (r - l + 1) - t[v];
        mod[v] ^= 1;
    }
    
    void push(int v, int l, int r) {
        if (mod[v]) {
            int m = (l + r) >> 1;
            inv(2 * v, l, m);
            inv(2 * v + 1, m + 1, r);
            mod[v] = false;
        }
    }
    
    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
        }
        else {
            int m = (l + r) >> 1;
            build(2 * v, l, m);
            build(2 * v + 1, m + 1, r);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    void inv(int v, int ql, int qr, int l, int r) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr)
            inv(v, l, r);
        else {
            push(v, l, r);
            int m = (l + r) >> 1;
            inv(2 * v, ql, qr, l, m);
            inv(2 * v + 1, ql, qr, m + 1, r);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    int get(int v, int ql, int qr, int l, int r) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[v];
        push(v, l, r);
        int m = (l + r) >> 1;
        return get(2 * v, ql, qr, l, m) + get(2 * v + 1, ql, qr, m + 1, r);
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[l[i]] = x;
    }
    segment_tree tree;
    tree.build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        int v;
        cin >> v;
        if (s == "pow") {
            tree.inv(1, l[v], r[v], 1, n);
        }
        else
            cout << tree.get(1, l[v], r[v], 1, n) << endl;
    }
}