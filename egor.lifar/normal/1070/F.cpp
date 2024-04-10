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
const int MAXN = 400228;    


int n;
long long pref[MAXN], pref1[MAXN], pref2[MAXN], pref3[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n;
    vector<int> g[4];
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int a;
        cin >> a;
        g[(t[0] - '0') + (t[1] - '0') * 2].pb(a);
    }
    for (int i = 0; i < 4; i++) {
        sort(all(g[i]));
    }
    reverse(all(g[0]));
    reverse(all(g[1]));
    reverse(all(g[2]));
     reverse(all(g[3]));
    for (int i = 0; i < sz(g[0]); i++) {
        pref[i] = g[0][i];
        if (i) {
            pref[i] += pref[i - 1];
        }
    }
    for (int i = 0; i < sz(g[1]); i++) {
        pref1[i] = g[1][i];
        if (i) {
            pref1[i] += pref1[i - 1];
        }
    }
    for (int i = 0; i < sz(g[2]); i++) {
        pref2[i] = g[2][i];
        if (i) {
            pref2[i] += pref2[i - 1];
        }
    }
    for (int i = 0; i < sz(g[3]); i++) {
        pref3[i] = g[3][i];
        if (i) {
            pref3[i] += pref3[i - 1];
        }
    }
    long long cur = 0;
    long long res = 0;
    int cntl = sz(g[3]);
    for (int diff = 0; diff <= cntl; diff++) {
        //cntl - diff
        int l = sz(g[1]) - 1;
        int r = l - diff;
        int can = (min(r, l) * 2 + cntl * 2) - l - r - cntl;
      //  cout << l << ' ' << r << ' ' << can << '\n';
        if (r < sz(g[2])) {
        chkmax(res, (cntl >= 1 ? pref3[cntl - 1]: 0) + (can >= 1 && sz(g[0]) ? pref[min(sz(g[0]) - 1, can - 1)]: 0) + (l >= 0 ? pref1[l]: 0) + (r >= 0 ? pref2[r]: 0));
        
        }
        r = sz(g[2]) - 1;
        l = r - diff;
        if (l < sz(g[1])) {
        can = (min(r, l) * 2 + cntl * 2) - l - r - cntl;
        chkmax(res, (cntl >= 1 ? pref3[cntl - 1]: 0) + (can >= 1 && sz(g[0]) ? pref[min(sz(g[0]) - 1, can - 1)]: 0) + (l >= 0 ? pref1[l]: 0) + (r >= 0 ? pref2[r]: 0));
        }
    }
    for (int diff = 0; diff <= cntl; diff++) {
        //cntl - diff
        int l = sz(g[1]) - 1;
        int r = l + diff;
        int can = (min(r, l) * 2 + cntl * 2) - l - r - cntl;
      //  cout << l << ' ' << r << ' ' << can << '\n';
        if (r < sz(g[2])) {
        chkmax(res, (cntl >= 1 ? pref3[cntl - 1]: 0) + (can >= 1 && sz(g[0]) ? pref[min(sz(g[0]) - 1, can - 1)]: 0) + (l >= 0 ? pref1[l]: 0) + (r >= 0 ? pref2[r]: 0));
        
        }
        r = sz(g[2]) - 1;
        l = r + diff;
        if (l < sz(g[1])) {
        can = (min(r, l) * 2 + cntl * 2) - l - r - cntl;
        chkmax(res, (cntl >= 1 ? pref3[cntl - 1]: 0) + (can >= 1 && sz(g[0]) ? pref[min(sz(g[0]) - 1, can - 1)]: 0) + (l >= 0 ? pref1[l]: 0) + (r >= 0 ? pref2[r]: 0));
        }
    }
    cout << res << '\n';
    return 0;
}