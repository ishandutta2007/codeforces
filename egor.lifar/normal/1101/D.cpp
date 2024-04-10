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
const int MAXN = 200228;



int n;
int a[MAXN];
vector<int> g[MAXN];
vector<int> divs[MAXN];
bool need[MAXN];
int used[MAXN];
int uk;
int c;
int dist[MAXN];
vector<int> kek[MAXN];
vector<int> st;
int ans = 0;
bool prime[MAXN];


void dfs(int u) {
    st.pb(u);
    used[u] = uk;
    for (auto h: g[u]) {
        if (used[h] != uk) {
            if (a[h] % c == 0) {
                dist[h] = dist[u] + 1;
                dfs(h);
            }
        }
    }
}


void dfs1(int u) {
    chkmax(ans, dist[u]);
    used[u] = uk;
    for (auto h: g[u]) {
        if (used[h] != uk) {
            if (a[h] % c == 0) {
                dist[h] = dist[u] + 1;
                dfs1(h);
            }
        }
    }
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        need[a[i]] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 2; i <= 200000; i++) {
        if (prime[i]) {
            continue;
        }
        for (int j = i; j <= 200000;  j+= i) {
            prime[j] = true;
            if (need[j]) {
                divs[j].pb(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto x: divs[a[i]]) {
            kek[x].pb(i);
        }
    }
    for (int i = 2; i <= 200000; i++) {
        if (!kek[i].empty()) {
            uk++;
            c = i;
            for (auto x: kek[i]) {
                if (used[x] != uk) {
                    st.clear();
                    dist[x] = 1;
                    dfs(x);
                    int opt = -1;
                    int su;
                    for (auto z: st) {
                        used[z] = 0;
                        if (dist[z] > opt) {
                            opt = dist[z];
                            su = z;
                        }
                    }
                    dist[su] = 1;
                    dfs1(su);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0; 
}