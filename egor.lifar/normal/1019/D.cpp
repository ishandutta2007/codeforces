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
const int MAXN = 2001;



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


int n;
long long s;
point p[MAXN];



bool comp(point a, point b) {
	return a.x < b.x || (a.x == b.x && a.y > b.y);
}


long long vec(point a, point b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}


int semiplane(point a) {
	if (a.x < 0 || (a.x == 0 && a.y >= 0)) {
		return 0;
	}
	return 1;
}

bool comp1(pair<int, int> a, pair<int, int> b) {
 	point c = p[a.second] - p[a.first];
 	point d = p[b.second] - p[b.first];
 	int fc = semiplane(c);
 	int fd = semiplane(d);
 	if (fc != fd) {
 		return fc < fd;
 	}
 	return vec(c, d) > 0;
}


int what[MAXN];
int pos[MAXN];


long long get(point c, point d, point e) {
	return vec(d - c, e - c);
}


int main() {
	ios_base::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
	//read(FILENAME);
	cin >> n >> s;
	s <<= 1;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		what[i] = i;
		pos[i] = i;
	}
	sort(p, p + n, comp);
	vector<pair<int, int> > st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			st.pb({i, j});
		}
	}
	sort(all(st), comp1);
	for (auto x: st) {
		int a = x.first;
		int b = x.second;
		swap(what[pos[a]], what[pos[b]]);
        swap(pos[a], pos[b]);
        int l = -1;
        int r = n;
        while (r - l > 1) {
        	int mid = (l + r) >> 1;
        	if (get(p[a], p[b], p[what[mid]]) >= s) {
        		l = mid;
        	}  else {
        		r = mid;
        	}
        }
        if (l != -1 && get(p[a], p[b], p[what[l]]) == s) {
        	cout << "Yes\n";
        	cout << p[a].x << ' ' << p[a].y << '\n';
        	cout << p[b].x << ' ' << p[b].y << '\n';
        	cout << p[what[l]].x << ' ' << p[what[l]].y << '\n';
        	return 0;
        }
	}
	cout << "No\n";
	return 0; 			
}