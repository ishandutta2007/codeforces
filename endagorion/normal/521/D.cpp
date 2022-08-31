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

bool comp(pi64 a, pi64 b) {
    if (a.fi / a.se != b.fi / b.se) return a.fi / a.se > b.fi / b.se;
    a.fi %= a.se;
    b.fi %= b.se;
    return a.fi * b.se > b.fi * a.se;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int k, n, m;
    cin >> k >> n >> m;
    vi64 a(k);
    forn(i, k) cin >> a[i];
    vector<pii> best_assign(k, mp(-1, -1));
    vector<vector<pi64>> adds(k), muls(k);

    vi type(n);

    forn(i, n) {
        int j, x;
        cin >> type[i] >> j >> x;
        --j;
        if (type[i] == 1) uax(best_assign[j], mp(x, i));
        else if (type[i] == 2) adds[j].pb(mp((i64)x, (i64)i));
        else if (type[i] == 3) muls[j].pb(mp((i64)x, (i64)i));
    }

    forn(i, k) {
        auto w = best_assign[i];
        if (w.fi <= a[i]) continue;
        w.fi -= a[i];
        adds[i].pb(w);
    }

    vector<pair<pi64, int> > ups;
    forn(i, k) {
        for (auto w: muls[i]) {
            --w.fi;
            if (w.fi) ups.pb(mp(mp(w.fi, 1LL), w.se));
        }
        sort(rall(adds[i]));
        for (auto [x, y]: adds[i]) {
            ups.pb(mp(mp(x, a[i]), y));
            a[i] += x;
        }
    }
    sort(all(ups), [&](auto a, auto b){return comp(a.fi, b.fi);});
    if (ups.size() > m) ups.resize(m);
    cout << ups.size() << '\n';
    for1(t, 3) {
        for (auto [p, id]: ups) if (type[id] == t) cout << id + 1 << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}