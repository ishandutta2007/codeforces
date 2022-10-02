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
const int MAXN = 300228;
 

int n;
int x[MAXN], y[MAXN];
    int ans = 0;
    set<pair<int, int> > sx, sy;

void check(int i, pair<int, int> p) {
    sy.erase({y[p.second], p.second});
    pair<int, int> p1 = *sy.rbegin();
    pair<int, int> p2 = *sy.begin();
    sy.insert({y[p.second], p.second});
    vector<int> tx;
    tx.pb(x[i]);
    tx.pb(p.first);
    tx.pb(x[p1.second]);
    vector<int> ty;
    ty.pb(y[i]);
    ty.pb(p1.first);
    ty.pb(y[p.second]);
    sort(all(tx));
    sort(all(ty));
    chkmax(ans, (ty[2] - ty[0] + tx[2] - tx[0]) * 2);
    tx.clear();
    ty.clear();
    tx.pb(x[i]);
    tx.pb(p.first);
    tx.pb(x[p2.second]);
    ty.pb(y[i]);
    ty.pb(p2.first);
    ty.pb(y[p.second]);
    sort(all(tx));
    sort(all(ty));
    chkmax(ans, (ty[2] - ty[0] + tx[2] - tx[0]) * 2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
	//read(FILENAME);
    cin >> n;
    int lx = 1e9;
    int rx = -1e9;
    int ly = 1e9;
    int ry = -1e9;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        chkmin(lx, x[i]);
        chkmax(rx, x[i]);
        chkmin(ly, y[i]);
        chkmax(ry, y[i]);
        sx.insert({x[i], i});
        sy.insert({y[i], i});
    }
    for (int i = 0; i < n; i++) {
        sx.erase(sx.find({x[i], i}));
        sy.erase(sy.find({y[i], i}));
        pair<int, int> p = *sx.rbegin();
        check(i, p);
        p = *sx.begin();
        check(i, p);
        sx.insert({x[i], i});
        sy.insert({y[i], i});
    }
    cout << ans << ' ';
    for (int i = 4; i <= n; i++) {
        cout << abs(lx - rx) * 2 + abs(ly - ry) * 2 << ' ';
    }
    cout << '\n';
    return 0;
}