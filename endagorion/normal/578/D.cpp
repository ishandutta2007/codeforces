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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 N, M;
    cin >> N >> M;
    if (N == 1) {
        cout << M - 1 << '\n';
        return 0;
    }
    string s;
    cin >> s;
    i64 ans = N * (M - 1);
    forn(i, N - 1) {
        if (s[i] != s[i + 1]) ans += N * (M - 1);
    }
    vi dp(N);
    dp[N - 1] = 1;
    dp[N - 2] = s[N - 2] == s[N - 1] ? 1 : 2;
    ford(i, N - 2) {
        if (s[i] == s[i + 1]) dp[i] = 1;
        else if (s[i] == s[i + 2]) dp[i] = dp[i + 1] + 1;
        else dp[i] = 2;
    }
    forn(i, N) ans -= dp[i] - 1;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}