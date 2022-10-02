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
#include <array>
       
        
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


char c[10001][10001];
vector<int> pos[26];
set<int> g[10001];
int ps[10001];
char fop[10001];


int main() {
    ios_base::sync_with_stdio(false);
  //  read(FILENAME);
    string ss;
    cin >> ss;
    mt19937 a;
    a.seed(time(NULL));
    int n = sz(ss);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
        }
    }
    for (int it = 0; it < 3; it++) {
        string s;
        if (it == 0) {
        for (int j = 0; j < n; j++) {
            s += char('a' + j % 26);
        }
        } else if (it == 1) {
        for (int j = 0; j < n; j++) {
            s += char('a' + (j / 26) % 26);
        }
        } else {
        for (int j = 0; j < n; j++) {
            s += char('a' + (j / 26 / 26) % 26);
        }
        }
        
        for (int t = 0; t < 26; t++) {
            pos[t].clear();
        }
        cout << "? " << s << endl;
        string res;
        cin >> res;
        for (int j = 0; j < n; j++) {
            pos[res[j] - 'a'].pb(j);
        }
        for (int j = 0; j < n; j++) {
            for (auto x: pos[s[j] - 'a']) {
                c[j][x]++;
            }
        }   
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == 3) {
                g[j].insert(i);
            }
        }
    }
    set<pair<int, int> > kek;
    for (int i = 0; i < n; i++) {
        kek.insert({sz(g[i]), i});
        //cout << sz(g[i]) << endl;
    }
    while (!kek.empty()) {
        pair<int, int> f =*kek.begin();
        kek.erase(f);
        ps[f.second] = *g[f.second].begin();
        for (int i = 0; i < n; i++) {
            if (c[ps[f.second]][i] == 3) {
                if (kek.find({sz(g[i]), i}) != kek.end()) {
                    kek.erase({sz(g[i]), i});
                    g[i].erase(ps[f.second]);
                    kek.insert({sz(g[i]), i});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        fop[ps[i]] = ss[i];
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << fop[i];
    }
    cout << endl;
    return 0;       
}