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
#include <array>
       
        
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    x2 -= x1;
    y2 -= y1;
    if (x2 == 0 && y2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            sy++;
        } else if (s[i] == 'D') {
            sy--;
        } else if (s[i] == 'L') {
            sx--;
        } else if (s[i] == 'R') {
            sx++;
        }
    }
    int curx = 0, cury = 0;
    long long ans = 1e18;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            cury++;
        } else if (s[i] == 'D') {
            cury--;
        } else if (s[i] == 'L') {
            curx--;
        } else if (s[i] == 'R') {
            curx++;
        }
        int tx = abs(curx - x2);
        int ty = abs(cury - y2);
        if (tx + ty <= i + 1) {
            cout << i + 1 << endl;
            return 0;
        }
        int have = n;
        int posx = abs(sx);
        if (tx == 0) {
            posx = 0;
            have -= abs(sx);
        } else if (curx > x2 && sx > 0) {
             posx = 0;
            have -= abs(sx);
        } else if (curx < x2 && sx < 0) {
             posx = 0;
            have -= abs(sx);
        }
        int posy = abs(sy);
        if (ty == 0) {
             posy = 0;
            have -= abs(sy);
        } else if (cury > y2 && sy > 0) {
             posy = 0;
            have -= abs(sy);
        } else if (cury < y2 && sy < 0) {
             posy = 0;
            have -= abs(sy);
        }
        long long l = 0;
        long long r = 2000000001;
        while (l != r) {
            long long mid = (l + r) >> 1;
            long long kek = 1LL * have * mid + i + 1;
            long long cur = 0;
            if (abs(1LL * tx - 1LL * posx * mid) + abs(1LL * ty - 1LL * posy * mid) <= kek) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
         long long kek = 1LL * have * l + i + 1;
        if (abs(1LL * tx - 1LL * posx * l) + abs(1LL * ty - 1LL * posy * l) <= kek) {
            chkmin(ans, i + 1 + 1LL * n * l);
        }
    }
    if (ans > 1e17) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << '\n';
    return 0;       
}