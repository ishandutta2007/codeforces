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

map<i64, i64> memo_clh;

i64 clh(i64 x, i64 l) {
    if (x < 2 * l) return 0;
    if (x == 3 && l == 1) return 2;
    if (x / 2 == l) return 1;
    if (memo_clh.count(x)) return memo_clh[x];
    return memo_clh[x] = clh(x / 2, l) + clh(x - x / 2, l);
}

i64 f(i64 n, i64 k) {
    if (k == 1) return 1;
    if (k == 2) return n;
    k -= 3;
    map<i64, i64> cnt;
    cnt[n - 1] = 1;
    i64 lh = -1;
    while (1) {
        i64 l = cnt.rbegin()->fi / 2;
        i64 c0 = 0, c1 = 0;
        while (!cnt.empty() && cnt.rbegin()->fi / 2 == l) {
            auto w = *cnt.rbegin();
            (w.fi % 2 ? c1 : c0) = w.se;
            cnt.erase(w.fi);
        }
        if (l == 1) c0 += c1;
        if (k < c0 + c1) {
            lh = l;
            break;
        }
        cnt[l] += 2 * c0 + c1;
        cnt[l + 1] += c1;
        k -= c0 + c1;
    }
    i64 s = 1, l = n - 1;
    while (l / 2 > lh) {
        i64 m = s + l / 2;
        i64 nk = clh(m - s, lh);
        if (k < nk) l = m - s;
        else k -= nk, l -= m - s, s = m;
    }
    if (k) {
        assert(k == 1 && lh == 1 && l == 3);
        ++s; --l;
    }
    return s + l / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 n, k;
    cin >> n >> k;
    cout << f(n, k) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}