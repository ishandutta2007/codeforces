/*
 












 
 */
#pragma GCC optimize "-oFast"
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
const int MAXN = 1000228;


int n, k;
vector<int> g[MAXN];
bool good[MAXN];
int pr[MAXN];
int in[MAXN];
int out[MAXN];
int deep[MAXN];
int timer = 0;


void dfs(int u, int prev = -1) {
    pr[u] = prev;
    timer++;
    in[u] = timer;
    for (auto h: g[u]) {
        if (h != prev) {
            deep[h] = deep[u] + 1;
            dfs(h, u);
        }
    }
    out[u] = timer;
}


int mod[MAXN * 4];
int d[MAXN * 4];
int ss = 1;


void push(int v) {
    if (mod[v]) {
        chkmax(d[v], mod[v]);
        if (v < ss) {
            chkmax(mod[v * 2], mod[v]);
            chkmax(mod[v * 2 + 1], mod[v]);
        }
        mod[v] = 0;
    }
}


void add(int v, int vl, int vr, int l, int r, int x) {
    if (vl > r || vr < l) {
        push(v);
        return;
    }
    if (l <= vl && vr <= r) {
        chkmax(mod[v], x);
        push(v);
        return;
    }
    push(v);
    add(v * 2, vl, (vl + vr) / 2, l, r, x);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x); 
    d[v] = max(d[v * 2], d[v * 2 + 1]);
}


int get(int i) {
    int ans = max(d[i], mod[i]);
    while (i >> 1 > 0) {
        i >>= 1;
        chkmax(ans, mod[i]);
    } 
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //read(FILENAME);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(n - 1);
    while (ss < n) {
        ss <<= 1;
    }
    good[n - 1] = true;
    int curcnt = 1;
    for (int i = n - 2; i >= 0; i--) {
        int s = get(ss + in[i] - 1);
        if (curcnt + deep[i] - s <= n - k) {
            int cur = i;
            while (cur >= 0 && !good[cur]) {
                good[cur] = true;
                add(1, 1, ss, in[cur], out[cur], deep[cur]);
                cur = pr[cur];
                curcnt++;
            }   
        }
    }
    for (int i = 0; i < n; i++) {
        if (!good[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
    return 0;
}