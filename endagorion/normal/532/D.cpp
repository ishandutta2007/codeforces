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

const int MAXN = 110000;
i64 x[MAXN], d[MAXN];
i64 dpl[MAXN], dpr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N + 2) cin >> x[i];
    for1(i, N) cin >> d[i];
    d[0] = d[N + 1] = 2e9;
    multiset<pair<i64, i64> > toDel;
    multiset<i64> ass;

    for1(i, N) {
        while (!toDel.empty() && toDel.begin()->fi < x[i]) {
            pair<i64, i64> p = *toDel.begin();
            toDel.erase(toDel.begin());
            ass.erase(ass.find(p.se));
        }
        if (!toDel.empty()) dpl[i] = *ass.rbegin();
        if (dpl[i] + 2 * d[i] > x[i]) {
            ass.insert(x[i]);
            toDel.insert(mp(dpl[i] + 2 * d[i], x[i]));
        }
//        cerr << x[i] << ' ' << dpl[i] << '\n';
        if (dpl[i] + 2 * d[i] >= x[N + 1]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    toDel.clear();
    ass.clear();
    forn(i, N + 1) dpr[i] = x[N + 1];
    for (int i = N; i >= 1; --i) {
        while (!toDel.empty() && toDel.rbegin()->fi > x[i]) {
            pair<i64, i64> p = *toDel.rbegin();
            toDel.erase(toDel.find(p));
            ass.erase(ass.find(p.se));
        }
        if (!toDel.empty()) dpr[i] = *ass.begin();
        if (dpr[i] - 2 * d[i] < x[i]) {
            ass.insert(x[i]);
            toDel.insert(mp(dpr[i] - 2 * d[i], x[i]));
        }
    }
    vector<pair<i64, i64> > stl, str;
    forn(i, N + 1) {
        i64 y = 2 * d[i] + dpl[i];
        if (y <= x[i]) continue;

        while (!stl.empty() && stl.back().fi <= y) stl.pop_back();
        stl.pb(mp(y, x[i]));
    }
    for (int i = N + 1; i > 0; --i) {
        i64 y = dpr[i] - 2 * d[i];
        if (y >= x[i]) continue;

        while (!str.empty() && str.back().fi >= y) str.pop_back();
        str.pb(mp(y, x[i]));
    }

/*    for (auto p: stl) cerr << p.fi << ' ' << p.se << '\n';
    cerr << '\n';
    for (auto p: str) cerr << p.fi << ' ' << p.se << '\n';
    cerr << '\n';*/

    i64 ans = 2e9;
    int j = str.size() - 1;
    forn(i, stl.size()) {
        while (j && str[j].fi > stl[i].fi) --j;
        if (str[j].fi <= stl[i].fi && str[j].se > stl[i].se) uin(ans, str[j].se - stl[i].se);
    }
    cout << 0.5 * ans << '\n';
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}