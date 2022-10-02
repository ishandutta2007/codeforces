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



int p;


int mul(int a, int b) {
	return (1LL * a * b) % p;
}

int powm(int a, int b) {
	int s = a;
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, s);
		}
		s = mul(s, s);
		b >>= 1;
	}
	return res;
}


unordered_map<int, short> dist[2];
unordered_map<int, int> pr[2];
unordered_map<int, char> type[2];


int dists(int a, int b) {
	return min(abs(a - b), p - max(a, b) + min(a, b));
}


vector<int> gl;


void restorepath(int id, int b) {
	vector<int> k;
	while (b != -1) {
		k.pb(type[id][b]);
		if (id == 1) {
			if (k.back() < 3) {
				k.back() = 3 - k.back();
			}
		}	
		b = pr[id][b];
	}
	k.pop_back();
	reverse(all(k));
	for (auto x: k) {
		gl.pb(x);
	}
}



void go(int a, int b) {
	int f = dists(a, b);
	if (a <= b && b - a == f) {
		for (int i = 0; i < b-  a; i++) {
			gl.pb(1);
		}
		return;
	}
	if (a >= b && a - b == f) {
		for (int i = 0; i < a - b; i++) {
			gl.pb(2);
		}
		return;
	}
	if (a <= b && a + p - b == f) {
		for (int i = 0; i < a; i++) {
			gl.pb(2);
		}
		for (int i = 0; i < p - b; i++) {
			gl.pb(2);
		}
		return;
	}
	if (a >= b && b + p - a == f) {
		for (int i = 0; i < p - a; i++) {
			gl.pb(1);
		}
		for (int i = 0; i < b; i++) {
			gl.pb(1);
		}
		return;
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int u, v;
	cin >> u >> v >> p;
	if (u == v) {
		cout << "0\n";
		exit(0);
	}
	queue<pair<int, int> > q;
	q.push({u, 0});
	dist[0][u] = 0;
	pr[0][u] = -1;
	q.push({v, 1});
	dist[1][v] = 0;
	pr[1][v] = -1;
	while (!q.empty()) {
		pair<int, int> as = q.front();
		int a = as.first;
		q.pop();
		if (as.second == 0 && dists(a, v) + dist[as.second][a] <= 200) {
			restorepath(as.second, a);
			go(a, v);
			cout << sz(gl) << '\n';
			for (auto x: gl) {
				cout << x << ' ';
			}
			cout << '\n';
			exit(0);
		}
		if (dist[as.second ^ 1].find(a) != dist[as.second ^ 1].end())  {
			if (as.second == 0) {
				restorepath(as.second, a);
				vector<int> gt = gl;
				gl.clear();
				restorepath(as.second ^ 1, a);
				reverse(all(gl));
				for (auto x: gl) {
					gt.pb(x);
				}
				cout << sz(gt) << '\n';
				for (auto x: gt) {
					cout << x << ' ';
				}
				cout << '\n';
			} else {
				restorepath(as.second ^ 1, a);
				vector<int> gt = gl;
				gl.clear();
				restorepath(as.second, a);
				reverse(all(gl));
				for (auto x: gl) {
					gt.pb(x);
				}
				cout << sz(gt) << '\n';
				for (auto x: gt) {
					cout << x << ' ';
				}
				cout << '\n';
			}
			exit(0);
		}
		if (dist[as.second][a] > 100) {
			continue;
		}
		int b = powm(a, p - 2);
		if (dist[as.second].find(b) == dist[as.second].end()) {
			dist[as.second][b] = dist[as.second][a] + 1;
			pr[as.second][b] = a;
			type[as.second][b] = 3;
			q.push({b, as.second});
		}
		b = (a + 1) % p;
		if (dist[as.second].find(b) == dist[as.second].end()) {
			dist[as.second][b] = dist[as.second][a] + 1;
			pr[as.second][b] = a;
			type[as.second][b] = 1;
			q.push({b, as.second});
		}
		b = (a + p - 1) % p;
		if (dist[as.second].find(b) == dist[as.second].end()) {
			dist[as.second][b] = dist[as.second][a] + 1;
			type[as.second][b] = 2;
			pr[as.second][b] = a;
			q.push({b, as.second});
		}
	}
	assert(false);
	return 0;				
}