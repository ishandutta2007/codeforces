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
const int MAXN = 500228;


int n;
int a[MAXN];
vector<int> st;
long long pref[MAXN];


bool can(int x) {
    int uk = n - 1;
    long long d = 0;
    for (int i = 1; i <= n - 1; i++) {
        while (st[uk] < i) {
            uk--;
        }
        long long kek = 1LL * (max(uk, i - 1) - i + 1) * i + pref[n - 1] - pref[max(uk, i - 1)];
        kek += 1LL * i * (i - 1);
       // cout << cur << ' ' << kek << endl;
        if (pref[i - 1] > kek) {
            chkmax(d, pref[i - 1] - kek);
        }
    }
    //cout << d << endl;
    return d <= x;
}


bool can1(int x) {
    vector<int> st2 = st;
    st2.pb(x);
    sort(all(st2));
    reverse(all(st2));
    for (int i = 0; i <= n; i++) {
        pref[i] = st2[i];
        if (i) {
            pref[i] += pref[i - 1];
        }
    }
    int uk = n;
    long long d = 0;
    for (int i = 1; i <= n; i++) {
        while (st2[uk] < i) {
            uk--;
        }
        long long kek = 1LL * (max(uk, i - 1) - i + 1) * i + pref[n] - pref[max(uk, i - 1)];
        kek += 1LL * i * (i - 1);
        //cout << kek << ' ' << pref[i - 1] << ' ' << i << endl;
        if (pref[i - 1] > kek) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    int sum = 0;    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.pb(a[i]);
        sum += a[i] & 1;
    }
    sort(all(st));
    reverse(all(st));
    for (int i = 0; i < n; i++) {
        pref[i] = st[i];
        if (i) {
            pref[i] += pref[i - 1];
        }
    }
    int l = 0, r = n;
    if (sum & 1) {
        l = 1;
    }
    if ((r & 1) != (l & 1)) {
        r--;
    }
    int ost = l & 1;
    l /= 2;
    r /= 2;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (can(mid * 2 + ost)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (!can1(l * 2 + ost)) {
        cout << -1 << '\n';
        return 0;
    }
    int l1 = l;
    int r1 = (n + 1) / 2;
    while (r1 * 2 + ost > n) {
        r1--;
    }
    while (l1 != r1) {
        int mid = (l1 + r1 + 1) >> 1;
        if (can1(mid * 2 + ost)) {
            l1 = mid;
        } else {
            r1 = mid - 1;
        }
    }
    for (int i = l; i <= l1; i++) {
        cout << ost + i * 2 << ' ';
    }
    cout << '\n';
    return 0; 
}