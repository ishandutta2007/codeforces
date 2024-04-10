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

int match(pii a, pii b) {
    if (a == b) return -2;
    int c = -1;
    forn(ii, 2) forn(jj, 2) {
        int x = ii ? a.se : a.fi;
        int y = jj ? b.se : b.fi;
        if (x == y) c = x;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vector<pii> a(n), b(m);
    forn(i, n) {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    }
    forn(i, m) {
        cin >> b[i].fi >> b[i].se;
        if (b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
    }

    int poss = 0;
    bool partsKnow = true;
    forn(i, n) forn(j, m) {
        if (a[i] == b[j] || poss == -1) continue;
        int c = match(a[i], b[j]);
        if (c == -1) continue;
        if (poss == 0) poss = c;
        if (poss != c) poss = -1;

        forn(jj, m) {
            if (a[i] == b[jj]) continue;
            int cc = match(a[i], b[jj]);
            if (cc > 0) partsKnow &= c == cc;
        }
        forn(ii, n) {
            if (a[ii] == b[j]) continue;
            int cc = match(a[ii], b[j]);
            if (cc > 0) partsKnow &= c == cc;
        }
    }

    if (poss > 0) {
        cout << poss << '\n';
        return 0;
    }

    cout << (partsKnow ? 0 : -1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}