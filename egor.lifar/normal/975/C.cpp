 /*
 












 
 */
#pragma GCC optimize "-oFast"
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
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 200228;


int n, q;
long long a[MAXN];
long long k[MAXN];
long long sum[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//read(FILENAME);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i] = a[i];
        if (i) {
            sum[i] += sum[i - 1];
        }
    }
    int cur = 0;
    long long sub = 0;
    for (int i = 0; i < q; i++) {
        cin >> k[i];
        if (a[cur] <= sub + k[i]) {
            k[i] -= a[cur] - sub;
            cur++;
            sub = 0;
        } else {
            sub += k[i];
            k[i] = 0;
        }
        if (cur == n) {
            k[i] = 0;
            cur = 0;
            sub = 0;
        }
      //  cout << a[cur] << ' ' << cur + 1 << ' ' << sub << endl;
        if (k[i] == 0) {
            cout << n - cur << '\n';
        } else {
            if (a[cur] > k[i] + sub) {
                sub += k[i];
                cout << n - cur << '\n';
            } else {
                int l = cur;
                int r = n - 1;
                while (l != r) {
                    int mid = (l + r + 1) >> 1;
                    if (sum[mid] - (cur ? sum[cur - 1]: 0) <= k[i]) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                k[i] -= sum[l] - (cur ? sum[cur - 1]: 0);
                sub = 0;
                cur = l + 1;
                // if (cur != n) {
                //     if (a[cur] <= sub + k[i]) {
                //         k[i] -= a[cur] - sub;
                //         cur++;
                //         sub = 0;
                //     } else {
                //         sub += k[i];
                //         k[i] = 0;
                //     }
                // }
                if (cur == n) {
                    k[i] = 0;
                    cur = 0;
                    sub = 0;
                    cout << n << '\n';
                } else {
                    sub = k[i];
                    cout << n - cur << '\n';
                }
            }
        }
    }
    return 0;
}