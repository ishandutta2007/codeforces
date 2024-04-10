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

int ans[30001][601];
int cost[30001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, D;
    cin >> N >> D;
    forn(i, N) {
        int x;
        cin >> x;
        ++cost[x];
    }
    forn(i, 30001) forn(j, 601) ans[i][j] = -1e9;
    ans[D][300] = cost[D];
    int res = 0;
    for (int i = D; i <= 30000; ++i) {
        for (int j = 0; j <= 600; ++j) {
            if (ans[i][j] < 0) continue;
            uax(res, ans[i][j]);
            for (int k = -1; k <= 1; ++k) {
                int v = D + j - 300 + k;
                if (v <= 0 || i + v > 30000) continue;
                uax(ans[i + v][j + k], ans[i][j] + cost[i + v]);
            }
        }
    }
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}