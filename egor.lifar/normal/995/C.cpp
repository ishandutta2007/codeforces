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
const int MAXN = 100001;


int n;
int x[MAXN], y[MAXN];
int c[MAXN];
int a[MAXN];
int id[MAXN];
int reals[MAXN];
int xs[MAXN], ys[MAXN];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	int curx = 0, cury = 0;
	int last = 0;
	int st = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		id[i] = i;
		xs[i] = x[i];
		ys[i] = y[i];
	}
	while (true) {
	random_shuffle(id, id + n);
	for (int i = 0; i < n; i++) {
		x[i] = xs[i];
		y[i] = ys[i];
	}	
	long long lst = 0;
	curx = 0;
	cury = 0;
	last = 0;
	st = 0;
	for (int i1 = 0; i1 < n; i1++) {
		int i = id[i1];
		long long res = 1e18;
		for (int t = 0; t < 2; t++) {
			for (int t1 = 0; t1 < 2; t1++) {
				int nx = curx + x[i];
				int ny = cury + y[i];
				chkmin(res, 1LL * nx * nx + 1LL * ny * ny);
				x[i] *= -1;
				y[i] *= -1;
			}
			curx *= -1;
			cury *= -1;
		}
		bool was = false;
		for (int t = 0; t < 2; t++) {
			int nx = curx + x[i];
			int ny = cury + y[i];
			if ((1LL * nx * nx + 1LL * ny * ny) == res) {
				c[i1] = last ^ t;
				if (i == 0) {
					st = t;
				}
				was = true;
				curx = nx;
				cury = ny;
				last = t;
				break;
			}
			x[i] *= -1;
			y[i] *= -1;
		}
		if (!was) {
			st ^= 1;
			last ^= 1;
			curx *= -1;
			cury *= -1;
			for (int t = 0; t < 2; t++) {
				int nx = curx + x[i];
				int ny = cury + y[i];
				if ((1LL * nx * nx + 1LL * ny * ny) == res) {
					c[i1] = t ^ last;
					if (i == 0) {
						st = t;
					}
					was = true;
					curx = nx;
					cury = ny;
					last = t;
					break;
				}
				x[i] *= -1;
				y[i] *= -1;
			}
		}
		lst = res;
		//cout << res << endl;
		//cout << curx << ' ' << cury << ' ' << i + 1 << endl;
	}
	if (lst <= 1500000LL * 1500000LL) {
		break;
	}
	}	
	//cout << curx << ' ' << cury << endl;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			a[i] = st;
		} else {
			if (c[i]) {
				a[i] = a[i - 1] ^ 1;
			} else {
				a[i] = a[i - 1];
			}
		}
		reals[id[i]] = a[i];
	}
	for (int i = 0; i < n; i++) {
		if (reals[i] == 0) {
			cout << 1 << ' ';
		} else {
			cout << -1 << ' ';
		}
	}
	cout << '\n';
	return 0;			
}