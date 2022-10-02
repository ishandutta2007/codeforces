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
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 1505;


int n, s, m, sk;
int a[MAXN];
int l[MAXN], r[MAXN];
int dp[MAXN][MAXN];
int ss[MAXN];
vector<int> g[MAXN];


bool can(int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            ss[i] = 1;
        } else {
            ss[i] = 0;
        }
        if (i) {
            ss[i] += ss[i - 1];
        }
    }
    memset(dp, 0, sizeof(dp));
    int cur = -1;
    for (int i = 0; i < n; i++) {
        for (auto x: g[i]) {
            chkmax(cur, x);
        }
        for (int j = 0; j <=  m; j++) {
            chkmax(dp[i + 1][j], dp[i][j]);
            if (cur != -1) {
            chkmax(dp[cur + 1][j + 1], dp[i][j] + ss[cur] - (i ? ss[i - 1]: 0));
        }
        }
    }
    int t = 0;
    for (int j = 0; j <= m; j++) {
        chkmax(t, dp[n][j]);
    }
    return t >= sk;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
   // read(FILENAME);
    cin >> n >> s >> m >> sk;
    vector<int> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k.pb(a[i]);
    }
    sort(all(k));
    for (int i = 0; i < s; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        g[l[i]].pb(r[i]);
    }
    k.resize(distance(k.begin(), unique(all(k))));
    int l = 0;
    int r = sz(k) - 1;
    if (!can(k.back())) {
        cout << -1 << '\n';
        return 0;
    }
    while (l != r) {
        int mid = (l + r) >> 1;
        if (can(k[mid])) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << k[l] << '\n';
    return 0;
}