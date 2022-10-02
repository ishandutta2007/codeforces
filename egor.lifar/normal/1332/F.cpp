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
const int MAXN = 300228;
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}

int mul(int a, int b) {
    return (ll)a * b % Mod;
}


int n;
vector<int> g[MAXN];
int dp[MAXN][2][2];


void dfs(int u, int pr = -1) {
    vector<int> sons;
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        dfs(h, u);
        sons.pb(h);
    }
    if (sons.empty()) {
        dp[u][1][1] = 1;
        dp[u][0][0] = 1;
        return;
    }
    dp[u][0][0] = 1;
    dp[u][1][1] = 1;
    for (auto x: sons) {
        int dp1[2][2];
        memset(dp1, 0, sizeof(dp1));
        for (int f = 0; f < 2; f++) {
            for (int f1 = 0; f1 < 2; f1++) {
                for (int t = 0; t < 2; t++) {
                    for (int need = 0; need < 2; need++) {
                        for (int on = 0; on < 2; on++) {
                            if (need && !on) {
                                continue;
                            }
                            if (f && t && on) {
                                continue;
                            }
                            int nf1 = f1;
                            if (on) {
                                nf1 = 0;
                            }
                            int val = dp[x][t][need];
                            dp1[f][nf1] = sum(dp1[f][nf1], mul(dp[u][f][f1], val));
                        }
                    }
                }
            }
        }
        for (int f = 0; f < 2; f++) {
            for (int f1 = 0; f1 < 2; f1++) {
                dp[u][f][f1] = dp1[f][f1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    cout << sum(sum(dp[0][1][0], dp[0][0][0]), Mod - 1) << '\n';
    return 0;
}