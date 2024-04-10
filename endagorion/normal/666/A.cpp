#include <iostream>
#include <tuple>
#include <sstream>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 11000;

char dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    cin >> s;
    int n = s.size();
    dp[n - 3][n] = dp[n - 2][n] = 1;
    set<string> ans;
    ford(i, n) {
        for (int j = i + 2; j <= i + 3; ++j) {
            for (int k = 2; k <= 3; ++k) {
                int jj = j + k;
                if (jj > n) break;
                if (dp[j][jj] && string(s.begin() + i, s.begin() + j) != string(s.begin() + j, s.begin() + jj)) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    forn(i, n + 1) for (int j = i + 2; j <= i + 3; ++j) {
        if (i >= 5 && dp[i][j]) ans.insert(string(s.begin() + i, s.begin() + j));
    }

    cout << ans.size() << '\n';
    for (string s: ans) cout << s << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}