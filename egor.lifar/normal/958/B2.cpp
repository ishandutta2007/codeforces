/*
 












 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
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
//WULD! NAH! KEST!
const int MAXN = 500228;


int n;
vector<int> g[MAXN];
int dist[MAXN];
bool good[MAXN];
int jump[MAXN];
int timer = 0;
int in[MAXN];
int out[MAXN];
int deep[MAXN];
int who[MAXN];
vector<int> v[MAXN];


void dfs(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h == pr) continue;
        dist[h] = dist[u] + 1;
        dfs(h, u);
    }
}


void dfspr(int u, int pr = -1) {
    timer++;
    who[timer]= u;
    in[u] = timer;
    for (auto h: g[u]) {
        if (h == pr) continue;
        jump[h] = u;
        v[u].pb(h);
        deep[h] = deep[u] + 1;
        dfspr(h, u);
    }
    out[u] = timer;
}


struct node
{
    int h;
    int sub;
    int id;
};


bool operator <(node a, node b) {
    return (a.h - a.sub < b.h - b.sub) || (a.h - a.sub == b.h - b.sub && a.id < b.id);
}


node d[MAXN * 4];
int mod[MAXN * 4];
int ss = 1;


void push(int u) {
    if (mod[u]) {
        chkmax(d[u].sub, mod[u]);
        if (u < ss) {
            chkmax(mod[u * 2], mod[u]);
            chkmax(mod[u * 2 + 1], mod[u]);
        }
        mod[u] = 0;
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
    add(v * 2, vl, (vl + vr) / 2, l, r, x);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
    d[v] = max(d[v * 2], d[v * 2 + 1]);
 }


void proceed(int u) {
    if (good[u]) return;
    add(1, 1, ss, in[u], out[u], deep[u]);
    while (u != -1 && !good[u]) {
        good[u] = true;
         add(1, 1, ss, in[u], in[u], deep[u]);
        for (auto h: v[u]) {
            if (!good[h]) {
                add(1, 1, ss, in[h], out[h], deep[u]);
            }
        }
        u = jump[u];
    }
    add(1, 1, ss, in[u], in[u], 1000000000);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    int root = 0;
    for (int i = 1; i < n; i++) {
        if (dist[i] > dist[root]) {
            root = i;
        }
    }
    jump[root] = -1;
    dfspr(root);
    good[root] = true;
    ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 1; i <= n; i++) {
        int u = who[i];
        d[ss + i - 1].id = u;
        d[ss + i - 1].h = deep[u];
        d[ss + i - 1].sub = 0;
    }
    for (int i = ss - 1; i >= 1; i--) {
        d[i] = max(d[i * 2], d[i * 2 + 1]);
    }
    int sum = 1;
    cout << sum << '\n';
    for (int it = 1; it < n; it++) {
        push(1);
        int f = d[1].id;
        sum += d[1].h - d[1].sub;
        cout << sum << '\n';
        proceed(f);
    }
    return 0;     
}