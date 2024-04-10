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

struct TQuery {
    int type;
    int x, y;
};

const int maxq = 510000;
vector<TQuery> byDay[maxq];
int day;

vector<pair<int*, int> > chs;
vi saveP;

void change(int *x, int y) {
    chs.pb(mp(x, *x));
    *x = y;
}

void save() {
    saveP.pb(chs.size());
}

void restore() {
    int sz = saveP.back();
    saveP.pop_back();
    while (chs.size() > sz) {
        auto w = chs.back();
        *w.fi = w.se;
        chs.pop_back();
    }
}

const int maxn = 110000;
int par[maxn], rk[maxn], sz[maxn];

int root(int x) {
    return x == par[x] ? x : root(par[x]);
}

void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
//    cerr << x << ' ' << y << '\n';
    if (rk[x] < rk[y]) swap(x, y);
    change(&sz[x], sz[x] + sz[y]);
    change(&par[y], x);
    if (rk[x] == rk[y]) change(&rk[x], rk[x] + 1);
}

void processDay(int d) {
    save();
    for (auto w: byDay[d]) {
//        cerr << w.type << ' ' << w.x << ' ' << w.y << '\n';
        if (w.type == 1) unite(w.x, w.y);
        else cout << sz[root(w.x)] << '\n';
    }
    restore();
}

void introDay(int d) {
    if (d < 0) return;
//    cerr << "intro " << d << '\n';
    for (auto w: byDay[d]) {
        if (w.type == 1) unite(w.x, w.y);
    }
}

void expand(int l, int r, int nl, int nr) {
    uax(l, 0);
    uax(nl, 0);
    if (nl >= nr) return;
    if (l >= r) l = r = nl;
//    cerr << l << ' ' << r << ' ' << nl << ' ' << nr << '\n';
    while (l > nl) introDay(--l);
    while (r < nr) introDay(r++);
}

int k;

void dnc(int l, int r) {
    if (r - l == 1) {
        processDay(l);
        return;
    }
    int m = (l + r) / 2;
    save();
    expand(r - k, l, m - k, l);
    dnc(l, m);
    restore();

    save();
    expand(r - k, l, r - k, m);
    dnc(m, r);
    restore();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q >> k;
    int qid = 0;
    forn(i, q) {
        int type;
        cin >> type;
        if (type == 3) ++day;
        else {
            TQuery qq;
            qq.type = type;
            if (type == 1) cin >> qq.x >> qq.y, --qq.x, --qq.y;
            else cin >> qq.x, --qq.x, qq.y = qid++;
            byDay[day].pb(qq);
        }
    }

    forn(i, n) par[i] = i, rk[i] = 0, sz[i] = 1;
    dnc(0, day + 1);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}