/*
 












 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
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
const int MAXN = 2002;


int n;
int a[MAXN], b[MAXN];
int dp[2][10][10][10][10][10];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i]; 
	}
	int gs = 0;
	int res = 1e9;
	vector<pair<int, pair<pair<int, int>, pair<int, int> > > > s;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int g = 0; g <= 9; g++) {
					int cnt = (i != 0) + (j != 0) + (k != 0) + (g != 0);
					s.pb({cnt, {{i, j}, {k, g}}});
				}
			}
		}
	}
	sort(all(s));
	reverse(all(s));
	for (int cur = 1; cur <= 9; cur++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int g = 0; g <= 9; g++) {
					for (int h = 0; h <= 9; h++) {
						dp[1][cur][j][k][g][h] = 1e9;
						dp[0][cur][j][k][g][h] = 1e9;
					}
				}
			}
		}
	}
	dp[0][1][0][0][0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (auto x: s) {
			for (int cur = 1; cur <= 9; cur++) {
				int j = x.second.first.first;
				int k = x.second.first.second;
				int g = x.second.second.first;
				int h = x.second.second.second;
				if (j == 0 && k == 0 && g == 0 && h == 0 && i == n) {
					chkmin(res, dp[gs][cur][j][k][g][h]);
				}	
			}
			for (int cur = 1; cur <= 8; cur++) {
				int j = x.second.first.first;
				int k = x.second.first.second;
				int g = x.second.second.first;
				int h = x.second.second.second;	
				chkmin(dp[gs][cur + 1][j][k][g][h], dp[gs][cur][j][k][g][h] + 1);
			}
			for (int cur = 9; cur >= 2; cur--) {
				int j = x.second.first.first;
				int k = x.second.first.second;
				int g = x.second.second.first;
				int h = x.second.second.second;	
				chkmin(dp[gs][cur - 1][j][k][g][h], dp[gs][cur][j][k][g][h] + 1);
			}
			for (int cur = 1; cur <= 9; cur++) {
				int j = x.second.first.first;
				int k = x.second.first.second;
				int g = x.second.second.first;
				int h = x.second.second.second;
				if (dp[gs][cur][j][k][g][h] == 1000000000) continue;
				int cnt = (h != 0) + (j != 0) + (k != 0) + (g != 0);
				//cout << x.second << ' ' << i << ' ' << cnt << endl;
				//for (int next = 1; next <= 9; next++) {
					if (cur == a[i]) {
						if (cnt < 4) {
							int j1 =j;
							int k1 = k;
							int g1 = g;
							int h1 = h;
							if (j1 == 0) {
								j1 = b[i];
							} else if (k1 == 0) {
								k1 = b[i];
							} else if (h1 == 0) {
								h1 = b[i];
							} else if (g1 == 0) {
								g1 = b[i];
							}
							chkmin(dp[gs ^ 1][cur][j1][k1][g1][h1], dp[gs][cur][j][k][g][h] );
						}
					}
					//	cout << "opa" << endl;
					int j1 = j;
					int k1 = k;
					int g1 = g;
					int h1 = h;
					if (j1 == cur) {
						j1 = 0;
					}
					if (k1 == cur) {
						k1 = 0;
					} 
					if (h1 == cur) {
						h1 = 0;
					} 
					if (g1 == cur) {
						g1 = 0;
					}
					int cnt1 = (h1 != 0) + (j1 != 0) + (k1 != 0) + (g1 != 0);
					//.//cout << sz(f) << endl;
					chkmin(dp[gs][cur][j1][k1][g1][h1], dp[gs][cur][j][k][g][h] );
					//cout << dp[g][cur][sz(f)][f] << endl;
					if (cur == a[i]) {
						if (cnt1 < 4) {
							if (j1 == 0) {
								j1 = b[i];
							} else if (k1 == 0) {
								k1 = b[i];
							} else if (h1 == 0) {
								h1 = b[i];
							} else if (g1 == 0) {
								g1 = b[i];
							}
							chkmin(dp[gs ^ 1][cur][j1][k1][g1][h1], dp[gs][cur][j][k][g][h] );
						}
					}
			//	}
			}
		}
		gs ^= 1;
		for (int cur = 1; cur <= 9; cur++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					for (int g = 0; g <= 9; g++) {
						for (int h = 0; h <= 9; h++) {
							dp[gs ^ 1][cur][j][k][g][h] = 1e9;
						}
					}
				}
			}
		}
	} 
	cout << res + 2 * n << endl;
	return 0;
}