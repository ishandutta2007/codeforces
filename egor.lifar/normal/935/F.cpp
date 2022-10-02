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
const int MAXN = 100001;
const long long INF = (long long)2e18;


int n;
long long a[MAXN];
long long d[MAXN * 4];
long long ans = 0;


void update(int q, long long val, int xl = 0, int xr = n, int id = 1) {
    if (xl == xr - 1) {
        ans -= abs(a[xl]);
        a[xl] += val;
        ans += abs(a[xl]);
        if (xr < n) {
            d[id] = max(0LL, -a[xl]) + max(0LL, a[xr]);
        }
        if (val) {
            update(q - 1, 0);
        }
        return ;
    }
    int mid = (xl + xr) / 2;
    if (q < mid) {
        update(q, val, xl, mid, id * 2);
    } else {
        update(q, val, mid, xr, id * 2 + 1);
    }
    d[id] = min(d[id * 2], d[id * 2 + 1]);
    chkmin(d[id], max(0LL, -a[mid - 1]) + max(0LL, a[mid]));
}


long long query(int ql, int qr, int xl = 0, int xr = n, int id = 1) {
    if (qr <= xl || xr <= ql) {
        return INF;
    }
    if (ql <= xl && xr <= qr) {
        return d[id];
    }
    int mid = (xl + xr) / 2;
    return min(query(ql, qr, xl, mid, id * 2), query(ql, qr, mid, xr, id * 2 + 1));
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  //  read(FILENAME);
    for (int i = 0; i < MAXN * 4; i++) {
        d[i] = INF;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            a[i - 1] = a[i] - a[i - 1];
        }
    }
    n--;
    for (int i = 0; i < n; i++) {
        long long aa = a[i];
        a[i] = 0;
        update(i, aa);
    }
    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        l--, r--;
        if (t == 1) {
            if (l == r) {
                if (l == 0) {
                    cout << ans - abs(a[0]) + abs(a[0] - x) << '\n';
                } else if (l == n) {
                    cout << ans - abs(a[n - 1]) + abs(a[n - 1] + x) << '\n';
                } else {
                    cout << ans - abs(a[l - 1]) - abs(a[l]) + abs(a[l - 1] + x) + abs(a[l] - x) << '\n';
                }
                continue;
            }
            long long add = max(x * 2 - query(max(0, l - 1), r) * 2, 0LL);
            if (l == 0) {
                chkmax(add, x - max(0LL, a[0]) * 2);
            }
            if (r == n) {
                chkmax(add, x - max(0LL, -a[n - 1]) * 2);
            }
            cout << ans + add << '\n';
        } else {
            if (l > 0) {
                update(l - 1, x);
            }
            update(r, -x); 
        }
    }
    return 0;
}