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
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 55;


int n, m;
int xa[MAXN], xb[MAXN], ya[MAXN], yb[MAXN];
int q[MAXN];
vector<tuple<int,int,int,int>> moves;


bool comp(int i, int j) {
    return xa[i] < xa[j];
}


bool comp1(int i, int j) {
    return yb[i] < yb[j];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> xa[i] >> ya[i];
        xa[i]--, ya[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> xb[i] >> yb[i];
        xb[i]--, yb[i]--;
    }
    for (int i = 0; i < m; i++) {
        q[i] = i;
    }
    sort(q, q + m, comp);
    for (int i = 0; i < m; i++) {
        int j = q[i];
        while (xa[j] > i) {
            moves.emplace_back(xa[j], ya[j], xa[j] - 1, ya[j]);
            xa[j]--;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        int j = q[i];
        while (xa[j] < i) {
            moves.emplace_back(xa[j], ya[j], xa[j] + 1, ya[j]);
            xa[j]++;
        }
    }
    sort(q, q + m, comp1);
    for (int i = 0; i < m; i++) {
        int j = q[i];
        while (ya[j] != i) {
            if (ya[j] > i) {
                moves.emplace_back(xa[j], ya[j], xa[j], ya[j] - 1);
                ya[j]--;
            } else {
                moves.emplace_back(xa[j], ya[j], xa[j], ya[j] + 1);
                ya[j]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        while (xa[i] != xb[i]) {
            if (xa[i] > xb[i]) {
                moves.emplace_back(xa[i], ya[i], xa[i] - 1, ya[i]);
                xa[i]--;
            } else {
                moves.emplace_back(xa[i], ya[i], xa[i] + 1, ya[i]);
                xa[i]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int j = q[i];
        while (ya[j] > yb[j]) {
            moves.emplace_back(xa[j], ya[j], xa[j], ya[j] - 1);
            ya[j]--;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        int j = q[i];
        while (ya[j] < yb[j]) {
            moves.emplace_back(xa[j], ya[j], xa[j], ya[j] + 1);
            ya[j]++;
        }
    }
    cout << sz(moves) << '\n';
    for (auto x: moves) {
        cout << get<0>(x) + 1 << ' ' << get<1>(x) + 1 << ' ' << get<2>(x) + 1 << ' ' << get<3>(x) + 1 << '\n';
    }
    return 0;       
}