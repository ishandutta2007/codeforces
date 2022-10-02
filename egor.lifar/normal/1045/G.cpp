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
const int MAXN = 100228;


struct fenwick {
    vector<int> f;
    int nn;
    void init(int n) {
        f.resize(n, 0);
        nn = n;
    }
    void inc(int i) {
        for (int j = i; j < nn; j = (j | (j + 1))) {
            f[j]++;
        }
    }
    int getsum(int l) {
        if (l < 0) {
            return 0;
        }
        int t = 0;
        for (int j = l; j >= 0; j = (j & (j + 1)) - 1) {
            t += f[j];
        }
        return t;
    }
    int get(int l, int r) {
        return getsum(r) - getsum(l - 1);
    }
};

int n, k;
int x[MAXN], r[MAXN], q[MAXN];
int id[MAXN];
unordered_map<int, vector<pair<int, int> > > g;
unordered_map<int, fenwick> d;
int pos[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);   
    cin >> n >> k;
    vector<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> r[i] >> q[i];
        st.pb({r[i], i});
        g[q[i]].pb({x[i], i});
    }
    sort(all(st));
    reverse(all(st));
    for (int i = 0; i < n; i++) {
        id[i] = st[i].second;
    }   
    for (auto &x: g) {
        sort(all(x.second));
        for (int j = 0; j < sz(x.second); j++) {
            pos[x.second[j].second] = j;
        }
        d[x.first].init(sz(x.second));
    }
    long long ans = 0;
    for (int it = 0; it < n; it++) {
        int i = id[it];
        for (int f = q[i] - k; f <= q[i] + k; f++) {
            if (g.find(f) == g.end()) {
                continue;
            }
            int ll = x[i] - r[i];
            int rr = x[i] + r[i];
            int fl = lower_bound(all(g[f]), make_pair(ll, 0)) - g[f].begin();
            int fr = upper_bound(all(g[f]), make_pair(rr, 1000000000))  - g[f].begin();
           // cout << fl << ' ' << fr << endl;
            if (fl < fr) {
                ans += d[f].get(fl, fr - 1);
                //cout << fl << ' ' << fr << ' ' << f << ' ' << i + 1 << endl;
            }
        }
        d[q[i]].inc(pos[i]);
    }
    cout << ans << endl;
    return 0;
}