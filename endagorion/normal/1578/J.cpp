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

const int maxn = 110000, BL = 300, BC = maxn / BL + 1;
int a[maxn];
int bord[BC];
vector<pii> val[BC];
vi sord[BC];

void flush(int bi) {
    if (val[bi].empty()) return;
    int ptr = -1;
    for (int i: sord[bi]) {
        while (ptr + 1 < (int)val[bi].size() && a[i] >= val[bi][ptr + 1].fi) ++ptr;
        if (ptr >= 0) a[i] = val[bi][ptr].se;
    }
    val[bi].clear();
}

void addval(int bi, int R, int lb, int x) {
    if (R <= bord[bi]) return;
    if (R >= bord[bi + 1]) {
//        cerr << bi << ' ' << R << ' ' << lb << ' ' << x << '\n';
        int elb = lb;
        while (!val[bi].empty() && val[bi].back().se >= lb) {
            uin(elb, val[bi].back().fi);
            val[bi].pop_back();
        }
        val[bi].pb(mp(elb, x));
        return;
    }
    flush(bi);
    vi vold, vnew;
    for (int i: sord[bi]) {
        if (i < R && a[i] >= lb) {
            a[i] = x;
            vnew.pb(i);
        } else vold.pb(i);
    }
    sord[bi] = vold;
    sord[bi].insert(sord[bi].end(), all(vnew));
}

void maxout(int r, int x) {
    int bi = r / BL;
    flush(bi);
    a[r] = x;
    sord[bi].erase(find(all(sord[bi]), r));
    sord[bi].pb(r);
}

vi lbyr[maxn];
vector<pii> qlbyr[maxn];
int ans[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    int B = 0;
    forn(i, n + 2) {
        a[i] = -1;
        int bi = i / BL;
        sord[bi].pb(i);
        uax(B, bi);
    }
    forn(i, B + 2) bord[i] = min(i * BL, n + 1);

    forn(i, m) {
        int l, r;
        cin >> l >> r;
        ++r;
        lbyr[r].pb(l);
    }
    int q;
    cin >> q;
    forn(qi, q) {
        int l, r;
        cin >> l >> r;
        ++r;
        qlbyr[r].pb(mp(l, qi));
    }

    for1(r, n + 1) {
//        forn(i, B + 1) flush(i);
        maxout(r, r);
        for (int l: lbyr[r]) forn(i, B + 1) addval(i, l + 1, l, r - 1);
        for (auto [l, qi]: qlbyr[r]) {
            flush(l / BL);
            ans[qi] = a[l];
        }
/*        cerr << r << '\n';
        forn(bi, B + 1) {
            cerr << "bi = " << bi << '\n';
            fore(i, bord[bi], bord[bi + 1] - 1) cerr << a[i] << ' ';
            cerr << '\n';
            for (auto [x, y]: val[bi]) cerr << x << ' ' << y << ", ";
            cerr << '\n';
        }
        cerr << '\n';*/
    }
    forn(i, q) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}