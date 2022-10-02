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



int n;
long long a[561], b[561];
long long dp[80][80][80];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] *= 1000;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long l = 0;
	long long r = 1000000000000LL;
	for (int it = 0; it < 80; it++) {
		long long mid = (l + r) / 2.0;
		//suma / sumb <= mid
		//suma <= mid * sumb;
		//suma - mi
		//a - mid * b
		vector<pair<long long, long long> > s;
		for (int i = 0; i < n; i++) {
			s.pb({a[i], -(a[i] - mid * b[i])});
		}
		sort(all(s));
		for (int i = n; i >= 0; i--) {
			for (int curbal = 0; curbal <= n; curbal++) {
				for (int t = 0; t <= n; t++) {
					dp[i][curbal][t] = -1e18;
				}
			}
		}
		dp[n][0][0] = 0;
		for (int i = n; i >= 1; i--) {
			for (int curbal = 0; curbal <= n; curbal++) {
				for (int t = 0; t <= n; t++) {
				//	cout << dp[i][curbal][t] << ' ' << i << endl;
					long long cost = s[i - 1].second;
					chkmax(dp[i - 1][curbal + 1][(i == n ? 1: (s[i - 1].first == s[i].first ? t + 1: 1))], cost + dp[i][curbal][t]);
					if (i != n) {
						if (s[i - 1].first == s[i].first) {
							if (curbal - t > 0) {
								chkmax(dp[i - 1][curbal - 1][t], dp[i][curbal][t]);
							} 
						} else {
							if (curbal) {
								chkmax(dp[i - 1][curbal - 1][0], dp[i][curbal][t]);
							}
						}
					}
				}
			}
		}
		bool good = false;
		for (int i = 0; i <= n; i++) {
			for (int t = 0; t <= n; t++) {
				if (dp[0][i][t] >= 0) {
					good = true;
				}
			}
		}
		if (good) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
	return 0;
}