#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

const int maxn = 110000;
int a[maxn];
const double PI = atan2(0, -1);

struct TPoint {
    double x, y;

    TPoint operator+(const TPoint &p) const {
        return {x + p.x, y + p.y};
    }

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y};
    }

    TPoint operator*(double t) const {
        return {t * x, t * y};
    }

    double operator*(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    TPoint rotate(double angle) const {
        return {x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle)};
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
    forn(i, n) cin >> a[i];
    a[n] = a[0];
    vector< tuple<double, int, int> > evs;
    forn(i, n) {
        TPoint v = TPoint({1, 0}).rotate(2 * PI / n) * a[i + 1] + TPoint({n, 0}) - TPoint({1, 0}).rotate(PI - 2 * PI / n) * (n - a[i]);
        double slope = v * TPoint({0, 1});
        evs.pb(mt(fabs(slope), i, int(slope > 0)));
    }
    sort(rall(evs));
    vi ans(n);
    int L = 0, R = n - 1;
    for (auto w: evs) {
        double t;
        int id, s;
        tie(t, id, s) = w;
        if (s) ans[id] = R--;
        else ans[id] = L++;
    }
    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}