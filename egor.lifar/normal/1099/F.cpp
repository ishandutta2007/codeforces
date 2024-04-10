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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 100228;



struct fenwick
{
    vector<long long> f;
    void init(int n) {
        f.resize(n);
    }
    void inc(int i, long long x) {
        for (int j = i; j < sz(f); j = j | (j + 1)) {
            f[j] += x;
        }
    }
    long long get(int i) {
        long long ans = 0;
        for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
            ans += f[j];
        }
        return ans;
    }
    long long getsum(int l, int r) {
        if (l > r) {
            return 0;
        }
        return get(r) - (l == 0 ? 0: get(l - 1));
    }
};


int n;
long long T;
int x[MAXN], t[MAXN];
vector<int> g[MAXN];
int l[MAXN];
long long deep[MAXN];
long long dp[MAXN];
int where[MAXN];
fenwick tot, cnt;
vector<pair<int, int> > st;


void add(int u, int mod) {
    tot.inc(where[u], 1LL * x[u] * t[u] * mod);
    cnt.inc(where[u], x[u] * mod);
}


long long getkek(long long border) {
    if (border < 0) {
        return 0;
    }
    if (tot.getsum(0, n - 1) <= border) {
        return cnt.getsum(0, n - 1);
    }
    int l = 0;
    int r = n - 1;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (tot.getsum(0, mid) > border) {
            r = mid;
        } else {
            l = mid + 1;
        }
    } 
    long long ans = cnt.getsum(0, l - 1);
    border -= tot.getsum(0, l - 1);
    int f = st[l].first;
    return ans + border / f;
}


void dfs(int u) {
    add(u, 1);
    for (auto h: g[u]) {
        deep[h] = deep[u] + l[h];
        dfs(h);
    }
    dp[u] = getkek(T - deep[u] * 2);
    if (u == 0) {
        for (auto h: g[u]) {
            chkmax(dp[u], dp[h]);
        }
    } else {
        long long sx = 0, sy = 0;    
        for (auto h: g[u]) {
            if (sx < dp[h]) {
                sy = sx;
                sx = dp[h];
            } else if (sy < dp[h]) {
                sy = dp[h];
            }
        }
        chkmax(dp[u], sy);
    }
    add(u, -1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        st.pb({t[i], i});
    }
    sort(all(st));
    for (int i = 0; i < n; i++) {
        where[st[i].second] = i;
    }
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p >> l[i];
        p--;
        g[p].pb(i);
    }
    tot.init(n);
    cnt.init(n);
    dfs(0);
    cout << dp[0] << endl;
    return 0; 
}