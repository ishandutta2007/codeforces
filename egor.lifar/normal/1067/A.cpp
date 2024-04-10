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
const int Mod = 998244353;
const int MAXN = 100228;


int sum(int a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
    return a;
}


int mul(long long a, long long b) {
    return (1LL * a * b) % Mod;
}


int n;
int a[MAXN];
int dp[MAXN][202][2];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
   //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] != -1) {
        dp[0][a[0]][0] = 1;
    } else {
        for (int i = 1; i <= 200; i++) {
            dp[0][i][0] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != -1) {
           // cout << dp[i - 1][a[i]][0] << '\n';
            dp[i][a[i]][1] = sum(dp[i - 1][a[i]][0], dp[i - 1][a[i]][1]);
            for (int j = a[i] + 1; j <= 200; j++) {
                dp[i][a[i]][1] = sum(dp[i][a[i]][1], dp[i - 1][j][1]);
            }
            for (int j = 1; j < a[i]; j++) {
                dp[i][a[i]][0] = sum(dp[i][a[i]][0], sum(dp[i - 1][j][1], dp[i - 1][j][0]));
            }
        } else {
            for (int j = 1; j <= 200; j++) {
                dp[i][j][1] = sum(dp[i - 1][j][0], dp[i - 1][j][1]);
            }
            int res = 0;
            for (int j = 200; j >= 1; j--) {
                dp[i][j][1] = sum(dp[i][j][1], res);
                res = sum(res, dp[i - 1][j][1]);
            }
            res = 0;
            for (int j = 1; j <= 200; j++) {
                dp[i][j][0] = sum(dp[i][j][0], res);
                res = sum(res, sum(dp[i - 1][j][1], dp[i - 1][j][0]));
            }
        }
    }
    //cout << dp[1][2][0] << '\n';
    int ans = 0;
    for (int i = 1; i <= 200; i++) {
        ans = sum(ans, dp[n - 1][i][1]);
    }
    cout << ans << '\n';
    return 0;
}