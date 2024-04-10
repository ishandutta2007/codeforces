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
const int MAXN = 511;
const int M = 998244353;

int n;
long long a[MAXN];
vector<pair<long long, int> > st[MAXN], st1[MAXN];
bool bad[MAXN];
long long tp[MAXN][MAXN];
bool divs[MAXN];
unordered_map<long long, int> cnt;


long long gcd(long long a, long long b) {
    return (a == 0 ? b: gcd(b % a, a));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n;
    //int anss = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

    }
    for (int i = 0; i < n; i++) {

        
        long long l = 1;
        while (l * l * l * l < a[i]) {
            l++;
        }
        if (l * l * l * l == a[i]) {
            st[i].pb({l, 4});
            continue;
        }
        l = 1;
        long long r = 2000000;
        while (l != r) {
            long long mid = (l + r + 1) >> 1;
            if (mid * mid * mid > a[i]) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if (l * l * l == a[i]) {
            st[i].pb({l, 3});
            continue;
        }
        long long f = (long long)sqrt(a[i]);
        if (f * f == a[i]) {
            st[i].pb({f, 2});
            continue;
        }
        bad[i] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tp[i][j] = gcd(a[i], a[j]);
        }
    }
    vector<int> checks;
    for (int i = 0; i < n; i++) {
        if (bad[i]) {
            for (int j = 0; j < n; j++) {
                if (!bad[j]) {
                    long long t = tp[i][j];
                   // assert(t < a[i]);
                    // assert(t < a[i] && t < a[j]);
                    if (t != 1 && t != a[j] && t != a[i]) {
                        st[i].pb({t, 1});
                        st[i].pb({a[i] / t, 1});
                        bad[i] = false;
                        checks.pb(i);
                        break;
                    }
                }
            }
        }
    }
    while (true) {
        vector<int> checks1;
        for (int i = 0; i < n; i++) {
            if (bad[i]) {
                for (auto j: checks) {
                    long long t = tp[i][j];
                    //assert(t < a[i] && t < a[j]);
                    if (t != 1) {
                        st[i].pb({t, 1});
                        st[i].pb({a[i] / t, 1});
                        bad[i] = false;
                        checks1.pb(i);
                        break;
                    }
                }
            }
        }
        checks = checks1;
        if (checks.empty()) {
            break;
        }
    }
    vector<pair<long long, int> > kek;
    vector<long long> td;
    for (int i = 0; i < n; i++) {
        if (bad[i]) {
           // cout << i << endl;
            td.pb(a[i]);
        }
    }
    sort(all(td));
    for (auto x: td) {
        if (kek.empty() || kek.back().first != x) {
            kek.pb({x, 1});
        } else {
            kek.back().second++;
        }
    }
    for (int i = 0; i < sz(kek); i++) {
        if (divs[i]) {
            continue;
        }
        for (int j = 0; j < sz(kek); j++) {
            if (i ==j) {
                continue;
            }
            long long t = gcd(kek[i].first, kek[j].first);
          //  assert(t < min(kek[i].first, kek[j].first));
            if (t != 1) {
                //cout << i << ' ' << j << ' ' << sz(kek) << endl;
                if (!divs[i]) {
                    st1[i].pb({kek[i].first / t, 1});
                    st1[i].pb({t, 1});
                }
                divs[i] = true;
                if (!divs[j]) {
                    st1[j].pb({kek[j].first / t, 1});
                    st1[j].pb({t, 1});
                }
                divs[j] = true;
            }
        }
    }
    //cout << gcd(kek[6].first, kek[7].first) << endl;
    int ans = 1;
    for (int i = 0; i < sz(kek); i++) {
        if (!divs[i]) {
            ans = (1LL * ans * (kek[i].second + 1)) % M; 
            ans = (1LL * ans * (kek[i].second + 1)) % M; 
           // cout << kek[i].first << endl;
        } else {
            for (auto x: st1[i]) {
               // cout << x.first << ' ' << x.second << endl;
                cnt[x.first] += x.second * kek[i].second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto x: st[i]) {
         //   cout << x.first << ' ' << x.second << endl;
            cnt[x.first] += x.second;
        }
    }
    for (auto x: cnt) {
      //  cout << x.first << ' ' << x.second << endl;
        ans = 1LL * ans * (x.second + 1) % M;
    }
   // cout << ans << endl;
    cout << ans << '\n';
    return 0;
}