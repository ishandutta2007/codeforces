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
const int MAXN = 100001;


int n, m;
vector<pair<int, int>> g[MAXN];
int tin[MAXN];
int fup[MAXN];
bool used[MAXN];
int tim;
int colour;


void dfs(int v, int p) {
    used[v] = true;
    tin[v] = fup[v] = tim++;
    for (auto h: g[v]) {
        if (h.first == p) {
            continue;
        }
        if (used[h.first]) {
            chkmin(fup[v], tin[h.first]);
        } else {
            dfs(h.first, v);
            chkmin(fup[v], fup[h.first]);
        }
    }
}


set<int> ups[MAXN], downs[MAXN];


void dfs_colour(int v, int p, int cur) {
    used[v] = true;
    for (auto h: g[v]) {
        if (h.first == p) {
            continue;
        }
        if (used[h.first]) {
            if (tin[v] > tin[h.first]) {
                ups[cur].insert(h.second);
                downs[cur].insert(v);
                downs[cur].insert(h.first);
            }
            continue;
        }
        if (fup[h.first] >= tin[v])  {
            colour++;
            ups[colour - 1].insert(h.second);
            downs[colour - 1].insert(v);
            downs[colour - 1].insert(h.first);
            dfs_colour(h.first, v, colour - 1);
        } else {
            ups[cur].insert(h.second);
            downs[cur].insert(v);
            downs[cur].insert(h.first);
            dfs_colour(h.first, v, cur);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, i + 1});
        g[b].push_back({a, i + 1});
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            colour++;
            dfs_colour(i, -1, colour - 1);
        }
    }
    vector<int> ans;
    for(int i = 0; i < colour; i++) {
        if (sz(ups[i]) == sz(downs[i])) {
            for (auto x: ups[i]) {
                ans.pb(x);
            }
        }
    }
    sort(all(ans));
    ans.resize(distance(ans.begin(), unique(all(ans))));
    cout << sz(ans) << endl;
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;   
    return 0;
}