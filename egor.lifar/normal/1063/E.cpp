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
const int MAXN = 1005;

int n;
int a[MAXN];
bool used[MAXN];
int st = -1;
int uk;
vector<int> cs[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            ok = false;
        }
    }
    if (ok) {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << '.';
            }
            cout << '\n';
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == a[i]) {
            continue;
        }
        if (used[i]) {
            continue;
        }
        if (st == -1) {
            st = i;
        }
        for (int j = i; !used[j]; cs[uk].pb(j), used[j] = true, j = a[j]);
        if (!uk) {
            cs[0].erase(cs[0].begin());
            cs[0].pb(i);
        }
        uk++;
    }
    //cout << sz(cs[0]) << endl;
    cout << n - 1 << '\n';
    int cnt = 0;
    for (int k = 0; k < uk; k++) {
      //  cout << k << endl;
        for (int i = 0; i < sz(cs[k]) - 1; i++) {
        //    cout << k << ' ' << i << endl;
            char e = (cs[k][i + 1] < cs[k][i] ? '\\': '/');
            for (int j = 0; j < n; j++) {
                cout << (j == cs[k][i + 1] || j == cs[k][i] || !i && k && j == st ? e: '.');
            }
            cout << '\n';
            cnt++;
        }
        for (int j = 0; j < n; j++) {
            cout << (j == st || j == cs[k].back() ? '\\': '.');
        }
        cout << '\n';
        cnt++;
    }
    for (int i = cnt; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << '\n';
    }
    return 0;
}