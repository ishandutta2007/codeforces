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

i64 C, h1, h2, w1, w2;


int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> C >> h1 >> h2 >> w1 >> w2;
    if (w1 < w2) swap(w1, w2), swap(h1, h2);
    i64 ans = 0;
    if (w1 >= 1000) {
        for (i64 a = 0; a * w1 <= C; ++a) {
            i64 b = (C - a * w1) / w2;
            uax(ans, a * h1 + b * h2);
        }
    } else {
        for (i64 a = 0; a <= 10000 && a * w1 <= C; ++a) {
            i64 b = (C - a * w1) / w2;
            uax(ans, a * h1 + b * h2);
        }
        for (i64 b = 0; b <= 10000 && b * w2 <= C; ++b) {
            i64 a = (C - b * w2) / w1;
            uax(ans, a * h1 + b * h2);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}