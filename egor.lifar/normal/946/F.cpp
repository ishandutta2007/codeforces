
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
const int Mod = 1000000007;
const int MAXN = 103;


inline int add(int a, int b) {  
    a += b;
    return a >= Mod ? a - Mod: a;
}

inline int mul(int a, int b) {  
    return 1ll * a * b % Mod;
}


int cost[MAXN];
int left[MAXN][MAXN][MAXN];
int right[MAXN][MAXN][MAXN];
int middle[MAXN][MAXN][MAXN];
int all[MAXN];
int n, x;
string s;


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  // read(FILENAME);
    cin >> n >> x >> s;
    for (int i = 0; i <= x; i++) {
        if (i <= 1) {
            for (int j = 0; j < n; j++) {
                if (s[j] == '0' + i) {
                    left[i][j][j] = 1;
                    right[i][j][j] = 1;
                    middle[i][j][j] = 1;
                    if (n == 1) {
                        cost[i] = 1;
                    }
                }   
            }
            all[i] = 2;
        } else {
            cost[i] = add(mul(cost[i - 1], all[i - 2]), mul(cost[i - 2], all[i - 1]));
            all[i] = mul(all[i - 1], all[i - 2]);
            //cout << all[i] << endl;
            for (int j = 0; j < n; j++) {
                for (int k = j; k < n; k++) {
                    left[i][j][k] = add(mul(left[i - 1][j][k], all[i - 2]), left[i - 2][j][k]);
                    for (int mid = j; mid < k; mid++) {
                        left[i][j][k] = add(left[i][j][k], mul(middle[i - 1][j][mid], left[i - 2][mid + 1][k]));
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = j; k < n; k++) {
                    right[i][j][k] = add(right[i - 1][j][k], mul(right[i - 2][j][k], all[i - 1]));
                    for (int mid = j; mid < k; mid++) {
                        right[i][j][k] = add(right[i][j][k], mul(right[i - 1][j][mid], middle[i - 2][mid + 1][k]));
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = j; k < n; k++) {
                    middle[i][j][k] = add(middle[i - 1][j][k], middle[i - 2][j][k]);
                    for (int mid = j; mid < k; mid++) {
                        middle[i][j][k] = add(middle[i][j][k], mul(middle[i - 1][j][mid], middle[i - 2][mid + 1][k]));
                    }
                }
            }
            for (int j = 0; j < n - 1; j++) {
                cost[i] = add(cost[i], mul(right[i - 1][0][j], left[i - 2][j + 1][n - 1]));
            }
        }
    }
    cout << cost[x] << '\n';
    return 0;     
}