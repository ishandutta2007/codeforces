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

int n;
string s;
const i64 P = 1000000000 + 7;
i64 a[1 << 20];
i64 d2[21];

void transform(int m, int b) {
    if (b == -1) {
        a[m] *= a[m];
        return;
    }
    forn(i, 1 << b) {
        i64 x = a[m + i], y = a[m + (1 << b) + i];
        a[m + i] = x + y;
        a[m + (1 << b) + i] = x - y;
    }
    transform(m, b - 1);
    transform(m | (1 << b), b - 1);
    forn(i, 1 << b) {
        i64 x = a[m + i], y = a[m + (1 << b) + i];
        a[m + i] = (x + y) / 2;
        a[m + (1 << b) + i] = (x - y) / 2;
    }
}

int popcount(int x) {
    int ans = 0;
    while (x) ++ans, x &= x - 1;
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

    cin >> n >> s;
    forn(i, 1 << n) a[i] = s[i] - '0';
    transform(0, n - 1);
//    forn(i, 1 << n) cerr << a[i] << ' ' ;
//    cerr << '\n';
    d2[0] = 1;
    forn(i, n) d2[i + 1] = d2[i] * 2 % P;

    i64 ans = 0;
    forn(m, 1 << n) (ans += a[m] * (d2[n - popcount(m)])) %= P;
    ans = ans * 3 % P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}