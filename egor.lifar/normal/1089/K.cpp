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
const int MAXN = 300228;



struct node
{
    long long ft;
    long long et;
    int cnt;
    long long cadd;
};


int q;
node d[MAXN * 4];
pair<long long, long long> seg[MAXN];
int kill[MAXN];
long long z[MAXN];
char whos[MAXN];
int ss = 1;
unordered_map<int, int> where;



node merge(node a, node b) {
    if (a.cnt == 0) {
        return b;
    }
    if (b.cnt == 0) {
        return a;
    }
    node c;
    c.cnt = a.cnt + b.cnt;
    c.ft = a.ft;
    if (a.et <= b.ft) {
        c.et = b.et;
        c.cadd = a.cadd + b.cadd + b.ft - a.et;
    } else {
        if (b.cadd >= a.et - b.ft) {
            c.et = b.et;
            c.cadd = a.cadd + b.cadd - (a.et - b.ft);
        } else {
            c.et = b.et + a.et - b.ft - b.cadd;
            c.cadd = a.cadd;
        }
    }
    return c;
}


void change(int i, pair<long long, long long> p) {
    d[i].ft = p.first;
    d[i].et = p.second;
    d[i].cadd = 0;
    d[i].cnt = 1;
    while (i >> 1 > 0) {
        i >>= 1;
        d[i] = merge(d[i * 2], d[i * 2 + 1]);
    }
}


void change1(int i) {
    d[i].ft = 0;
    d[i].et = 0;
    d[i].cadd = 0;
    d[i].cnt = 0;
    while (i >> 1 > 0) {
        i >>= 1;
        d[i] = merge(d[i * 2], d[i * 2 + 1]);
    }
}


node rmq(int v, int vl, int vr, int l, int r) {
    if (l > vr || vl > r) {
        node t;
        t.et = 0;
        t.cnt = 0;
        return t;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    return merge(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   //read(FILENAME);
    cin >> q;
    vector<int> ts;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        whos[i] = c;
        if (c == '+') {
            int t, d;
            cin >> t >> d;
            ts.pb(t);
            seg[i] = make_pair(t, t + d);
            z[i] = -1;
        } else if (c == '-') {
            int id;
            cin >> id;
            id--;
            kill[i] = id;
        } else if (c == '?') {
            int t;
            cin >> t;
            ts.pb(t);
            z[i] = t;
        }
    }
    sort(all(ts));
    ts.resize(distance(ts.begin(), unique(all(ts))));
    for (int i = 0; i < sz(ts); i++) {
        where[ts[i]] = i;
    }
    ss = 1;
    while (ss < sz(ts)) {
        ss <<= 1;
    }
    for (int i = 0; i < 2 * ss; i++) {
        d[i].cnt = 0;
        d[i].ft = 0;
        d[i].et = 0;
        d[i].cadd = 0;
    }
    for (int i = 0; i < q; i++) {
        if (whos[i] == '+') {
            change(ss + where[seg[i].first], seg[i]);
        } else if (whos[i] == '-') {
            change1(ss + where[seg[kill[i]].first]);
        } else if (whos[i] == '?') {
            node t = rmq(1, 1, ss, 1, where[z[i]] + 1);
            cout << max(0LL, t.et - z[i]) << '\n';
        }
    }
    return 0;
}