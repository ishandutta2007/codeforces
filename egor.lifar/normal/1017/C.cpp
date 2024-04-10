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


int n;
int dp[20], dp1[20];
int res[20];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	//3 4 1 2
	//1 6 
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if (n == 2) {
		cout << 2 << ' ' << 1 << '\n';
		return 0;
	}
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	a[i] = i + 1;
	// }
	// int kek = 1e9;
	// do {
	// 	int as = 0, bs = 0;
	// 	for (int i = 0; i < n; i++) {
	// 		dp[i] = 1;
	// 		dp1[i] = 1;
	// 		for (int j = 0; j < i; j++) {
	// 			if (a[i] > a[j]) {
	// 				chkmax(dp[i], dp[j] + 1);
	// 			} else {
	// 				chkmax(dp1[i], dp1[j] + 1);
	// 			}
	// 		}
	// 		chkmax(as, dp[i]);
	// 		chkmax(bs, dp1[i]);
	// 	}
	// 	chkmin(kek, as + bs);
	// 	if (as + bs == kek) {
	// 		for (int i = 0; i < n; i++) {
	// 			res[i] = a[i];
	// 			//cout << a[i] << ' ';
	// 		}
	// 		// /cout << '\n';
	// 	}
	// } while (next_permutation(a, a + n));
	// if (n & 1) {
	// 	int cur = n - 1;
	// 	while (cur >= 2) {
	// 		cout << cur << ' ' << cur + 1 << ' ';
	// 		cur -= 2;
	// 	}
	// 	cout << "1" << '\n';
	// } else {
	// 	int cur = n - 1;
	// 	while (cur > 2) {
	// 		cout << cur << ' ' << cur + 1 << ' ';
	// 		cur -= 2;
	// 	}
	// 	cout << "1 2" << '\n';
	// }
	int t = 1e9;
	for (int len = 1; len <= n; len++) {
		chkmin(t, len + (n + len - 1) / len);
	}
	for (int len = 1; len <= n; len++) {
		if (len + (n + len - 1) / len == t) {
			vector<vector<int> > g;
			for (int i = 1; i <= n; i += len) {
				int j = min(n, i + len - 1);
				vector<int> t;
				for (int s = i; s <= j; s++) {
					t.pb(s);
				}
				g.pb(t);
			}
			reverse(all(g));
			for (int i = 0; i < sz(g); i++) {
				for (auto x: g[i]) {
					cout << x << ' ';
				}
			}
			cout << '\n';
			exit(0);
		}
	}
	// cout << kek << '\n';
	// for (int i = 0; i < n; i++) {
	// 	cout << res[i] << ' ';
	// }
	// cout << '\n';
	return 0; 		
}