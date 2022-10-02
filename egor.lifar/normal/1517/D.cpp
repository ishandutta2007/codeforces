/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
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


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 505;


int n, m, k;
int c[MAXN][MAXN], c1[MAXN][MAXN];
int dp[21][MAXN][MAXN];
pair<int, int> gk[2][MAXN * MAXN];
int ukg[2];


void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c1[i][j];
        }
    }
    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << ' ';
            } 
            cout << '\n';
        }
        return;
    }
    for (int f = 1; f <= k / 2; f++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[f][i][j] = 1e9;
            }
        }
    }
    for (int f = 0; f < k / 2; f++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = dp[f][i][j];
                if (val > 9e8) {
                    continue;
                }
                chkmin(dp[f + 1][i + 1][j], c1[i][j] + val);
                chkmin(dp[f + 1][i][j + 1], c[i][j] + val);
                if (i) {
                    chkmin(dp[f + 1][i - 1][j], c1[i - 1][j] + val);
                }
                if (j) {
                    chkmin(dp[f + 1][i][j - 1], c[i][j - 1] + val);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << 2 * dp[k / 2][i][j] << ' ';
        }
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}