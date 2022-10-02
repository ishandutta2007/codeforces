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
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
const string FILENAME = "input";
const int MAXN = 2002;

int n, m;
string s[2002];
vector<int> g[2002];
vector<int> v[2002];
bool used[2002];
int who[2002];
int uk = 0;
vector<int> st[2002];
vector<int> order;
int ans[2002];


void dfs(int u) {
  used[u] = true;
  who[u] = uk;
  st[uk].pb(u);
  for (auto h: v[u]) {
    if (!used[h]) {
      dfs(h);
    }
  }
}


void dfs1(int u) {
  used[u] = true;
  for (auto h: g[u]) {
    if (!used[h]) {
      dfs1(h);
    }
  }
  order.pb(u);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '=') {
          v[i].pb(j + n);
          v[j + n].pb(i);
        }
      }
    }
    for (int i = 0; i < n + m; i++) {
      if (!used[i]) {
        dfs(i);
        uk++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '=') {
        } else {
          if (s[i][j] == '>') {
            g[who[i]].pb(who[j + n]);
          } else {
            g[who[j + n]].pb(who[i]);
          }
        }
      }
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < uk; i++) {
      if (!used[i]) {
        dfs1(i);
      } 
    }
    for (int it = 0; it < uk; it++) {
      int i = order[it];
      int res = 1;
      for (auto x: g[i]) {
        chkmax(res, ans[x] + 1);
      } 
      ans[i] = res;
    }
    for (int i = 0; i < uk; i++) {
      for (auto x: g[i]) {
        if (ans[x] >= ans[i]) {
          cout << "No\n";
          return 0;
        }
      }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      cout << ans[who[i]] << ' ';
    }
    cout << '\n';
for (int i = 0; i < m; i++) {
      cout << ans[who[i + n]] << ' ';
    }
    cout << '\n';
    return 0;
}