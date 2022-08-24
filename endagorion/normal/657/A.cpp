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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, d, h;
    cin >> n >> d >> h;
    if (n == 2) {
        if (d == 1 && h == 1) {
            cout << 1 << ' ' << 2 << '\n';
        } else cout << -1 << '\n';
        return 0;
    }
    if (d == 1) {
        cout << -1 << '\n';
        return 0;
    }
    if (d > 2 * h) {
        cout << -1 << '\n';
        return 0;
    }
    forn(i, h) cout << i + 1 << ' ' << i + 2 << '\n';
    if (d > h) {
        cout << 1 << ' ' << h + 2 << '\n';
        forn(j, d - h - 1) cout << h + 2 + j << ' ' << h + 3 + j << '\n';
        for (int j = d + 2; j <= n; ++j) cout << h << ' ' << j << '\n';
    } else {
        for (int j = h + 2; j <= n; ++j) cout << j << ' ' << h << '\n';
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}