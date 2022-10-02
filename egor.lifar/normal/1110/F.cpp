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
#include <array>
       
        
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
const int MAXN = 500228;


int n, q;
vector<pair<int, int> > g[MAXN];
long long deep[MAXN];
int uk = 0;
int pos[MAXN];
int gr[MAXN];



struct rmq
{
    int ss;
    vector<long long> val;
    vector<long long> mod;
    void init(int n) {
        ss = 1;
        while (ss < n) {
            ss <<= 1;
        }
        val.resize(2 * ss, 0);
        mod.resize(2 * ss, 0);
    }
    void push(int v) {
        if (mod[v] != 0) {
            val[v] += mod[v];
            if (v < ss) {
                mod[v * 2] += mod[v];
                mod[v * 2 + 1] += mod[v];
            }
            mod[v] = 0;
        }
    }
    void add(int v, int vl, int vr, int l, int r, long long x) {
        if (l > r) {
            return;
        }
        if (vl > r || vr < l) {
            push(v);
            return;
        }
        if (l <= vl && vr <= r) {
            mod[v] += x;
            push(v);
            return;
        } 
        push(v);
        add(v * 2, vl, (vl + vr) / 2, l, r, x);
        add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
        val[v] = min(val[v * 2], val[v * 2 + 1]);
    }
    long long get(int v, int vl, int vr, int l, int r) {
        if (vl > r || vr < l) {
            return 1e18;
        }
        if (l <= vl && vr <= r) {
            return val[v] + mod[v];
        } 
        push(v);
        return min(get(v * 2, vl, (vl + vr) / 2, l, r), get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
    }
};


rmq tr;
vector<pair<pair<int, int>, int> > kek[MAXN];


void dfs(int u, int pr = -1) {
    uk++;
    pos[u] = uk;
    for (auto h: g[u]) {
        if (h.first != pr) {
            deep[h.first] = deep[u] + h.second;
            dfs(h.first, u);
        }
    }
    gr[u] = uk;
}

long long ans[MAXN];

void dfs1(int u, int pr = -1) {
    for (auto h: g[u]) {
        if (h.first != pr) {
            tr.add(1, 1, tr.ss, pos[h.first], gr[h.first], -h.second);
            tr.add(1, 1, tr.ss, 1, pos[h.first] - 1, h.second);
            tr.add(1, 1, tr.ss, gr[h.first] + 1, n, h.second);
            dfs1(h.first, u);
            tr.add(1, 1, tr.ss, pos[h.first], gr[h.first], +h.second);
            tr.add(1, 1, tr.ss, 1, pos[h.first] - 1, -h.second);
            tr.add(1, 1, tr.ss, gr[h.first] + 1, n, -h.second);
        }
    }   
    for (auto x: kek[u]) {
        ans[x.second] = tr.get(1, 1, tr.ss, x.first.first, x.first.second);
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p, w;
        cin >> p >> w;
        p--;
        g[p].pb({i, w});
    }
    for (int i = 0; i < n; i++) {
        sort(all(g[i]));
    }
    dfs(0);
    tr.init(n);
    for (int i = 0; i < n; i++) {
        if (sz(g[i]) == 0) {
            //cout << i << endl;
            tr.add(1, 1, tr.ss, pos[i], pos[i], deep[i]);
        } else {    
            tr.add(1, 1, tr.ss, pos[i], pos[i], 1000000000000000000LL);
        }
    }
    //cout << tr.get(1, 1, tr.ss, pos[4], pos[4]) << endl;
    for (int it = 0; it < q; it++) {
        int v, l, r;
        cin >> v >> l >> r;
        v--;
        kek[v].pb({{l, r}, it});
    }
    //cout << pos[4] << endl;
    dfs1(0);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;       
}