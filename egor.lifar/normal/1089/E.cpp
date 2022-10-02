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


string get(int i, int j) {
    char a = 'a' + i;
    char b = j + '1';
    string s;
    s += a;
    s += b;
    return s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    int n;
    cin >> n;
    vector<pair<int, int> > st;
    for (int i = 7; i >= 2; i--) {
        if (i % 2 == 1) {
            for (int j = 7; j >= 0; j--) {
                st.pb({i, j});
            } 
        } else {
            for (int j = 0; j <= 7; j++) {
                st.pb({i, j});
            } 
        }
    }
    vector<pair<int, int> > st1 = st;
    for (int j = 7; j >= 0; j--) {
        st1.pb({1, j});
        if (j == 6) {
            continue;
        }
        st.pb({1, j});
    }
    st.pb({1, 6});
    st.pb({0, 6});
    for (int j = 7; j >= 0; j--) {
        if (j != 6) {
            st.pb({0, j});
        }
    }
    if (st[n - 1].first == 0 || st[n - 1].second == 0)  {
        cout << "a1 ";
        for (int j = n - 1; j >= 0; j--) {
            cout << get(st[j].first, st[j].second) << ' ';
        }
        cout << '\n';
        return 0;
    }

    if (sz(st1) >= n) {
        if (st1[n - 1].first == 0 || st1[n - 1].second == 0) {
                cout << "a1 ";
            for (int j = n - 1; j >= 0; j--) {
                cout << get(st1[j].first, st1[j].second) << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    if (sz(st1) >= n - 1) {
        if (st1[n - 2].first >= 1 && st1[n - 2].second != 0) {
                cout << "a1 ";
                cout << get(0, st1[n - 2].second) << ' ';
            for (int j = n - 2; j >= 0; j--) {
                cout << get(st1[j].first, st1[j].second) << ' ';
            }
            cout << '\n';
            return 0;
        }
    }

     if (st[n - 2].first >= 1 && st[n - 2].second != 0) {
        cout << "a1 ";
        cout << get(0, st[n - 2].second) << ' ';
        for (int j = n - 2; j >= 0; j--) {
            cout << get(st[j].first, st[j].second) << ' ';
        }
        cout << '\n';
        return 0;
    }
    if (st[n - 2].first >= 2 && st[n - 2].second == 0) {
         cout << "a1 ";
        cout << get(1, 0) << ' ';
        for (int j = n - 2; j >= 0; j--) {
            cout << get(st[j].first, st[j].second) << ' ';
        }
        cout << '\n';
        return 0;
    }
    return 0;
}