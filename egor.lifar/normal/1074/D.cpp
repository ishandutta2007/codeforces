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
const string FILENAME = "input";
const int MAXN = 200228;


map<int, int> cur;
map<int, int> ranks;
map<int, int> parent;
map<int, bool> was;



int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    int g = parent[v];
    int x = findset(parent[v]);
    parent[v] = x;
    cur[v] ^= cur[g];
    return x;
}


void add(int l, int r, int x) {
    if (was.find(l) == was.end()) {
        parent[l] = l;
        cur[l] = 0;
        was[l] = true;
        ranks[l] = 0; 
    }
    if (was.find(r) == was.end()) {
        parent[r] = r;
        cur[r] = 0;
        was[r] = true;
        ranks[r] = 0;
    }
    int lr = findset(l);
    int rr = findset(r);
    if (lr == rr) {
        if ((cur[l] ^ cur[r]) != x) {
            return;
        }
    }
    x ^= cur[l] ^ cur[r];
    if (ranks[lr] > ranks[rr]) {
        chkmax(ranks[lr], ranks[rr] + 1);
        parent[rr] = lr;
        cur[rr] = x;
    } else {
        chkmax(ranks[rr], ranks[lr] + 1);
        parent[lr] = rr;
        cur[lr] = x;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
	//read(FILENAME);
    int q;
    cin >> q;
    int last = 0;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l1, r1, x1;
            cin >> l1 >> r1 >> x1;
            l1 = l1 ^ last;
            r1 = r1 ^ last;
            x1 = x1 ^ last;
            if (l1 > r1) {
                swap(l1, r1);
            }
            l1++;
            r1++;
            add(l1 - 1, r1, x1);
        } else {
            int l1, r1;
            cin >> l1 >> r1;
            l1 = l1 ^ last;
            r1 = r1 ^ last;
            if (l1 > r1) {
                swap(l1, r1);
            }
            l1++;
            r1++;
            l1--;
            if (was.find(l1) == was.end()) {
                parent[l1] = l1;
                cur[l1] = 0;
                was[l1] = true;
                ranks[l1] = 0;
            }
            if (was.find(r1) == was.end()) {
                parent[r1] = r1;
                cur[r1] = 0;
                was[r1] = true;
                ranks[r1] = 0;
            }
            if (findset(l1) != findset(r1)) {
                last = 1;
                cout << -1 << '\n';
            } else {
                int x = cur[l1] ^ cur[r1];
                cout << x << '\n';
                last = x;
            }
        }
    }
    return 0;
}