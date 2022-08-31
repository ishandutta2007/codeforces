#include <iostream>
#include <vector>
#include <cassert>
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
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

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

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef unsigned long long u64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;

int N, M;
i64 P;

i64 dp[2][511][511];

void add(i64 &a, i64 b) {
    a += b; a %= P;
}

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    cin >> N >> M >> P;
    vi c(N);
    forn(i, M) {                                                                   
        string f;
        cin >> f;
        forn(j, N) if (f[j] == '1') ++c[j];
    }
    int x0 = 0, x1 = 0;
    forn(i, N) {
        if (c[i] == 0) ++x0;
        if (c[i] == 1) ++x1;
    }
//    dp[M][x0][x1] = 1;
    forn(i, N + 1) {
        int cur = i & 1, nxt = cur ^ 1;
        forn(j, N + 1) forn(k, N - j + 1) dp[nxt][j][k] = 0;
        if (i == M) dp[cur][x0][x1] = 1;
        forn(j, N + 1) forn(k, N - j + 1) {
            if (!dp[cur][j][k]) continue;
            if (j >= 2) add(dp[nxt][j - 2][k + 2], dp[cur][j][k] * j * (j - 1) / 2);
            if (j && k) add(dp[nxt][j - 1][k], dp[cur][j][k] * j * k);
            if (k >= 2) add(dp[nxt][j][k - 2], dp[cur][j][k] * k * (k - 1) / 2);
        }
    }
    cout << dp[N & 1][0][0] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}