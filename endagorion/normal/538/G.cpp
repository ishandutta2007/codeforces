#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 1010000;

i64 t[MAXN], x[MAXN], y[MAXN];
int N, L;

struct TPoint {
    i64 t, a, b;

    TPoint(i64 t = 0, i64 a = 0, i64 b = 0)
        : t(t)
        , a(a)
        , b(b)
    {
    }

    bool operator<(const TPoint &p) const {
        return t < p.t;
    }
};

i64 fl(i64 x, i64 y) {
    if (x >= 0) return x / y;
    return x / y - (x % y ? 1 : 0);
}

i64 cl(i64 x, i64 y) {
    if (x >= 0) return (x + y - 1) / y;
    return x / y;
}

vi solve(vi64 x) {
    forn(i, N) {
        if ((x[i] + t[i]) % 2) return vi();
        x[i] = (x[i] + t[i]) / 2;
    }
    vector<vector<pi64> > q(L + 1);
    forn(i, N) {
        q[t[i] % L].pb(mp(-(t[i] / L), x[i]));
    }
    q[0].pb(mp(0LL, 0LL));
    q[L].pb(mp(1LL, 0LL));
    i64 l = 0, r = L;
    i64 pt = -1, pa = -1, pb = -1;
    forn(t, L + 1) {
        for (pi64 w: q[t]) {
            if (pt != -1) {
                i64 a = w.fi - pa, b = w.se - pb;
                i64 d = t - pt;
                i64 lh = -b, rh = d - b;
                if (!a) {
                    if (lh > 0 || rh < 0) return vi();
                } else {
                    if (a < 0) {
                        a = -a;
                        swap(lh, rh);
                        lh = -lh; rh = -rh;
                    }
                    uin(r, fl(rh, a));
                    uax(l, cl(lh, a));
                }
            }
            pt = t; pa = w.fi; pb = w.se;
        }
    }
    if (l > r) return vi();
    vi ans;
    int s = 0;
    forn(t, L + 1) {
        for (pi64 w: q[t]) {
            while (s < l * w.fi + w.se) {
                ans.pb(1);
                ++s;
            }
            while (ans.size() < t) ans.pb(0);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> L;
    forn(i, N) cin >> t[i] >> x[i] >> y[i];
    vi64 x1(N), x2(N);
    forn(i, N) {
        x1[i] = x[i] + y[i]; x2[i] = x[i] - y[i];
    }
    vi ans1 = solve(x1), ans2 = solve(x2);
    if (ans1.empty() || ans2.empty()) {
        cout << "NO\n";
    } else {
        forn(i, L) cout << "LDUR"[2 * ans1[i] + ans2[i]];
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}