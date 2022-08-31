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

const int maxn = 110000;
int a[maxn];

bool isPrime(i64 x) {
    if (x <= 1) return false;
    for (i64 p = 2; p * p <= x; ++p) {
        if (x % p == 0) return false;
    }
    return true;
}

i64 deg(i64 x, i64 d, i64 p) {
    d %= p - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y = 1LL * y * x) %= p;
        (x = 1LL * x * x) %= p;
        d /= 2;
    }
    return y;
}

i64 ord(i64 x, i64 p) {
    i64 z = p - 1;
    i64 ord = p - 1;
    for (i64 y = 2; y * y <= z; ++y) {
        while (z % y == 0) {
            if (deg(x, ord / y, p) == 1) ord /= y;
            z /= y;
        }
    }
    if (z > 1 && deg(x, ord / z, p) == 1) ord /= z;
    return ord;
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
    string s;
    cin >> n >> s;
    forn(i, n) a[i] = s[i] - '0';
    i64 p;
    for (p = 10000 * n + 1; !isPrime(p); p += n) {}
    cerr << p << '\n';
    assert(p <= 4e9);
    i64 tries = 100;
    bool ok = true;
    i64 z = 2;
    while (tries) {
        while (z < p && ord(z, p) % n) ++z;
        assert(z < p);
        z = deg(z, ord(z, p) / n, p);
        i64 w = 1;
        i64 sum = 0;
        forn(i, n) {
            (sum += 1LL * w * a[i]) %= p;
            (w = 1LL * w * z) %= p;
        }
        if (sum) {
            ok = false;
            break;
        }
        --tries;
        ++z;
    }
    cout << (ok ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}