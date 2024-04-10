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
const int MAXN = 400001;


int q;
int jump[MAXN][20];
long long maxt[MAXN][20];
int jump1[MAXN][20];
long long sum[MAXN][20];
long long k[MAXN];
int deep[MAXN];
int uk = 0;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   //read(FILENAME);
    long long last = 0;
    cin >> q;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        long long ps, qs;
        cin >> ps >> qs;
        int r = ps ^ last;
        long long w = qs ^ last;
        if (t == 1) {
            uk++;
            r--;
            k[uk] = w;
            jump[uk][0] = r;
            maxt[uk][0] = k[r];
            for (int t = 1; t < 20; t++) {
                jump[uk][t] = jump[jump[uk][t - 1]][t - 1];
                maxt[uk][t] = max(maxt[uk][t - 1], maxt[jump[uk][t - 1]][t - 1]);
            }
            int cur = uk;
            for (int t = 19; t >= 0; t--) {
                if (maxt[cur][t] < k[uk]) {
                    cur = jump[cur][t];
                }
            }
            cur = jump[cur][0];
            if (k[cur] >= k[uk]) {
                jump1[uk][0] = cur;
                sum[uk][0] = k[cur];
                deep[uk] = deep[cur] + 1;
                for (int t = 1; t < 20; t++) {
                    jump1[uk][t] = jump1[jump1[uk][t - 1]][t - 1];
                    sum[uk][t] = sum[uk][t - 1] + sum[jump1[uk][t - 1]][t - 1];
                }
            } else {
                deep[uk] = 0;
                jump1[uk][0] = uk;
                sum[uk][0] = 0;
                for (int t = 1; t < 20; t++) {
                    jump1[uk][t] = uk;
                    sum[uk][t] = 0;
                }
            }
        } else {
            r--;
            int ans = 0;
            if (k[r] <= w) {
                w -= k[r];
                ans++;
                int cur = r;
                for (int t = 19; t >= 0; t--) {
                    if (sum[cur][t] <= w) {
                        w -= sum[cur][t];
                        cur = jump1[cur][t];
                    }
                }
                ans += deep[r] - deep[cur];
            }
            cout << ans << '\n';
            last = ans;
        }
    }
}