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

vi operator+(vi a, vi b) {
    vi c(a.size());
    forn(i, a.size()) c[i] = a[i] + b[i];
    return c;
}

vi operator-(vi a, vi b) {
    vi c(a.size());
    forn(i, a.size()) c[i] = a[i] - b[i];
    return c;
}

const int maxn = 210000;
const i64 P = 1000000000 + 7;

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

i64 fact[maxn], tcaf[maxn];

i64 cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    fact[0] = tcaf[0] = 1;
    for1(i, n) fact[i] = i * fact[i - 1] % P, tcaf[i] = deg(fact[i], -1);
/*
//    vi64 a(n);
    vvi a(n, vi(n));
//    forn(i, n) cin >> a[i];
    forn(i, n) a[i][i] = 1;
    bool add = true;
    while (a.size() > 1) {
        vvi b(a.size() - 1);
        forn(i, b.size()) {
            if (add) b[i] = a[i] + a[i + 1];
            else b[i] = a[i] - a[i + 1];
//            b[i] %= P;
            add ^= 1;
        }
        a = b;
    }
    forn(i, n) cout << a[0][i] << ' ';
    cout << '\n';
//    if (a[0] < 0) a[0] += P;
//    cout << a[0] << '\n';
*/
    
    vi a(n);
    forn(i, n) cin >> a[i];
    i64 sum = 0;
    forn(i, n) {
        i64 coef = 0;
        if (n % 4 == 1) {
            if (i % 2 == 0) coef = cnk(n / 2, i / 2);
        } else if (n % 4 == 2) {
            coef = cnk(n / 2 - 1, i / 2);
        } else if (n % 4 == 3) {
            coef = cnk(n / 2 - 1, i / 2);
            if (i) coef += cnk(n / 2 - 1, (i - 1) / 2) * (i % 2 ? 1 : -1);
        } else coef = cnk(n / 2 - 1, i / 2) * (i % 2 ? -1 : 1);
//        cerr << coef << ' ';
        sum += a[i] * coef;
        sum %= P;
    }
//        cerr << '\n';
    if (sum < 0) sum += P;
    cout << sum << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}