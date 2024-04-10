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
#define x first
#define y second
const string FILENAME = "input";
const int MAXN = 300228;


int n;
long long a[MAXN];
int pr[MAXN];
int sums[MAXN][2];


int getcnt(int l, int r, int t) {
    if (l > r) {
        return false;
    }
    return sums[r][t] - (l == 0 ? 0: sums[l - 1][t]);
}

int l[MAXN], r[MAXN];




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);   
    cin >> n;
    int sum = 0;
    int cnt[2];
    cnt[0] = 1;
    cnt[1] = 0;
    long long ans = 0;
    sums[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = __builtin_popcountll(a[i]);
        //cout << a[i] << endl;
        sum += a[i];
        sum &= 1;
        pr[i] = sum;
        sums[i + 1][0] = (pr[i] == 0);
        sums[i + 1][1] = (pr[i] == 1);
        sums[i + 1][0] += sums[i][0];
        sums[i + 1][1] += sums[i][1];
    }
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        l[i] = (st.empty() ? 0: st.back() + 1);
        st.pb(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
         while (!st.empty() && a[st.back()] < a[i]) {
            st.pop_back();
        }
        r[i] = (st.empty() ? n - 1: st.back() - 1);
        st.pb(i);
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int cur = 0;
        for (int j = i; j <= r[i]; j++) {
            if (j != i) {
                sum += a[j];
            }
            cur += a[j];
            cur &= 1;
            int sum1 = sum;
            int cur1 = cur;
            for (int f = i; f >= max(l[i], i - 100); f--) {
                if (f != i) {
                    sum1 += a[f];
                    cur1 += a[f];
                    cur1 &= 1;
                }
                if (sum1 >= a[i] && cur1 == 0) {
                    ans++;
                    //cout << f << ' ' << j << endl;
                }
            }
            ans += getcnt(l[i], max(l[i], i - 100) - 1, pr[j]);
        }
    }
    cout << ans << endl;
    return 0;
}