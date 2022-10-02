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
const int MAXN = 600001;
const int Mod = 1000000007;


int powm(int a, int x) {
    if (x == 0) {
        return 1;
    } else if (x & 1) {
        int s = powm(a, x - 1);
        return (1LL * s * a) % Mod;
    } else {
        int s = powm(a, x >> 1);
        return (1LL * s * s) % Mod;
    }
}


inline void add(long long &a, long long b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
}


inline void sub(long long &a, long long b) {
    a -= b;
    if (a < 0) {
        a += Mod;
    }
}


int k, n, m;
vector<long long> vx;
int la[MAXN];
int ra[MAXN];
int lb[MAXN];
int rb[MAXN];
long long f[2][MAXN];
long long cnt[2];
int uk[2][MAXN];
int p[2];


int getx(int x) {
    return lower_bound(all(vx), x) - vx.begin();
}


void addseg(int x, int y, long long z) {
    add(cnt[x], z);
    add(f[x][y], z);
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> k >> n >> m;
    vx.push_back(0);
    vx.push_back(k);
    for (int i = 0; i < n; i++) {
        cin >> la[i] >> ra[i];
        vx.push_back(--la[i]);
        vx.push_back(ra[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> lb[i] >> rb[i];
        vx.push_back(--lb[i]);
        vx.push_back(rb[i]);
    }
    vx.push_back(-1);
    sort(all(vx));
    vx.resize(unique(all(vx)) - vx.begin());
    int c = sz(vx) - 1;
    addseg(0, 0, 1);
    for (int i = 0; i < n; i++) {
        chkmax(uk[0][getx(ra[i])], getx(la[i]));
    }
    for (int i = 0; i < m; i++) {
        chkmax(uk[1][getx(rb[i])], getx(lb[i]));
    }
    for (int i = 1; i < c; i++) {
        long long good = powm(2, vx[i + 1] - vx[i]);
        long long cur[2] = {cnt[0], cnt[1]};
        good -= 2;
        if (good < 0) {
            good += Mod;
        }
        good = (good * (cur[0] + cur[1])) % Mod;
        addseg(0, i, good);
        for (int j = 0; j < 2; j++) {
            addseg(j, i - 1, cur[j ^ 1]);
            while (p[j] < uk [j ^ 1][i + 1]) {
                sub(cnt[j], f[j][p[j]++]);
            }
        }
    }
    cout << (cnt[0] + cnt[1]) % Mod << '\n';
    return 0;       
}