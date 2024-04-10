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
const int MAXN = 300001;


int n;
int a[MAXN], b[MAXN];
long long prefa[MAXN], prefb[MAXN];
long long costa[MAXN];
long long costb[MAXN];
long long suffa[MAXN];
long long suffb[MAXN];


long long geta(int l, int r) {
	return prefa[r] - (l ? prefa[l - 1]: 0);
}


long long getb(int l, int r) {
	return prefb[r] - (l ? prefb[l - 1]: 0);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1LL * i * a[i];
		ans += 1LL * (n + n - i - 1) * b[i];
	}
	for (int i = 0; i < n; i++) {
		prefa[i] = a[i];
		prefb[i] = b[i];
	}
	for (int i = 1; i < n; i++) {
		prefa[i] += prefa[i - 1];
		prefb[i] += prefb[i - 1];
	}
	costa[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		costa[i] = costa[i + 1] + geta(i + 1, n - 1);
	}
	costb[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		costb[i] = costb[i + 1] + getb(i + 1, n - 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		suffa[i] = 1LL * (n - i - 1) * a[i];
		if (i != n - 1) {
			suffa[i] += suffa[i + 1];
		}
		suffb[i] = 1LL * (n - i - 1) * b[i];
		if (i != n - 1) {
			suffb[i] += suffb[i + 1];
		}
	}
	long long cur = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			cur += 1LL * (2 * i + 1) * a[i];
			cur += 1LL * (2 * i) * b[i];
		} else {
			cur += 1LL * (2 * i) * a[i];
			cur += 1LL * (2 * i + 1) * b[i];
		}
		if (i == n - 1) {
			//cout << cur << endl;
			chkmax(ans, cur);
			break;
		}
		if (i & 1) {
			long long res = cur;
			res += costa[i + 1] + 1LL * (2 * (i + 1)) * geta(i + 1, n - 1); 
			res += suffb[i + 1] + 1LL * (n + i + 1) * getb(i + 1, n - 1); 
			chkmax(ans, res);
		} else {
			long long res = cur;
			//cout << res << endl;
			res += costb[i + 1] + 1LL * (2 * (i + 1)) * getb(i + 1, n - 1); 
			//cout << res << ' ' << costb[i + 1] << endl;
			res += suffa[i + 1] + 1LL * (n + i + 1) * geta(i + 1, n - 1); 
			chkmax(ans, res);
		}
	}
	cout << ans << '\n';
	return 0; 		
}