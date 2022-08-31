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

struct TRect {
    int x1, x2, y1, y2;

    TRect operator+(TRect r) const {
        return {max(x1, r.x1), min(x2, r.x2), max(y1, r.y1), min(y2, r.y2)};
    }
};

const int maxn = 150000;
TRect r[maxn], pref[maxn], suf[maxn];

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
    forn(i, n) cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
    pref[0] = suf[0] = {-(int)2e9, (int)2e9, -(int)2e9, (int)2e9};
    forn(i, n) pref[i + 1] = pref[i] + r[i];
    forn(i, n) suf[i + 1] = suf[i] + r[n - i - 1];

    forn(i, n) {
        TRect t = pref[i] + suf[n - i - 1];
        if (t.x1 <= t.x2 && t.y1 <= t.y2) {
            cout << t.x1 << ' ' << t.y1 << '\n';
            break;
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}