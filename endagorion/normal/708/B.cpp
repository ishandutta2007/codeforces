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

i64 f(i64 x) {
    i64 y = 0;
    while (y * (y - 1) / 2 < x) ++y;
    if (y * (y - 1) / 2 != x) y = -1;
    return y;
}

bool ok(i64 n, i64 c, i64 s) {
    return c >= 0 && c <= n && s >= c * (c - 1) / 2 && s <= n * (n - 1) / 2 - (n - c) * (n - c - 1) / 2;
}

bool restore(i64 c1, i64 s1, string &s) {
    int n = s.size();
    if (!ok(n, c1, s1)) return false;
    ford(i, n) {
        if (ok(i, c1, s1)) continue;
        s[i] = '1';
        --c1;
        s1 -= i;
        assert(ok(i, c1, s1));
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    i64 sum = a00 + a01 + a10 + a11;
    if (sum == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int L = f(sum);
    if (L == -1) {
        cout << "Impossible\n";
        return 0;
    }

    bool done = false;
    string s(L, '0');
    i64 c0 = f(a00), c1 = f(a11);
    for (i64 b0 = c0; b0 <= c0 + (c0 == 0); ++b0) {
        for (i64 b1 = c1; b1 <= c1 + (c1 == 0); ++b1) {
            if (done) break;
            if (b0 + b1 != L) continue;
            i64 /*s0 = a00 + a10, */s1 = a01 + a11;
//            cerr << b1 << ' ' << s1 << '\n';
            if (restore(b1, s1, s)) done = true;
        }
    }
    if (!done) cout << "Impossible\n";
    else cout << s << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}