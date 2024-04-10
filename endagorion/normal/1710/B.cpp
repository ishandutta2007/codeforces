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

struct Ev {
    int type;
    i64 x, da, db;

    bool operator<(const Ev &ev) const {
        return x < ev.x;
    }
};

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
        i64 m;
        cin >> n >> m;
        vi64 x(n), p(n);
        forn(i, n) cin >> x[i] >> p[i];

        i64 mind = -1e18, mins = -1e18;
        vector<Ev> evs;
        forn(i, n) {
            evs.pb({0, x[i] - p[i], 1, p[i] - x[i]});
            evs.pb({0, x[i], -2, 2 * x[i]});
            evs.pb({0, x[i] + p[i], 1, -(x[i] + p[i])});
            evs.pb({1, x[i], -1, -1});
        }
        sort(all(evs));
        i64 A = 0, B = 0;
        for (auto ev: evs) {
            if (ev.type == 0) A += ev.da, B += ev.db;
            else {
                i64 y = A * ev.x + B;
                if (y > m) {
                    uax(mins, ev.x + y - m);
                    uax(mind, y - m - ev.x);
                }
            }
        }

        forn(i, n) {
            cout << (p[i] + x[i] >= mins && p[i] - x[i] >= mind ? '1' : '0');
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}