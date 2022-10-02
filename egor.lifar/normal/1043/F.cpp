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
const int MAXN = 300228;


int n;
int a[MAXN];
vector<int> g[MAXN];
int cnt[MAXN];
int dp[129];


int gcd(int a, int b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}


int len;
int val;
int cur = 0;
int ks = 0;


void get(int i, int mask) {
    if (i == len) {
        //cout << cur << ' ' << mask << '\n';
        //cout << cur << ' ' << mask << ' ' << ks << '\n';
        if (ks & 1) {
            dp[cur] -= val;
        } else {
            dp[cur] += val;
        }
       // cout << dp[cur] << ' ' << cur << ' ' << val << '\n'; 
        return;
    }
    if (mask & (1 << i)) {
        ks++;
        get(i + 1, mask);
        ks--;
        cur |= (1 << i);
        get(i + 1, mask);
        cur ^= (1 << i);
    } else {
        get(i + 1, mask);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n;
    vector<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.pb(a[i]);
    }
    sort(all(st));
    st.resize(distance(st.begin(), unique(all(st))));
    n = sz(st);
    for (int i = 0; i < n; i++) {
        a[i] = st[i];
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        t = gcd(t, a[i]);
    }
    if (t != 1) {
        cout << -1 << '\n';
        return 0;
    }
    //<= 6
    for (int i = 0; i < n; i++) {
        //cout << a[i] << '\n';
        if (a[i] == 1) {
            cout << 1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int j = 2;
        while (j * j <= a[i]) {
            if (a[i] % j == 0) {
                g[i].pb(j);
                while (a[i] % j == 0) {
                    a[i] /= j;
                }
            } 
            j++;
        }
        if (a[i] != 1) {
            g[i].pb(a[i]);
        }
    }
    vector<vector<int> > cur;
    for (int i = 0; i < n; i++) {
        cur.pb(g[i]);
    }
    sort(all(cur));
    cur.resize(distance(cur.begin(), unique(all(cur))));
    if (sz(cur) == 1) {
        cout << -1 << '\n';
        return 0;
    }
    for (int lens = 2; lens <= 1000; lens++) {  
        if (lens == n) {
            cout << n << '\n';
            return 0;
        }  
        memset(cnt, 0, sizeof(cnt));
        for (auto x: cur) {
            for (int mask = 0; mask < (1 << sz(x)); mask++) {
                int kek = 1;
                for (int j = 0; j < sz(x); j++) {
                    if (mask & (1 << j)) {
                        kek *= x[j];
                    }
                }
                cnt[kek]++;
            }   
        }
        vector<vector<int> > ns;
        for (int i = 0; i < n; i++) {
            memset(dp, 0, sizeof(dp));
            for (int mask = (1 << sz(g[i])) - 1; mask >= 0; mask--) {
                int kek = 1;
                for (int j = 0; j < sz(g[i]); j++) {
                    if (mask & (1 << j)) {
                        kek *= g[i][j];
                    }
                }
                val = cnt[kek];
                len = sz(g[i]);
               // cout << cnt[kek] << ' ' << kek << '\n';
                get(0, mask);
            }   
            for (int mask = 0; mask < (1 << sz(g[i])); mask++) {
                if (dp[mask]) {
                    int kek = 1;
                    vector<int> gs;
                    for (int j = 0; j < sz(g[i]); j++) {
                        if (mask & (1 << j)) {
                            gs.pb(g[i][j]);
                            kek *= g[i][j];
                        }
                    }
                   // cout << dp[mask] << ' ' << kek << '\n';
                    if (kek == 1) {
                        cout << lens << '\n';
                        return 0;
                    }
                    ns.pb(gs);
                }
            }
        }
        sort(all(ns));
        ns.resize(distance(ns.begin(), unique(all(ns))));
        cur = ns;
    }
    return 0;
}