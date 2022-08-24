#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TEdge {
    int x;
    int id;
};

TEdge edges[3100];
int n, m;

void euler(vvi &e, vi &ptr, vi &used, int v, vi &path) {
    while (ptr[v] < e[v].size()) {
        int id = e[v][ptr[v]++];
        if (!used[id]) {
            used[id] = 1;
            euler(e, ptr, used, v ^ edges[id].x, path);
        }
    }
    path.pb(v + 1);
}

vi maybe_euler(vvi e, int v) {
    int odd = 0;
    forn(i, e.size()) {
        if (e[i].size() & 1) ++odd;
    }
    if (odd > 2) return {};
    if (odd == 2 && e[v].size() % 2 == 0) return {};
    vi ptr(n);
    vi used(m);
    vi path;
    euler(e, ptr, used, v, path);
    forn(i, n) if (ptr[i] != (int)e[i].size()) path.clear();
//    reverse(all(path));
    return path;
}

void append_store(vi &ans, int v, vi store) {
    ans.pb(-1);
    for (int id: store) {
        if (id == -1) continue;
        int u = v ^ edges[id].x;
        ans.pb(u + 1);
        ans.pb(v + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    vvi e(n);
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges[i] = {u ^ v, i};
        e[u].pb(i);
        e[v].pb(i);
    }

    vi ans;
    forn(v, n) {
        if (!ans.empty()) break;

        vvi ne(n);
        vi store;
        forn(x, n) for (int id: e[x]) {
            int y = x ^ edges[id].x;
            if (x != v && y != v) ne[x].pb(id);
        }
//        cerr << "here\n";
        for (int id: e[v]) {
            int u = v ^ edges[id].x;
            if (ne[u].size() & 1) {
                ne[v].pb(id);
                ne[u].pb(id);
            } else store.pb(id);
        }
        
        vi res;
        if (!(res = maybe_euler(ne, v)).empty()) {
            ans = res;
            append_store(ans, v, store);
        }
//        cerr << v << '\n';
        for (int &id: store) {
            if (!ans.empty()) break;
//            cerr << v << ' ' << id << '\n';
            int x = -1;

            int u = v ^ edges[id].x;
//            cerr << v << ' ' << id << ' ' << u << '\n';
            ne[v].pb(id);
            ne[u].pb(id);
            swap(id, x);
            if (!(res = maybe_euler(ne, v)).empty()) {
                ans = res;
                append_store(ans, v, store);
            }

            swap(id, x);
            ne[v].pop_back();
            ne[u].pop_back();
        }
    }

    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}