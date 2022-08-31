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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int L, R;
    cin >> L >> R;
    int add = L - 1;
    L -= add; R -= add; ++R;

    vi ls = {0}, rs = {1};
    vector<array<int, 3> > es;
    int sp = 1;
    for (int i = 1; ; ++i) {
        int l = 1, r = min(1 + sp, R);
        ls.pb(l);
        rs.pb(r);
        ford(j, i) {
//            cerr << i << ' ' << j << ' ' << l << ' ' << r << ' ' << ls[j] << ' ' << rs[j] << '\n';
            if (rs[j] - ls[j] <= r - l) {
                if (r <= rs[j]) continue;
                es.pb({j, i, r - rs[j]});
                r -= rs[j] - ls[j];
            }
        }
        assert(l == r);
        sp += rs.back() - ls.back();
        if (rs.back() == R) break;
    }

    cout << "YES\n";
    cout << ls.size() << ' ' << es.size() << '\n';
    for (auto [x, y, w]: es) {
        if (x == 0) w += add;
        cout << x + 1 << ' ' << y + 1 << ' ' << w << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}