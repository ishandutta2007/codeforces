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
const int MAXN = 2228;


int n, k;
string s[MAXN];
int dp[MAXN][MAXN];
bool g[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
   //read(FILENAME);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1e9;
        }
    }
    if (k >= 1 && s[0][0] != 'a') {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for (int i = 1; i < 2 * n - 1; i++) {
        int curx = (i < n ? i: n - 1);
        int cury = (i < n ? 0: i - n + 1);
        char c = 'z';
        //cout << curx << ' ' << cury << endl;
        while (true) {
            if (curx) {
                if (dp[curx - 1][cury] < k) {
                    chkmin(c, 'a');
                }
                if (dp[curx - 1][cury] <= k) {
                    chkmin(c, s[curx][cury]);
                }
            }
            if (cury) {
                if (dp[curx][cury - 1] < k) {
                    chkmin(c, 'a');
                }
                if (dp[curx][cury - 1] <= k) {
                    chkmin(c, s[curx][cury]);
                }
            }
            curx--;
            cury++;
            if (curx < 0 || cury >= n) {
                break;
            }
        }
        //cout << c << endl;
        curx = (i < n ? i: n - 1);
        cury = (i < n ? 0: i - n + 1);
        while (true) {
            if (s[curx][cury] == c) {
                g[curx][cury] = true;
                if (curx) {
                    if (dp[curx - 1][cury] <= k) {
                        chkmin(dp[curx][cury], dp[curx - 1][cury]);
                    }
                }
                if (cury) {
                    if (dp[curx][cury - 1] <= k) {
                        chkmin(dp[curx][cury], dp[curx][cury - 1]);
                    }
                }
            } else {
                if (curx) {
                    if (dp[curx - 1][cury] < k) {
                        chkmin(dp[curx][cury], dp[curx - 1][cury] + 1);
                    }
                }
                if (cury) {
                    if (dp[curx][cury - 1] < k) {
                        chkmin(dp[curx][cury], dp[curx][cury - 1] + 1);
                    }
                }
            }
            curx--;
            cury++;
            if (curx < 0 || cury >= n) {
                break;
            }
        }
    }
    int curi = n - 1;
    int curj = n - 1;
    string ans;
    while (true) {
        if (curi == 0 && curj == 0) {
            if (dp[0][0] == 1) {
                ans += 'a';
            } else {
                ans += s[0][0];
            }
            break;
        }
        if (curi) {
            if (g[curi][curj] && dp[curi - 1][curj] == dp[curi][curj]) {
                ans += s[curi][curj];
                curi--;
                continue;
            }
            if (!g[curi][curj] && dp[curi - 1][curj] == dp[curi][curj] - 1) {
                ans += 'a';
                curi--;
                continue;
            }
        }
        if (curj) {
            if (g[curi][curj] &&  dp[curi][curj - 1] == dp[curi][curj]) {
                ans += s[curi][curj];
                curj--;
                continue;
            }
            if (!g[curi][curj] &&  dp[curi][curj - 1] == dp[curi][curj] - 1) {
                ans += 'a';
                curj--;
                continue;
            }
        }
    }
    reverse(all(ans));
    cout << ans << '\n';
    return 0;
}