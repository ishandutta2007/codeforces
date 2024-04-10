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
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxs = 1000001;

ld prob[2][maxs];
ld pref[maxs];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 1 << '\n';
        return 0;
    }
    prob[0][0] = 1.0;
    int total = 0;
    forn(i, n) {
        int x;
        cin >> x;
        total += x;
        int s = i * m;
        forn(j, s + m + 1) pref[j + 1] = pref[j] + prob[0][j];
        forn(j, s + m + 1) {
            prob[1][j] = pref[j];
            if (j >= m) prob[1][j] -= pref[j - m];
            if (j >= x) prob[1][j] -= prob[0][j - x];
            prob[1][j] /= m - 1;
        }
        forn(j, s + m + 1) prob[0][j] = prob[1][j];
    }
    double ans = 0.0;
    forn(i, total) ans += prob[0][i];
    cout << 1.0 + (m - 1) * ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}