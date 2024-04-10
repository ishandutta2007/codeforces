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

const i64 P = 1000000000 + 7;
const int maxn = 1100000;
vi64 cnt[3];
i64 a[3][maxn];
int n, l, m;

vi64 mul(vi64 a, vi64 b) {
    vi64 c(m);
    forn(i, m) forn(j, m) (c[(i + j) % m] += a[i] * b[j]) %= P;
    return c;
}

vi64 deg(vi64 a, i64 d) {
    vi64 c(m);
    c[0] = 1;
    while (d) {
        if (d & 1) c = mul(c, a);
        a = mul(a, a);
        d /= 2;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> l >> m;
    forn(i, 3) cnt[i].resize(m);
    forn(i, 3) forn(j, n) {
        int x;
        cin >> x;
        a[i][j] = x;
        ++cnt[i][x % m];
    }

    vi64 y = mul(cnt[0], deg(cnt[1], l - 2));
    i64 ans = 0;
    forn(i, n) (ans += y[(2 * m - a[1][i] % m - a[2][i] % m) % m]) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}