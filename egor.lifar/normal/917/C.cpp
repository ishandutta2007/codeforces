
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
const long long INF = 2000000000000000000LL;



int x, k, n, q;
int c[8];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> x >> k >> n >> q;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    long long add = 0;
    vector<pair<int, int> > bad;
    for (int i = 0; i < q; i++) {
        int p, w;
        cin >> p >> w;
        p--;
        if (p + x >= n) {
            add += w;
        } else {
            bad.push_back(make_pair(p, w));
        }
    }
    bad.push_back(make_pair(0, 0));
    bad.push_back(make_pair(n - x, 0));
    sort(all(bad));
    vector<vector<vector<long long > > > matrix(30, vector<vector<long long > >(1 << k, vector<long long >(1 << k, INF)));
    vector<int> st;
    for(int i = 0; i < 1 << k; i++) {
        if (__builtin_popcount(i) != x) {
            continue;
        }
        st.emplace_back(i);
        if (i & 1) {
            int nextbit = i >> 1;
            for (int j = 0; j < k; j++) {
                if ((nextbit >> j) & 1) {
                    continue;
                }
                matrix[0][i][nextbit | (1 << j)] = c[j];
            }
        } else {
            matrix[0][i][i >> 1] = 0;
        }
    }
    for (int i = 1; i < 30; i++) {
        for (auto j: st) {
            for (auto ks: st) {
                for (auto l: st) {
                    chkmin(matrix[i][j][l], matrix[i - 1][j][ks] + matrix[i - 1][ks][l]);
                }
            }
        }
    }
    vector<long long > dp(1 << k, INF);
    dp[(1 << x) - 1] = 0;
    for (int i = 1; i < sz(bad); i++) {
        int dist = bad[i].first - bad[i - 1].first;
        for (int j = 0; j < 30; j++) {
            if ((dist >> j) & 1) {
                vector<long long > dp2(1 << k, INF);
                for (auto ks: st) {
                    for (auto l: st) {
                        chkmin(dp2[l], dp[ks] + matrix[j][ks][l]);
                    }
                }
                dp2.swap(dp);
            }
        }
        for (int j = 0; j < (1 << k); j++) {
            if (j & 1) {
                dp[j] += bad[i].second;
            }
        }
    }
    cout << dp[(1 << x) - 1] + add << endl;
}