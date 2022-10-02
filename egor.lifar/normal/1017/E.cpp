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
const int MAXN = 400228;
const int P = 179;


struct point
{	
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};


point operator -(const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}


int n, m;
point a[MAXN], b[MAXN];
point as, bs;


long long dist(point e) {
	return 1LL * e.x * e.x + 1LL * e.y * e.y;
}


long long vec(point c, point d) {
	return 1LL * c.x * d.y - 1LL * c.y * d.x;
}

long long scal(point c, point d) {
	return 1LL * c.x * d.x + 1LL * c.y * d.y;
}


bool comp(point c, point d) {
	c = c - as;
	d = d - as;
	long long s = vec(c, d);
	if (s == 0) {
		return dist(c) < dist(d);
	}
	return s > 0;
}


bool comp1(point c, point d) {
	c = c - bs;
	d = d - bs;
	long long s = vec(c, d);
	if (s == 0) {
		return dist(c) < dist(d);
	}
	return s > 0;
}


unsigned long long hs[MAXN], hs1[MAXN], stp[MAXN];


unsigned long long get(int l, int r) {
	return hs[r] - (l == 0 ? 0ULL: hs[l - 1] * stp[r - l + 1]);
}


unsigned long long get1(int l, int r) {
	return hs1[r] - (l == 0 ? 0ULL: hs1[l - 1] * stp[r - l + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
	}
	as = a[0];
	bs = b[0];
	for (int i = 1; i < n; i++) {
		if (as.y > a[i].y || (as.y == a[i].y && as.x > a[i].x)) {
			as = a[i];
		}
	}
	for (int i = 1; i < m; i++) {
		if (bs.y > b[i].y || (bs.y == b[i].y && bs.x > b[i].x)) {
			bs = b[i];
		}
	}
	sort(a, a + n, comp);
	sort(b, b + m, comp1);
	vector<int> st;
	for (int i = 0; i < n; i++) {
		//cout << a[i].x << ' '  << a[i].y << endl;
		if (sz(st) < 2) {
			st.pb(i);
		} else {
			while (sz(st) >= 2 && vec(a[st[sz(st) - 1]] - a[st[sz(st) - 2]], a[i] - a[st[sz(st) - 2]]) <= 0) {
				st.pop_back();
			}
			st.pb(i);
		}
	}
	while (sz(st) > 2 && vec(a[st[sz(st) - 1]] - a[st[sz(st) - 2]], a[0] - a[st[sz(st) - 2]]) <= 0) {
		st.pop_back(); 
	}
	vector<int> st1;
	for (int i = 0; i < m; i++) {
		//cout << b[i].x << ' '  << b[i].y << endl;
		if (sz(st1) < 2) {
			st1.pb(i);
		} else {
			while (sz(st1) >= 2 && vec(b[st1[sz(st1) - 1]] - b[st1[sz(st1) - 2]], b[i] - b[st1[sz(st1) - 2]])<= 0) {
				st1.pop_back();
			}
			st1.pb(i);
		}
	}
	while (sz(st1) > 2 && vec(b[st1[sz(st1) - 1]] - b[st1[sz(st1) - 2]], b[0] - b[st1[sz(st1) - 2]]) <= 0) {
		st1.pop_back();
	}
	// 	for (auto x: st) {
	// 	cout << a[x].x << ' ' << a[x].y << '\n';
	// }
	//cout << sz(st) << ' ' << sz(st1) << endl;
	if (sz(st) != sz(st1)) {
		cout << "NO\n";
		exit(0);
	}
	vector<unsigned long long> h, h1;
	for (int i = 0; i < sz(st); i++) {
		long long f = dist(a[st[(i + 1) % sz(st)]] - a[st[i]]);
		h.pb(f);
		f = vec(a[st[(i + 1) % sz(st)]] - a[st[i]], a[st[(i - 1 + sz(st)) % sz(st)]] - a[st[i]]);
		h.pb(f);
		// f = scal(a[st[(i + 1) % sz(st)]] - a[st[i]], a[st[(i - 1 + sz(st)) % sz(st)]] - a[st[i]]);
		// h.pb(f);
	}

	for (int i = 0; i < sz(st1); i++) {
		long long f = dist(b[st1[(i + 1) % sz(st1)]] - b[st1[i]]);
		h1.pb(f);
		f = vec(b[st1[(i + 1) % sz(st1)]] - b[st1[i]], b[st1[(i - 1 + sz(st1)) % sz(st1)]] - b[st1[i]]);
		h1.pb(f);
		// f = scal(b[st1[(i + 1) % sz(st1)]] - b[st1[i]], b[st1[(i - 1 + sz(st1)) % sz(st1)]] - b[st1[i]]);
		// h1.pb(f);
	}
	hs[0] = h[0];
	for (int i = 1; i < sz(h); i++) {
		hs[i] = hs[i - 1] * P + h[i];
	}
	hs1[0] = h1[0];
	for (int i = 1; i < sz(h1); i++) {
		hs1[i] = hs1[i - 1] * P + h1[i];
	}
	stp[0] = 1;
	for (int i = 1; i <= sz(h); i++) {
		stp[i] = stp[i - 1] * P;
		//cout << stp[i] << endl;
	}
	set<unsigned long long> kek;
	for (int i = 0; i < sz(h); i++) {
		unsigned long long f = get(i, sz(h) - 1);
		//cout << f << endl;
		if (i) {
			f *= stp[i];
			f += hs[i - 1];
		}
		//cout << f << endl;
		kek.insert(f);
	}
	for (int i = 0; i < sz(h); i++) {
		unsigned long long f1 = get1(i, sz(h) - 1);
		//cout << f1 << endl;
		if (i) {
			f1 *= stp[i];
			f1 += hs1[i - 1];
		}
		if (kek.find(f1) != kek.end()) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0; 		
}