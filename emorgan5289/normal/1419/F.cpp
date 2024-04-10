#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename it1, typename it2, typename cmp = less<>>
void compress(it1 first, it1 last, it2 result, cmp ord = less<>()) {
    using T = typename remove_reference<decltype(*first)>::type;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [_, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
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

const int N = 1005;
ll n, x[N], y[N], cx[N], cy[N];
vector<int> mx[N], my[N];
dsu uf(0);

bool check3(ll t) {
    for (int i = 0; i < n; i++)
        mx[i].clear();
    for (int i = 0; i < n; i++)
        mx[cx[i]].pb(i);
    for (int i = 0; i < n; i++) {
        sort(all(mx[i]),[&](int a, int b){return y[a] < y[b];});
        for (int j = 0; j < int(mx[i].size())-1; j++)
            for (int k = 0; k < n; k++)
                if (!uf.query(mx[i][j], k) && !uf.query(mx[i][j+1], k) && !uf.query(mx[i][j], mx[i][j+1])) {
                    if (abs(x[mx[i][j]]-x[k]) <= t && abs(y[k]-y[mx[i][j]]) <= t && abs(y[k]-y[mx[i][j+1]]) <= t)
                        return 1;
                }
    }
    return 0;
}

bool check4(ll t) {
    for (int i = 0; i < n; i++) {
        mx[i].clear();
        my[i].clear();
    }
    for (int i = 0; i < n; i++) {
        mx[cx[i]].pb(i);
        my[cy[i]].pb(i);
    }
    for (int i = 0; i < n; i++) {
        sort(all(mx[i]),[&](int a, int b){return y[a] < y[b];});
        sort(all(my[i]),[&](int a, int b){return x[a] < x[b];});
    }
    for (int i = 0; i < n; i++)
        for (int i1 = 0; i1 < int(mx[i].size())-1; i1++)
            for (int j = 0; j < n; j++)
                for (int j1 = 0; j1 < int(my[j].size())-1; j1++) {
                    int a = mx[i][i1], b = mx[i][i1+1];
                    int c = my[j][j1], d = my[j][j1+1];
                    if (uf.query(a, b)) continue;
                    if (uf.query(a, c)) continue;
                    if (uf.query(a, d)) continue;
                    if (uf.query(b, c)) continue;
                    if (uf.query(b, d)) continue;
                    if (uf.query(c, d)) continue;
                    if (abs(x[a]-x[c]) <= t && abs(x[a]-x[d]) <= t && abs(y[c]-y[a]) <= t && abs(y[c]-y[b]) <= t) {
                        debug(a, b, c, d);
                        return 1;
                    }
                }
    return 0;
}

bool check(ll t) {
    ll c = n;
    uf = dsu(n);
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if ((x[i] == x[j] && abs(y[i]-y[j]) <= t || y[i] == y[j] && abs(x[i]-x[j]) <= t) && !uf.query(i, j))
                c--, uf.unite(i, j);
    debug(t, c);
    if (c == 1) return 1;
    if (c == 2) {
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                if (uf.query(i, j)) continue;
                if (abs(y[i]-y[j]) <= t && abs(x[i]-x[j]) <= t)
                    return 1;
                if (abs(y[i]-y[j]) <= 2*t && x[i] == x[j])
                    return 1;
                if (abs(x[i]-x[j]) <= 2*t && y[i] == y[j])
                    return 1;
            }
    }
    if (c == 3) {
        if (check3(t)) return 1;
        for (int i = 0; i < n; i++)
            swap(x[i], y[i]), swap(cx[i], cy[i]);
        if (check3(t)) return 1;
    }
    if (c == 4) {
        return check4(t);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    compress(x, x+n, cx);
    compress(y, y+n, cy);
    ll t = (1ll<<32)-1;
    for (ll i = 1ll<<31; i > 0; i /= 2)
        if (check(t-i)) t -= i;
    cout << (t == (1ll<<32)-1 ? -1 : t) << "\n";
}