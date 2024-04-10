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


int n, m;
vector<int> g[MAXN];
bool can[MAXN][2];
int pr[MAXN][2];
int used[MAXN];


void dfs(int u) {
    used[u] = 1;
    for (auto h: g[u]) {
        if (used[h]) {
            if (used[h] == 1) {
                cout << "Draw\n";
                exit(0);
            }
        } else {
            dfs(h);
        }
    }
    used[u] = 2;
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            a--;
            g[i].push_back(a);
        }
    }
    int s;
    cin >> s;
    s--;
    queue<pair<int, int> > q;
    q.push(make_pair(s, 0));
    can[s][0] = true;
    while (!q.empty()) {
        pair<int, int> a = q.front();
        q.pop();
        for (auto x: g[a.first]) {
            if (!can[x][a.second ^ 1]) {
                can[x][a.second ^ 1] = true;
                pr[x][a.second ^ 1] = a.first;
                q.push(make_pair(x, a.second ^ 1));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
            if (can[i][1]) {
                cout << "Win\n";
                int cur = i;
                int t = 1;
                vector<int> g;
                while (cur != s || t != 0) {
                    g.push_back(cur);
                    cur = pr[cur][t];
                    t ^= 1;
                }
                g.push_back(s);
                reverse(all(g));
                for (auto x: g) {
                    cout << x + 1 << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }
    dfs(s);
    cout << "Lose\n";
    return 0;
}