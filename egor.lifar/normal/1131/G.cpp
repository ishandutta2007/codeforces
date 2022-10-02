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
const int MAXN = 250001;
const int MAXM = 10000001;

int n, m;
int k[MAXN];
vector<int> a[MAXN], c[MAXN];
int h[MAXM];
long long cost[MAXM];
int left[MAXM];
int right[MAXM];
long long fen[MAXM];
long long dp[MAXM];


void dec(int i, long long val) {
	for (; i < m; i |= (i + 1)) {
		chkmin(fen[i], val);
	}
}


long long getmin(int i) {
	long long res = 1e18;
	for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
		chkmin(res, fen[j]);
	}
	return res;
}


void inc(int i, int val) {
	for (; i < m; i |= (i + 1)) {
		chkmax(fen[i], val);
	}
}


int getmax(int i) {
	int res = -1;
	for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
		chkmax(res, fen[j]);
	}
	return res;
}


// vector<int> death[MAXM];
// long long d[MAXM * 4];


// void change(int i, long long x) {
// 	d[i] = x;
// 	while (i >> 1 > 0) {
// 		i >>= 1;
// 		d[i] = min(d[i * 2], d[i * 2 + 1]);
// 	}
// }



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
  	cin >> n >> m;
  	for (int i = 0; i < n; i++) {
  		cin >> k[i];
  		a[i].resize(k[i]);
  		c[i].resize(k[i]);
  		for (auto &x: a[i]) {
  			cin >> x;
  		}
  		for (auto &x: c[i]) {
  			cin >> x;
  		}
  	}
  	int q;
  	cin >> q;
  	int uk = 0;
  	for (int i = 0; i < q; i++) {
  		int id, mul;
  		cin >> id >> mul;
  		id--;
  		for (int j = 0; j < k[id]; j++) {	
  			h[uk] = a[id][j];
  			cost[uk] = 1LL * c[id][j] * mul;
  			uk++;
  		}
  	}
  	assert(uk == m);
  	for (int i = 0; i < m; i++) {
  		fen[i] = 1e9;
  	}
  	for (int i = 0; i < m; i++) {
  		if (i < h[i]) {
  			left[i] = -1;
  		} else if (h[i] == 1) {
  			left[i] = i - 1;
  		} else {
  			left[i] = min(i - h[i], (int)getmin(m - (i - h[i] + 1) - 1));
  			chkmax(left[i], -1);
  		}
  		dec(m - i - 1, left[i]);
  	}
  	for (int i = 0; i < m; i++) {
  		fen[i] = -1;
  	}
  	for (int i = m - 1; i >= 0; i--) {
  		if (m - 1 - i < h[i]) {
  			right[i] = m;
  		} else if (h[i] == 1) {
  			right[i] = i + 1;
  		} else {
  			right[i] = max(i + h[i], getmax(i + h[i] - 1));
  			chkmin(right[i], m);
  		}
  		inc(i, right[i]);
  	}
  	for (int i = 0; i <= m; i++) {
  		dp[i] = 1e18;
  	}
  	int ss = 1;
  	while (ss < m) {
  		ss <<= 1;
  	}
  	// for (int i = 0; i < 2 * ss; i++) {
  	// 	d[i] = 1e18;
  	// }
  	dp[0] = 0;
  	for (int i = 0; i < m; i++) {
  		fen[i] = 1e18;
  	}
  	for (int i = 0; i < m; i++) {
  		// for (auto x: death[i]) {
  		// 	change(ss + x, 1e18);
  		// }
  		//chkmin(dp[i], d[1]);
  		dec(m - i - 1, dp[i]);
  		//cout << left[i] << ' ' << i << endl;
  		chkmin(dp[i + 1], cost[i] + (left[i] == -1 ? 0LL: getmin(m - left[i] - 2)));
  		chkmin(dp[i + 1], cost[i] + dp[i]);
  	//	death[right[i] + 1].pb(i);
  		chkmin(dp[right[i]], cost[i] + dp[i]);
  	//	change(ss + i, cost[i] + dp[i]);
  	}
  	cout << dp[m] << endl;
    return 0;
}