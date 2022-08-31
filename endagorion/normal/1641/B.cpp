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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        map<int, int> cnt;
        for (auto &x: a) {
            cin >> x;
            ++cnt[x];
        }
        bool ok = true;
        for (auto [x, c]: cnt) ok &= c % 2 == 0;
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        int L = 0;
        vector<pii> ops;
        vi ls;
        int s = 0;

        while (L < n) {
            int i = find(L + 1 + all(a), a[L]) - a.begin();
            int d = i - L - 1;
            ls.pb(2 * (d + 1));
            forn(j, d) {
                ops.pb({i + s + j, a[L + j + 1]});
            }
            s += 2 * d;
            reverse(a.begin() + L + 1, a.begin() + i + 1);
            L += 2;
        }
        cout << ops.size() << '\n';
        for (auto [x, y]: ops) cout << x + 1 << ' ' << y << '\n';
        cout << ls.size() << '\n';
        for (int x: ls) cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}