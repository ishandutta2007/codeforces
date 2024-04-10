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

const int maxn = 310000;
i64 x[maxn];
char c[maxn];

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
    forn(i, n) cin >> x[i] >> c[i];
    vi gs;
    forn(i, n) if (c[i] == 'G') gs.pb(i);
    i64 ans = 0;
    if (gs.empty()) {
        i64 lb = -1, lr = -1;
        forn(i, n) {
            if (c[i] == 'B') {
                if (lb != -1) ans += x[i] - lb;
                lb = x[i];
            } else {
                if (lr != -1) ans += x[i] - lr;
                lr = x[i];
            }
        }
        cout << ans << '\n';
        return 0;
    }
    {
        i64 lb = -1, lr = -1;
        forn(i, gs[0]) {
            if (c[i] == 'B') {
                if (lb != -1) ans += x[i] - lb;
                lb = x[i];
            } else {
                if (lr != -1) ans += x[i] - lr;
                lr = x[i];
            }
        }
        if (lb != -1) ans += x[gs[0]] - lb;
        if (lr != -1) ans += x[gs[0]] - lr;
    }
    {
        i64 lb = -1, lr = -1;
        for (int i = n - 1; i > gs.back(); --i) {
            if (c[i] == 'B') {
                if (lb != -1) ans += lb - x[i];
                lb = x[i];
            } else {
                if (lr != -1) ans += lr - x[i];
                lr = x[i];
            }
        }
        if (lb != -1) ans += lb - x[gs.back()];
        if (lr != -1) ans += lr - x[gs.back()];
    }

    forn(i, gs.size() - 1) {
        int a = gs[i], b = gs[i + 1];
        i64 dr = 0, db = 0;
        i64 lr = x[a], lb = x[a];
        for (int j = a + 1; j < b; ++j) {
            if (c[j] == 'R') {
                uax(dr, x[j] - lr);
                lr = x[j];
            } else {
                uax(db, x[j] - lb);
                lb = x[j];
            }
        }
        uax(dr, x[b] - lr);
        uax(db, x[b] - lb);
        ans += min(2 * (x[b] - x[a]), 3 * (x[b] - x[a]) - dr - db);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}