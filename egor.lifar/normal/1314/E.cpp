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
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 2035;
const int Mod = 998244353;


int sum(const int a, const int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(const int a, const int b) {
    return (ll)a * b % Mod;
}


int n, k;
int dp[2][MAXN][MAXN];
int ans = 0;


bool can(vector<int> a) {
    for (int i = 0; i < k - 1; i++) {
        vector<int> st;
        for (int j = 0; j < sz(a); j++) {
            for (int k = 0; k < a[j]; k++) {
                st.pb(j + 1);
                if (sz(st) > n) {
                    return false;
                }
            }
        }
        reverse(all(st));
        swap(a, st);
    }
    int sum = 0;
    for (int j = 0; j < sz(a); j++) {
        sum += a[j];
    }
    if (sum > n) {
        return false;
    }
    return true;
}

vector<int> a;

void get(int n) {
    if (n == 0) {
        return;
    }
    a.pb(n);
    if (can(a)) {
        ans++;
        get(n);
    } 
    a.pop_back();
    get(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> k;
    if (k == 1) {
        int ans = 0;
        dp[0][0][n] = 1;
        for (int i = 0; i <= n; i++) {
            for (int last = n; last >= 1; last--) {
                if (!dp[0][i][last]) {
                    continue;
                }
                int cur = i + last;
                if (cur <= n) {
                    dp[0][cur][last] = sum(dp[0][cur][last], dp[0][i][last]);
                }
                dp[0][i][last - 1] = sum(dp[0][i][last - 1], dp[0][i][last]);
            }
            if (i != 0) {
               ans = sum(ans, dp[0][i][0]);   
            }
        }
        cout << ans << '\n';
        return 0;
    }
    if (k == 2) {
        int g = 0;
        dp[0][0][n] = 1;
        int ans = 0;
        for (int t = 1; t <= 80; t++) {
            for (int i = 0; i <= n; i++) {
                for (int last = n; last >= 1; last--) {
                    if (!dp[g][i][last]) {
                        continue;
                    }
                    int cur = i + last * t;
                    if (cur <= n) {
                        dp[g ^ 1][cur][last] = sum(dp[g ^ 1][cur][last], dp[g][i][last]);
                    }
                    dp[g][i][last - 1] = sum(dp[g][i][last - 1], dp[g][i][last]);
                }
                if (i != 0) {
                   ans = sum(ans, dp[g][i][0]);   
                }
            }
            g ^= 1;
            memset(dp[g ^ 1], 0, sizeof(dp[g ^ 1]));
        }
        cout << ans << '\n';
        return 0;
    }
    if (k > 10) {
        cout << 1 << '\n';
        return 0;
    }
    get(n);
    cout << ans << '\n';
    return 0;
}