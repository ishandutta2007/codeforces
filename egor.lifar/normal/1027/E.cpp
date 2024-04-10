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
const int MAXN = 508;
const int Mod = 998244353;


int sum(int a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
    return a;
}


int mul(int a, int b) {
    return (1LL * a * b) % Mod;
}

int n, k;
int dp[2][MAXN][MAXN];
int dp1[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> k;
    //cout << n << ' ' << k << '\n';
    //cout << "opa" << '\n';
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
   // cout << n << ' ' << k << '\n';
    dp[0][1][1] = 1;
    int g = 1;
    for (int i = 0; i < n - 1; i++) {
        memset(dp[g], 0, sizeof(dp[g]));
        for (int maxt = 1; maxt <= i + 1; maxt++) {
            for (int cur = 1; cur <= i + 1; cur++) {
                if (dp[g ^ 1][maxt][cur] == 0) {
                    continue;
                }
                dp[g][max(maxt, cur + 1)][cur + 1] = sum(dp[g][max(maxt, cur + 1)][cur + 1], dp[g ^ 1][maxt][cur]);
                dp[g][maxt][1] = sum(dp[g][maxt][1], dp[g ^ 1][maxt][cur]);
            }
        }
        g ^= 1;
    }
    int ans = 0;
    for (int cur = 1; cur <= n; cur++) {
        for (int f = 1; f <= n; f++) {
            dp1[cur] = sum(dp1[cur], dp[g ^ 1][cur][f]);
        }
    }
    for (int cur = 1; cur <= n; cur++) {
        for (int cur1 = 1; cur1 <= n; cur1++) {
            if (cur * cur1 < k) {
                ans = sum(ans, mul(dp1[cur], dp1[cur1]));
            }
        }
    }
    ans = mul(ans, 2);
    cout << ans << '\n';
    return 0;       
}