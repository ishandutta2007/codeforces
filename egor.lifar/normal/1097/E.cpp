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
const int MAXN = 100228;

int n;
vector<vector<int> > st;


void getkek(vector<int> a) {
    while (true) {
        bool bad = false, bad1 = false;
        for (int i = 0; i < sz(a) - 1; i++) {
            if (a[i] < a[i + 1]) {
                bad = true;
            } else {
                bad1 = true;
            }
        }
        if (!bad || !bad1) {
            st.pb(a);
            return;
        }   
       // cout << "opa" << endl;
        vector<int> dp;
        dp.resize(sz(a) + 1);
        vector<int> who;
        who.resize(sz(a) + 1);
        for (int i = 1; i <= sz(a); i++) {
            dp[i] = 1e9;
        }
        vector<int> kek;
        vector<int> pr;
        pr.resize(sz(a));
        kek.resize(sz(a));
        who[0] = -1;
        int t = 0;
        int last = -1;
        vector<bool> used;
        used.resize(sz(a));
        for (int i = 0; i < sz(a); i++) {
            int pos = lower_bound(all(dp), a[i]) - dp.begin();
            pos--;
            used[i] = 0;
            kek[i] = pos + 1;
            chkmax(t, kek[i]);
            if (t == kek[i]) {
                last = i;
            }
            pr[i] = who[pos];
            if (dp[pos + 1] > a[i]) {
                dp[pos + 1] = a[i];
                who[pos + 1] = i;
            }
        }
       // cout << t << endl;
        if (t * (t + 1) > sz(a) * 2) {
           // cout << "opa" << endl;
            vector<int> f;
            while (last != -1) {
                f.pb(a[last]);
                used[last] = true;
                last = pr[last];
            }
            reverse(all(f));
            st.pb(f);
            vector<int> a1;
            for (int i = 0; i < sz(a); i++) {
                if (!used[i]) {
                    a1.pb(a[i]);
                }
            }
            a = a1;
            continue;
        }
        vector<vector<int> > g;
        g.resize(sz(a) + 1);
        for (int i = 0; i < sz(a); i++) {
            g[kek[i]].pb(a[i]);
        }
        for (int i = 1; i <= sz(a); i++) {
            if (!g[i].empty()) {
                st.pb(g[i]);
            }
        }
        return;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.clear();
        getkek(a);
        cout << sz(st) << '\n';
        for (auto x: st) {
            cout << sz(x);
            for (auto y: x) {
                cout << ' ' << y;
            }
            cout << '\n';
        }
    }
    return 0; 
}