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

const i64 P = 1000000000 + 7;
const int maxn = 210000;
i64 fact[maxn], tcaf[maxn];

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        x *= x, x %= P;
        d /= 2;
    }
    return y;
}

i64 cnk(i64 n, i64 k) {
    if (n == -1) return k == -1 ? 1 : 0;
    if (n < 0) return 0;
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = tcaf[0] = 1;
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P, tcaf[i] = deg(fact[i], -1);

    int f, w, h;
    cin >> f >> w >> h;
    i64 total = 0;
    forn(i, f + 1) {
        add(total, (i ? 2 : 1) * cnk(f - 1, i - 1) * cnk(w - 1, i - 1));
        add(total, cnk(f - 1, i - 1) * cnk(w - 1, i - 2));
        add(total, cnk(f - 1, i - 1) * cnk(w - 1, i));
    }
    //++h;
    swap(f, w);

    i64 good = 0;
    forn(i, f + 1) {
        add(good, (i ? 2 : 1) * cnk(f - 1LL * h * i - 1, i - 1) * cnk(w - 1, i - 1));
        add(good, cnk(f - 1LL * h * i - 1, i - 1) * cnk(w - 1, i));
        add(good, cnk(f - 1LL * h * i - 1, i - 1) * cnk(w - 1, i - 2));
    }
    cout << good * deg(total, -1) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}