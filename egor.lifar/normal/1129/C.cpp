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
#define rank rank228
#define y1 y1228                                                         
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
const string FILENAME = "input";
const int MAXN = 3001;
const int Mod = 1000000007;


int m;
string s;
int nxt[MAXN * MAXN][2];
int uk = 0;
int dp[MAXN][MAXN];
int cur[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   	//read(FILENAME);
    cin >> m;
    string s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
    	int t;
    	cin >> t;
    	s += char('0' + t);
    	for (int j = 0; j <= i; j++) {
    		bool tt = false;
    		if (nxt[cur[j]][t]) {
    			cur[j] = nxt[cur[j]][t];
    		} else {
    			uk++;
    			nxt[cur[j]][t] = uk;
    			cur[j] = uk;
    			tt = true;
    		}
    		if (j == i) {
    			dp[j][i] = 1;
    		} else {
    				dp[j][i] += dp[j][i - 1];
    				dp[j][i] %= Mod;
    			if (i - 1 == j) {
    				dp[j][i]++;
    				dp[j][i] %= Mod;
    			} else {
    				if (i - 1 > j) {
    					dp[j][i] += dp[j][i - 2];
    					dp[j][i] %= Mod;
    				}
    			}
    			if (i - 2 == j) {
    				dp[j][i]++;
    				dp[j][i] %= Mod;
    			} else {
    				if (i - 2 > j) {
    					dp[j][i] += dp[j][i - 3];
    					dp[j][i] %= Mod;
    				}
    			}
    		}
    		if (i >= 3) {
    			string ff;
    			ff += s[i - 3];
    			ff += s[i - 2];
    			ff += s[i - 1];
    			ff += s[i];
    		//	cout << ff << endl;
    			if (ff != "0011" && ff != "0101" && ff != "1110" && ff != "1111") {
    				dp[j][i] += (i - 3 == j ? 1: (i - 3 > j ? dp[j][i - 4]: 0));
    				dp[j][i] %= Mod;
    			}
    		}
    		//cout << dp[j][i] << ' ' << j << ' ' << tt << endl;
    		//110
    		if (tt) {
    			ans += dp[j][i];
    			ans %= Mod;
    		}
    	}
    	cout << ans << '\n';;
    }
    return 0;
}