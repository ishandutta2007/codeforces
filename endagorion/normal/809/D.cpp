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
    int x, y;
    int l, r;
    int sz, val;
    int lx, rx;
};

const int maxn = 510000;
TNode t[maxn];
int tc = 1;

#define dn TNode &n = t[node]

int newNode(int x) {
    int node = tc++;
    dn;
    n = {x, rand(), 0, 0, 1, 0, x, x};
    return node;
}

void addval(int node, int x) {
    dn;
    n.x += x;
    n.val += x;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void relax(int node) {
    dn;
    n.sz = 1 + t[n.l].sz + t[n.r].sz;
    n.lx = n.l ? t[n.l].lx : n.x;
    n.rx = n.r ? t[n.r].rx : n.x;
}

int merge(int l, int r) {
    if (!l) return r;
    if (!r) return l;
    if (t[l].y < t[r].y) {
        push(l);
        t[l].r = merge(t[l].r, r);
        relax(l);
        return l;
    } else {
        push(r);
        t[r].l = merge(l, t[r].l);
        relax(r);
        return r;
    }
}

pii split(int node, int x) {
    if (!node) return {0, 0};
    dn;
    push(node);
    pii res;
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

int erase(int node, int x) {
    auto res = split(node, x);
    auto res2 = split(res.se, x + 1);
    return merge(res.fi, res2.se);
}

void print(int node, bool first = true) {
    if (!node) return;
    dn;
    push(node);
    print(n.l, false);
    cerr << n.x << ' ';
    print(n.r, false);
    if (first) cerr << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int root = newNode(0);
    int n;
    cin >> n;
    forn(i, n) {
        int L, R;
        cin >> L >> R;
        auto [rest, top] = split(root, R);
//        cerr << rest << ' ' << top << '\n';
        if (top) top = erase(top, t[top].lx);
        auto [low, mid] = split(rest, L);
//        cerr << low << ' ' << mid << '\n';
        addval(mid, 1);
        low = merge(low, newNode(L));
        root = merge(low, merge(mid, top));
//        print(root);
    }
    cout << t[root].sz - 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}