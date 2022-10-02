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
const int MAXN = 100228;

int n, k;
vector<pair<int, int> > g[MAXN];
int down[MAXN];
int up[MAXN];
int prs[MAXN];
int deep[MAXN];


void dfs(int u, int pr = -1) {
    for (auto h: g[u]) {
        int x = h.first;
        if (x == pr) {
            continue;
        }
        prs[x] = u;
        deep[x] = deep[u] + 1;
        dfs(x, u);
        chkmax(down[u], down[x] + h.second);
    }
}


void dfs1(int u, int pr = -1) {
    multiset<int> s;
    for (auto h: g[u]) {
        int x = h.first;
        if (x == pr) {
            continue;
        }
        s.insert(down[x] + h.second);
    }
    for (auto h: g[u]) {
        int x = h.first;
        if (x == pr) {
            continue;
        }
        s.erase(s.find(down[x] + h.second));
        up[x] = max(up[u], (s.empty() ? 0: *s.rbegin())) + h.second;
        dfs1(x, u);
        s.insert(down[x] + h.second);
    }
}


int getlen(int a, int b, int c) {
    if (deep[b] > deep[a]) {
        return down[b];
    }
    return up[a] - c;
}


set<pair<int, pair<int, int> > > ss;

void add(int pre, int u) {
    for (auto x: g[u]) {
        if (x.first != pre) {
            ss.insert({getlen(u, x.first, x.second) + x.second, {u, x.first}});
        }
    }
}


bool bad[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dfs(0);
    dfs1(0);
    int center, opt = 2e9;
    for (int i = 0; i < n; i++) {
        int dist = up[i];
        for (auto h: g[i]) {
            if (h.first == prs[i]) {
                continue;
            }
            chkmax(dist, down[h.first] + h.second);
        }
        if (dist < opt) {
            opt = dist;
            center = i;
        }
    }
    vector<pair<int, int> > st;
    for (auto x: g[center]) {
        st.pb({getlen(center, x.first, x.second) + x.second, x.first});
    }
    sort(all(st));
    reverse(all(st));
    int cnt = 1;
    for (int i = 0; i < min(min(k - 1, 2), sz(st)); i++) {
        add(center, st[i].second);
        cnt++;
    }
    int ans = 0;
    for (int i = min(min(k - 1, 2), sz(st)); i < sz(st); i++) {
        chkmax(ans, st[i].first);
    }
    while (cnt < k && !ss.empty()) {
        pair<int, pair<int, int> > p = *ss.rbegin();
        ss.erase(p);
        if (bad[p.second.first]) {
            chkmax(ans, p.first);
            continue;
        }
        bad[p.second.first] = true;
        add(p.second.first, p.second.second);
        cnt++;
    }
    if  (ss.empty()) {
        cout << ans << '\n';
    } else {
        cout << max(ans, (*ss.rbegin()).first) << '\n';
    }
    return 0;
}