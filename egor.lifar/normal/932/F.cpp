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
const int MAXN = 100001;


struct line {
    long long k, b;   
    line() {k = 0, b = 0;}
    line(long long _k, long long _b) {
        k = _k;
        b = _b;
    }
    long long val(long long x) {
        return k * x + b;
    }
};


bool operator <(const line &a, const line &b) {
    return a.k > b.k;
}


long long mdiv(long long a, long long b) {
    if (b < 0) {
        a = -a, b = -b;
    }
    if (a < 0) {
        return a / b;
    } else {
        return (a + b - 1) / b;
    }
}


long long intersect(const line &a, const line &b) {
    return mdiv(a.b - b.b, b.k - a.k);
}


struct ConvexHull {
    vector<line> st;
    vector<long long> points;
    ConvexHull(){}
    void add(const line &l) {
        if (sz(st) && st.back().k == l.k && l.b >= st.back().b) {
            return;
        }
        while (sz(st) && st.back().k == l.k && l.b < st.back().b) {
            st.pop_back();
            if (sz(points)) {
                points.pop_back();
            }
        }
        while (sz(points) && points.back() >= intersect(l, st.back())) {
            st.pop_back();
            points.pop_back();
        }
        if (sz(st)) {
            points.push_back(intersect(l, st.back()));
        }
        st.push_back(l);
    }
    long long get(long long x) {
        if (sz(st) == 0) {
            return (long long)1e18;
        }
        int uk = (int)(upper_bound(all(points), x) - points.begin());
      //  cout << uk << ' ' << sz(st) << endl;
        //cout << st[uk].k << ' ' << st[uk].b << ' ' << x << endl;
        return st[uk].val(x);
    }
};


int n;
int a[MAXN], b[MAXN];
vector<int> g[MAXN];
vector<line> h[MAXN * 4];
ConvexHull tr[MAXN * 4];
int ss = 1;



long long rmq(int v, int vl, int vr, int l, int r, long long x) {
    if (vr < l || vl > r) {
        return (long long)1e18;
    } 
    if (l <= vl && vr <= r) {
       // cout << x << endl;
      //  cout << tr[v].get(x) << ' ' << x << endl;
        return tr[v].get(x);
    }
    return min(rmq(v * 2, vl, (vl + vr) / 2, l, r, x), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x));
}


inline void build(int i) {
    for (auto x: h[i]) {
        tr[i].add(x);
    }
}


inline void change(int i, line x) {
   // cout << x.k << endl;
    h[i].push_back(x);
    build(i);
    while (i >> 1) {
        i >>= 1;
        if (h[i].empty() && sz(h[i * 2]) && sz(h[i * 2 + 1])) {
            h[i].resize(sz(h[i * 2]) + sz(h[i * 2 + 1]));
            merge(all(h[i * 2]), all(h[i * 2 + 1]), h[i].begin());
            build(i);
        }
    }
}


int in[MAXN];
int out[MAXN];
int tt = 0;
long long ans[MAXN];


void dfs(int u, int pr = -1) {
    tt++;
    in[u] = tt;
    for (auto h: g[u]) {
        if (h != pr) {
            dfs(h, u);
        }
    }
    out[u] = tt;
    if (pr != -1 && sz(g[u]) == 1) {
        ans[u] = 0;
    } else {
        //cout << rmq(1, 1, ss, in[u] + 1, out[u], a[u]) << endl;
        ans[u] = rmq(1, 1, ss, in[u] + 1, out[u], a[u]); 
    }
   // cout << in[u] << endl;
   // cout << b[u] << endl;
    change(ss + in[u] - 1, line(b[u], ans[u]));
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 //   read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        g[c].push_back(d);
        g[d].push_back(c);
    }
    while (ss < n) {
        ss <<= 1;
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}