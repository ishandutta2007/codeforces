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

const int maxa = 1100000;
int mind[maxa + 1], sqf[maxa + 1];
vi ps;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    mind[1] = sqf[1] = 1;
    fore(i, 2, maxa) mind[i] = i;
    fore(i, 2, maxa) {
        if (mind[i] == i) ps.pb(i);
        if (i / mind[i] % mind[i] == 0) sqf[i] = sqf[i / mind[i] / mind[i]];
        else sqf[i] = sqf[i / mind[i]] * mind[i];

        for (int p: ps) {
            if (p > mind[i]) break;
            if (p > maxa / i) break;
            mind[i * p] = p;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        forn(i, n) {
            int x;
            cin >> x;
            ++cnt[sqf[x]];
//            cerr << sqf[x] << ' ';
        }
//        cerr << '\n';
        int ans = 0;
        for (auto [x, y]: cnt) uax(ans, y);

        map<int, int> cnt2;
        for (auto [x, y]: cnt) {
            if (y % 2 == 0) cnt2[1] += y;
            else cnt2[x] += y;
        }

        int ans2 = 0;
        for (auto [x, y]: cnt2) uax(ans2, y);

        int qs;
        cin >> qs;

        while (qs--) {
            i64 t;
            cin >> t;
            cout << (t == 0 ? ans : ans2) << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}