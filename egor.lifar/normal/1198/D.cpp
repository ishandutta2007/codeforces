/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 55;


int n;
string s[MAXN];
int c[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#') {
                c[i][j] = 1;
            }
            c[i][j] += (i ? c[i - 1][j]: 0) + (j ? c[i][j - 1]: 0) - (i && j ? c[i - 1][j - 1]: 0);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            for (int i1 = i; i1 < n; i1++) {
                for (int j1 = j; j1 < n; j1++) {
                    int f = c[i1][j1] - (i ? c[i - 1][j1]: 0) - (j ? c[i1][j - 1]: 0) + (i && j ? c[i - 1][j - 1]: 0);
                    if (f == 0) {
                        dp[i][j][i1][j1] = 0;
                        continue;
                    }
                    if (j1 - j + 1 == i1 - i + 1) {
                        dp[i][j][i1][j1] = j1 - j + 1;
                    } else {
                        dp[i][j][i1][j1] = 1e9;
                    }
                    for (int k = i; k < i1; k++) {
                        chkmin(dp[i][j][i1][j1], dp[i][j][k][j1] + dp[k + 1][j][i1][j1]);
                    }
                    for (int k = j; k < j1; k++) {
                        chkmin(dp[i][j][i1][j1], dp[i][k + 1][i1][j1] + dp[i][j][i1][k]);
                    }
                }
            }
        }
    }
    cout << dp[0][0][n - 1][n - 1] << endl;
    return 0;
}