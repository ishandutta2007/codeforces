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

struct TNode {
    i64 x;
    int y;
    int l, r;
    int d, sd, minp;
};

const int maxn = 610000;
TNode t[maxn];

int tc = 1;

#define dn TNode &n = t[node]

int newNode(i64 x, int delta) {
    int node = tc++;
    dn;
    n = {x, rand(), 0, 0, delta, delta, min(0, delta)};
    return node;
}

void relax(int node) {
    dn;
    n.sd = t[n.l].sd + n.d + t[n.r].sd;
    n.minp = t[n.l].minp;
    uin(n.minp, t[n.l].sd + n.d + t[n.r].minp);
}

bool find_and_change(int node, i64 x, int d) {
    if (!node) return false;
    dn;
    if (n.x == x) {
        n.d += d;
        relax(node);
        return true;
    }
    bool res = find_and_change(x < n.x ? n.l : n.r, x, d);
    if (res) relax(node);
    return res;
}

pii split(int node, i64 x) {
    if (!node) return {0, 0};
    pii res;
    dn;
    if (n.x < x) {
        res = split(n.r, x);
        n.r = res.fi;
        res.fi = node;
    } else {
        res = split(n.l, x);
        n.l = res.se;
        res.se = node;
    }
    relax(node);
    return res;
}

int merge(int l, int r) {
    if (!l) return r;
    if (!r) return l;
    if (t[l].y < t[r].y) {
        t[l].r = merge(t[l].r, r);
        relax(l);
        return l;
    } else {
        t[r].l = merge(l, t[r].l);
        relax(r);
        return r;
    }
}

int change(int node, i64 x, int d) {
    if (find_and_change(node, x, d)) return node;
    pii res = split(node, x);
    return merge(res.fi, merge(newNode(x, d), res.se));
}

i64 leftx(int node) {
    if (!node) return 2e9;
    dn;
    return n.l ? leftx(n.l) : n.x;
}

void print(int node) {
    if (!node) return;
    dn;
    print(n.l);
    cerr << node << ' ' << n.x << ' ' << n.d << '\n';
    print(n.r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, r;
    cin >> n >> r;
    vector<pii> a;
    forn(i, n) {
        int l, r;
        cin >> l >> r;
        uax(l, 0);
        if (l <= r) a.pb(mp(r, l));
    }
    sort(all(a));

    int close = 0, far = 0;
    int ptr = 0;
    int v0 = 0, v1 = 0, v2 = 0;
    while (ptr < (int)a.size() || close) {
        i64 close_out = close ? leftx(close) + r : 1e18;
        i64 move_ptr = ptr < (int)a.size() ? a[ptr].fi + 1 : 1e18;
//        cerr << close_out << ' ' << move_ptr << ' ' << v2 << '\n';
//        cerr << far << ' ' << close << '\n';
/*        cerr << "far \n";
        print(far);
        cerr << "close \n";
        print(close);
        cerr << "---\n";*/
        i64 x = min(close_out, move_ptr);
//        cerr << x - 1 << ' ' << v2 << '\n';
        if (close_out <= move_ptr) {
            auto [node, rest] = split(close, close_out - r + 1);
            v1 += t[node].d;
            close = rest;
            if (t[node].d) far = merge(far, node);
        } else {
            int y = a[ptr].se;
            ++v0;
            if (y > x - r) close = change(close, y, -1);
            else far = change(far, y, -1);
            ++ptr;
        }
        int nv2 = v0 + t[far].minp;
        if (v2 != nv2) {
            close = change(close, x, nv2 - v2);
//            print(close);
            v2 = nv2;
        }
    }

//    print(far);

    cout << a.size() - v2 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}