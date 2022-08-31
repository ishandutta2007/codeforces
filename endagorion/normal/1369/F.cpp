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

int solve(vector<pi64> a, int fin) {
    reverse(all(a));
    vi win(2, fin);
    forn(i, a.size()) {
        auto [s, n] = a[i];
        while (1) {
            i64 nn = n / 2;
            if (!win[0]) win = vi(2, 1);
            else {
                win[n & 1] = !win[(n & 1) ^ 1];
            }
//            cerr << i << ' ' << nn << ' ' << n << ' ' << win[0] << ' ' << win[1] << '\n';
            if (s > nn) {
                win = vi(2, !win[s & 1]);
                break;
            } else n = nn;
        }
    }
    return !win[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    vector<pi64> a(t);
    for (auto &[x, y]: a) cin >> x >> y;

    cout << solve(a, 1) << ' ' << solve(a, 0) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}