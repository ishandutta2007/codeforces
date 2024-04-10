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

i64 deg(i64 x, i64 d) {
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x;
        x *= x; d /= 2;
    }
    return y;
}

bool isPrime(i64 x) {
    for (i64 i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

i64 isPDeg(i64 N) {
    for (int k = 1; (1LL << k) <= N; ++k) {
        i64 x = (i64)(pow(1.0 * N, 1.0 / k));
        while (deg(x + 1, k) <= N) ++x;
        if (deg(x, k) == N && isPrime(x)) return x;
    }
    return -1;
}

i64 ways[2][10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 N;
    cin >> N;
    vi64 divs;
    for (i64 x = 1; x * x <= N; ++x) {
        if (N % x) continue;
        divs.pb(x);
        if (x * x < N) divs.pb(N / x);
    }
    sort(all(divs));
    int K = divs.size();
    assert(K < 10000);
    map<i64, int> en;
    forn(i, K) en[divs[i]] = i;
    map<i64, vi64> pd;
    for (i64 x: divs) {
        i64 y = isPDeg(x - 1);
        if (y != -1) pd[y].pb(x);
    }

    ways[0][0] = ways[1][0] = 1;
    for (auto w: pd) {
        for (i64 x: w.se) {
//            for (i64 z: divs) {
            forn(i, K) {
                i64 z = divs[i];
                if (z > N / x) break;
                if (N % (x * z) || !ways[0][i]) continue;
                ways[1][en[x * z]] += ways[0][i];
            }    
        }
        forn(i, K) ways[0][i] = ways[1][i];
    }
    cout << ways[0][en[N]] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}