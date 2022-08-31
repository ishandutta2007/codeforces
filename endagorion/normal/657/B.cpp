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

    int n;
    i64 k;
    cin >> n >> k;
    vi64 a(n + 1);
    forn(i, n + 1) cin >> a[i];
    vi64 gr(n + 2);
    gr[n + 1] = 0;
    for (int i = n; i >= 0; --i) {
        gr[i] = 2 * gr[i + 1] + a[i];
        uin(gr[i], 10 * (k + 1));
        uax(gr[i], -10 * (k + 1));
    }

    i64 s = 0;
    int ans = 0;
    forn(i, n + 1) {
        if (s % 2) break;
        s /= 2;
        i64 x = s + 2 * gr[i + 1];
//        cerr << s << ' ' << gr[i + 1] << ' ' << x << '\n';
        if (abs(x) <= k) {
            if (i != n || x != 0) ++ans;
        }
        s += a[i];
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}