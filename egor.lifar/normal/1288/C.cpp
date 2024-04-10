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
const int Mod = 1000000007;
const int MAXN = 400228;


int sum(const int a, const int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}

int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


void add(int &a, const int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
}


int powm(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int n, m;
int dp[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    //b1 >= b2
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 1; j <= k; j++) {
                add(dp[j + 1], dp[j]);
            }
        }
        int res = 0;
        int pt1 = 0;
        for (int j = 1; j <= k; j++) {
            add(res, dp[j]);
            add(pt1, res);
        }
        memset(dp, 0, sizeof(dp));
        dp[k] = 1;
        for (int i = 0; i < m - 1; i++) {
            for (int j = k; j <= n; j++) {
                if (i != 0) {
                    add(dp[j + 1], dp[j]);
                }
            }
        }
        int res1 = 0;
        int pt = 0;
        for (int j = k; j <= n; j++) {
               add(res1, dp[j]);
            add(pt, res1);
        }
        if (m == 1) {
            pt = 1;
        }
        ans = sum(ans, mul(pt1, pt));
    }
    cout << ans << '\n';
    return 0;    
}