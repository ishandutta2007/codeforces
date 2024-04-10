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
const int MAXN = 628;


map<vector<int>, int>  mem;


int ask(const vector<int> &p) {
    if (sz(p) == 1) {
        return 0;
    }
    if (mem.find(p) != mem.end()) {
        return mem[p];
    }
    cout << "? " << sz(p) << endl;
    for (auto x: p) {
        cout << x << ' ';
    }
    cout << endl;
    int res;
    cin >> res;
    mem[p] = res;
    return res; 
}


int getcnt(const vector<int> &a, const vector<int> &b) {
    if (a.empty() || b.empty()) {
        return 0;
    }
    vector<int> c;
    for (auto x: a) {
        c.pb(x);
    }
    for (auto x: b) {
        c.pb(x);
    }
    return ask(c) - ask(a) - ask(b);
}


pair<int, int> getedge(const vector<int> &a, const vector<int> &b) {
    int l = 0;
    int r = sz(a) - 1;
    while (l != r) {
        int mid = (l + r) >> 1;
        vector<int> as;
        for (int i = 0; i <= mid; i++) {
            as.pb(a[i]);
        }
        int t = getcnt(as, b);
        if (t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int la = a[l];
    vector<int> as;
    as.pb(la);
    l = 0;
    r = sz(b) - 1;
    while (l != r) {
        int mid = (l + r) >> 1;
        vector<int> bs;
        for (int i = 0; i <= mid; i++) {
            bs.pb(b[i]);
        }
        int t = getcnt(as, bs);
        if (t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int lb = b[l];
    return make_pair(la, lb);
}


pair<int, int> getedge1(const vector<int> &a) {
    int l = 0;
    int r = sz(a) - 1;
    while (l != r) {
        int mid = (l + r) >> 1;
        vector<int> as;
        for (int i = 0; i <= mid; i++) {
            as.pb(a[i]);
        }
        int t = ask(as);
        if (t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int la = a[l];
    vector<int> as;
    as.pb(la);
    r = l - 1;
    l = 0;
    while (l != r) {
        int mid = (l + r) >> 1;
        vector<int> bs;
        for (int i = 0; i <= mid; i++) {
            bs.pb(a[i]);
        }
        int t = getcnt(as, bs);
        if (t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int lb = a[l];
    return make_pair(la, lb);
}


int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> kek[2];


void dfs(int u, int t = 0) {
    kek[t].pb(u);
    for (auto h: g[u]) {
        dfs(h, t ^ 1);
        g[h].pb(u);
    }
}

vector<int> st;
bool dfs1(int u, int need) {
    used[u] = true;
    if (u == need) {
        st.pb(u);
        return true;
    }
    for (auto h: g[u]) {
        if (!used[h] && dfs1(h, need)) {
            st.pb(u);
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); 
    //read(FILENAME);
    cin >> n;
    if (n == 1) {
        cout << "Y " << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    vector<int> cura;
    cura.pb(1);
    used[1] = true;
    while (sz(cura) < n) {
        vector<int> curb;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                curb.pb(i);
            }
        }
        pair<int, int> p = getedge(cura, curb); 
        used[p.second] = true;
        g[p.first].pb(p.second);
        cura.pb(p.second);
    }
    dfs(1);
    int t = ask(kek[0]);
    if (t) {
        pair<int, int> p = getedge1(kek[0]);
        memset(used, 0, sizeof(used));
        dfs1(p.first, p.second);
        cout << "N " << sz(st) << endl;
        for (auto x: st) {
            cout << x << ' ';
        }
        cout << endl;
        return 0;
    }
    int t1 = ask(kek[1]);
    if (t1) {
        pair<int, int> p = getedge1(kek[1]);
        memset(used, 0, sizeof(used));
        dfs1(p.first, p.second);
        cout << "N " << sz(st) << endl;
        for (auto x: st) {
            cout << x << ' ';
        }
        cout << endl;
        return 0;
    }
    cout << "Y " << sz(kek[0]) << endl;
    for (auto x: kek[0]) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}