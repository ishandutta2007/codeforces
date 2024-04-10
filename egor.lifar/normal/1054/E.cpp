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
const int MAXN = 305;


struct query
{
    int x1, y1, x2, y2;
    query(){}
    query(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};

int n, m;
string s[MAXN][MAXN];
deque<int> d[MAXN][MAXN];
vector<query> ans[2];
string need[MAXN][MAXN];



void kek(int id) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j].clear();
            for (auto x: s[i][j]) {
                d[i][j].push_back(x - '0');
            }
        }
    }  
    int cnt = sz(d[1][1]);
    int cnt1 = sz(d[n][m]);
    for (int i = n - 1; i > 1; i--) {
        while (!d[i][1].empty() || !d[i][m].empty()) {
            if (!d[i][1].empty()) {
                int x = d[i][1].back();
                d[i][1].pop_back();
                if (x == 0) {
                    ans[id].pb(query(i, 1, 1, 1));
                    d[1][1].push_front(0);
                } else {
                    ans[id].pb(query(i, 1, i, m));
                    d[i][m].push_front(1);
                }
            }
            if (!d[i][m].empty()) {
                int x = d[i][m].back();
                d[i][m].pop_back();
                if (x == 1) {
                    ans[id].pb(query(i, m, n, m));
                    d[n][m].push_front(1);
                } else {
                    ans[id].pb(query(i, m, i, 1));
                    d[i][1].push_front(0);
                }
            }
        }
    }
     for (int i = m - 1; i > 1; i--) {
        while (!d[1][i].empty() || !d[n][i].empty()) {
            if (!d[1][i].empty()) {
                int x = d[1][i].back();
                d[1][i].pop_back();
                if (x == 0) {
                    ans[id].pb(query(1, i, 1, 1));
                    d[1][1].push_front(0);
                } else {
                    ans[id].pb(query(1, i, n, i));
                    d[n][i].push_front(1);
                }
            }
            if (!d[n][i].empty()) {
                int x = d[n][i].back();
                d[n][i].pop_back();
                if (x == 1) {
                    ans[id].pb(query(n, i, n, m));
                    d[n][m].push_front(1);
                } else {
                    ans[id].pb(query(n, i, 1, i));
                    d[1][i].push_front(0);
                }
            }
        }
    }
    while (!d[1][m].empty()) {
        int x = d[1][m].back();
        d[1][m].pop_back();
        if (x == 0) {
            d[1][1].push_front(x);
            ans[id].pb(query(1, m, 1, 1));
        } else {
            d[n][m].push_front(x);
            ans[id].pb(query(1, m, n, m));
        }
    }
     while (!d[n][1].empty()) {
        int x = d[n][1].back();
        d[n][1].pop_back();
        if (x == 0) {
            d[1][1].push_front(x);
            ans[id].pb(query(n, 1, 1, 1));
        } else {
            d[n][m].push_front(x);
            ans[id].pb(query(n, 1, n, m));
        }
    }
   // cout << cnt << ' ' << cnt1 << endl;
    for (int i = n - 1; i > 1; i--) {
        for (int j = 2; j <= m - 1; j++) {
            while (!d[i][j].empty()) {
                int x = d[i][j].back();
                d[i][j].pop_back();
                if (x == 0) {
                    d[1][j].push_front(x);
                    ans[id].pb(query(i, j, 1, j));
                } else {
                    d[n][j].push_front(x);
                    ans[id].pb(query(i, j, n, j));
                }
            }
        }
    }
    for (int i = 2; i < m; i++) {
        while (!d[1][i].empty()) {
            int x = d[1][i].back();
            d[1][i].pop_back();
            d[1][1].push_front(0);
            ans[id].pb(query(1, i, 1, 1));
        }
    }
    for (int i = 2; i < m; i++) {
        while (!d[n][i].empty()) {
            int x = d[n][i].back();
            d[n][i].pop_back();
            d[n][m].push_front(1);
            ans[id].pb(query(n, i, n, m));
        }
    }
    for (int i = 0; i< cnt; i++) {
        int x = d[1][1].back();
        d[1][1].pop_back();
        if (x == 1) {
            d[n][m].push_front(1);
            ans[id].pb(query(1, 1, 1, m));
            ans[id].pb(query(1, m, n, m));
        } else {
            d[n][1].push_front(0);
            ans[id].pb(query(1, 1, n, 1));
        }
    }
    for (int i = 0; i< cnt1; i++) {
        int x = d[n][m].back();
        d[n][m].pop_back();
        if (x == 0) {
            d[1][1].push_front(0);
            ans[id].pb(query(n, m, 1, m));
            ans[id].pb(query(1, m, 1, 1));
        } else {
            d[n][1].push_front(1);
            ans[id].pb(query(n, m, n, 1));
        }
    }
    while (!d[n][1].empty()) {
        int x = d[n][1].back();
        d[n][1].pop_back();
        if (x == 0) {
            d[1][1].push_front(0);
            ans[id].pb(query(n, 1, 1, 1));
        } else {
            d[n][m].push_front(1);
            ans[id].pb(query(n, 1, n, m));
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
   // / read(FILENAME);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }  
    kek(0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> need[i][j];
            reverse(all(need[i][j]));
            s[i][j] = need[i][j];
        }
    }
    kek(1);
    reverse(all(ans[1]));
    for (auto &g: ans[1]) {
        swap(g.x1, g.x2);
        swap(g.y1, g.y2);
    }
    cout << sz(ans[0]) + sz(ans[1]) << '\n';
    for (auto x: ans[0]) {
        cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << '\n';
    }
    for (auto x: ans[1]) {
        cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << '\n';
    }
    return 0;
}