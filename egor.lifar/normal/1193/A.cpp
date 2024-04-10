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
const int MAXN = 18;
const int Mod = 998244353;


inline int mul(const int& a, const int& b) {
    return (1LL * a * b) % Mod;
}


inline int sum(const int& a, const int& b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int n, m;
bool g[MAXN][MAXN];
bool good[(1 << 18) + 228];
int dp[(1 << 18) + 228];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> m;
    vector<pair<int, int> > st;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = true;
        g[b][a] = true;
    }   
    for (int i = 0; i < (1 << n); i++) {
        good[i] = true;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (((i >> j) & 1) && ((i >> k) & 1) && g[j][k]) {
                    good[i] = false;
                }
            }
        }
    }
    dp[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j; j = i & (j - 1)) {
            if (good[j]) {
                if (__builtin_popcount(j) & 1) {
                    dp[i] = sum(dp[i], dp[i ^ j]);
                } else {
                    dp[i] = sum(dp[i], Mod - dp[i ^ j]);
                }
            }
        }
    }
    int res = mul(mul(dp[(1 << n) - 1], m), powm(2, Mod - 2));
    cout << res << endl;
    return 0; 
}