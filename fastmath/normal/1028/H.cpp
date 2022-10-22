#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int MAXM = 5e6 + MAXN;
const int INF = 1e9 + 7;
const int K = 8;
const int WANT = MAXN * 2 * K * 20;
const int MAXMEM = WANT * 4 / 5;

vector <int> d[MAXM];
bool ch[MAXM];

void precalc() {
    for (int i = 0; i < MAXM; ++i) ch[i] = 1;
    for (int i = 2; i < MAXM; ++i) {
        if (ch[i]) {
            d[i].push_back(i);
            for (int j = i * 2; j < MAXM; j += i) {
                ch[j] = 0;
                d[j].push_back(i);
            }
        }
    }
}

int n, q;
int a[MAXN];

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int e : d[a[i]]) {
            int cnt = 0;
            int t = a[i];
            while (t % e == 0) {
                ++cnt;
                t /= e;
            }
            for (int j = 0; j < cnt; ++j) a[i] /= e;
            if (cnt % 2) a[i] *= e;
        }
    }
}

int dp[MAXM][K];
int mr[MAXN][2 * K];

struct Node {
    int mn;
    int l, r;
};

int cur = 0;
Node mem[MAXMEM];

int newnode() {
    mem[cur].mn = INF;
    mem[cur].l = mem[cur].r = -1;
    ++cur;
    return cur - 1;
}

int build(int tl, int tr) {
    int nt = newnode();
    if (tl == tr) return nt;
    int tm = (tl + tr) / 2;
    mem[nt].l = build(tl, tm);
    mem[nt].r = build(tm + 1, tr);
    return nt;
}

int upd(int t, int tl, int tr, int p, int x) {
    int nt = newnode();

    if (tl == tr) {
        mem[nt].mn = min(mem[t].mn, x);
        return nt;
    }

    int tm = (tl + tr) / 2;
    if (p <= tm) {
        mem[nt].l = upd(mem[t].l, tl, tm, p, x);
        mem[nt].r = mem[t].r;
    }
    else {
        mem[nt].l = mem[t].l;
        mem[nt].r = upd(mem[t].r, tm + 1, tr, p, x);
    }

    mem[nt].mn = min(mem[mem[nt].l].mn, mem[mem[nt].r].mn);
    return nt;
}

int get(int t, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return mem[t].mn;
    int tm = (tl + tr) / 2;
    return min(get(mem[t].l, tl, tm, l, r), get(mem[t].r, tm + 1, tr, l, r));
}

int tree[MAXN];

void build() {
    tree[0] = build(0, n - 1);
    for (int i = 0; i < n; ++i) {
        tree[i + 1] = tree[i];
        for (int cost = 0; cost < 2 * K; ++cost) {
            int l = mr[i][cost];
            if (l == -INF) continue;
            tree[i + 1] = upd(tree[i + 1], 0, n - 1, l, cost);
        }
    }
}

void get(int p) {
    for (int i = 0; i < 2 * K; ++i) mr[p][i] = -INF;
    int sz = d[a[p]].size();
    for (int mask = 0; mask < (1 << sz); ++mask) {
        int f = 1;
        for (int i = 0; i < sz; ++i) {
            if ((mask >> i) & 1) f *= d[a[p]][i];
        }
        int add = sz - __builtin_popcount(mask);
        for (int i = 0; i < K; ++i) {
            int cost = add + i;
            mr[p][cost] = max(mr[p][cost], dp[f][i]);
        }
    }
}

void add(int p) {
    int sz = d[a[p]].size();
    for (int mask = 0; mask < (1 << sz); ++mask) {
        int f = 1;
        for (int i = 0; i < sz; ++i) {
            if ((mask >> i) & 1) f *= d[a[p]][i];
        }
        int cost = sz - __builtin_popcount(mask);
        dp[f][cost] = p;
    }
}

void solve() {
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 0; j < K; ++j) {
            dp[i][j] = -INF;
        }
    }
    for (int i = 0; i < n; ++i) {
        get(i);
        add(i);
    }
    build();
}

int get(int l, int r) {
    return get(tree[r + 1], 0, n - 1, l, r);
}

void print() {
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r; --l; --r;
        cout << get(l, r) << '\n';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    precalc();
    read();
    solve();
    print();

    return 0;
}