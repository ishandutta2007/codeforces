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
#define next next228
#define rank rank228
#define prev prev228
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
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
} 



int powm(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}


const int MAXN = 5005;


int n, m, k;
int dp[MAXN][MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //  read(FILENAME);
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i + 1][j] = sum(mul(dp[i][j], j), mul(dp[i][j - 1], Mod + n - j + 1));
        }
    }
    int kek = powm(m, Mod - 2);
    int cur = 1;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        cur = mul(cur, kek);
        ans = sum(ans, mul(dp[k][i], cur));
    }
    cout << ans << '\n';
}