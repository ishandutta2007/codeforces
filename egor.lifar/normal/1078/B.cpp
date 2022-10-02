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
#define mp make_pair
const int MAXN = 101;


int n;
int a[MAXN];
int dp[2][MAXN * MAXN][102];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	dp[0][0][0] = 1;
	int t = 0;
	vector<pair<int, int> > st;
	int allsum = 0;
	for (int i = 0; i < n; i++) {
		allsum += a[i];
		if (st.empty() || st.back().first != a[i]) {
			st.pb({a[i], 1});
		}  else {
			st.back().second++;
		}
	}
	for (int i = 0; i < sz(st); i++) {
		for (int mass = 0; mass <= 10000; mass++) {
			for (int cnt = 0; cnt <= 100; cnt++) {
				if (dp[t][mass][cnt]) {
					dp[t ^ 1][mass][cnt] += dp[t][mass][cnt];
					chkmin(dp[t ^ 1][mass][cnt], 2);
					int curmass = mass;
					int curcnt = cnt;
					for (int ts = 1; ts <= st[i].second; ts++) {
						curcnt++;
						curmass += st[i].first;
						dp[t ^ 1][curmass][curcnt] += dp[t][mass][cnt];
						chkmin(dp[t ^ 1][curmass][curcnt], 2);
					}
				}
			}
		}
		t ^= 1;
		//cout << dp[t][4][2] << endl;
		memset(dp[t ^ 1], 0, sizeof(dp[t ^ 1]));
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[j] != a[i]) {
				break;
			}
			int sum = (j - i + 1) * a[i];
			if (dp[t][sum][j - i + 1] == 1 || dp[t][allsum - sum][n - (j - i + 1)] == 1) {
				chkmax(res, j - i + 1);
				set<int> s;
				for (int k = 0; k < n; k++) {
					if (k < i || k > j) {
						s.insert(a[k]);
					}
				}
				if (sz(s) == 1) {
					chkmax(res, n);
				}
			}
		}
	}
	cout << res << '\n';
	return 0;
}