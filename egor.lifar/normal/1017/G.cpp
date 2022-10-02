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
#define prev preg128
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 1000228;
const int BLOCK = 600;


bool black[MAXN];
vector<int> g[MAXN]; 
bool prblack[MAXN]; 
int t[MAXN], v[MAXN]; 
bool used[MAXN]; 
vector<pair<pair<int, int>, int> > g1[MAXN]; 
int push[MAXN]; 
bool clear[MAXN]; 


void dfs1(int pos, int prev = -1, int white = 0, int dist = 0){
    if (used[pos]) {
        if (prev != -1) {
            g1[prev].pb(make_pair(make_pair(pos, white), dist));
        }
        for (auto a: g[pos]) {
            dfs1(a, pos, 0, 0);
        }
    }else{
        if (!black[pos]) {
            white++;
        }
        for (auto a: g[pos]) {
            dfs1(a, prev, white, dist + 1);
        }
    }
}


void get1(int pos){
    if (!black[pos]) {
        black[pos] = true;
        return;
    }
    push[pos]++;
    for (auto a: g1[pos]) {
        if (a.first.second + 1 <= push[pos]) {
            get1(a.first.first);
        }
    }
}

void get2(int pos) {
    black[pos] = false;
    push[pos] = 0;
    clear[pos] = true;
    for (auto &a: g1[pos]){
        a.first.second = a.second;
        get2(a.first.first);
    }
}


void dfs2(int pos, int p = 0, bool cl = false){
    if (used[pos]) {
        p = push[pos];
        cl |= clear[pos];
    }else{
        black[pos] = prblack[pos];
        if (cl) {
            black[pos] = false;
        }
        if(!black[pos] && p){
            black[pos] = true;
            p--;
        }
    }
    for (auto a: g[pos]) {
        dfs2(a, p, cl);
    }
}

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        g[a].pb(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[i] >> v[i];
    }
    int root = 1;
    for (int i = 1; i <= q; i += BLOCK) {
        for (int j = 1; j <= n; j++) {
            used[j] = false;
            g1[j].clear();
            prblack[j] = black[j];
            push[j] = 0;
            clear[j] = false;
        }
        for (int j = 0; j < BLOCK && i + j <= q; j++) {
            used[v[i + j]] = true;
        }
        dfs1(root);
        for (int j = 0; j < BLOCK && i + j <= q; j++) {
            if (t[i + j] == 1) {
                get1(v[i + j]);
            } else if(t[i + j] == 2) {
                get2(v[i + j]);
            } else {
                cout << (black[v[i + j]] ? "black": "white") << '\n';
            }
        }
        dfs2(root);
    }
    return 0;       
}