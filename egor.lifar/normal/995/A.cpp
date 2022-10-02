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

int n, k;
int r = -1, c = 0;
int cnt = 0;
vector<pair<int, pair<int, int> > > v;
int a[5][60];


void cycle(){
   int pr = r, pc = c;
   if(r == 2){
      c++;
      if(c > n){
         c --;
         r ++;
      }
   } else {
      c--;
      if (c < 1){
         c++;
         r--;
      }
   }
   if (a[r][c] == 0) {
      return;
   }
   v.pb({a[r][c], {pr, pc}});
   a[pr][pc] = a[r][c];
   a[r][c] = 0;
   int b = (pr == 2) ? 1 : 4;
   if (a[pr][pc] == a[b][pc]){
      cnt++;
      v.pb({a[pr][pc], {b, pc}});
      a[pr][pc] = 0;
   }
}
//-235 62 250
// -301 67 301

//-168 62 250
//-234 67 301



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   //read(FILENAME);
   cin >> n >> k;
   for (int i = 1; i <= 4; i++) {
      for (int j = 1; j <= n; j++) {
         cin >> a[i][j];
      }
   }
   for (int i = 2; i <= 3; i++) {
      int b = (i == 2) ? 1: 4;
      for (int j = 1; j <= n; j ++) {
         if (a[i][j] && a[i][j] == a[b][j]){
            v.pb({a[i][j], {b,j}});
            cnt++;
            a[i][j] = 0;
         }
         if (a[i][j] == 0) {
            r = i;
            c = j;
         }
      }
   }
   if (r == -1 && cnt != k) {
      cout << "-1\n";
      return 0;  
   }
   while (cnt != k) {
      cycle();
   }
   cout << sz(v) << '\n';
   for (auto x: v) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << '\n';
   }
   return 0;
}