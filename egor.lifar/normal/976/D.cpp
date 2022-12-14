/*
 












 
 */
#pragma GCC optimize "-oFast"
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
const int MAXN = 3001;


int n;
int d[MAXN];
vector<pair<short, short> > ans;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   //read(FILENAME);
    cin >> n;
   // n = 300;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
       // d[i] = 700 + i;
    }
    int l = 0;
    int r = n - 1;
    int stl = 1;
    int str = d[n - 1] + 1;
    while (true) {
        if (l > r) {
            break;
        }
        if (l < 0 || r >= n || l >= n || r < 0) break;
        if (d[l] == 0) {
            l++;
            continue;
        }
        if (l == r) {
            for (int i = stl; i <= str; i++) {
                for (int j = i + 1; j <= str; j++) {
                    ans.pb({i, j});
                }
            }
            break;
        }
        for (int i = str - d[l] + 1; i <= str; i++) {
            for (int j = i + 1; j <= str; j++) {
                ans.pb({i, j});
            }
        }
        int focus = d[l];
        for (int i = str - focus + 1; i <= str; i++) {
            for (int j = stl; j < str - focus + 1; j++) {
                ans.pb({i, j});
                //d[j]--;
            }
            for (int j = l; j < r; j++) {
                d[j]--;
            }
        }
        if (r == 0) break;
        if (l == n - 1) break;
        if (l + 1 > r - 1) break;
        if (r < 1) {
            break;
        }
        stl = str - focus - d[r - 1];
        str = str - focus;
        l++;
        r--;
    }
    cout << sz(ans) << '\n';
    for (auto x: ans) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}