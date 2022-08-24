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

struct Portal {
    int x, y, s;

    bool operator<(const Portal &p) const {
        return x < p.x;
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

    int n;
    cin >> n;
    vector<Portal> ps(n);
    forn(i, n) cin >> ps[i].x >> ps[i].y >> ps[i].s;
    sort(rall(ps));
    i64 ans = ps[0].x + 1;
    map<i64, i64> m;
    m[0] = 1;
    i64 sum = 1, sy = 0;
    i64 lx = ps[0].x + 1;
    for (auto p: ps) {
        while (!m.empty() && m.rbegin()->fi > p.x) {
            auto p = *m.rbegin();
            (sum -= p.se) %= P;
            m.erase(p.fi);
        }
        i64 ex = sum - (p.s ? 0 : 1);
        (m[p.y] += ex) %= P;
        (sum += ex) %= P;
        (ans += ex * (p.x - p.y)) %= P;
        lx = p.x;
//        cerr << p.x << ' ' << p.y << ' ' << p.s << ' ' << ans << '\n';
//        for (auto [x, y]: m) cerr << x << ' ' << y << '\n';
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}