
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
const int MAXN = 200001;


int n, L;
int a[MAXN];
int b[MAXN];
int add[MAXN];


bool can(int dist) {
	for (int i = 0; i < n; i++) {
		add[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		vector<pair<int, int> > segs;
		int l = b[i] - dist;
		int r = b[i] + dist;
		if (r - l + 1 >= L) {
			segs.pb({0, L - 1});
		} else {
			if (r >= L) {
				segs.pb({0, r - L});
				r = L - 1;
			}
			if (l < 0) {
				segs.pb({L + l, L - 1});
				l = 0;
			}
			segs.pb({l, r});
		}
		for (auto x: segs) {
			//cout << x.first << ' ' << x.second << endl;
			int ll = lower_bound(a, a + n, x.first) - a;
			int rr = upper_bound(a, a + n, x.second) - a;
			rr--;
			//cout << ll << ' ' << rr << endl;
			if (ll > rr) continue;
			int fl = ll - i;
			int fr = rr - i;
			if (fl < 0) {
				fl += n;
				fr += n;
			}
			if (fr < 0) {
				fr += n;
			}
			if (fl >= n && fr >= n) {
				fl -= n;
				fr -= n;
			}
			//cout << fl << ' ' << fr << endl;
			if (fl < n && fr < n) {
				add[fl]++;
				add[fr + 1]--;
			} else {
				add[fl]++;
				add[0]++;
				add[fr - n + 1]--;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += add[i];
		if (sum == n) {
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b, b + n);
	int l = 0;
	int r = L;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (can(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}