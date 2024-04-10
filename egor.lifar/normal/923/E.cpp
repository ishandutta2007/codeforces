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
const int MAXN = 1 << 18;
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


void fft(vector<int> & v) {
    for (int i = 0; i < MAXN; i++) {
        if (i < brev[i]) {
            swap(v[i], v[brev[i]]);
        }
    }
    for (int len = 2; len <= MAXN; len *= 2) {
        const int hlen = len / 2;
        const int step = MAXN / len;
        for (int i = 0; i < MAXN; i += len) {
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
    int xx = powm(MAXN, Mod - 2);
    for (int i = 0; i < MAXN; i++) {
        v[i] = mul(v[i], xx);
    }
}


int fc[MAXN];
int rfc[MAXN];


void mult(vector<int>& a, vector<int>& b) {
    a.resize(MAXN, 0);
    b.resize(MAXN, 0);
    fft(a);
    fft(b);
    for (int i = 0; i < MAXN; i++) {
        a[i] = mul(a[i], b[i]);
    }
    reverse_fft(a);
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int n;
    long long  m;
    cin >> n >> m;
    n++;
    root_st[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        root_st[i] = mul(root_st[i - 1], 2192);
    }
    brev[0] = 0;
    for (int i = 1; i < MAXN; i++) {
      brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (18 - 1));
    }
    fc[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fc[i] = mul(fc[i - 1], i);
    }
    for (int i = 0; i < MAXN; i++) {
        rfc[i] = powm(fc[i], Mod - 2);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        p[i] = mul(p[i], fc[i]);
    }
    vector<int> g(n + 1);
    for (int i = 0; i <= n; i++) {
        g[i] = rfc[n - i];
    }
    mult(p, g);
    p.erase(p.begin(), p.begin() + n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
        p[i] = mul(p[i], rfc[i]);
    }
    for (int i = 0; i < n; i++) {
        p[i] = mul(p[i], powm(powm(i + 1, Mod - 2), m));
    }
    for (int i = 0; i < n; i++) {
        p[i] = mul(p[i], fc[i]);
    }
    for (int i = 1; i < n; i += 2) {
        p[i] = (Mod - p[i]) % Mod;
    }
    g.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        g[i] = rfc[n - i];
    }
    mult(p, g);
    p.erase(p.begin(), p.begin() + n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
        p[i] = mul(p[i], rfc[i]);
        if (i & 1) {
            p[i] = (Mod - p[i]) % Mod;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;       
}