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
typedef pair<i64, i64> pi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int B = 21;

i64 lh[2 << B], rh[2 << B];

void rec(int i, i64 x, i64 s, i64 w, i64 *v) {
    if (i == B) {
        v[s] += w;
        return;
    }
    if ((x >> i) & 1) {
        rec(i + 1, x, s + (1 << i), 2 * w, v);
    } else {
        rec(i + 1, x, s, w, v);
        rec(i + 1, x, s + 2 * (1 << i), w, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 s, x;
    cin >> s >> x;
    //unordered_map<i64, i64> lh, rh;
    rec(0, x & ((1 << B) - 1), 0, 1, lh);
    rec(0, x >> B, 0, 1, rh);
    i64 ans = 0;
    //for (auto w: rh) {
    forn(x, 2 << B) {
        i64 y = s - ((i64)x << B);
        if (y < 0 || y >= (2 << B)) continue;
        //if (!w.first || !(s - (w.first << B))) continue;
        ans += rh[x] * lh[y];
    }
    if (s == x) ans -= 2;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}