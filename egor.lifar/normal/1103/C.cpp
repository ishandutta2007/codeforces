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
#include <array>
       
        
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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 250001;


int n, m, k;
vector<int> g[MAXN], v[MAXN];
bool used[MAXN];
int deep[MAXN];
int deep1[MAXN];
int prs[MAXN];
vector<int> gt[MAXN];


void dfs(int u, int prt = -1) {
    used[u] = true;
    for (auto h: g[u]) {
        if (!used[h]) {
            deep[h] = deep[u] + 1; 
            v[u].pb(h);
            v[h].pb(u);
            dfs(h, u);
        } else {
            if (h != prt) {
                if (deep[h] < deep[u]) {
                    gt[u].pb(h);
                }
            }
        }
    }
}


void dfs1(int u, int pr = -1) {
    for (auto h: v[u]) {
        if (h != pr) {
            deep1[h] = deep1[u] + 1; 
            prs[h] = u;
            dfs1(h, u);
        }
    }
}


vector<vector<int> > st;
int prt[MAXN];


void dfs2(int u, int pr = -1) {
    int cnt = 0;
    for (auto h: v[u]) {
        if (h != pr) {
            prt[h] = u;
            dfs2(h, u);
            cnt++;
        }
    }
    if (cnt) {
        return;
    }
    if (sz(st) == k) {
        return ;
    }
    bool good = false;
    for (auto h: gt[u]) {
        int s = deep[u] - deep[h] + 1;
        if (s % 3 != 0) {
            int cur = u;
            vector<int> kek;
            while (cur != h) {
                kek.pb(cur + 1);
                cur = prt[cur];
            }
            kek.pb(cur + 1);
            st.pb(kek);
            good = true;
            break;
        }
    }
    if (!good) {
        int h = gt[u][0];
        int h1 = gt[u][1];
        if (deep[h] > deep[h1]) {
            swap(h, h1);
        }
        vector<int> kek;
        kek.pb(u + 1);
        int cur = h1;
        while (cur != h) {
            kek.pb(cur + 1);
            cur = prt[cur];
        }
        kek.pb(cur + 1);
        st.pb(kek);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    int t = 0;
    for (int i = 1; i < n; i++) {
        if (deep[i] > deep[t]) {
            t = i;
        }
    }
    prs[t] = -1;
    dfs1(t);
    t = 0;
    for (int i = 1; i < n; i++) {
        if (deep1[i] > deep1[t]) {
            t = i;
        }
    }
    if (deep1[t] + 1 >= (n + k - 1) / k) {
        cout << "PATH\n";
        cout << deep1[t] + 1 << '\n';
        while (t != -1) {
            cout << t + 1 << ' ';
            t = prs[t];
        }
        cout << '\n';
        return 0;
    }
    dfs2(0);
    cout << "CYCLES\n";
    for (auto x: st) {
        cout << sz(x) << '\n';
        for (auto y: x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return 0;       
}