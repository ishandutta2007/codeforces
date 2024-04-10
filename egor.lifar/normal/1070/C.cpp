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
const string FILENAME = "input";
const int MAXN = 1000228;    


int n;
long long k;
int m;
int c[MAXN], p[MAXN];
vector<pair<int, int> > g[MAXN];
long long cnts[MAXN * 4];
long long sum[MAXN * 4];
int ss = 1;


void change(int i, long long cnt) {
    int tt = i - ss;
    while (i) {
        cnts[i] += cnt;
        sum[i] += 1LL * cnt * (tt);
        i >>= 1;        
    }
}


long long getcnt(int l, int r) {
    if (l > r) {
        return 0;
    }
    l += ss;
    r += ss;
    long long ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += cnts[l];
            l++;
        }
        if (!(r & 1)) {
            ans += cnts[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
} 


long long getsum(int l, int r) {
    if (l > r) {
        return 0;
    }
    l += ss;
    r += ss;
    long long ans = 0;
    while (l <= r) {
        if (l & 1) {
            ans += sum[l];
            l++;
        }
        if (!(r & 1)) {
            ans += sum[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
} 



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    //read(FILENAME);
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cin >> c[i] >> p[i];
        g[l].pb({i, 1});
        g[r + 1].pb({i, -1});
    }
    while (ss <= 1000001) {
        ss <<= 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto x: g[i]) {
            if (x.second == 1) {
                change(ss + p[x.first], c[x.first]);
            } else {
                change(ss + p[x.first], -c[x.first]);
            }
        }
        long long f = getcnt(0, 1000000);
       // cout << f << endl;
        if (f <= k) {
            ans += getsum(0, 1000000);
           // cout << ans << endl;
        } else {
            int l = 0;
            int r = 1000000;
            while (l != r) {
                int mid = (l + r) >> 1;
                if (getcnt(0, mid) < k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            //cout << l << endl;
            int cntp = k - getcnt(0, l - 1);
          //  cout << cntp << endl;
          //  cout << getsum(0, l - 1) << endl;
            ans += getsum(0, l - 1);
          //  cout << l << endl;
            ans += 1LL * cntp * l;
           // cout << ans << endl;
        }
      //  cout << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}