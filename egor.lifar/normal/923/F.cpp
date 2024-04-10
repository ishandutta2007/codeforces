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
const int MAXN = 10001;


int n;
bool v[MAXN][MAXN];
vector<int> g[MAXN * 2];
int ans[MAXN * 2];
int who[MAXN * 2];


bool check() {
    for (int i = 0; i < n; i++) {
        who[ans[i]] = i;
    }
    bool bad = false;
    for (int i = n; i < 2 * n; i++) {
        for (auto x: g[i]) {
            if (v[who[i]][who[x]]) {
                bad = true;
                break;
            }
        }
        if (bad) {
            break;
        }
    }
    if (bad) {
        return false;
    }
    return true;
}


int badv;


inline void link(int a, int b) {
    if (a >= n) {
        ans[b] = a;
    } else {
        ans[a] = b;
    }
}


bool bads[MAXN * 2];


void gen() {
    int l = 0;
    int r = n - 1;
    int l1 = n;
    int r1 = n + n - 1;
    if (badv < n) {
        l += n;
        r += n;
        l1 -= n;
        r1 -= n;
    }
    vector<int> s;
    for (int i = l; i <= r; i++) {
        if (sz(g[i]) == 1) {
            s.push_back(i);
        }
    }
    if (sz(s) == 0) {
        cout << "No\n";
        exit(0);
    }
    int t = s[rand() % sz(s)];
    link(badv, t);
    int d = g[t][0];
    for (auto x: g[badv]) {
        bads[x] = true;
    }
    vector<int> s1;
    for (int i = l1; i <= r1; i++) {
        if (!bads[i] && i != badv) {
            s1.push_back(i);
        }
    }
    if (sz(s1) == 0) {
        cout << "No\n";
        exit(0);
    }
    int t1 = s1[rand() % sz(s1)];
    link(d, t1);
    vector<int> g;
    for (int i = n; i < 2 * n; i++) {
        if (i != badv && i != t1 && i != t && i != d) {
            g.push_back(i);
        }
    }
    random_shuffle(all(g));
    int uk = 0;
    for (int i = 0; i < n; i++) {
        if (i != badv && i != t1 && i != t && i != d) {
            ans[i] = g[uk];
            uk++;
        }
    }
}



int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    time_t cur = clock();
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a][b] = true;
        v[b][a] = true;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        ans[i] = i + n;
    }
    badv = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (sz(g[i]) > sz(g[badv])) {
            badv = i;
        }
    }
    while (true) {
        gen();
        if (check()) {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                cout << ans[i] + 1 << ' ';
            }
            cout << '\n';
            return 0;
        }
        if (double(clock() - cur) / CLOCKS_PER_SEC >= 3.8) {
            break;
        }
    }
    cout << "No\n";
    return 0;       
}