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
#define x first
#define y second
const string FILENAME = "input";


long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);   
    int n, m, k;
    cin >> n >> m >> k;
    long long s = 2LL * n * m;
    if (s % k != 0) {
        cout << "NO\n";
        return 0;
    }
    s /= k;
    long long fl = n;
    long long fr = m;
    if (fl > fr) {
        long long g = gcd(fl, k);
        fl /= g;
        k /= g;
        g = gcd(fr, k);
        fr /= g;
        k /= g;
    } else {
        long long g = gcd(fr, k);
        fr /= g;
        k /= g;
         g = gcd(fl, k);
        fl /= g;
        k /= g;
    }
    if (k == 2) {
        cout << "YES\n";
        cout << 0 << ' ' << 0 << endl;
        cout << fl << ' ' << 0 << endl;
        cout << 0 << ' ' << fr << endl;
        return 0;
    }
    if (fl * 2 <= n) {
        cout << "YES\n";
        cout << 0 << ' ' << 0 << endl;
        cout << fl * 2 << ' ' << 0 << endl;
        cout << 0 << ' ' << fr << endl;
        return 0;
    }
    if (fr * 2 <= m) {
        cout << "YES\n";
        cout << 0 << ' ' << 0 << endl;
        cout << fl << ' ' << 0 << endl;
        cout << 0 << ' ' << fr * 2 << endl;
        return 0;
    }
    cout << "NO\n";
    //ax * by = s
    //
    //nm / k
    //ax * by - ay * bx == 2 * nm / k
    //ax, bx <= n
    //ay, by <= m
    //a * b - c * d = 2 * n * m / k
    //n * m - (n * m - (2 * n * m) / k);
    //(n * m * (1 - 2 / k));
    //n * m * (k - 2) / k

    return 0;
}