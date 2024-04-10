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
const int MAXN = 505;
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b) % Mod;
}


int mul(int a, int b) {
    return (1LL * a * b) % Mod;
}


int n, m;
int c[MAXN];
int pos[MAXN];
int dp[MAXN][MAXN];
int llen[MAXN];
int rlen[MAXN];
int l[MAXN], r[MAXN];
int ls[MAXN], rs[MAXN];
int cc[MAXN];
int divdp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        pos[c[i]] = i;
        cc[i] = c[i];
    }
    for (int i = n; i >= 1; i--) {
        int uk = pos[i];
        while (uk > 0 && c[uk - 1] == 0) {
            uk--;
        }
        int uk1 = pos[i];
        while (uk1 + 1 < m && c[uk1 + 1] == 0) {
            uk1++;
        }
        l[i] = (uk == 0 ? -1: c[uk - 1]);
        r[i] = (uk1 == m - 1 ? -1: c[uk1 + 1]);
        ls[i] = uk;
        rs[i] = uk1;
        llen[i] = pos[i] - uk + 1;
        rlen[i] = uk1 - pos[i] + 1;
        c[pos[i]] = 0;
    }
    for (int j = m - 1; j >= 0; j--) {
        for (int k = j; k < m; k++) {
            if (j == k) {
                dp[j][k] = 1;
                continue;
            }
            int ress = 1e9;
            for (int t = j; t <= k; t++) {
                chkmin(ress, cc[t]);
            }
            int g = pos[ress];
            int res = 0;
            for (int f = g - 1; f >= j - 1; f--) {
                res = sum(res, mul((f < j ? 1: dp[j][f]), (f + 1 > g - 1 ? 1: dp[f + 1][g - 1])));
            }
            if (g == j) {
                res = 1;
            }
            int res1 = 0;
            for (int f = g + 1; f <= k + 1; f++) {
                res1 = sum(res1, mul((k < f ? 1: dp[f][k]), (g + 1 > f - 1 ? 1: dp[g + 1][f - 1])));
            }
            if (g == k) {

                res1 = 1;
            }
           // cout << res << ' ' << res1 << endl;
            dp[j][k] = mul(res, res1);
        }
    }
    cout << dp[0][m - 1] << '\n';
    return 0;
}