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


map<int, int> t, b;


long long comp(const pair<int, int> &x, const pair<int, int> &y, const pair<int, int> &z){
	return 1LL * (x.first - z.first) * (y.second - z.second) - 1LL * (x.second - z.second) * (y.first - z.first);
}


bool inside(map<int, int> &h, const pair<int, int> &x){
	auto i = h.lower_bound(x.first);
	if (i == h.end()) {
		return 0;
	}
	if ((*i).first == x.first) {
		return x.second <= (*i).second;
	}
	if (i == h.begin()) {
		return 0;
	}
	auto j = i--;
	return comp(x, *j, *i) >= 0;
}



void add(map<int, int> &h, const pair<int, int> &x){
	h[x.first] = x.second;
	auto i = h.upper_bound(x.first);
	if (i != h.end()) { 
		for (auto j = i++; i != h.end(); j = i++) {
			if (comp(*i, *j, x) <= 0) {
				h.erase(j);
			} else {
				break;
			}
		}
	}
	i = h.find(x.first);
	if (i != h.begin()) {
		auto j = --i;
		for(; j != h.begin();) {
			i = j--;
			if (comp(*i, *j, x) <= 0) {
				h.erase(i);
			} else {
				break;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
	int n;
	cin >> n;
	for (int it = 0; it < n; it++) {
		int ts, x, y;
		cin >> ts >> x >> y;
		bool ft = inside(t, {x, y});
		bool fb = inside(b, {x, -y});
		if (ts == 1) {
			if (!ft) {
				add(t, {x, y});
			}
			if (!fb) {
				add(b, {x, -y});
			}
		} else {
			if (ft && fb) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}