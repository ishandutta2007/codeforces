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


const int MAXN = 105;

int n, k;
vector<int> g[MAXN];
int deep[MAXN];


void dfs(int u) {
    deep[u] = 1;
    for (auto h: g[u]) {
        dfs(h);
        chkmax(deep[u], deep[h] + 1);
    }
}


bool need[MAXN];


void findfuck(int u, int &k) {
    if (k) {
        k--;
        need[u] = true;
    }
    for (auto h: g[u]) {
        if (k) {
            findfuck(h, k);
        }
    }
}


int cnt = 0;
int bd;
vector<int> st;


void dfse(int u) {
    if (need[u]) {
        st.pb(u);
        cnt++;
    }
    reverse(all(g[u]));
    for (auto h: g[u]) {
        dfse(h);
        if (cnt < bd && need[h]) {
            if (need[u]) {
                st.pb(u);
            }
        }
    }
    
}


void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        need[i] = false;
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    } 
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
            continue;
        }
        int opt = g[i][0];
        for (auto h: g[i]) {
            if (deep[h] > deep[opt]) {
                opt = h;
            }
        }
        for (auto &h: g[i]) {
            if (h == opt) {
                swap(h, g[i][0]);
                break;
            }
        }
    }
    st.clear();
    bd = k;
    findfuck(0, k);
    cnt = 0;
    dfse(0);
    cout << sz(st) - 1 << '\n';
    for (auto x: st) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}