
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
#define x first
#define y second
const string FILENAME = "input";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);   
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int len = 1e9;
        string ans;
        for (int i = 0; i < sz(s); i++) {
            for (int j = i - 1; j < sz(s); j++) {
                bool d = 0, d1 = 0, d2 = 0;
                for (int t1 = 0; t1 < i; t1++) {
                    if (s[t1] >= '0' && s[t1] <= '9') {
                        d = true;
                    }
                    if (s[t1] >= 'a' && s[t1] <= 'z') {
                        d1 = true;
                    }
                    if (s[t1] >= 'A' && s[t1] <= 'Z') {
                        d2 = true;
                    }
                }
                for (int t1 = j + 1; t1 < sz(s); t1++) {
                    if (s[t1] >= '0' && s[t1] <= '9') {
                        d = true;
                    }
                    if (s[t1] >= 'a' && s[t1] <= 'z') {
                        d1 = true;
                    }
                    if (s[t1] >= 'A' && s[t1] <= 'Z') {
                        d2 = true;
                    }
                }
                string f = s;
                int uk = i;
                if (!d) {
                    if (uk <= j) {
                        f[uk] = '0';
                        uk++;
                    } else {
                        continue;
                    }
                }
                 if (!d1) {
                    if (uk <= j) {
                        f[uk] = 'a';
                        uk++;
                    } else {
                        continue;
                    }
                }
                 if (!d2) {
                    if (uk <= j) {
                        f[uk] = 'Z';
                        uk++;
                    } else {
                        continue;
                    }
                }
                if (len > j - i + 1) {
                    len = j - i + 1;
                    ans = f;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}