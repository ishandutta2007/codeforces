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

vector<pii> ans;

vi mrg(const vi &a, const vi &b) {
    vi res(a.size() + b.size());
    forn(i, a.size()) res[i] = a[i];
    forn(i, b.size()) res[a.size() + i] = b[i];
    forn(i, a.size()) ans.pb(mp(a[i], b[i]));
    return res;
}

vvi split(int L, int R) {
    if (R - L == 1) return {{L}, {}};
    int l = L, r = R - (R - L) % 2, m = (l + r) / 2;
    vvi a = split(l, m), b = split(m, r);
    forn(z, 2) assert(a[z].size() == b[z].size());
    vvi c(2);
    forn(z, 2) c[z] = mrg(a[z], b[z]);
    if (c[0].size() < c[1].size()) c[0].swap(c[1]);
    if (r < R) {
        vi d = {r};
        forn(b, 20) {
            int z = (c[1].size() >> b) & 1;
            vi ct(c[z].end() - (1 << b), c[z].end());
            c[z].resize(c[z].size() - (1 << b));
            d = mrg(d, ct);
            if (c[1].empty()) break;
        }
        c[1] = d;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    split(0, n);
    cout << ans.size() << '\n';
    for (pii p: ans) cout << p.fi + 1 << ' ' << p.se + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}