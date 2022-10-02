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
const int MAXN = 1000228;


int t;
bool used[26];
int who[26];
bool was[26];
int cnt[26];
bool can[MAXN][26], can1[MAXN][26];
bool canr[MAXN];
bool canr1[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int k;
        cin >> k;
        string s, a, b;
        cin >> s >> a >> b;
        memset(used, 0, sizeof(used));
        memset(was, 0, sizeof(was));
        int n = sz(s);
        vector<pair<int, int> > st;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            canr[i] = false;
            canr1[i] = false;
            memset(can[i], 0, sizeof(can[i]));
              memset(can1[i], 0, sizeof(can1[i]));
        }
        for (int i = 0; i < n; i++) {
            if (was[s[i] - 'a']) {
                if (who[s[i] - 'a'] < a[i] - 'a') {
                    break;
                }
                if (who[s[i] - 'a'] > a[i] - 'a') {
                    can[i][who[s[i] - 'a']] = true;                  
                    break;
                }
            } else {
                for (int t = a[i] - 'a' + 1; t < k; t++) {
                    if (!used[t]) {
                        can[i][t] = true;
                    }
                }
            }
            if (was[s[i] - 'a']) {
                if (who[s[i] - 'a'] != a[i] - 'a') {
                    break;
                }
            } else {
                if (used[a[i] - 'a']) {
                    break;
                }
                st.pb({s[i] - 'a', a[i] - 'a'});
                used[a[i] - 'a'] = true;
                who[s[i] - 'a'] = a[i] - 'a';
                was[s[i] - 'a'] = true;
            }
            canr[i] = true;
            if (i == n - 1) {
                can[i][a[i] - 'a'] = true;
            }
        }
        vector<pair<int, int> > st1 = st;
        st.clear();
        memset(used, 0, sizeof(used));
        memset(was, 0, sizeof(was));
        for (int i = 0; i < n; i++) {
            if (was[s[i] - 'a']) {
                if (who[s[i] - 'a'] > b[i] - 'a') {
                    break;
                }
                if (who[s[i] - 'a'] < b[i] - 'a') {
                    can1[i][who[s[i] - 'a']] = true;
                    break;
                }
            } else {
                for (int t = b[i] - 'a' - 1; t >= 0; t--) {
                    if (!used[t]) {
                        can1[i][t] = true;
                    }
                }
            }
            if (was[s[i] - 'a']) {
                if (who[s[i] - 'a'] != b[i] - 'a') {
                    break;
                }
            } else {
                if (used[b[i] - 'a']) {
                    break;
                }
                st.pb({s[i] - 'a', b[i] - 'a'});
                used[b[i] - 'a'] = true;
                who[s[i] - 'a'] = b[i] - 'a';
                was[s[i] - 'a'] = true;
            }
            if (i == n - 1) {
                can1[i][b[i] - 'a'] = true;
            }
            canr1[i] = true;
        }
        memset(used, 0, sizeof(used));
        for (int i = 0; i < k; i++) {
            who[i] = -1;
        }
        bool wass = false;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (canr[i - 1] && canr1[i - 1])) {
                if (a[i] < b[i] || (i == n - 1 && a[i] == b[i])) {
                    for (int t = 0; t < k; t++) {
                        if (can[i][t] && can1[i][t]) {
                            if ((t > a[i] - 'a' && t < b[i] - 'a') || (i == n - 1 && (t >= a[i] - 'a' && t <= b[i] - 'a'))) {
                                for (int j = 0; j < i; j++) {
                                    who[s[j] - 'a'] = a[j] - 'a';
                                    used[a[j] - 'a'] = true;
                                }
                                who[s[i] - 'a'] = t;
                                used[t] = true;
                                vector<int> g;
                                for (int j = 0; j < k; j++) {
                                    if (!used[j]) {
                                        g.pb(j);
                                    }
                                }   
                                cout << "YES\n";
                                for (int j = 0; j < k; j++) {
                                    if (who[j] == -1) {
                                        who[j] = g.back();
                                        g.pop_back();
                                    }
                                    cout << char(who[j] + 'a');
                                }
                                cout << '\n';
                                wass = true;
                                break;
                            }
                        }
                    }
                }
                if (wass) {
                    break;
                }
            }
            if (a[i] != b[i]) {
                break;
            }
        }
        if (wass) {
            continue;
        }
        bool was = false;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < k; i++) {
            who[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            if (i == 0 || canr[i - 1]) {
                for (int t = 0; t < 26; t++) {
                    if (can[i][t] && t >= a[i] - 'a' + (i != n - 1)) {
                        if (was) {
                            cout << "YES\n";
                            who[s[i] - 'a'] = t;
                            used[t] = true;
                            vector<int> g;
                            for (int j = 0; j < k; j++) {
                                if (!used[j]) {
                                    g.pb(j);
                                }
                            }   
                            for (int j = 0; j < k; j++) {
                                if (who[j] == -1) {
                                    who[j] = g.back();
                                    g.pop_back();
                                }
                                cout << char(who[j] + 'a');
                            }
                            cout << '\n';
                            wass = true;
                            break;
                        }
                    }
                }
                if (wass) {
                    break;
                }
            }
            who[s[i] - 'a'] = a[i] - 'a';
            used[a[i] - 'a'] = true;
            if (a[i] < b[i]) {
                was = true;
            }
            if (!was && a[i] > b[i]) {
                break;
            }
        }
        if (wass) {
            continue;
        }
        memset(used, 0, sizeof(used));
        for (int i = 0; i < k; i++) {
            who[i] = -1;
        }
        was = false;
        for (int i = 0; i < n; i++) {
            if (i == 0 || canr1[i - 1]) {
                for (int t = 0; t < 26; t++) {
                    if (can1[i][t] && t <= b[i] - 'a' - (i != n - 1)) {
                        if (was) {
                            cout << "YES\n";
                            who[s[i] - 'a'] = t;
                            used[t] = true;
                            vector<int> g;
                            for (int j = 0; j < k; j++) {
                                if (!used[j]) {
                                    g.pb(j);
                                }
                            }   
                            for (int j = 0; j < k; j++) {
                                if (who[j] == -1) {
                                    who[j] = g.back();
                                    g.pop_back();
                                }
                                cout << char(who[j] + 'a');
                            }
                            cout << '\n';
                            wass = true;
                            break;
                        }
                    }
                }
                if (wass) {
                    break;
                }
            }
            who[s[i] - 'a'] = b[i] - 'a';
            used[b[i] - 'a'] = true;
            if (b[i] > a[i]) {
                was = true;
            }
            if (!was && a[i] > b[i]) {
                break;
            }
        }
        if (wass) {
            continue;
        }
        cout << "NO\n";
    }
    return 0; 
}