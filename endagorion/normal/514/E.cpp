#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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

const i64 P = 1000000000 + 7;

vvi64 mul(const vvi64 &a, const vvi64 &b) {
    int N = a.size();
    vvi64 c(N, vi64(N));
    forn(i, N) forn(j, N) forn(k, N) {
        c[i][k] += a[i][j] * b[j][k];
        c[i][k] %= P;
    }
    return c;
}

vvi64 deg(vvi64 a, i64 d) {
    int N = a.size();
    vvi64 res(N, vi64(N));
    forn(i, N) res[i][i] = 1;
    while (d) {
        if (d & 1) res = mul(res, a);
        a = mul(a, a); d /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, X;
    cin >> N >> X;
    vvi64 c(101, vi64(101));
    c[100][0] = 1;
    c[100][100] = 1;
    forn(i, 99) c[i + 1][i] = 1;
    forn(i, N) {
        int d;
        cin >> d;
        ++c[0][d - 1];
    }
    vvi64 m = deg(c, X + 1);
    i64 ans = m[100][0];
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}