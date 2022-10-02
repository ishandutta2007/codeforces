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
const int MAXN = 500228;


int n;
string s;
int c[MAXN];
int p[MAXN];
int cn[MAXN];
int where[MAXN];
int who[MAXN];
vector<int> g;
vector<int> x[MAXN];
int lcp[MAXN];
int sparse[MAXN][20];
int step[MAXN];
int dp[MAXN];


int getmin(int l, int r) {
    if (l > r) {
        return n - who[l];
    }
    int t = step[r - l + 1];
    return min(sparse[l][t], sparse[r - (1 << t) + 1][t]);
}


int uk; 
int t[MAXN * 4];
int ss = 1;


void change(int i, int val) {
    while (i) {
        chkmax(t[i], val);
        i >>= 1;
    }
}


int rmq(int l, int r) {
    l += ss;
    r += ss;
    int ans = 0;
    while (l <= r) {
        if (l & 1) {
            chkmax(ans, t[l]);
            l++;
        }
        if (!(r & 1)) {
            chkmax(ans, t[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}
                                           
bool check(int i, int len) {
    if (len == 1) {
        return true;
    }
    while (uk >= i + len) {
        change(ss + where[uk], dp[uk]);
        uk--;
    }
    int j = where[i];
    int l = 0;
    int r = j;
    while (l != r) {
        int mid = (l + r) >> 1;
       // cout << l << ' ' << r << endl;
        if (getmin(mid, j - 1) < len - 1) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int gl = l;
    l = j;
    r = n - 1;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
       // cout << l << ' ' << r << endl;
        if (getmin(j, mid - 1) < len - 1) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    int gr = l;
   // cout << gl << ' ' << gr << ' ' << where[i] << '\n'; 
    //gl gr
    return rmq(gl, gr) >= len - 1;
}


bool check1(int i, int len) {
    if (len == 1) {
        return true;
    }
    while (uk >= i + len) {
        change(ss + where[uk], dp[uk]);
        uk--;
    }
    int j = where[i + 1];
    int l = 0;
    int r = j;
    while (l != r) {
        int mid = (l + r) >> 1;
       // cout << l << ' ' << r << endl;
        if (getmin(mid, j - 1) < len - 1) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int gl = l;
    l = j;
    r = n - 1;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
       // cout << l << ' ' << r << endl;
        if (getmin(j, mid - 1) < len - 1) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    int gr = l;
  ///  cout << gl << ' ' << gr << ' ' << where[i] << '\n'; 
    //gl gr
    return rmq(gl, gr) >= len - 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
   // read(FILENAME);
    cin >> n;
    cin >> s;
    s += 'z' + 1;
    n++;
    vector<pair<char, int> > v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(s[i], i));
    }
    sort(v.begin(), v.end());
    int classes = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            classes++;
        }
        c[v[i].second] = classes - 1;
        p[i] = v[i].second;
    }
    for (int h = 0; (1 << h) < n; h++) {
        int k = (1 << h);
        vector<pair<pair<int, int>, int> > v1;
        for (int i = 0; i <= classes; i++) {
            x[i].clear();
        }
        for (int i = 0; i < n; i++) {
            x[c[(p[i] + k) % n]].push_back(p[i]);
        }
        vector<int> pn;
        for (int i = 0; i < classes; i++) {
            for (int j = 0; j < sz(x[i]); j++) {
                pn.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] = pn[i];
        }
        for (int i = 0; i <= classes; i++) {
            x[i].clear();
        }
        for (int i = 0; i < n; i++) {
            x[c[p[i]]].push_back(p[i]);
        }
        pn.clear();
        for (int i = 0; i < classes; i++) {
            for (int j = 0; j < sz(x[i]); j++) {
                pn.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] = pn[i];
        }
        vector<int> cn;
        classes = 0;
        cn.resize(n);
        for (int i = 0; i < n; i++) { 
            if (i == 0 || (c[p[i]] != c[p[i - 1]] || (c[(p[i] + k) % n] != c[(p[i - 1] + k) % n]))) {
                classes++;
            } 
            cn[p[i]] = classes - 1;
        }   
        for (int i = 0; i < n; i++) {
            c[i] = cn[i];
        }
    }
    for (int i = 0; i < n; i++) {
        where[p[i]] = i;
        who[i] = p[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = max(0, x - 1);
        if (where[i] != n - 1) {
            int j = who[where[i] + 1];
            for (int g = i + x; g < n; g++) {
                if ((g - i + 1 > n - j)) {
                    break;
                }
                if (s[g] != s[j + (g -  i)]) {
                    break;
                }
                x++;
            }
            lcp[where[i]] = x;
        }
    } 
    for (int i = 0; i < n; i++) {
        sparse[i][0] = lcp[i];
    }
    int curst = 0;
    int curp = 1;
    for (int i = 1; i <= n; i++) {
        if (curp + curp <= i) {
            curp <<= 1;
            curst++;
        }
        step[i] = curst;
    }
    for (int k = 1; k <= 19; k++) {
        for (int i = 0; i < n; i++) {
            sparse[i][k] = min(sparse[i][k - 1], sparse[min(n - 1, i + (1 << (k - 1)))][k - 1]);
        }
    }
    n--;
    while (ss <= n) {
        ss <<= 1;
    }
    int lastp = 0;
    int ans = 0;
    uk = n - 1;
   // return 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = lastp + 1;
        while (!check(i, dp[i]) && !check1(i, dp[i])) {
            dp[i]--;
        }
        lastp = dp[i];
        chkmax(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}