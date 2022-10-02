/*
 
















 
*/
 //#pragma GCC optimize("Ofast")
 #pragma GCC optimize("O3")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
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
#include <array>

		
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
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define len(c) sz(c)
// const int ML_ = 250;
// char mem_[ML_ * 1024 * 1024];
// size_t _ptr = 0, _magic = 21323400;
// void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { ;  _ptr = cnt + _magic; return mem_ + _magic; } }
// void operator delete(void *) {}
using ll = long long;
const string FILENAME = "input";
const int MAXN = 500003;
const int Mod = 1000000007;


inline int sum(const int a, const int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}

inline void sums(int &a, const int b) {
	a += b;
	if (a >= Mod) {
		a -= Mod;
	}
}

inline int mul(const int a, const int b) {
	return ((ll)a * b) % Mod;
}


inline void muls(int &a, const int b) {
	a = ((ll)a * b) % Mod;
}


inline int powm(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			muls(res, a);
		}
		b >>= 1;
		muls(a, a);
	}
	return res;
}



int n, m;
vector<int> st;
int parent[MAXN];
bool ok[MAXN];


int findset(int a) {
	if (a == parent[a]) {
		return a;
	}
	return parent[a] = findset(parent[a]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		parent[i] = i;
		ok[i] = false;
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vector<int> cur;
		for (int it = 0; it < k; it++) {
			int x;
			cin >> x;
			x--;
			cur.pb(x);
		}
		if (sz(cur) == 1) {
			int a = findset(cur[0]);
			if (!ok[a]) {
				ok[a] = true;
				st.pb(i + 1);
			}
		} else {
			int a = findset(cur[0]);
			int b = findset(cur[1]);
			if (a == b) {
				continue;
			}
			if (ok[a] && ok[b]) {
				parent[a] = b;
				continue;
			}
			st.pb(i + 1);
			parent[a] = b;
			ok[b] |= ok[a];
		}
	}
	cout << powm(2, sz(st)) << ' ' << sz(st) << '\n';
	sort(all(st));
	for (auto x: st) {
		cout << x << ' ';
	}
	cout << '\n';
}