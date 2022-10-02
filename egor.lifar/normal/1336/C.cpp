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
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return (ll)a * b % Mod;
}


int n, m;
int dp[3005][3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    string s, t;
    cin >> s >> t;
    n = sz(s);
    m = sz(t);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            int id = j - i;
            if (i == j) {
                if (j >= m || (j < m && t[j] == s[id])) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = 0;
                }
                continue;
            }
            dp[i][j] = 0;
            if (j >= m || (j < m && t[j] == s[id])) {
                dp[i][j] = sum(dp[i][j], dp[i][j - 1]);
            }
            if (i >= m || (i < m && t[i] == s[id])) {
                dp[i][j] = sum(dp[i][j], dp[i + 1][j]);
            }
        }
    }
    int ans = 0;
    for (int t = m - 1; t < n; t++) {
        ans = sum(ans, dp[0][t]);
    }
    cout << ans << '\n';
}