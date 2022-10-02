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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   //read(FILENAME);
    int m;
    cin >> m;
    for (int it = 0; it < m; it++) {
        int a, b;
        cin >> a >> b;
        int res = -10000;
        int ks, ks1;
        vector<pair<int, int> > ans;
        for (int len = 3; len <= 5; len++) {
            for (int mask = 0; mask < (1 << len); mask++) {
                int t = __builtin_popcount(mask);
                if (t < 3 && len - t < 3) {
                    continue;
                }
                if (t > 3 || len - t > 3) {
                    continue;
                }
                if (t == 3) {
                    if (!(mask & (1 << (len - 1)))) {
                        continue;
                    }
                } else {
                    if (mask & (1 << (len - 1))) {
                        continue;
                    }
                }
                int ta = a;
                int tb = b;
                vector<pair<int, int> > scores;
                for (int i = 0; i < len; i++) {
                    if (i == 4) {
                        if (mask & (1 << i)) {
                            ta -= 15;
                            scores.pb({15, 0});
                        } else {
                            tb -= 15;
                            scores.pb({0, 15});
                        }
                        continue;
                    }
                    if (mask & (1 << i)) {
                        ta -= 25;
                        scores.pb({25, 0});
                    } else {
                        tb -= 25;
                        scores.pb({0, 25});
                    }
                }
                if (ta < 0 || tb < 0) {
                    continue;
                }
                for (int i = 0; i < len && ta; i++) {
                    while (ta && scores[i].first + 2 < scores[i].second) {
                        scores[i].first++;
                        ta--;
                    }                
                }
                for (int i = 0; i < len && tb; i++) {
                    while (tb && scores[i].second + 2 < scores[i].first) {
                        scores[i].second++;
                        tb--;
                    }
                }
                if (ta != tb) {
                    if (ta > tb) {
                        for (int i = 1; i < len; i++) {
                            if (scores[i].first > scores[i].second) {
                                int k = min(ta - tb, scores[i].second);
                                scores[i].second -= k;
                                tb += k;
                            }
                        }
                    } else {
                       for (int i = 1; i < len; i++) {
                            if (scores[i].first < scores[i].second) {
                                int k = min(tb - ta, scores[i].first);
                                scores[i].first -= k;
                                ta += k;
                            }
                        } 
                    }
                }
                if (ta != tb) {
                    continue;
                }
              //  cout << ta << ' ' << tb << endl;
                if (ta) {
                    scores[0].first += ta;
                    scores[0].second += tb;
                }
                int f = t - (len - t);
                if (f > res) {
                    res = f;
                    ks = t;
                    ks1 = len - t;
                    ans = scores;
                }
            }
        }
        if (res == -10000) {
            cout << "Impossible\n";
        } else {
            cout << ks << ':' << ks1 << '\n';
            for (auto x: ans) {
                cout << x.first << ':' << x.second << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}