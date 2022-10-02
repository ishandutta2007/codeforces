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
const int MAXN = 300001;


int n, m;
vector<pair<int, int> > g[MAXN];
long long dist[MAXN];
long long dist1[MAXN];
int prs[MAXN];


void dfs(int u, int pr = -1) {
	for (auto x: g[u]) {
		int h = x.first;
		if (h == pr) {
			continue;
		}
		dist[h] = dist[u] + x.second;
		prs[h] = u;
		dfs(h, u);
	}
}


void dfs1(int u, int pr = -1) {
	for (auto x: g[u]) {
		int h = x.first;
		if (h == pr) {
			continue;
		}
		dist1[h] = dist1[u] + x.second;
		dfs1(h, u);
	}
}


map<pair<int, int>, long long> who;
long long dist2[MAXN];
bool bad[MAXN];
long long score[MAXN];
int cntp = 0;



void dfs2(int u, int pr, int c) {
	chkmax(score[c], dist2[u]);
	cntp++;
	for (auto x: g[u]) {
		int h = x.first;
		if (h == pr || bad[h]) {
			continue;
		}
		dist2[h] = dist2[u] + x.second;
		dfs2(h, u, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].pb({b, w});
		g[b].pb({a, w});
		who[{a, b}] = w;
		who[{b, a}] = w;
	}
	prs[1] = -1;
	dfs(1);
	dfs1(n);
	int cur = n;
	vector<int> path;
	while (cur != -1) {
		path.pb(cur);
		cur = prs[cur];
	}
	reverse(all(path));
	long long t = 1e18;
	for (int i = 0; i < sz(path); i++) {
		bad[path[i]] = true;
	}
	bool good = false;
	for (int i = 0; i < sz(path); i++) {
		cntp = 0;
		dfs2(path[i], -1, i);
		if (cntp >= 3) {
			good = true;
		}
	//	cout << score[i] << endl;
	}
	//score[i] + score[j] + x < distij - bad
	//min po ij, distij - scorei - scorej
	long long curmax = 1e18;
	if (score[0]) {
		curmax = -score[0];
	}
	for (int i = 1; i < sz(path); i++) {
		curmax += who[{path[i - 1], path[i]}];
		if (i >= 2) {
			chkmin(curmax, -score[i - 2] + who[{path[i - 1], path[i]}] + who[{path[i - 1], path[i - 2]}]);
		}
		chkmin(t, curmax - score[i]);
		if (score[i]) {
			chkmin(t, who[{path[i - 1], path[i]}] - score[i] - score[i - 1]);
		}
		if (score[i]) {
			chkmin(curmax, -score[i]);
		}
	}
	//cout << t << endl;
	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		if (t <= x || good) {
			cout << dist[n] << '\n';
		} else {
			cout << dist[n] - t + x << '\n';
		}
	}
	return 0; 		
}