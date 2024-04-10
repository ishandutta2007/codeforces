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

vector<pii> groups(const vi &a) {
    pii p = {a[0], 1};
    vector<pii> res;
    for1(i, a.size() - 1) {
        if (a[i] == p.fi) ++p.se;
        else res.pb(p), p = {a[i], 1};
    }
    res.pb(p);
    reverse(all(res));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        for (int &x: a) cin >> x;
        for (int &x: b) cin >> x;
        auto ga = groups(a), gb = groups(b);
        map<int, int> need;
        int ptra = 0;
        bool ok = true;
        forn(i, gb.size()) {
            while (ok) {
                if (ptra == ga.size()) {
                    ok = false;
                    break;
                }
                auto &[x, c] = ga[ptra];
                int z = min(c, need[x]);
                c -= z;
                need[x] -= z;
                if (x != gb[i].fi) {
                    if (!c) ++ptra;
                    else {
                        ok = false;
                        break;
                    }
                } else {
                    int c2 = gb[i].se;
                    if (c > c2) {
                        ok = false;
                        break;
                    }
                    need[x] += c2 - c;
                    ++ptra;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}