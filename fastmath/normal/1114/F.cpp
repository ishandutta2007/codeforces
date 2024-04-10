#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5 + 7;
const int Q = N >> 1;
const int MOD = 1000 * 1000 * 1000 + 7;
const int C = 301;
const int P = 63;
inline int mod(int n) {
    if (0 <= n && n < MOD) return n;
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int n, int pw) {
    int curr = n;
    int ans = 1;
    for (int p = 0; (1ll << p) <= pw; ++p) {
        if ((pw >> p) & 1) {
            ans = mod(ans * curr);
        }   
        curr = mod(curr * curr);
    }
    return ans;
}   
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
int n, q;
int a[N];
vector <int> pr;
bool is_pr[C];
vector <int> rv[C];
int num[C];
void prec() {
    for (int i = 2; i < C; ++i) {
        is_pr[i] = 1;
    }   
    for (int i = 2; i < C; ++i) {
        if (is_pr[i]) {
            num[i] = pr.size();
            pr.push_back(i);
            rv[i] = {i};
            for (int j = 2 * i; j < C; j += i) {
                is_pr[j] = 0;
                rv[j].push_back(i);
            }   
        }   
    }
}

int tree[N << 2];   
int add[N << 2];
void push(int v) {
    if (add[v]) {
        tree[v * 2 + 1] |= add[v];
        tree[v * 2 + 2] |= add[v];
        add[v * 2 + 1] |= add[v];
        add[v * 2 + 2] |= add[v];
        add[v] = 0;
    }   
}   
void upd(int v, int tl, int tr, int l, int r, int mask) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        tree[v] |= mask;
        add[v] |= mask;
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, mask); upd(v * 2 + 2, tm + 1, tr, l, r, mask);
    tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
}   
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    push(v);
    return get(v * 2 + 1, tl, tm, l, r) | get(v * 2 + 2, tm + 1, tr, l, r);
}   

int ftree[N << 2];
int fadd[N << 2];

void fpush(int v, int tl, int tr) {
    if (fadd[v] != 1) {
        int tm = (tl + tr) >> 1;
        fadd[v * 2 + 1] = mod(fadd[v * 2 + 1] * fadd[v]);
        fadd[v * 2 + 2] = mod(fadd[v * 2 + 2] * fadd[v]);
        ftree[v * 2 + 1] = mod(ftree[v * 2 + 1] * fp(fadd[v], tm - tl + 1));
        ftree[v * 2 + 2] = mod(ftree[v * 2 + 2] * fp(fadd[v], tr - tm));
        fadd[v] = 1;
    }   
}   

void fupd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        fadd[v] = mod(fadd[v] * x);
        ftree[v] = mod(ftree[v] * fp(x, tr - tl + 1));
        return;
    }   
    int tm = (tl + tr) >> 1;
    fpush(v, tl, tr);
    fupd(v * 2 + 1, tl, tm, l, r, x); fupd(v * 2 + 2, tm + 1, tr, l, r, x);
    ftree[v] = mod(ftree[v * 2 + 1] * ftree[v * 2 + 2]);
}   

int fget(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 1;
    if (l <= tl && tr <= r) return ftree[v];
    int tm = (tl + tr) >> 1;
    fpush(v, tl, tr);
    return mod(fget(v * 2 + 1, tl, tm, l, r) * fget(v * 2 + 2, tm + 1, tr, l, r));
}   

int f[Q];
string type[Q];
int l[Q], r[Q], x[Q];
int inv[C];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    
    for (int i = 0; i < C; ++i) {
        inv[i] = fp(i, MOD - 2);
    }   

    prec();
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> type[i] >> l[i] >> r[i];
        --l[i]; --r[i];
        if (type[i][0] == 'M') cin >> x[i];
    }   

    for (int i = 0; i < (N << 2); ++i) ftree[i] = fadd[i] = 1;
    for (int i = 0; i < n; ++i) {
        fupd(0, 0, n - 1, i, i, a[i]);
    }   
    for (int i = 0; i < q; ++i) {
        if (type[i][0] == 'M') {
            fupd(0, 0, n - 1, l[i], r[i], x[i]);
        }
        else {
            f[i] = fget(0, 0, n - 1, l[i], r[i]);
        }   
    }   

    #ifdef HOME
        cerr << "TIME " << (double)clock() / CLOCKS_PER_SEC << '\n';
    #endif
    
    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int p : rv[a[i]]) {
            mask |= 1ll << num[p];
        }   
        upd(0, 0, n - 1, i, i, mask);
    }   
    for (int i = 0; i < q; ++i) {
        if (type[i][0] == 'M') {
            int mask = 0;
            for (int p : rv[x[i]]) {
                mask |= 1ll << num[p];
            }   
            upd(0, 0, n - 1, l[i], r[i], mask);
        }
        else {
            int mask = get(0, 0, n - 1, l[i], r[i]);
            for (int ii = 0; ii < P; ++ii) {
                if ((mask >> ii) & 1) {
                    f[i] = mod(f[i] - mod(f[i] * inv[pr[ii]]));
                }   
            }   
        }   
    }   

    for (int i = 0; i < q; ++i) {
        if (type[i][0] != 'M') {
            cout << f[i] << '\n';
        }
    }   
    #ifdef HOME
        cerr << "TIME " << (double)clock() / CLOCKS_PER_SEC << '\n';
    #endif
}