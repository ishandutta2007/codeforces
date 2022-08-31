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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    double l = 0.0, r = 2e9;
    forn(ITS, 100) {
        double m = (l + r) * 0.5;
        double minad = 8e18, maxad = -8e18, minbc = 8e18, maxbc = -8e18;
        forn(ta, 2) forn(tb, 2) {
            uin(minad, (a + (2 * ta - 1) * m) * (d + (2 * tb - 1) * m)); 
            uax(maxad, (a + (2 * ta - 1) * m) * (d + (2 * tb - 1) * m));
        }
        forn(ta, 2) forn(tb, 2) {
            uin(minbc, (b + (2 * ta - 1) * m) * (c + (2 * tb - 1) * m)); 
            uax(maxbc, (b + (2 * ta - 1) * m) * (c + (2 * tb - 1) * m));
        }
        (max(minad, minbc) <= min(maxad, maxbc) ? r : l) = m;
    }                                                        
    cout << r << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}