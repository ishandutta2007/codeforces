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
const int MAXN = 100228;


int n;
string s;
int dp[MAXN];
int jump[MAXN][2];
string cur;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> s;
    n = sz(s);
    for (int i = 0; i < n; i++) {
        jump[i][0] = i - 1;
        jump[i][1] = i + 1;
    }
    jump[n - 1][1] = -1; 
    int curl = 0;
    int curr = 0;
    int pl = 1;
    int pr = n - 1;
    for (int i = 1; i < n; i++) {
        if (s[curr] != s[pl]) {
            int f = pl;
            for (int t = 0; t < 2; t++) {
                if (jump[pl][t] != curr) {
                    pl = jump[pl][t];
                    break;
                }
            }
            curr = f;
        } else {
            swap(curl, curr);
            swap(pl, pr);
             for (int t = 0; t < 2; t++) {
                if (jump[curr][t] == -1) {
                    jump[curr][t] = pl;
                    break;
                }
             }
               for (int t = 0; t < 2; t++) {
                if (jump[curl][t] == pr) {
                    jump[curl][t] = -1;
                    break;
                }
             }
            for (int t = 0; t < 2; t++) {
                if (jump[pl][t] == -1) {
                    jump[pl][t] = curr;
                    break;
                }
            }
            for (int t = 0; t < 2; t++) {
                if (jump[pr][t] == curl) {
                    jump[pr][t] = -1;
                    break;
                }
            }
            int f = pl;
            for (int t = 0; t < 2; t++) {
                if (jump[pl][t] != curr) {
                    pl = jump[pl][t];
                    break;
                }
            }
            curr = f;
        }
    }
    int cur = curl;
    int p = -1;
    string st;
    st += s[cur];
    for (int i = 0; i < n - 1; i++) {
        for (int t = 0; t < 2; t++) {
            if (jump[cur][t] != p) {
                p = cur;
                cur = jump[cur][t];
                break;
            }
        }
        st += s[cur];
    }
    //cout << st << '\n';
    int curlen = 1;
    char last = st[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (st[i] != last) {
            curlen++;
            chkmax(ans, curlen);
            last = st[i];
        } else {
            curlen = 1;
            last = st[i];
        }
    }
    cout << ans << '\n';
    return 0;       
}