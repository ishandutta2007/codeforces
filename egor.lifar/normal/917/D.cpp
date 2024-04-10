
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
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
const int MAXN = 105;
const int Mod = 1000000007;


int sum(int a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
    return a;
}


inline void sume(int &a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
}


int mul(int a, int b) {
    return (1LL * a * b) % Mod;
}


int powm(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b & 1) {
        return mul(powm(a, b - 1), a);
    } else {
        int s = powm(a, b >> 1);
        return mul(s, s);
    }
}


int n;
int dp[MAXN][MAXN][MAXN], dp1[MAXN][MAXN];
int cnt[MAXN], cnk[MAXN][MAXN];
int sz[MAXN];
vector<int> g[MAXN];


void dfs(int v, int pr = -1) {
    dp[v][1][1] = 1;
    sz[v] = 1;
    for (auto u: g[v]) {
        if (u != pr) {
            dfs(u, v);
            for (int i = 0; i <= sz[u] + sz[v]; i++) {
                for (int j = 0; j <= sz[u] + sz[v]; j++) {
                    dp1[i][j] = 0;
                }
            }
            for (int j = 1; j <= sz[u]; j++) {
                for (int i = 1; i <= sz[v]; i++) {
                    for (int k = 1; k <= sz[u]; k++) {
                        for (int l = 1; l <= sz[v]; l++) {
                            sume(dp1[i + j - 1][l + k], mul(dp[v][i][l], dp[u][j][k]));
                            sume(dp1[i + j][l], mul(dp[v][i][l], mul(dp[u][j][k], k)));
                        }
                    }
                }
            }
            sz[v] += sz[u];
            for (int i = 0; i <= sz[v]; i++) {
                for (int j = 0; j <= sz[v]; j++) {
                    dp[v][i][j] = dp1[i][j];
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i <= n; i++) {
        cnk[i][0] = cnk[i][i] = 1;
        for (int j = 1; j < i; j++) {
            cnk[i][j] = sum(cnk[i - 1][j - 1], cnk[i - 1][j]);
        }
    }
    int mult = 1;
    cnt[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i > 2) {
            mult = mul(mult, n);
        }
        int now = 0;
        for (int j = 0; j <= sz[0]; j++) {
            sume(now, mul(dp[0][i][j], j));
        }
        cnt[i] = mul(now, mult);
        for (int j = 1; j < i; j++) {
            sume(cnt[i], Mod - mul(cnt[j], cnk[n - j][i - j]));
        }   
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[n + 1 - i] << ' ';
    }
    cout << '\n';
    return 0;     
}