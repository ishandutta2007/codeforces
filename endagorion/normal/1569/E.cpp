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

const i64 P = 998244353;
const int maxp = 33;
i64 ph[maxp];

int off;

void rec(vi &teams, int L, i64 h, int pw, vi &pv, vi &places, map<i64, vi> &ps) {
    if ((int)teams.size() - L == 1) {
        pv[teams[L] - off] = pw;
/*        cerr << off << ": ";
        for (auto x: pv) cerr << x << ' ';
        cerr << '\n';*/
        ps[(h + teams[L] * ph[pw]) % P] = pv;
        return;
    }
    forn(z, 2) {
        int win = teams[L + z], lose = teams[L + (z ^ 1)];
        pv[lose - off] = places[L / 2];
        teams.pb(win);
        rec(teams, L + 2, (h + lose * ph[places[L / 2]]) % P, pw, pv, places, ps);
        teams.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int k, a;
    i64 h0;
    cin >> k >> a >> h0;

    ph[0] = 1;
    forn(i, maxp - 1) ph[i + 1] = ph[i] * a % P;
    vi ans;
    vi teams1, teams2;
    for1(i, 1 << k) (i > (1 << (k - 1)) ? teams2 : teams1).pb(i);
    vi places;
    for (int kk = k; kk >= 2; --kk) {
        forn(i, (1 << (kk - 2))) places.pb((1 << (kk - 1)) + 1);
    }
//    for (int x: places) cerr << x << ' ';
//    cerr << '\n';
    forn(z, 2) {
        if (!ans.empty()) break;
        map<i64, vi> ps1, ps2;
        vi pv(1 << (k - 1));
        off = 1;
        rec(teams1, 0, 0, (z == 0 ? 1 : 2), pv, places, ps1);
        off = (1 << (k - 1)) + 1;
        rec(teams2, 0, 0, (z == 0 ? 2 : 1), pv, places, ps2);
        for (auto &[h1, v1]: ps1) {
            i64 h2 = (P + h0 - h1) % P;
            if (ps2.count(h2)) {
                for (auto x: v1) ans.pb(x);
                for (auto x: ps2[h2]) ans.pb(x);
                break;
            }
        }
    }

    if (ans.empty()) cout << -1 << '\n';
    else {
        for (auto x: ans) cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}