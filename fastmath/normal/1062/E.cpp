#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n, q;
vector <int> g[MAXN];
void read() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
}

int h[MAXN];
int tl[MAXN], tr[MAXN];
vector <int> e;
void dfs(int u, int parent, int d) {
    h[u] = d;
    tl[u] = e.size();
    e.push_back(u);
    for (int v : g[u]) {
        dfs(v, u, d + 1);
        e.push_back(u);
    }   
    tr[u] = e.size() - 1;
}   

const int LG = 21;

inline int mmin(int u, int v) {
    if (h[u] < h[v]) return u;
    else return v;
}   

int pw[MAXN << 2];
int sp[LG][MAXN << 2];
void build() {
    int n = e.size();
    for (int i = 0; i < n; ++i) {
        sp[0][i] = e[i];
    }   
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i + (1 << p) - 1 < n; ++i) {
            sp[p][i] = mmin(sp[p - 1][i], sp[p - 1][i + (1 << (p - 1))]);
        }   
    }   
    int curr = 0;
    for (int i = 0; i < (MAXN << 2); ++i) {
        if ((1 << (curr + 1)) < i) ++curr;
        pw[i] = curr;
    }   
}   

inline int lca(int u, int v) {
    if (u == -1) return v;
    if (v == -1) return u;
    int l = min(tl[u], tl[v]);
    int r = max(tr[u], tr[v]);
    int p = pw[r - l + 1];      
    return mmin(sp[p][l], sp[p][r - (1 << p) + 1]);
}   

int minl(int u, int v) {
    if (tl[u] < tl[v]) return u;
    else return v;
}   

int minr(int u, int v) {
    if (tr[u] > tr[v]) return u;
    else return v;
}   

int sp1[LG][MAXN], spl[LG][MAXN], spr[LG][MAXN];
void build1() {
    for (int i = 0; i < n; ++i) {
        sp1[0][i] = i;
    }   
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i + (1 << p) - 1 < n; ++i) {
            sp1[p][i] = lca(sp1[p - 1][i], sp1[p - 1][i + (1 << (p - 1))]);
        }   
    }   

    for (int i = 0; i < n; ++i) {
        spl[0][i] = i;
    }   
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i + (1 << p) - 1 < n; ++i) {
            spl[p][i] = minl(spl[p - 1][i], spl[p - 1][i + (1 << (p - 1))]);
        }   
    }   

    for (int i = 0; i < n; ++i) {
        spr[0][i] = i;
    }   
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i + (1 << p) - 1 < n; ++i) {
            spr[p][i] = minr(spr[p - 1][i], spr[p - 1][i + (1 << (p - 1))]);
        }   
    }   
}

void solve() {
    dfs(0, 0, 0);
    build();
    build1();
}

int getlca(int l, int r) {
    if (r < l) return -1;
    int p = pw[r - l + 1];
    return lca(sp1[p][l], sp1[p][r - (1 << p) + 1]);
}   

int get(int l, int r, int i) {
    return lca(getlca(l, i - 1), getlca(i + 1, r));
}

int getl(int l, int r) {
    int p = pw[r - l + 1];
    return minl(spl[p][l], spl[p][r - (1 << p) + 1]);
}

int getr(int l, int r) {
    int p = pw[r - l + 1];
    return minr(spr[p][l], spr[p][r - (1 << p) + 1]);
}   
   
void print() {
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;

        int wl = getl(l, r);
        int wr = getr(l, r);
        
        int ans1 = get(l, r, wl);
        int ans2 = get(l, r, wr);

        if (h[ans1] > h[ans2]) {
            cout << wl + 1 << ' ' << h[ans1] << '\n';
        }
        else {
            cout << wr + 1 << ' ' << h[ans2] << '\n';
        }
    }
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