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
const int Mod =  998244353;


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


const int MAXN = 1000228;


int n;
int dp[MAXN], pdp[MAXN], dp2[MAXN];


void solve() {
    cin >> n;
    if (n == 1) {
        cout << 5 << '\n';
        return;
    }
    dp[0] = 1;
    pdp[0] = 1;
    int dva = powm(2, Mod - 2);
    for (int i = 1; i <= n; i++) {
        dp[i] = sum(dp[i - 1], sum(mul(dp[i - 1], (i == 1 ? 0: pdp[i - 2])), mul(mul(dp[i - 1], dp[i - 1] + 1), dva)));
        pdp[i] = sum(dp[i], pdp[i - 1]);
        dp2[i] = sum(dp[i], Mod - dp[i - 1]);
    }
    int ans = sum(dp[n], mul(mul(dp[n - 1], mul(pdp[n - 2], pdp[n - 2] + 1)), powm(2, Mod - 2)));
    ans = sum(ans, mul(mul(pdp[n - 2], mul(dp[n - 1], dp[n - 1] + 1)), powm(2, Mod - 2)));
    ans = sum(ans, mul(mul(dp[n - 1], mul(dp[n - 1] + 1, dp[n - 1] + 2)), powm(6, Mod - 2)));
    ans = mul(ans, 2);
    ans = sum(ans, Mod - 1);
    for (int i = 0; i < n; i++) {
        ans = sum(ans, mul(sum(dp[i], Mod - 1), dp2[n - i - 1]));
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
   // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}