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
const int MAXN = 200228;
const int Mod = 998244353;

int n;
int a[MAXN];
int f[MAXN];



int powm(int a, int x) {
    if (x == 0) {
        return 1;
    }
    if (x & 1) {
        return (1LL * powm(a, x - 1) * a) % Mod;
    }
    int s = powm(a, x >> 1);
    return (1LL * s * s) % Mod;
}


void inc(int i, int val) {
    for (int j = i; j <= n; j |= (j + 1)) {
        f[j] += val;
    }
}


int get(int i) {
    int ans = 0;
    for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
        ans += f[j];
    }
    return ans;
}


int getsum(int l, int r) {
    return get(r) - (l == 0 ? 0: get(l - 1));
}


bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            ans += getsum(a[i], n);
            ans %= Mod;
            used[a[i]] = true;
        }
        if (a[i] != -1) {
            inc(a[i], 1);
        } else {
            cnt++;
        }
    }
    ans += (((1LL * cnt * (cnt - 1) / 2) % Mod) * powm(2, Mod - 2)) % Mod;
    ans %= Mod;
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            st.pb(i);
        }
    }
   // cout << ans<< '\n';
    int cur = 0;
     for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            int pos = lower_bound(all(st), a[i]) - st.begin();
            pos = sz(st) - pos;
            if (pos != 0) {
                int k = (1LL * pos * powm(sz(st), Mod - 2)) % Mod;
                k = (1LL * k * cur) % Mod;
                ans += k;
                ans %= Mod;
            }
        } else {
            cur++;
        }
    }
    cur = 0;
     for (int i = n - 1; i >= 0; i--) {
        if (a[i] != -1) {
            int pos = lower_bound(all(st), a[i]) - st.begin();
            if (pos != 0) {
                int k = (1LL * pos * powm(sz(st), Mod - 2)) % Mod;
                k = (1LL * k * cur) % Mod;
                ans += k;
                ans %= Mod;
            }
        } else {
            cur++;
        }
    }
    cout << ans << endl;
    return 0; 
}