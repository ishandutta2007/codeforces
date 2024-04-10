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
const string FILENAME = "input";
const int MAXN = 500228;


int n;
int c[MAXN];
int l[MAXN], r[MAXN];


void add(vector<int> &g) {
	int id = 0;
	for (int i = 19; i >= 0; i--) {
		int tp = 0;
		int pos = -1;
		for (int j = id; j < sz(g); j++) {
			if (g[j] & (1 << i)) {
				if (tp < g[j]) {
					tp = g[j];
					pos = j;
				}
			}
		}
		if (pos == -1) {
			continue;
		}
		swap(g[pos], g[id]);
		for (int j = 0; j < sz(g); j++) {
			if (j == id) {
				continue;
			}
			if (g[j] & (1 << i)) {
				g[j] ^= g[id];
			}
		}
		id++;
	} 
	while (sz(g) > 20) {
		g.pop_back();
	}
	while (!g.empty() && g.back() == 0) {
		g.pop_back();
	}
}



int getf(int val) {
    if (val == 0) {
        return -1;
    }
    return 31 - __builtin_clz(val);
}


void add1(vector<int> &g) {
	for (int i = 0; i < sz(g) - 1; i++) {
		if (getf(g[i]) == getf(g.back())) {
			g.back() ^= g[i];
		}
	}
	int i = sz(g) - 1;
	while (i > 0 && g[i] > g[i - 1]) {
		swap(g[i], g[i - 1]);
		i--;
	}
	while (!g.empty() && g.back() == 0) {
		g.pop_back();
	}
}


int ans[MAXN];
int need[MAXN];
int uk = 0;
vector<int> kek[MAXN];


void get(int ls, int rs, vector<int> ids) {
	if (ids.empty()) {
		return;
	}
	if (ls == rs) {
		for (auto x: ids) {
			ans[x] = c[ls];
		}
		return;
	}
	int mid = (ls + rs) >> 1;
	vector<int> cur, cur1, cur2;
	for (auto x: ids) {
		if (l[x] <= mid && r[x] > mid) {
			cur.pb(x);
		} else {
			if (r[x] <= mid) {
				cur1.pb(x);
			} else {
				cur2.pb(x);
			}
		}
	}
	get(ls, mid, cur1);
	get(mid + 1, rs, cur2);
	vector<int> s;
	uk++;
	for (auto x: cur) {
		need[l[x]] = uk;
		need[r[x]] = uk;
	}
	for (int i = mid; i >= ls; i--) {
		s.pb(c[i]);
		add1(s);
		if (need[i] == uk) {
			kek[i] = s;
		}
	}
	s.clear();
	for (int i = mid + 1; i <= rs; i++) {
		s.pb(c[i]);
		add1(s);
		if (need[i] == uk) {
			kek[i] = s;
		}
	}
	for (auto x: cur) {
		vector<int> f = kek[l[x]];
		for (auto y: kek[r[x]]) {
			f.pb(y);
		//	cout << y << ' ' << x + 1 << endl;
			add1(f);
		}
		int res = 0;
		for (auto x: f) {
			if ((res ^ x) > res) {
				res ^= x;
			}
		}
		ans[x] = res;
	}
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
  	cin >> n;
  	for (int i = 1; i <= n; i++) {
  		cin >> c[i];
  	}
  	int q;
  	cin >> q;
  	vector<int> ids;
  	for (int i = 0; i < q; i++) {
  		cin >> l[i] >> r[i];
  		ids.pb(i);
  	}
  	get(1, n, ids);
  	for (int i = 0; i < q; i++) {
  		cout << ans[i] << '\n';
  	}
    return 0;   
}