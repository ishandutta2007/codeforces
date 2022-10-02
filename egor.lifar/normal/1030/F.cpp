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
#define x first
#define y second
const string FILENAME = "input";
const int MAXN = 200228;
const int M = 1000000007;
const long long base = 1000000000000000000LL;

struct fenwick {
    vector<long long> f;
    int nn;
    void init(int n) {
        f.resize(n, 0);
        nn = n;
    }
    void inc(int i, long long val) {
        for (int j = i; j < nn; j = (j | (j + 1))) {
            f[j]+= val;
        }
    }
    long long getsum(int l) {
        if (l < 0) {
            return 0;
        }
        long long t = 0;
        for (int j = l; j >= 0; j = (j & (j + 1)) - 1) {
            t += f[j];
        }
        return t;
    }
    long long get(int l, int r) {
        return getsum(r) - getsum(l - 1);
    }
};


struct fenwick1 {
    vector<long long> f;
    int nn;
    void init(int n) {
        f.resize(n, 0);
        nn = n;
    }
    void inc(int i, long long val) {
        for (int j = i; j < nn; j = (j | (j + 1))) {
            f[j]+= val;
            f[j] %= M;
        }
    }
    long long getsum(int l) {
        if (l < 0) {
            return 0;
        }
        long long t = 0;
        for (int j = l; j >= 0; j = (j & (j + 1)) - 1) {
            t += f[j];
            t %= M;
        }
        return t;
    }
    long long get(int l, int r) {
        return (getsum(r) - getsum(l - 1)) % M;
    }
};



int n, q;
int a[MAXN];
int w[MAXN];
fenwick wss;
fenwick1 wss1;
fenwick1 pref;
fenwick1 suff;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);   
    cin >> n >> q;
    wss.init(n);
    wss1.init(n);
    pref.init(n);
    suff.init(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        wss.inc(i, w[i]);
        wss1.inc(i, 1LL * w[i] * a[i] % M);
    }
    for (int i = 0; i < n; i++) {
        pref.inc(i, 1LL * w[i] * (i + 1) % M);
    }
    for (int i = 0; i < n; i++) {
        suff.inc(i, 1LL * w[i] * (n - i) % M);
    }
    for (int it = 0; it < q; it++) {
        int x;
        cin >> x;
        if (x < 0) {
            int y;
            cin >> y;
            x *= -1;
            x--;
            wss.inc(x, y - w[x]);
            wss1.inc(x, (1LL * y * a[x]) % M -(1LL * w[x] * a[x]) % M);
             pref.inc(x, (1LL * y * (x + 1)) % M - 1LL * w[x] * (x + 1) % M);
             suff.inc(x, (1LL * y * (n - x)) % M - 1LL * w[x] * (n - x) % M);
            w[x] = y;
        } else {
            int y;
            cin >> y;
            x--, y--;
            int l = x;
            int r = y;
            long long f = wss.get(x, y);
            while (l != r) {
                int mid = (l + r) >> 1;
                long long k = wss.get(x, mid);
                if (k >= f - k) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            //cout << l << endl;
            long long ans = 0;
            if (x < l) {
                long long t = wss1.get(x, l - 1);
                long long f = 1LL * a[l] * (wss.get(x, l - 1) % M) % M;
                //1 * w[l - 1];
                //2 * w[l - 2];
                f -= suff.get(x, l - 1);
                f += (wss.get(x, l - 1) * (n - l)) % M;
                f -= t;
                f %= M;
                if (f < 0) {
                    f += M;
                }
                ans += f;
                ans %= M;
            } 
           //  cout << ans << ' ' << it + 1 << ' ' << l << endl;
            if (l + 1 <= y) {
                long long t = wss1.get(l + 1, y);
                //out << t << endl;
                long long f = 1LL * a[l] * (wss.get(l + 1, y) % M) % M;
              //  cout << f << endl;
                //1 * w[l - 1];
                //2 * w[l - 2];
                f += pref.get(l + 1, y);
              // cout << wss.get(l + 1, y) * (l + 1) << endl;
                f -= (wss.get(l + 1, y) * (l + 1)) % M;
               // cout << f - 13 << endl;
                t -= f;
                t %= M;
                if (t < 0) {
                    t += M;
                }
                ans += t;
                ans %= M;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}