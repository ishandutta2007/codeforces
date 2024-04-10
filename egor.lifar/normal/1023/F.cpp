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
const int MAXN = 500228;


int n, k, m;
int ma[MAXN];
int mb[MAXN];
int parent[2][MAXN];
int ranks[2][MAXN];
int fa[MAXN], fb[MAXN], fw[MAXN];


int findset(int id, int v) {
    if (v == parent[id][v]) {
        return v;
    }
    return parent[id][v] = findset(id, parent[id][v]);
}


void setunion(int id, int a, int b) {
    a = findset(id, a);
    b = findset(id, b);
    if (a == b) {
        return;
    }
    if (ranks[id][a] > ranks[id][b]) {
        parent[id][b] = a;
        chkmax(ranks[id][a], ranks[id][b] + 1);
    } else {
        parent[id][a] = b;
        chkmax(ranks[id][b], ranks[id][a] + 1);
    }
}


vector<pair<int, int> > g[MAXN];
bool used[MAXN];
int deep[MAXN];
pair<bool, int> pr[MAXN];
int where[MAXN];


void dfs(int u) {
    used[u] = true;
    for (auto h: g[u]) {
        if (!used[h.second]) {
            deep[h.second] = deep[u] + 1;
            pr[h.second] = {h.first, u};
            dfs(h.second);
        }
    }
}


int findplace(int x) {
    if (x == where[x]) {
        return x;
    }
    return where[x] = findplace(where[x]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) {
        cin >> ma[i] >> mb[i];
        ma[i]--;
        mb[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> fa[i] >> fb[i] >> fw[i];
        fa[i]--;
        fb[i]--;
    }
    for (int i = 0; i < n; i++) {
        for (int it = 0; it < 2; it++) {
            ranks[it][i] = 1;
            parent[it][i] = i;
        }
    }
    for (int i = 0; i < k; i++) {
        setunion(0, ma[i], mb[i]);
        g[ma[i]].pb({1, mb[i]});
        g[mb[i]].pb({1, ma[i]});
    }
    vector<int> st;
    for (int i = 0; i < m; i++) {
        if (findset(0, fa[i]) == findset(0, fb[i]) && findset(1, fa[i]) != findset(1, fb[i])) {
            st.pb(i);
        } else {
            setunion(0, fa[i], fb[i]);
            setunion(1, fa[i], fb[i]);
            g[fa[i]].pb({0, fb[i]});
            g[fb[i]].pb({0, fa[i]});
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        where[i] = i;
    }
    int cnt = 0;
    long long ans = 0;
    for (auto x: st) {
        int a = findplace(fa[x]), b = findplace(fb[x]);
        vector<int> kek;
        while (a != b) {
            kek.pb(a);
            kek.pb(b);
            if (deep[a] < deep[b]) {
                swap(a, b);
            }
            if (pr[a].first) {
                cnt++;
                pr[a].first = 0;
                ans += fw[x];
            }
            a = findplace(pr[a].second);
        }
        for (auto x: kek) {
            where[x] = a;
        }
    } 
    if (cnt != k) {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;       
}