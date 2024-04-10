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
//WULD! NAH! KEST!
const int MAXN = 100228;
const double Pi = acos(-1);


int n;
long double xx, yy;
long double v, t, rr;
long double x[MAXN], y[MAXN], r[MAXN];
long double l, ans;
vector<pair<long double, long double> > p;


int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
	l = -Pi;
	cin >> xx >> yy >> v >> t >> n;
	rr = v * t;
	for (int i = 0; i < n; i++) {
		int as, bs, cs;
		cin >> as >> bs >> cs;
		x[i] = as;
		y[i] = bs;
		r[i] = cs;
		x[i] -= xx;
		y[i] -= yy;
		if (sqrt(x[i] * x[i] + y[i] * y[i]) <= r[i]) {
			cout << 1 << '\n';
			return 0;
		}
		long double L, R, a;
		long double dd = sqrt(x[i] * x[i] + y[i] * y[i]);
		if (dd >= r[i] + rr) {
			continue;
		}
		L = atan2(y[i], x[i]);
		a = sqrt(x[i] * x[i] + y[i] * y[i] - r[i] * r[i]);
		if (a <= rr) {
			R = asin(r[i] / dd);
		} else  {
			R = acos((dd * dd + rr * rr - r[i] * r[i]) / (2 * dd * rr));
		}
		L -= R;
		R = L + R * 2;
		if (L < -Pi) {
			p.push_back({L + 2 * Pi, Pi});
			L = -Pi;
		}
		if (R > Pi) {
			p.push_back({-Pi, R - 2 * Pi});
			R = Pi;
		}
		p.push_back({L, R});
	}
	sort(all(p));
	for (auto x: p) {
		if (l < x.first) {
			l = x.first;
		}
		if (x.second <= l) {
			continue;
		}
		ans += x.second - l;
		l = x.second;
	}
	cout.precision(18);
	cout << fixed << (double)ans / (2 * Pi) << endl;
	return 0;
}