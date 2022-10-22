#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define u first
#define v second
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 5e5+7;

int a[N];
int l[N], r[N], nxt[N], par[N];
ii ed[N], d[N];
bool del[N];
ii seg[N]; //corner vertices

int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);
}   

ii mx[N << 2];

void build(int v, int tl, int tr, vector <int> &vals) {
    if (tl == tr) {
        mx[v] = mp(vals[tl], tl);
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, vals);
    build(v * 2 + 2, tm + 1, tr, vals);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}   

ii get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return mp(-1, -1);
    if (l <= tl && tr <= r)
        return mx[v];
    int tm = (tl + tr) >> 1;
    return max(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));                              
}   

void del_pos(int v, int tl, int tr, int i) {
    if (tl == tr) {
        mx[v].f = 0;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (i <= tm)
        del_pos(v * 2 + 1, tl, tm, i);
    else
        del_pos(v * 2 + 2, tm + 1, tr, i);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif    
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].u >> ed[i].v;
    }           
    for (int i = 0; i < q; ++i) {
        cin >> d[i].f >> d[i].s;
        if (d[i].f == 2) {
            d[i].s--;
            del[d[i].s] = 1;
        }   
    }   

    // init l, r, nxt, par

    for (int i = 1; i <= n; ++i) {
        l[i] = r[i] = i;
        nxt[i] = 0;
        par[i] = i;
    }   

    auto add = [&] (ii e) {
        int u = root(e.u);
        int v = root(e.v);
        if (u == v)
            return;

        par[u] = v;
        nxt[r[u]] = l[v];
        l[v] = l[u];
    };

    for (int i = 0; i < m; ++i) {
        if (!del[i]) {
            add(ed[i]);
        }
    }   
    for (int i = q - 1; i >= 0; --i) {
        if (d[i].f == 2) {
            add(ed[d[i].s]);
        }   
        else {
            int c = root(d[i].v);
            seg[i] = mp(l[c], r[c]);
        }   
    }   

    vector <int> ord;
    vector <bool> in(n + 1);
    for (int i = 1; i <= n; ++i)
        if (nxt[i])
            in[nxt[i]] = 1;

    vector <int> si;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            si.app(i);

    for (int u : si) {
        while (u) {
            ord.app(u);
            u = nxt[u];
        }   
    }               
    assert(ord.size() == n);

    vector <int> pos(n + 1);
    for (int i = 0; i < n; ++i)
        pos[ord[i]] = i;

    vector <int> vals;
    for (int u : ord)
        vals.app(a[u]);

    //build segtree
    build(0, 0, n - 1, vals);

    for (int i = 0; i < q; ++i) {
        if (d[i].f == 1) {

            /*
            ii mx = mp(-1, -1);
            for (int j = pos[seg[i].u]; j <= pos[seg[i].v]; ++j) {
                int u = ord[j];
                mx = max(mx, mp(a[u], u));                
            }   
            cout << mx.f << endl;
            a[mx.s] = 0;
            */

            auto t = get(0, 0, n - 1, pos[seg[i].u], pos[seg[i].v]);
            cout << t.f << endl;
            del_pos(0, 0, n - 1, t.s);

            //cout << get(0, 0, n - 1, pos[seg[i].u], pos[seg[i].v]) << endl;
        }   
    }   
}