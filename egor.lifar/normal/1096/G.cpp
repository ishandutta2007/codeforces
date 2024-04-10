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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 1 << 22;
const int Mod = 998244353;
const int g = 3;


int mul(int a, int b) {
    return (1LL * a * b) % Mod;
}

int sum(int a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
    return a;
}


int powm(int a, long long b) {
    if (b == 0) {
        return 1;
    } else {
        if (b & 1) {
            return mul(powm(a, b - 1), a);
        } else {
            int s = powm(a, b >> 1);
            return mul(s, s);
        }
    }
}


int root_st[MAXN];
int brev[MAXN];
int cur = (1 << 21);


void fft(vector<int> & v) {
    for (int i = 0; i < cur; i++) {
        if (i < brev[i]) {
            swap(v[i], v[brev[i]]);
        }
    }
    for (int len = 2; len <= cur; len *= 2) {
        const int hlen = len / 2;
        const int step = cur / len;
        for (int i = 0; i < cur; i += len) {
            for (int j = 0; j < hlen; j++) {
              int a = v[i + j];
              int b = mul(v[i + j + hlen], root_st[j * step]);
              v[i + j] = sum(a, b);
              v[i + j + hlen] = sum(a, Mod - b);
            }
        }
    }
}


void reverse_fft(vector<int>& v) {
    fft(v);
    reverse(v.begin() + 1, v.end());
    int xx = powm(cur, Mod - 2);
    for (int i = 0; i < cur; i++) {
        v[i] = mul(v[i], xx);
    }
}


vector<int> gg;


void mult(vector<int> &a, vector<int> b) {
    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
    while (!b.empty() && b.back() == 0) {
        b.pop_back();
    }
    cur = 1;
    int cntp =0;
    while (cur < sz(a) + sz(b)) {
        cur <<= 1;
        cntp++;
    }
   // cout << sz(a) << endl;
    int tp = powm(g, (Mod - 1) / cur);
    root_st[0] = 1;
    for (int i = 1; i < cur; i++) {
        root_st[i] = mul(root_st[i - 1], tp);
    }
    brev[0] = 0;
    for (int i = 1; i < cur; i++) {
      brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (cntp - 1));
    }
    a.resize(cur, 0);
    b.resize(cur, 0);
    fft(a);
    fft(b);
    for (int i = 0; i < cur; i++) {
        a[i] = mul(a[i], b[i]);
    }
    reverse_fft(a);
    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
}


vector<int> pows(int st) {
    vector<int> f = gg;
    vector<int> res;
    res.resize(1);
    res[0] = 1;
    while (st > 0) {
        if (st & 1) {
            mult(res, f);
        }
        st >>= 1;
        if (st) {
            mult(f, f);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int n, k;
    cin >> n >> k;
  
    gg.resize(10);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        gg[d] = 1;
    }
    vector<int> t = pows(n / 2);
    int ans = 0;
    for (int i = 0; i < sz(t); i++) {
        ans = sum(ans, mul(t[i], t[i]));
    }
    cout << ans << '\n';
    return 0; 
}