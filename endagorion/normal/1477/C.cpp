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

struct TPoint {
    i64 x, y;

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y};
    }

    i64 operator*(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    i64 operator~() const {
        return x * x + y * y;
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
    vector<TPoint> p(n);
    forn(i, n) cin >> p[i].x >> p[i].y;
    vi used(n);

    int cur = 0;
    used[cur] = 1;
    vi ans = {0};

    forn(i, n - 1) {
        int bj = -1;
        forn(j, n) {
            if (used[j]) continue;
            if (bj == -1 || ~(p[bj] - p[cur]) < ~(p[j] - p[cur])) bj = j;
        }
//        cerr << bj << '\n';
        if (ans.size() > 1) assert((p[bj] - p[ans.back()]) * (p[ans.end()[-2]] - p[ans.back()]) > 0);
        ans.pb(bj);
        used[bj] = 1;
        cur = bj;
    }

    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}