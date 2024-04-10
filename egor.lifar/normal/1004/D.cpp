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
#include <iomanip>
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
const int MAXN = 1000228;

int t;
int a[MAXN];
int dist = 0;
int cnt[MAXN];
int cntp[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        chkmax(dist, a[i]);
    }
    //cout << dist << endl;
    int len = dist + 1;
    for (int cur = 1; cur <= dist; cur++) {
        if (cnt[cur] != cur * 4) {
            len = cur;
            break;
        }
    }
  //  cout << len << endl;
    for (int i = 1; i <= (int)sqrt(t); i++) {
        if (t % i == 0) {
            int n = i;
            int m = t / i;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                  //  sort(all(g));
                    if (min(min(i + 1, j + 1), min(n - i, m - j)) == len) {
                   // cout << g[2] + g[3] - 2 << endl;
                       // cout << n << ' ' << m << ' ' << i + 1 << ' ' << j + 1 << endl;
                     //   cout << g[2] << ' ' << g[3] << endl;
                        if (max(i + 1, n - i) + max(m - j, j + 1) - 2 == dist) {
                            //cout << n << ' ' << m << ' ' << i + 1 << ' ' << j + 1 << endl;
                            memset(cntp, 0, sizeof(cntp));
                            for (int i1 = 0; i1 < n; i1++) {
                                for (int j1 = 0; j1 < m; j1++) {
                                    cntp[abs(i1 - i) + abs(j1 - j)]++;
                                }
                            }
                            bool bad = false;
                            for (int i1 = 0; i1 <= dist; i1++) {
                                if (cntp[i1] != cnt[i1]) {
                                    bad = true;
                                    break;
                                }
                            }
                            if (!bad) {
                                cout << n << ' ' << m << '\n';
                                cout << i + 1 << ' ' << j +1 << '\n';
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}