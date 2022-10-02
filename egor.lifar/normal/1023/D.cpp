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
const int MAXN = 200228;


int n, q;
int a[MAXN];
vector<int> pos[MAXN];
set<int> pos0;
int res[MAXN];
int f[MAXN];


void inc(int i, int val) {
    for (int j = i; j < n; j = j | (j + 1)) {
        f[j] += val;
    }
}


int get(int i) {
    if (i == -1) {
        return 0;
    }
    int res = 0;
    for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
        res += f[j];
    }
    return res;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);
        res[i] = a[i];
        if (a[i]) {
            inc(i, 1);
        } else {
            pos0.insert(i);
        }
    }
    int cnt = 0;
    for (int i = q; i >= 1; i--) {
        if (pos[i].empty()) {
            if (!pos0.empty()) {
                int a = *pos0.rbegin();
                if (res[a] == 0) {
                    res[a] = i;
                }
                pos0.erase(a);
                cnt++;
            } else {
                if (cnt == 0) {
                    cout << "NO\n";
                    exit(0);
                }
            }
        } else {
            for (auto x: pos[i]) {
                inc(x, -1);
                cnt++;
            }
            int l = pos[i][0];
            int r = pos[i].back();
            while (true) {
                auto it = pos0.lower_bound(l);
                if (it == pos0.end() || *it > r) {
                    break;
                }
                int f = *it;
                res[f] = i;
                pos0.erase(f);
            }
           // cout << l << ' ' << r << '\n'; 
            if (get(l, r) != 0) {
                cout << "NO\n";
                exit(0);
            }
            pos[i].clear();
        }
    }
    for (int i = 0; i < n; i++) {
        if (res[i] == 0) {
            res[i] = 1;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << "\n";
    return 0;       
}