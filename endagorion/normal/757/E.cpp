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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1000000, maxk = 20;
const int P = 1000000000 + 7;

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int mind[maxn + 1];
int sum[maxn + 1][maxk + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    vi primes;
    for1(i, maxn) mind[i] = i;
    for (int i = 2; i <= maxn; ++i) {
        if (i == mind[i]) primes.pb(i);
        for (int p: primes) {
            if (p > mind[i] || 1LL * i * p > maxn) break;
            mind[i * p] = p;
        }
    }
    forn(i, maxk + 1) sum[0][i] = (i > 0 ? 2 : 1);
    for1(i, maxn) {
        int s = 0;
        forn(j, maxk + 1) {
            add(s, sum[i - 1][j]);
            sum[i][j] = s;
        }
    }

    int q;
    cin >> q;
    forn(i, q) {
        int r, n;
        cin >> r >> n;
        int ans = 1;
        while (n > 1) {
            int k = mind[n];
            int z = 0;
            while (n % k == 0) n /= k, ++z;
            ans = 1LL * ans * sum[r][z] % P;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}