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


long long mcnt[MAXN / 2][343];



long long getcnt(int i, int j) {
    if (i == 0) {
        return 0;
    }
    if (j == 1) {
        return 1LL * i * (i + 1) / 2;
    }
    if (j >= i - 1) {
        return i + i - 1;
    }
  //  cout << i << ' ' << j << endl;
    int k = (i - 1) / j + ((i - 1) % j != 0);
    if (k - 1 <= j) {
        int a = (i - 1) / j;
        int cnt = j - (i - 1) % j;
        int b = (i - 1) / j + 1;
        int cnt1 = (i - 1) % j;
        return i + (i - 1) - j + 1LL * cnt * a + 1LL * cnt1 * b;
    } else {
        int a = (i - 1) / j;
        int cnt = j - (i - 1) % j;
        int b = (i - 1) / j + 1;
        int cnt1 = (i - 1) % j;
        return i + 1LL * cnt * mcnt[a][j] + 1LL * cnt1 * mcnt[b][j];
    }
}


int res;


long long getrespekt(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b >= a) {
        return a;
    }
    int c = a / b;
    int cnt = b - a % b;
    int c1 = a / b + 1;
    int cnt1 = a % b;
    return getcnt(c, res) * cnt + getcnt(c1, res) * cnt1;
}   

int uk = 2;
int p[MAXN];



void build(int i, int need, long long cur) {
    cur -= need;
    need--;
    if (need == 0) {
        return;
    }
    int fs = 0;
    while (need) {
        fs++;
       // cout << fs << ' ' << i << ' ' << cur << ' ' << need << endl;
        int kek = 1;
        if (fs == res) {
            kek = need; 
        } else {
            while (cur - getcnt(kek, res) < getrespekt(need - kek, res - fs)) {
                kek++;
            }
            int l = kek;
            int r = need;
             while (l != r) {
                int mid = (l + r + 1) >> 1;
                if (getcnt(mid, res)  > cur || cur - getcnt(mid, res) < getrespekt(need - mid, res - fs)) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            kek = l;
        }
       // cout << kek << ' ' << cur << endl;
        need -= kek;
        int a = uk;
        p[a] = i;
        uk++;
        long long s = min(cur, 1LL * kek * (kek + 1) / 2);
        chkmin(s, cur - getrespekt(need, res - fs));
       // cout << s << endl;
        cur -= s;
        build(a, kek, s);
       // cout << cur << ' ' << need << ' ' << i << endl;
        if (cur == 0) {
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    long long n;
    cin >> n;
    long long s;
    cin >> s;
    if (s > n * (n + 1) / 2) {
        cout << "No\n";
        return 0;
    }
    if (s < n + (n - 1)) {
        cout << "No\n";
        return 0;
    }
    //cout << s << endl;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int t = 1; t <= min(i - 1, 338); t++) {
            int a = (i - 1) / t;
            int cnt = t - (i - 1) % t;
            int b = (i - 1) / t + 1;
            int cnt1 = (i - 1) % t;
            mcnt[i][t] = i + getcnt(a, t) * cnt + getcnt(b, t) * cnt1;
        }
    }
    res = -1;
    for (int t = 1; t <= n - 1; t++) {
        if (getcnt(n, t) <= s) {
            res = t;
            break;
        }
    }
   // cout << res << endl;
    build(1, n, s);
    cout << "Yes\n";
    for (int i = 2; i <= n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
    return 0; 
}