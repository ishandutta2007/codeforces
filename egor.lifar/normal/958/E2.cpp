/*
 












 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
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
//WULD! NAH! KEST!
const int MAXN = 500228;


struct interval
{
    int l, r;
    long long add;
    interval(){}
    interval(int _l, int _r, long long _add) {
        l = _l;
        r = _r;
        add = _add;
    }
};



bool operator <(const interval &a, const interval &b) {
    return a.add < b.add || (a.add == b.add && make_pair(a.l, a.r) < make_pair(b.l, b.r));
}

int n;
int a[MAXN];
long long sum[MAXN];


long long getsum(int l, int r) {
    return sum[r] - (l >= 2 ? sum[l - 2]: 0);
}


set<interval> kek;
set<int> keks;
set<pair<int, int> > segs;


void delsingles(int l, int r) {
    auto it = keks.lower_bound(r);
    if (it != keks.end()) {
        int s = *it;
        if (s == r + 1) {
            keks.erase(s);
            kek.erase(interval(s + 1, s, a[s + 1] - a[s]));
        }
    }
    it = keks.lower_bound(l);
    if (it != keks.begin()) {
        it--;
        int s = *it;
        if (s == l - 1) {
            keks.erase(s);
            kek.erase(interval(s + 1, s, a[s + 1] - a[s]));
        }
    }
}   


long long getscore(int l, int r) {
    if (l == 0 || r == n - 1) {
        return 1e18;
    }
    return getsum(l - 1, r + 1) - getsum(l, r);
}


void add(int l, int r) {
    segs.insert({l, r});
    kek.insert(interval(l, r, getscore(l, r)));
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // / read(FILENAME);
    int ks;
    cin >> ks >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        sum[i] = a[i + 1] - a[i];
        if (i >= 2) {
            sum[i] += sum[i - 2];
        }
    }
    n--;
    for (int i = 0; i < n; i++) {
        keks.insert(i);
        kek.insert(interval(i + 1, i, a[i + 1] - a[i]));
    }
    long long sum = 0;
    for (int cnt = 1; cnt <= ks; cnt++) {
        assert(sz(kek));
        interval q = *kek.begin();
        kek.erase(q);
        sum += q.add; 
        if (cnt == ks) {
            cout << sum << '\n';
            return 0;
        }
        if (q.l > q.r) {
            q.l--;
            keks.erase(q.l);
        } else {
            segs.erase({q.l, q.r});
            q.l--;
            q.r++;
        }
        int l = q.l;
        int r = q.r;
        delsingles(l, r);
        if (segs.empty()) {
            add(l, r);
        } else {
            auto it = segs.lower_bound({r, -1});
            if (it != segs.end()) {
                pair<int, int> p = *it;
                if (p.first == r + 2) {
                    segs.erase(p);
                    kek.erase(interval(p.first, p.second, getscore(p.first, p.second)));
                    r = p.second;
                }
            }
            it = segs.lower_bound({l, -1});
            if (it != segs.begin()) {
                it--;
                 pair<int, int> p = *it;
                if (p.second == l - 2) {
                    segs.erase(p);
                    kek.erase(interval(p.first, p.second, getscore(p.first, p.second)));
                    l = p.first;
                }
            }
            add(l, r);
        }
    }
    return 0;     
}