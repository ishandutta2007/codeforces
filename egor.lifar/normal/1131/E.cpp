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
const int MAXN = 100228;


int n;
string s[MAXN];
int was[26];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }  
    int curl = 0;
    char last = -1;
    int res = 0;
    for (int i = 0; i < sz(s[n - 1]); i++) {
        if (last == -1) {
            last = s[n - 1][i];
            curl = 1;
        } else {
            if (last != s[n - 1][i]) {
                last = s[n - 1][i];
                curl = 1;
            } else {
                curl++;
            }
        }
        chkmax(res, curl);
    }
    bool kek = res == sz(s[n - 1]);
   // cout << kek << endl;
    if (!kek) {
        int uk = 0;
        while (uk < sz(s[n - 1]) && s[n - 1][uk] == s[n - 1][0]) {
            uk++;
        }
        int uk1 = sz(s[n - 1]) - 1;
        while (uk1 >= 0 && s[n - 1][uk1] == s[n - 1].back()) {
            uk1--;
        }
        //cout << uk1 << endl;
        int len = uk + sz(s[n - 1]) - uk1 - 1;
        //cout << len << endl;
         for (int i = 0; i < n - 1; i++) {
            for (auto x: s[i]) {
                was[x - 'a'] = true;
            }
         }
        if (was[s[n - 1][0] - 'a']) {
            chkmax(res, uk + 1);
        }
        if (was[s[n - 1].back() - 'a']) {
            chkmax(res, sz(s[n - 1]) - uk1 - 1 + 1);
        }
        if (was[s[n - 1][0] - 'a'] && s[n - 1][0] == s[n - 1].back()) {
            chkmax(res, len + 1);
        }
    }   
    if (!kek) {
        cout << res << endl;
        return 0;
    }
    //cout << "opa" << endl;
     for (int i = 0; i < n - 1; i++) {
        for (auto x: s[i]) {
            was[x - 'a']++;
        }
     }
    int cur = res;
    char c = s[n - 1][0];
    for (int i = n - 2; i >= 0; i--) {
        int f = 0;
        int t = 0;
        for (int j = 0; j < sz(s[i]); j++) {
            was[s[i][j] - 'a']--;
            if (s[i][j] == c) {
                f++;
            } else {
                f = 0;
            }
            chkmax(t, f);
        }
        if (t == sz(s[i])) {
            cur = cur * (t + 1) + t;
            continue;
        }
        if (true) {
            int uk = 0;
            while (uk < sz(s[i]) && s[i][uk] == s[i][0]) {
                uk++;
            }
            int uk1 = sz(s[i]) - 1;
            while (uk1 >= 0 && s[i][uk1] == s[i].back()) {
                uk1--;
            }
            int len = uk + sz(s[i]) - uk1 - 1;
            if (was[c - 'a'] && s[i][0] == c) {
                chkmax(t, uk + 1);
            }
            if (was[c - 'a'] && s[i].back() == c) {
                chkmax(t, sz(s[i]) - uk1 - 1 + 1);
            }
            if (was[c - 'a'] && s[i][0] == c && s[i][0] == s[i].back()) {
                chkmax(t, len + 1);
            }
        }
       // cout << t << ' ' << t << endl;
        if (t == 0) {
            if (was[c - 'a']) {
                cur = cur * 2 + 1;
            }
            break;
        }
        cur = cur * (t + 1) + t;
        break;
    }       
    cout << cur << endl;
    return 0;
}