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
const int MAXN = 100228;


int n, l;
long long s;
int w[MAXN];
vector<int> g[MAXN];
int jump[MAXN][20];
long long sum[MAXN][20];
int step[MAXN];
int deep[MAXN];


void dfs(int u) {
    for (auto h: g[u]) {
        jump[h][0] = u;
        sum[h][0] = w[u];
        deep[h] = deep[u] + 1;
        dfs(h);
    }
}


int dp[MAXN];
int up[MAXN];


void dfscalc(int u) {
    if (sz(g[u]) == 0) {
        dp[u] = 1;
        up[u] = deep[step[u]];
    } else {
        int t = 1e9;
        for (auto h: g[u]) {
            dfscalc(h);
            dp[u] += dp[h];
            chkmin(t, up[h]);
        }
        if (t > deep[u]) {
            dp[u]++;
            up[u] = deep[step[u]];
        } else {
            up[u] = t;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n >> l >> s;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        if (w[i] > s) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    dfs(0);
    for (int k = 1; k <= 18; k++) {
        for (int i = 0; i < n; i++) {
            jump[i][k] = jump[jump[i][k - 1]][k - 1];
            sum[i][k] = sum[i][k - 1] + sum[jump[i][k - 1]][k - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        int f = i;
        int curl = l - 1;
        long long curs = s - w[i];
        for (int k = 18; k >= 0; k--) {
            if (sum[f][k] <= curs && (1 << k) <= curl) {
                //cout << "p[a" << endl;
                curl -= (1 << k);
                curs -= sum[f][k];
                f = jump[f][k];
            }
        }
        step[i] = f;
       //  cout << step[i] << endl;
    }
    dfscalc(0);
    cout << dp[0] << '\n';
    return 0;
}