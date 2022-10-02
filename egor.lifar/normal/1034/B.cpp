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
#define x first
#define y second
const string FILENAME = "input";


int dx[10] = {1, 2, 0, 3, -1, -2, -1, 1, -2, 2};
int dy[10] = {2, 1, 3, 0, -2, -1, 2, -2, 1, -1};
short dp[1 << 25];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);   
    int n, m;
    cin >> n >> m;
    if (n % 6 == 0 || m % 6 == 0) {
        cout << 1LL * n * m << endl;
        return 0;
    }
    if (n > m) {
        swap(n, m);
    }
    long long ans = 0;
    if (n == 1) {
        ans += m / 6 * 6;
        m %= 6;
        for (int i = 1; i <= 5; i++) {
            for (int j = i; j <= 5; j++) {
                if (i == n && j == m && i == 5 && j == 5) {
                    cout << ans + 24 << endl;
                    return 0;
                }
                if (i == n && j == m && i == 4 && j == 5) {
                    cout << ans + 20 << endl;
                    return 0;
                }
                if (i == n && j == n && i == 4 && j == 4) {
                    cout << ans + 16 << endl;
                    return 0;
                }
                int res = 0;
                for (int mask = 0; mask < (1 << (i * j)); mask++) {
                    dp[mask] = 0;
                    for (int f = 0; f < i; f++) {
                        for (int f1 = 0; f1 < j; f1++) {
                            if (mask & (1 << (f * j + f1))) {
                                for (int g = 0; g < 10; g++) {
                                    int x = f + dx[g];
                                    int y = f1 + dy[g];
                                    if (x < 0 || y < 0 || x >= i || y >= j) {
                                        continue;
                                    }
                                    if (mask & (1 << (x * j + y))) {
                                        chkmax(dp[mask], dp[mask ^ (1 << (f * j + f1)) ^ (1 << (x * j + y))] + 2);
                                    }
                                }
                            }
                        }
                    }
                    chkmax(res, dp[mask]);
                }
                if (i == n && j == m) {
                    cout << ans + res << endl;
                    return 0;
                }
            }
        }
        return 0;
    }
    if (n > m) {
        swap(n, m);
    }
    if (n == 2) {
        if (m == 7) {
            cout << 12 << endl;
            return 0;
        }
        if (m <= 5) {
            for (int i = 1; i <= 5; i++) {
                for (int j = i; j <= 5; j++) {
                    if (i == n && j == m && i == 5 && j == 5) {
                        cout << ans + 24 << endl;
                        return 0;
                    }
                    if (i == n && j == m && i == 4 && j == 5) {
                        cout << ans + 20 << endl;
                        return 0;
                    }
                    if (i == n && j == n && i == 4 && j == 4) {
                        cout << ans + 16 << endl;
                        return 0;
                    }
                    int res = 0;
                    for (int mask = 0; mask < (1 << (i * j)); mask++) {
                        dp[mask] = 0;
                        for (int f = 0; f < i; f++) {
                            for (int f1 = 0; f1 < j; f1++) {
                                if (mask & (1 << (f * j + f1))) {
                                    for (int g = 0; g < 10; g++) {
                                        int x = f + dx[g];
                                        int y = f1 + dy[g];
                                        if (x < 0 || y < 0 || x >= i || y >= j) {
                                            continue;
                                        }
                                        if (mask & (1 << (x * j + y))) {
                                            chkmax(dp[mask], dp[mask ^ (1 << (f * j + f1)) ^ (1 << (x * j + y))] + 2);
                                        }
                                    }
                                }
                            }
                        }
                        chkmax(res, dp[mask]);
                    }
                    if (i == n && j == m) {
                        cout << ans + res << endl;
                        return 0;
                    }
                }
            }
            return 0;
        }
    }
    cout << 1LL * (1LL * n * m) / 2 * 2 << endl;
    return 0;
}