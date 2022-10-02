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
const int MAXN = 100001;


int n;
int l[105], r[105], dist[105];
int k;
int dp[105][MAXN][2];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //read(FILENAME);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> l[i] >> r[i];
        dist[i - 1] = l[i] - r[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i][1] = dp[0][i][0] = 1e9;
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= k; i++) {
        deque<int> st, st1;
        int uk = dist[i - 1], uk1 = r[i] - l[i];
        for(int j = 0;j <= n;j++){
            while (!st.empty() && st.front() < j - uk1) {
                st.pop_front();
            }
            while (!st.empty() && dp[i - 1][st.back()][1] >= dp[i - 1][j][1]) {
                st.pop_back();
            }
            st.push_back(j);
            dp[i][j][0] = dp[i - 1][st.front()][1] + 1;
            dp[i][j][1] = dp[i - 1][st.front()][1] + 2;
            if (j - uk - uk1 >= 0) {
                chkmin(dp[i][j][0], dp[i - 1][j - uk - uk1][0]);
            }
            chkmin(dp[i][j][1], dp[i - 1][j][1]);
            if (j < uk) {
                continue;
            }
            while (!st1.empty() && st1.front() < j - uk - uk1) {
                st1.pop_front();
            }
            while (!st1.empty() && dp[i - 1][st1.back()][0] >= dp[i - 1][j - uk][0]) {
                st1.pop_back();
            }
            st1.push_back(j - uk);
            chkmin(dp[i][j][0], dp[i - 1][st1.front()][0] + 2);
            chkmin(dp[i][j][1], dp[i - 1][st1.front()][0] + 1);
        }
    }
    dist[k] = 2 * n - r[k];
    int ans = dp[k][n][1];
    if (dist[k] <= n) {
        chkmin(ans, dp[k][n - dist[k]][0]);
    }
    if (ans == (int)1e9) {
        cout << "Hungry\n";
        return 0;
    }
    cout << "Full\n";
    cout << ans << '\n';
    return 0;
}