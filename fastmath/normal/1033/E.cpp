#include <bits/stdc++.h>

using namespace std;

const int MAXN = 607;

map <set <int>, int> d;

int quer(vector <int> v) {
    set <int> ms;
    for (int e : v) ms.insert(e);

    if ((int)ms.size() <= 1) return 0;
    
    if (d.find(ms) != d.end()) return d[ms];

    cout << "? " << ms.size() << '\n';
    for (int e : ms) cout << e + 1 << ' ';
    cout << '\n';
    fflush(stdout);

    int ans;
    cin >> ans;
    return d[ms] = ans;
}

int quer(vector <int> a, vector <int> b) {
    vector <int> v;
    for (int e : a) v.push_back(e);
    for (int e : b) v.push_back(e);
    return quer(v) - quer(a) - quer(b);
}

pair <int, int> find(vector <int> a, vector <int> b) {
    if (!quer(a, b)) return {-1, -1};

    int l, r;
    
    l = 0;
    r = (int)a.size() - 1;
    while (l != r) {
        int m = (l + r) / 2;
        vector <int> lv;
        for (int i = l; i <= m; ++i) lv.push_back(a[i]);
        vector <int> rv;
        for (int i = m + 1; i <= r; ++i) rv.push_back(a[i]);
        if (quer(lv, b)) r = m;
        else l = m + 1;
    }
    a = {a[l]};

    l = 0;
    r = (int)b.size() - 1;
    while (l != r) {
        int m = (l + r) / 2;
        vector <int> lv;
        for (int i = l; i <= m; ++i) lv.push_back(b[i]);
        vector <int> rv;
        for (int i = m + 1; i <= r; ++i) rv.push_back(b[i]);
        if (quer(a, lv)) r = m;
        else l = m + 1;
    }   
    b = {b[l]};

    return {a[0], b[0]};
}

pair <int, int> find(vector <int> v) {
    if (!quer(v)) return {-1, -1};

    vector <int> l, r;
    int m = v.size() / 2;
    for (int i = 0; i < m; ++i) l.push_back(v[i]);
    for (int i = m; i < (int)v.size(); ++i) r.push_back(v[i]);

    if (quer(l)) return find(l);
    else if (quer(r)) return find(r);
    else return find(l, r);
}

int n;
bool used[MAXN];
vector <int> g[MAXN];
void build() {
    vector <int> l = {0};
    used[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        vector <int> r;
        for (int t = 0; t < n; ++t) {
            if (!used[t]) r.push_back(t);
        }
        auto p = find(l, r);
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
        used[p.second] = 1;
        l.push_back(p.second);
    }
}

int color[MAXN];
void dfs(int u, int parent, int c) {
    color[u] = c;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, c ^ 1);
    }
}

vector <int> st;
void getp(int u, int parent, int want, vector <int> &ans) {
    st.push_back(u);
    if (u == want) ans = st;
    for (int v : g[u]) {
        if (v == parent) continue;
        getp(v, u, want, ans);
    }
    st.pop_back();
}

signed main() {
    cin >> n;

    build();

    dfs(0, 0, 0);
    
    vector <int> l, r;
    for (int i = 0; i < n; ++i) {
        if (!color[i]) l.push_back(i);
        else r.push_back(i);
    }

    auto p = find(l);
    if (p.first != -1) {
        cout << "N ";
        vector <int> v;
        getp(p.first, p.first, p.second, v);
        cout << v.size() << '\n';
        for (int e : v) cout << e + 1 << ' ';
        cout << '\n';
        exit(0);
    }

    p = find(r);
    if (p.first != -1) {
        cout << "N ";
        vector <int> v;
        getp(p.first, p.first, p.second, v);
        cout << v.size() << '\n';
        for (int e : v) cout << e + 1 << ' ';
        cout << '\n';
        exit(0);
    }

    cout << "Y " << l.size() << '\n';
    for (int e : l) cout << e + 1 << ' ';
    cout << '\n';

    return 0;
}