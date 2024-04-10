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
const int MAXN = 4022;

struct point
{
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


point operator -(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
}



long long vec(point a, point b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}


int n;
point p[MAXN];


int semiplane(const point &a) {
    return (a.y > 0 || (a.y == 0 && a.x < 0));
}


bool comp(pair<point, int> as, pair<point, int> bs) {
    point a = as.first;
    point b = bs.first;
    int t = semiplane(a);
    int t1 = semiplane(b);
    if (t != t1) {
        return t > t1;
    }
    return vec(a, b) > 0;
}


int sum[MAXN];
int pos[MAXN];
vector<pair<point, int> > st;


int get(int l, int r) {
    if (l <= r) {
        return sum[r] - (l ? sum[l - 1]: 0);
    }
    return sum[sz(st) - 1] - (l ? sum[l - 1]: 0) + sum[r];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);   
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        st.clear();
        for (int j = 0; j < n; j++) {
            if (i != j) {
                st.pb({p[j] - p[i], j});
                st.pb({p[i] - p[j], n + j});
            }   
        }
        sort(all(st), comp);
        for (int j = 0; j < sz(st); j++) {
            sum[j] = (st[j].second < n ? 1: 0);
            if (j) {
                sum[j] += sum[j - 1];
            }
            if (st[j].second >= n) {
                pos[st[j].second - n] = j;
            }
        }
        for (int j = 0; j < sz(st); j++) {
            if (st[j].second < n) {
                int l = (j + 1) % sz(st);
                int r = pos[st[j].second];
                int f = get(l, r);
                int f1 = get((r + 1) % sz(st), (j - 1 + sz(st)) % sz(st));
                long long sts = 1LL * f * (f - 1) / 2 * f1 * (f1 - 1) / 2;
                ans += sts;
            } 
        }
    }
    cout << ans / 2 << '\n';
    return 0;       
}