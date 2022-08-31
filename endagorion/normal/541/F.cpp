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

int d[101][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, T;
    cin >> N >> T;
    vector<pii> a(N);
    forn(i, N) {
        cin >> a[i].fi >> a[i].se;
        a[i].fi = T - a[i].fi;
    }
    sort(all(a));
    int j = 0;
    forn(i, 101) forn(j, 1001) d[i][j] = -1e9;
    d[0][1] = 0;
    forn(i, T) {
        for (; j < N && a[j].fi == i; ++j) {
            for1(k, N) uax(d[i][k - 1], d[i][k] + a[j].se);
        }
        forn(k, N + 1) uax(d[i + 1][min(2 * k, N)], d[i][k]);
    }
    int ans = 0;
    forn(k, N + 1) uax(ans, d[T][k]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}