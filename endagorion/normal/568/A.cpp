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

const int MAXN = 20000000;
int mind[MAXN], pc[MAXN], palc[MAXN];
int d[10];

bool ispal(int x) {
    if (x <= 0) return false;
    int c = 0;
    while (x) {
        d[c++] = x % 10;
        x /= 10;
    }
    forn(i, c) {
        if (d[i] != d[c - i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    vi primes;
    forn(i, MAXN) mind[i] = i;
    for (int i = 2; i < MAXN; ++i) {
        if (mind[i] == i) primes.pb(i);
        pc[i] = pc[i - 1] + (mind[i] == i);
        for (int p: primes) {
            if (p > mind[i] || 1LL * p * i >= MAXN) break;
            mind[i * p] = p;
        }
    }
//    cerr << "pc\n";
    for1(i, MAXN - 1) {
        palc[i] = palc[i - 1] + ispal(i);
    }

    int p, q;
    int ans = -1;
    cin >> p >> q;
    for1(i, MAXN - 1) {
        if (1LL * q * pc[i] <= 1LL * p * palc[i]) ans = i;
    }
    assert(ans >= 0);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}