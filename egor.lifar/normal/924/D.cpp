// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#pragma GCC target("sse4,tune=native")
//#pragma GCC optimize("O3")
#include <iostream>
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
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
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
  
typedef long long base;
typedef pair<base, base> point;

const string FILENAME = "input";

const int MAXN = 1e5 + 15;


int n, w;
int x[MAXN], v[MAXN];
point t1[MAXN], t2[MAXN];

int p[MAXN];
vector<int> id;

bool cmp(point a, point b) {
	return a.x * b.y < b.x * a.y;
}

bool eq(point a, point b) {
	return a.x * b.y == b.x * a.y;
}

bool cmp1(int i, int j) {
	if (eq(t1[i], t1[j])) {
		return cmp(t2[j], t2[i]);
	}
	return cmp(t1[i], t1[j]);
}

bool cmp2(int i, int j) {
	if (eq(t2[i], t2[j])) {
		return cmp(t1[j], t1[i]);
	}
	return cmp(t2[i], t2[j]);
}

struct fen {
	int a[MAXN];

	void add(int i) {
		while (i < MAXN) {
			++a[i];
			i |= (i + 1);
		}
	}

	int get(int i) {
		int ans = 0;
		while (i > 0) {
			ans += a[i];
			i &= (i + 1);
			--i;
		}
		return ans;
	}
};

long long ans = 0;
fen box;

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> v[i];
		t1[i].x = abs(x[i]);
		t1[i].y = abs(v[i] - w);
		t2[i].x = abs(x[i]);
		t2[i].y = abs(v[i] + w);
		id.pb(i);
	}
	sort(id.begin(), id.end(), cmp1);
	if (w == 0) {
		int lst = 1;
		for (int i = 1; i < n; ++i) {
			if (eq(t1[id[i - 1]], t1[id[i]])) {
				ans += lst;
				++lst;
			} else {
				lst = 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		p[id[i]] = i;
	}
	sort(id.begin(), id.end(), cmp2);
	for (int i = 0; i < n; ++i) {
		ans += i - box.get(p[id[i]]);
		box.add(p[id[i]]);
	}
	cout << ans << endl;
}