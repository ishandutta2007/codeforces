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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 300228;


int n, m;
string s[MAXN];
vector<int> g[MAXN];
char c[4] = {'A', 'G', 'T', 'C'};
int who[300];
int opt[2] = {-1, -1};
vector<string> kek[2];
vector<int> g1[MAXN];


void check(int a1, int a2, int a3, int a4, bool inv = false) {
    int res = 0;
    vector<string> kekt;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            int cnt[2] = {0, 0};
            for (int j = 0; j < m; j++) {
                if (g[i][j] == a1) {
                    cnt[j & 1]++;
                }
                if (g[i][j] == a2) {
                    cnt[1 - (j & 1)]++;
                }
            }
            if (cnt[0] > cnt[1]) {
                res += cnt[0];
                string keks;
                for (int j = 0; j < m; j++) {
                    if (j & 1) {
                        keks += c[a2];
                    } else {
                        keks += c[a1];
                    }
                }
                kekt.pb(keks);
            } else {
                res += cnt[1];
                string keks;
                for (int j = 0; j < m; j++) {
                    if (j & 1) {
                        keks += c[a1];
                    } else {
                        keks += c[a2];
                    }
                }
                kekt.pb(keks);
            }
        } else {
            int cnt[2] = {0, 0};
            for (int j = 0; j < m; j++) {
                if (g[i][j] == a3) {
                    cnt[j & 1]++;
                }
                if (g[i][j] == a4) {
                    cnt[1 - (j & 1)]++;
                }
            }
            if (cnt[0] > cnt[1]) {
                res += cnt[0];
                string keks;
                for (int j = 0; j < m; j++) {
                    if (j & 1) {
                        keks += c[a4];
                    } else {
                        keks += c[a3];
                    }
                }
                kekt.pb(keks);
            } else {
                res += cnt[1];
                string keks;
                for (int j = 0; j < m; j++) {
                    if (j & 1) {
                        keks += c[a3];
                    } else {
                        keks += c[a4];
                    }
                }
                kekt.pb(keks);
            }
        }
    }
    if (res > opt[inv]) {
        opt[inv] = res;
        kek[inv] = kekt;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //  read(FILENAME);
    //AGAT
    //CTCG
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        who[c[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            g[i][j] = who[s[i][j]];
        }
    }
    for (int i1 = 0; i1 < 4; i1++) {
        for (int j1 = 0; j1 < 4; j1++) {
            if (i1 != j1) {
                for (int t1 = 0; t1 < 4; t1++) {
                    for (int t2 = 0; t2 < 4; t2++) {
                        if (t1 != i1 && t1 != j1 && t2 != i1 && t2 != j1 && t1 != t2) {
                            check(i1, j1, t1, t2);
                        }
                    }
                }
            }
        }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
        g1[i].resize(m);
        for (int j = 0; j < m; j++) {
            g1[i][j] = g[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        g[i] = g1[i];
    }
    for (int i1 = 0; i1 < 4; i1++) {
        for (int j1 = 0; j1 < 4; j1++) {
            if (i1 != j1) {
                for (int t1 = 0; t1 < 4; t1++) {
                    for (int t2 = 0; t2 < 4; t2++) {
                        if (t1 != i1 && t1 != j1 && t2 != i1 && t2 != j1 && t1 != t2) {
                            check(i1, j1, t1, t2, 1);
                        }
                    }
                }
            }
        }
    }
    swap(n, m);
    if (opt[0] > opt[1]) {
        for (int i = 0; i < n; i++) {
            cout << kek[0][i] << '\n';
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << kek[1][j][i];
            }
            cout << '\n';
        }
    }
    return 0; 
}