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
const int MAXN = 100001;
const int Mod = 1000000007;


string s;
int p, m;
int gr;


vector<pair<int, int> > calc(int l, int r, bool flag) {
    //cout << l << ' ' << r << endl;
    if (s[l] == '(' && s[r] == ')') {
        l++;
        r--;
    }
    if (l == r) {
        vector<pair<int, int> >  vals0;
        vals0.resize(gr + 1);
        for (int cnt = 0; cnt <= gr; cnt++) {
            if (cnt != 0) {
                vals0[cnt].second = 1e9;
                vals0[cnt].first = -1e9;
                continue;
            }
            vals0[cnt].second = s[l] - '0';
            vals0[cnt].first = s[l] - '0'; 
        }
        return vals0;
    }
    int cnts = 0;
    int pos = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            cnts++;
        } else if (s[i] == ')') {
            cnts--;
        }
        if (cnts == 0) {
            if (s[i] == '?') {
                pos = i;
                break;
            }
        }
    }
    int l1 = l;
    int r1 = pos - 1;
    int l2 = pos + 1;
    int r2 = r;
    vector<pair<int, int> >  vals = calc(l1, r1, flag);
    vector<pair<int, int> >  vals1 = calc(l2, r2, flag);
    vector<pair<int, int> >  vals0;
    vals0.resize(gr + 1);
    for (int cnt = 0; cnt <= gr; cnt++) {
        vals0[cnt].second = 1e9;
        vals0[cnt].first = -1e9;
        if (flag) {
            if (cnt) {
                for (int i = 0; i <= cnt - 1; i++) {
                    chkmax(vals0[cnt].first, vals[i].first + vals1[cnt - 1 - i].first);
                    chkmin(vals0[cnt].second, vals[i].second + vals1[cnt - 1 - i].second);
                }
            }
            for (int i = 0; i <= cnt; i++) {
                chkmax(vals0[cnt].first, vals[i].first - vals1[cnt - i].second);
                chkmin(vals0[cnt].second, vals[i].second - vals1[cnt - i].first);
            }
        } else {
            if (cnt) {
                for (int i = 0; i <= cnt - 1; i++) {
                    chkmax(vals0[cnt].first, vals[i].first - vals1[cnt - 1 - i].second);
                    chkmin(vals0[cnt].second, vals[i].second - vals1[cnt - 1 - i].first);
                }
            }
            for (int i = 0; i <= cnt; i++) {
                chkmax(vals0[cnt].first, vals[i].first + vals1[cnt - i].first);
                chkmin(vals0[cnt].second, vals[i].second + vals1[cnt - i].second);
            }
        }
    }
    return vals0;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  //  read(FILENAME);
    cin >> s;
    if (sz(s) == 1) {
        cout << s[0] - '0' << endl;
        return 0;
    }
    cin >> p >> m;
    if (p < m) {
        gr = p;
        vector<pair<int, int> > st = calc(0, sz(s) - 1, true);
        cout << st[p].first << endl;
    } else {
        gr = m;
        vector<pair<int, int> > st = calc(0, sz(s) - 1, false);
        cout << st[m].first << endl;
    }
}