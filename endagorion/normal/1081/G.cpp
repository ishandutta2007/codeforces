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

i64 P;
const int maxn = 110000;
i64 rec[maxn];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

map<int, i64> cnt;

void merge(int l, int k) {
    if (k <= 1 || l == 1) {
        ++cnt[l];
        return;
    }
    merge(l / 2, k - 1);
    merge(l - l / 2, k - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k >> P;

    merge(n, k);
//    for (auto w: cnt) cout << w.fi << ' ' << w.se << '\n';

    i64 ans = 0;
    for (auto w1: cnt) {
        int n = w1.fi;
        i64 q = w1.se;
        (ans += q * n % P * (n - 1) % P * deg(4, -1)) %= P;
    }

    for (auto w1: cnt) for (auto w2: cnt) {
        int n = w1.fi, m = w2.fi;
        if (m < n) continue;
        i64 coef;
        if (n == m) coef = w1.se * (w1.se - 1) / 2 % P;
        else coef = w1.se * w2.se % P;
        i64 R = 1LL * n * m % P * (P + 1) / 2 % P;
        for1(s, n + m) {
            int l = max(1, s - m), r = min(n, s - 1);
            (R -= 1LL * (r - l + 1) * deg(s, -1)) %= P;
        }
        (ans += coef * R) %= P;
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}