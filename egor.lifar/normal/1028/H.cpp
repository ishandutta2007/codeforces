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
const int MAXN = 200000;


int n, q;
int a[MAXN];
vector<pair<int, bool> > st[5032110];
bool prime[5032110];
bool need[5032110];
int pos[8][5032110];
int gr[15][MAXN * 4];
int ss = 1;


int getmin(int i, int l, int r) {
    l += ss - 1;
    r += ss - 1;
    int res = 1e9;
    while (l <= r) {
        if (l & 1) {
            chkmin(res, gr[i][l]);
            l++;
        }
        if (!(r & 1)) {
            chkmin(res, gr[i][r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    //read("input");
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        need[a[i]] = true;
    }
    for (int i = 2; i <= 5032107; i++) {
        if (!prime[i]) {
            for (int j = i; j <= 5032107; j += i) {
                if (need[j]) {
                    int cur = j;
                    int cnt = 0;
                    while (cur % i == 0) {
                        cur /= i;
                        cnt++;
                    }
                    cnt &= 1;
                    st[j].pb({i, cnt});
                }
                prime[j] = true;
            }
        }
    }  
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int cost = 0; cost <= 14; cost++) {
            gr[cost][ss + i] = n;
        }
        vector<pair<int, int> > poss;
        for (int mask= 0; mask < (1 << sz(st[a[i]])); mask++) {
            long long kek = 1;
            int cnt = 0;
             bool bad = false;
            for (int j = 0; j < sz(st[a[i]]); j++) {
                if (st[a[i]][j].second == 1) {
                    cnt++;
                } else {
                    if (mask & (1 << j)) {
                        bad = true;
                        break;
                    }
                    continue;
                }
                if (mask & (1 << j)) {
                    kek *= st[a[i]][j].first;
                }
            }
            if (bad) {
                continue;
            }
            if (i != n - 1) {
                int c = __builtin_popcount(mask);
                for (int t = 0; t <= 7; t++) {
                    if (t + cnt - c * 2 < 0) {
                        continue;
                    }
                    chkmin(gr[t + cnt - c * 2][ss + i], (pos[t][kek] == 0? n: pos[t][kek]));
                }
            }
            poss.pb({cnt, kek});
        }
        for (auto x: poss) {
            pos[x.first][x.second] = i;
        }
    }
    for (int i = 0; i <= 14; i++) {
        for (int j = ss - 1; j >= 1; j--) {
            gr[i][j] = min(gr[i][j * 2], gr[i][j * 2 + 1]);
        }
    }
 //   cout << gr[2][ss + 1] << endl;
    for (int it = 0; it < q; it++) {
        int l, r;
        cin >> l >> r;
        for (int i = 0; i <= 14; i++) {
            int t = getmin(i, l, r);
            if (t < r) {
                cout << i << '\n';
                break;
            }
        }
    }
}