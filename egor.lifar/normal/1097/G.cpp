/*
 












 
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
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
const string FILENAME = "input";
const int MAXN = 100228;
const int MAXK = 256;
const int Mod = 1000000007;
const unsigned long long Mod1 = 8ULL * Mod * Mod;


void inc(int &a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
}


int add(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


void dec(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += Mod;
    }
}


int sub(int a, int b) {
    return (a - b >= 0 ? a - b: a - b + Mod);
}


int mul(long long a, long long b) {
    return (a * b) % Mod;
}

int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int rev(int a) {
    return powm(a, Mod - 2);
}


int fact[MAXK], rfact[MAXK], ri[MAXK];
int n, k;
vector<int> g[MAXN];
int dp[MAXN][MAXK];
unsigned long long A[MAXK], B[MAXK], C[MAXK];
int ans = 0;


void pmul() {
    memset(C, 0, sizeof(C));
    for (int i = 0; i <= k; i++) {
        if (i % 8 == 0) {
            for (int j = 0; j <= k; j++) {
                if (C[j] >= Mod1) {
                    C[j] -= Mod1;
                }
            }
        }
        unsigned long long x = A[i];
        for (int j = 0; j <= k - i; j++) {
            C[i + j] += B[j] * x;
        }
    }
    for (int j = 0; j <= k; j++) {
        C[j] %= Mod;
    }
}



void muldp(int a, int b, int c) {
    for (int i = 0; i <= k; i++) {
        A[i] = dp[a][i];
        B[i] = dp[b][i];
    }
    pmul();
    for (int i = 0; i <= k; i++) {
        dp[c][i] = C[i];
    }
}


void dfs(int u, int pr) {
    dp[u][0] = 1;
    int sums = 0;
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        dfs(h, u);
        muldp(u, h, MAXN - 1);
        inc(sums, dp[h][k]);
        for (int i = 0; i <= k; i++) {
            inc(dp[u][i], dp[MAXN - 1][i]);
        }
    }
    inc(ans, dp[u][k]);
    inc(ans, dp[u][k]);
    dec(ans, sums);
    memset(dp[MAXN - 2], 0, sizeof(dp[MAXN - 2]));
    for (int i = 0; i <= k; i++) {
        dp[MAXN - 2][i] = rfact[i];
    }
    muldp(u, MAXN - 2, u);
    for (int i = 0; i <= k; i++) {
        inc(dp[u][i], dp[u][i]);
        dec(dp[u][i], rfact[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    fact[0] = 1;
    rfact[0] = 1;
    ri[1] = 1;
    for (int i = 1; i < MAXK; i++) {
        fact[i] = mul(fact[i - 1], i);
        ri[i] = rev(i);
        rfact[i] = mul(rfact[i - 1], ri[i]);
    }
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    ans = mul(ans, fact[k]);
    cout << ans << '\n';
    return 0; 
}