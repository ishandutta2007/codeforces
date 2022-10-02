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
const string FILENAME = "input";
const int MAXN = 1001;


int n;
vector<int> g[MAXN];
int id[MAXN];
bool used[MAXN];
bool good[MAXN];
int last[MAXN];
bool good1[MAXN];


void dfs(int u, int cur) {
    if (good[u]) {
        last[u] = u;
        cur = u;
    }
    used[u] = true;
    for (auto h: g[u]) {
        if (!used[h]) {
            last[h] = cur; 
            dfs(h, cur);
        } 
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	//read(FILENAME);
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        cin >> n;
        for (int i= 1; i <= n; i++) {
            g[i].clear();
            used[i] = false;
            good[i] = false;
            good1[i] = false;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        int k1;
        cin >> k1;
        for (int i = 0; i < k1; i++) {
            cin >> id[i];
            good[id[i]] = true;
        }
        dfs(id[0], id[0]);
        int k2;
        cin >> k2;
        for (int i = 0; i < k2; i++) {
            cin >> id[i];
            good1[id[i]] = true;
        }
        cout << "B " << id[0] << endl;
        int res;
        cin >> res;
        if (good[res]) {
            cout << "C " << res << endl;
            continue;
        }
        cout << "A " << last[res] << endl;
        int res1;
        cin >> res1;
        if (good1[res1]) {
            cout << "C " << last[res] << endl;
        } else {
            cout << "C " << -1 << endl;
        }
    }
    return 0;
}