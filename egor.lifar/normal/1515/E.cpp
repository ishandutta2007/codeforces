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
int Mod;


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


const int MAXN = 405;


int n;
int c[MAXN][MAXN];
int dp[MAXN][2][2];
int dp1[MAXN][MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> Mod;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
            }
        }
    }
    for (int t = 0; t < 2; t++) {
        for (int t1 = 0; t1 < 2; t1++) {
            dp[0][t][t1] = 1;
        }
    }       
    for (int len = 1; len <= n; len++) {
        for (int t = 0; t < 2; t++) {
            for (int t1 = 0; t1 < 2; t1++) {
                if (len == 1 && t == 1 && t1 == 1) {
                    continue;
                } 
                for (int f = 1; f <= len; f++) {
                    int val = mul(dp[f - 1][t][1], dp[len - f][1][t1]);
                    if (val == 0) {
                        continue;
                    }
                    val = mul(val, c[len - 1][f - 1]);
                    dp[len][t][t1] = sum(dp[len][t][t1], val);
                }
            }
        }
    }
    dp1[0][0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int have = 0; have <= n; have++) {
            if (!dp1[i][have]) continue;
            for (int j = i; j < n; j++) {
                int val = dp[j - i + 1][0][0];
                int val1 = mul(dp1[i][have], val);
                val1 = mul(val1, c[have + j - i + 1][j - i + 1]);
                if (j == n - 1) {
                    ans = sum(ans, val1);
                } else {
                    dp1[j + 2][have + j - i + 1] = sum(dp1[j + 2][have + j - i + 1], val1);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}