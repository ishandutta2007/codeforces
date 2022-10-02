/*
 












 
 */
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")  
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
template<typename T1, typename T2>inline void chkmin(T1 &x, const T2 &y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, const T2 &y) { if (x < y) x = y; } 
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
#define read(FILENAME) freopen(((string)FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen(((string)FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const int MAXN = 150228;


int n;
int b[MAXN];
long long a[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
   // read("input");
    cin >> n;
    int at = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        chkmax(at, b[i]);
    }
    bool good = false;
    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            good = true;
        }
    }
    if (!good) {
        if (b[0] == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << 1 << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    int pos;
    for (int i = 0; i < n; i++) {
        if (b[i] == at && b[(i - 1 + n) % n] != at) {
            pos = i;
            break;
        }
    }
    a[pos] = b[pos];
    int uk = pos;
    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            a[(pos - 1 + n) % n] = a[pos] * 2 + b[(pos - 1 + n) % n];
        } else {
            a[(pos - 1 + n) % n] = a[pos] + b[(pos - 1 + n) % n];
        }
        pos = (pos - 1 + n) % n;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % a[(i + 1) % n] != b[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}