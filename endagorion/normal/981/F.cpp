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

const int maxn = 610000;
i64 a[maxn], b[maxn];
int ps[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, l;
    cin >> n >> l;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    sort(a, a + n);
    forn(i, n) a[i + n] = a[i] + l;
    sort(b, b + n);
    forn(i, n) b[i] -= l, b[i + n] = b[i] + l, b[i + 2 * n] = b[i] + 2 * l;

    int L = -1, R = l / 2 + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        int ist = 0, ien = 0, j = 0;
        int mx = -1e9;
        bool ok = true;
        while (1) {
            i64 xst = ist < 2 * n ? a[ist] - M : 1e18;
            i64 xen = ien < 2 * n ? a[ien] + M : 1e18;
            i64 xj = j < 3 * n ? b[j] : 1e18;
            if (max({xst, xen, xj}) > 1e17) break;
            if (xst <= xj && xst <= xen) ps[ist] = j, ++ist;
            else if (xj <= xen) ++j;
            else {
                uax(mx, ps[ien] - ien);
                if (j - ien < mx + 1) {
                    ok = false;
                    break;
                }
                ++ien;
            }
        }
        (ok ? R : L) = M;
    }
    cout << R << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}