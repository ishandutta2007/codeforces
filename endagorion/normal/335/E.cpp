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

    string s;
    cin >> s;
    int n, H;
    cin >> n >> H;
    ++H;
    if (s == "Alice") {
        ld sumv = 1.0;
        for1(d, n - 1) for1(h, H) {
            ld eq = pow(0.5, min(h, H - 1));
            ld sm = 1.0 - pow(0.5, h - 1);
//            cerr << d << ' ' << h << ' ' << eq << ' ' << sm << '\n';
            ld p1 = eq * eq * (d == 1 ? 1.0 : pow(sm, d - 1)) * (h == H ? 1.0 * (n - d) : 2 * (1.0 - pow(sm + eq, n - d)) / (1.0 - (sm + eq)) - pow(sm + eq, n - d - 1) * (n - d));
            sumv += pow(2, h - 1) * p1;

//            if (h == H) continue;
            ld p2 = h == H ? 0.0 : (1.0 - pow(sm + eq, n - d)) / (1.0 - (sm + eq)) * eq * (d == 1 ? 1.0 : pow(sm, d - 1)) * (1.0 - sm - eq) * 2;
            sumv += pow(2, h - 1) * p2;
//            cerr << d << ' ' << h << ' ' << sm << ' ' << eq << ' ' << p1 << ' ' << p2 << '\n';
        }

        cout << sumv << '\n';
    } else {
        cout << n << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}