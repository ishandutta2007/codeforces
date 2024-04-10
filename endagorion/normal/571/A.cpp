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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXL = 1000000;

i64 sq(i64 ls, i64 lx, i64 ly) {
    if (ls < 0) return 0;
    i64 ans = 0;
    if (lx + ly <= ls) ans += 1LL * (lx + 1) * (ly + 1);
    else {
        ans += 1LL * (ls + 1) * (ls + 2) / 2;
        if (ls > lx) {
            i64 d = ls - lx;
            ans -= d * (d + 1) / 2;
        }
        if (ls > ly) {
            i64 d = ls - ly;
            ans -= d * (d + 1) / 2;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int a, b, c, l;
    cin >> a >> b >> c >> l;
    i64 ans = 0;
    for1(i, MAXL) {
        if (a <= i && b <= i && c <= i && 3 * i - a - b - c <= l) ++ans;
    }
    forn(j, 3) {
        for1(i, MAXL) {
            if (i < a || i < b || c >= i) continue;
            int ll = l - (2 * i - a - b);
            if (ll < 0) continue;
            ans += min(ll + 1, i - c);
        }
        swap(a, b);
        swap(b, c);
    }
    forn(j, 3) {
        for1(i, MAXL) {
            if (i < a || b >= i || c >= i) continue;
            int ls = l - (i - a);
            int lx = i - b - 1;
            int ly = i - c - 1;
            if (ls < i - b - c) continue;
            ans += sq(ls, lx, ly) - sq(i - b - c, lx, ly);
        }
        swap(a, b);
        swap(b, c);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}