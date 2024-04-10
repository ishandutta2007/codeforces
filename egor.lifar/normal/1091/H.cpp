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
const int MAXN = 200228;


int n, f;
int a[MAXN], b[MAXN];
int cntp[MAXN];
bool good[MAXN];
bitset<MAXN + 5> where[2002];
vector<int> pos[2002];
int g[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    for (int i = 2; i < MAXN; i++) {
        if (cntp[i] == 0) {
            cntp[i] = 1;
            for (int j = 2 * i; j < MAXN; j += i) {
                int s = j;
                while (s % i == 0) {
                    s /= i;
                    cntp[j]++;
                }
            }
        }
    }
    cin >> n >> f;
    vector<int> st;
    for (int i = 2; i < MAXN; i++) {
        if (cntp[i] <= 2 && i != f) {
            st.pb(i);
            good[i] = true;
        }   
    }
    where[0][0] = 1;
    g[0] = 0;
    pos[0].push_back(0);
    for (int i = 1; i < MAXN; i++) {
        while (true) {
            bool bad = false;
            for (auto x: pos[g[i]]) {
                if (good[i - x]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                break;
            }
            g[i]++;
        }
        pos[g[i]].push_back(i);
        where[g[i]][i] = true;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        res ^= g[b - a - 1];
        res ^= g[c - b - 1];
    }
    if (res) {
        cout << "Alice\n";
        cout << "Bob\n";
    } else {
        cout << "Bob\n";
        cout << "Alice\n";
    }
    return 0; 
}