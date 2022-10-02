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
const int MAXN = 6005;


int n;
vector<pair<int, int> > g[MAXN];
int as[MAXN], bs[MAXN];
int sz[MAXN];



void dfs(int u, int pr, int &k) {
    k++;
    for (auto h: g[u]) {
        if (h.first != pr) {
            dfs(h.first, u, k);
        }
    }
}


int kek;
vector<pair<int, int> > f[MAXN];
ll dp[MAXN][MAXN];


void dfs1(int u, int pr, int len, int lst) {
    f[len].pb({kek, lst});
    for (auto h: g[u]) {
        if (h.first != pr) {
            dfs1(h.first, u, len + 1, h.second);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);     
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        as[i * 2] = a;
        bs[i * 2] = b;
        as[i * 2 + 1] = b;
        bs[i * 2 + 1] = a;
        g[a].pb({b, i * 2});
        g[b].pb({a, i * 2 + 1});
    }
    for (int i = 0; i < 2 * n - 2; i++) {
        dfs(bs[i], as[i], sz[i]);
    }
    for (int i = 0; i < 2 * n - 2; i++) {
        kek = i ^ 1;
        dfs1(bs[i], as[i], 1, i);
    }
    ll res = 0;
    for (int len = 1; len <= n; len++) {
        for (auto x: f[len]) {
            if (len == 1) {
                dp[x.first][x.second] = sz[x.first] * sz[x.second];
            } 
            // cout << sz[x.first] << ' ' << sz[x.second] << '\n';
            chkmax(res, dp[x.first][x.second]);
            for (auto f: g[bs[x.first]]) {
                chkmax(dp[f.second][x.second], dp[x.first][x.second] + (ll)sz[f.second] * sz[x.second]);
            }
            for (auto f: g[bs[x.second]]) {
                chkmax(dp[x.first][f.second], dp[x.first][x.second] + (ll)sz[f.second] * sz[x.first]);
            }
        }
    }
    cout << res << '\n';
    return 0;
}