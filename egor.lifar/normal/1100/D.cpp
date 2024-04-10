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

pair<int, int> cur[670];



int main() {
    ios_base::sync_with_stdio(false);
   // read(FILENAME);
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 666; i++) {
        int xx, yy;
        cin >> xx >> yy;
        cur[i] = make_pair(xx, yy);
    }
    while (x != 500 || y != 500) {
        int movex = 0, movey = 0;
        if (x != 500) {
            movex = (500 - x) / abs(500 - x);
        }
        if (y != 500) {
            movey = (500 - y) / abs(500 - y);
        }
        x += movex;
        y += movey;
        cout << x << ' ' << y << endl;
        int k, xx, yy;
        cin >> k >> xx >> yy;
        if (k == -1) {
            return 0;
        }
        k--;
        cur[k] = make_pair(xx, yy);
    }
    assert(x == 500 && y == 500);
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 0; i < 666; i++) {
        if (cur[i].first > x && cur[i].second > y) {
            cnt[0]++;
        }
        if (cur[i].first < x && cur[i].second < y) {
            cnt[1]++;
        }
        if (cur[i].first > x && cur[i].second < y) {
            cnt[2]++;
        }
        if (cur[i].first < x && cur[i].second > y) {
            cnt[3]++;
        }
    }            
    int t = 1e9;
    for (int i = 0; i < 4; i++) {
        chkmin(t, cnt[i]);
    }       
    vector<pair<int, int> > st;
    st.pb({1, 1});
    st.pb({-1, -1});
    st.pb({1, -1});
    st.pb({-1, 1});    
    pair<int, int> p;         
    for (int i = 0; i < 4; i++) {
        if (t == cnt[i]) {
            p = st[i];
            break;
        }
    }
    while (true) {
        for (int i = 0; i < 666; i++) {
            if (x + 1 == cur[i].first) {
                cout << x + 1 << ' ' << y << endl;
                int k, xx, yy;
                cin >> k >> xx >> yy;
                if (k == -1) {
                    return 0;
                }
            }
            if (x - 1 == cur[i].first) {
                cout << x - 1 << ' ' << y << endl;
                int k, xx, yy;
                cin >> k >> xx >> yy;
                if (k == -1) {
                    return 0;
                }
            }
            if (y + 1 == cur[i].second) {
                cout << x << ' ' << y + 1 << endl;
                int k, xx, yy;
                cin >> k >> xx >> yy;
                if (k == -1) {
                    return 0;
                }
            }
            if (y - 1 == cur[i].second) {
                cout << x << ' ' << y - 1 << endl;
                int k, xx, yy;
                cin >> k >> xx >> yy;
                if (k == -1) {
                    return 0;
                }
            }
        }
        x -= p.first;
        y -= p.second;
        cout << x << ' ' << y << endl;
        int k, xx, yy;
        cin >> k >> xx >> yy;
        if (k == -1) {
            return 0;
        }
        if (k == 0) {
            exit(0);
        }
        k--;
        cur[k] = make_pair(xx, yy);
    }
    return 0;   
}