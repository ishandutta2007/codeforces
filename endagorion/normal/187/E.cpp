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

i64 solve(vi64 x, int l, int s, vi &p) {
    int n = x.size();
    int r = n - l - 1;
    i64 ans;
    p.clear();
/*    if (s == 0) {
        if (l) return 1e18;
        ans = x.back() - x[0];
        for1(i, n - 1) p.pb(i);
        return ans;
    }*/
//    if (!l || !r) return 1e18;
    int ptr;
    if (s) {
        ptr = s - 1;
        while (ptr && l > 1) {
    //        cerr << ptr << ' ' << l << '\n';
            p.pb(ptr);
            --ptr; --l;
        }
    //    cerr << "out\n";
    //    cerr << ptr << ' ' << l << '\n';
    //    if (ptr) {
        if (!l) return 1e18;
        --l; p.pb(0);
        for1(i, ptr) {
            --r; p.pb(i);
        }
    //    }
    }
    vector<pi64> difs;
    for (int i = s + 1; i + 1 < n; ++i) {
        difs.pb(mp(x[i + 1] - x[i], i));
    }
    sort(all(difs));
//    cerr << l << '\n';
    if (l > (int)difs.size()) return 1e18;
    set<pi64> bdifs(difs.begin(), difs.begin() + l);
    int bsz = l;
    i64 sc = 0;
    forn(i, l) sc += 2 * difs[i].fi;

    i64 bsc = sc;
    ptr = n - 2;
//    cerr << "here\n";
//    cerr << l << ' ' << r << '\n';
    while (!bdifs.empty()) {
        pi64 p = mp(x[ptr + 1] - x[ptr], ptr);
        if (bdifs.count(p)) {
            bdifs.erase(p);
            sc -= p.fi;
        } else {
            auto it = prev(bdifs.end());
            sc -= 2 * it->fi;
            bdifs.erase(it);
            sc += p.fi;
        }
//        cerr << bdifs.size() << ' ' << sc << '\n';
        if (uin(bsc, sc)) bsz = bdifs.size();
        --ptr;
    }

//    cerr << "here\n";

    bdifs = set<pi64>(difs.begin(), difs.begin() + l);
    ptr = n - 2;
    while (bdifs.size() != bsz) {
        pi64 p = mp(x[ptr + 1] - x[ptr], ptr);
        if (bdifs.count(p)) {
            bdifs.erase(p);
        } else {
            auto it = prev(bdifs.end());
            bdifs.erase(it);
        }
        --ptr;
    }

//    cerr << "done\n";
//    cerr << bsz << ' ' << l - bsz << '\n';
//    for (auto [sc, i]: bdifs) cerr << sc << ' ' << i << '\n';

    vi lft(n);
    for (auto [sc, i]: bdifs) lft[i] = 1;
    forn(i, l - bsz) lft[n - 2 - i] = 1;

//    cerr << "here\n";

    ptr = s + 1;
//    forn(i, n) cerr << lft[i];
//    cerr << '\n';
    while (ptr < n) {
        int q = ptr;
        while (q < n && lft[q]) ++q;
        assert(q < n);
        for (int r = q; r >= ptr; --r) p.pb(r);
        ptr = q + 1;
    }
/*    cerr << "fin\n";
    for (int v: p) cerr << v << ' ';
    cerr << '\n';*/
    assert(p.size() == n - 1);
    ans = 0;
    int v = s;

    forn(i, n - 1) {
        ans += abs(x[v] - x[p[i]]);
        v = p[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, l, s;
    cin >> n >> l >> s;
    --s; 
    vi64 x(n);
    forn(i, n) cin >> x[i];

    i64 ans = 1e18;
    vi bp;
    forn(z, 2) {
        vi p;
        i64 res = solve(x, l, s, p);
        if (z) {
            for (int &v: p) v = n - 1 - v;
        }
//        cerr << z << ' ' << res << '\n';
        if (uin(ans, res)) {
            bp = p;
        }
        reverse(all(x));
        for (auto &v: x) v *= -1;
        l = n - 1 - l;
        s = n - 1 - s;
    }

    if (ans > 1e17) cout << -1 << '\n';
    else {
        cout << ans << '\n';
        for (int v: bp) cout << v + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}