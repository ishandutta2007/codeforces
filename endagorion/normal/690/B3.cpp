#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TPoint {
    i64 x, y;

    TPoint(i64 x, i64 y)
        : x(x)
        , y(y)
    {
    }

    TPoint operator+(const TPoint &p) const {
        return TPoint(x + p.x, y + p.y);
    }

    TPoint operator-(const TPoint &p) const {
        return TPoint(x - p.x, y - p.y);
    }

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    i64 operator*(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    i64 operator~() const {
        return *this * *this;
    }

    bool operator<(const TPoint &p) const {
        return mp(x, y) < mp(p.x, p.y);
    }
};

bool cmp(const TPoint &a, const TPoint &b) {
    if (a % b) return a % b > 0;
    return ~a < ~b;
}

const int maxn = 210000;
int miny[maxn], maxy[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    while (1) {
        cin >> n >> m;
        if (!n) break;
        forn(i, n + 10) miny[i] = 1e9, maxy[i] = -1e9;
        forn(i, m) {
            int x, y;
            cin >> x >> y;
//            --x; --y;
            uin(miny[x], y);
            uax(maxy[x], y);
        }
        vector<TPoint> p;
        forn(i, n + 2) {
            if (i && miny[i] < miny[i - 1]) p.pb(TPoint(i, miny[i]));
            if (miny[i] < miny[i + 1]) p.pb(TPoint(i - 1, miny[i]));
            if (i && maxy[i] > maxy[i - 1]) p.pb(TPoint(i, maxy[i] - 1));
            if (maxy[i] > maxy[i + 1]) p.pb(TPoint(i - 1, maxy[i] - 1));
        }
        TPoint O = *min_element(all(p));
        for (auto &w: p) w = w - O;
        sort(all(p), cmp);
        vector<TPoint> st;
        for (auto w: p) {
            while (st.size() > 1) {
                TPoint prv = st.back(), pprv = st[st.size() - 2];
                if ((w - pprv) % (prv - pprv) >= 0) st.pop_back();
                else break;
            }
            st.pb(w);
        }
        reverse(all(st));
        forn(i, st.size()) {
            st[i] = st[i] + O;
//            ++st[i].x; ++st[i].y;
//            swap(st[i].x, st[i].y);
//            st[i].x += 1;
//            st[i].y = n - st[i].y - 1;
        }
        int j = min_element(all(st)) - st.begin();
        cout << st.size() << '\n';
        //for (auto w: st) {
        forn(i, st.size()) {
            TPoint w = st[(i + j) % st.size()];
            cout << w.x << ' ' << w.y << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}