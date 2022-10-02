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
const int MAXN = 200228;
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b) % Mod;
}


int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}


int n, q;
int ss = 1;
int d[MAXN * 4];
int moda[MAXN * 4];
int modb[MAXN * 4];


void push(int v, int len) {
	if (moda[v] != 1 || modb[v] != 0) {
		d[v] = mul(d[v], moda[v]);
		d[v] = sum(d[v], mul(modb[v], len));
		if (v < ss) {
			moda[v * 2] = mul(moda[v * 2], moda[v]);
			modb[v * 2] = sum(mul(modb[v * 2], moda[v]), modb[v]);
			moda[v * 2 + 1] = mul(moda[v * 2 + 1], moda[v]);
			modb[v * 2 + 1] = sum(mul(modb[v * 2 + 1], moda[v]), modb[v]);
		}
		moda[v] = 1;
		modb[v] = 0;
	}
} 



void add(int v, int vl, int vr, int l, int r, int t) {
	if (vl > r || vr < l) {
		push(v, vr - vl + 1);
		return;
	}
	if (l <= vl && vr <= r) {
		if (t == 1) {
			modb[v] = sum(modb[v], 1);
		} else {
			moda[v] = mul(moda[v], 2);
			modb[v] = mul(modb[v], 2);
		}
		push(v, vr - vl + 1);
		return;
	}
	push(v, vr - vl + 1);
	add(v * 2, vl, (vl + vr) / 2, l, r, t);
	add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, t);
	d[v] = sum(d[v * 2], d[v * 2 + 1]);
}


int rmq(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		push(v, vr - vl + 1);
		return d[v];
	}
	push(v, vr - vl + 1);
	return sum(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}

set<pair<int, int> > g[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> q;
	ss = 1;
	while (ss < n) {
		ss <<= 1;
	}
	for (int i = 0; i < 2 * ss; i++) {
		moda[i] = 1;
	}
	for (int its = 0; its < q; its++) {
		int type;
		cin >> type;
		//cout << "opa" << endl;
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << rmq(1, 1, ss, l, r) << '\n';
			continue;
		}
		int l, r, x;
		cin >> l >> r >> x;
		int ps = l;
		vector<pair<int, int> > dels;
		auto start = g[x].lower_bound({l, l});
		if (start != g[x].begin()) {
			start--;
		}
		int ts = l;
		for (auto it = start; it != g[x].end(); it++) {
			pair<int, int> p = *it;
			if (p.first > r) {
				break;
			}
			if (p.second < l) {
				continue;
			}
			if (p.first < l) {
				ts = p.first;
			}
			add(1, 1, ss, max(p.first, l), min(p.second, r), 2);
			if (ps < p.first) {
				add(1, 1, ss, ps, p.first - 1, 1);
			}
			ps = p.second + 1;
			dels.pb(p);
		}
		if (ps <= r) {
			add(1, 1, ss, ps, r, 1);
			ps = r;
		} else {
			ps--;
		}
		chkmax(ps, r);
		for (auto xx: dels) {
			g[x].erase(xx);
		}
		//cout << ts << ' ' << ps << ' ' << x << endl;
		g[x].insert({ts, ps});
	}
	return 0;
}