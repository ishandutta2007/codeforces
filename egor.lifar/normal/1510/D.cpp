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
const int Mod = 1000000009;


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


const int MAXN = 100228;


int n, d;
int a[MAXN];
double dp[MAXN][11];
int pr[MAXN][11];
bool vs[MAXN][11];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i <= n; i++) {
        for (int t = 0; t < 10; t++) {
            dp[i][t] = -1e9;
        }
    }
    for (int j = 0; j < n; j++) {
        dp[j + 1][a[j] % 10] = log(a[j]);
        pr[j + 1][a[j] % 10] = -1;
        vs[j + 1][a[j] % 10] = true;
    }
    for (int i = 0; i < n; i++) {
        double val = log(a[i]);
        for (int t = 0; t < 10; t++) {
            if (dp[i][t] >= 0) {
                if (dp[i + 1][t] < dp[i][t]) {
                    dp[i + 1][t] = dp[i][t];
                    pr[i + 1][t] = t;
                    vs[i + 1][t] = false;
                }
                int t1 = (t * (a[i] % 10)) % 10;
                if (dp[i + 1][t1] < val + dp[i][t]) {
                    dp[i + 1][t1] = val + dp[i][t];
                    pr[i + 1][t1] = t;
                    vs[i + 1][t1] = true;
                }
            }
        }
    }
    if (dp[n][d] < -1) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans;
    int cur = d;
    int p = n;
    while (cur != -1) {
        if (vs[p][cur]) {
            ans.pb(a[p - 1]);
        }
        cur = pr[p][cur];
        p--;
    }
    sort(all(ans));
    cout << sz(ans) << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}