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



int n, m, q;
vector<pair<int, int> > z[4228];
int ans[500228];
int w[20];
int cntp[102];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	vector<int> g;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				t += 1 << i;
			}
		}
		g.pb(t);
	}
	sort(all(g));
	vector<pair<int, int> > st;
	for (int i = 0; i < m; i++) {
		if (st.empty() || st.back().first != g[i]) {
			st.pb({g[i], 1});
		} else {
			st.back().second++;
		}
	}
	m = sz(st);
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				t += 1 << i;
			}
		}
		int k;
		cin >> k;
		z[t].pb({k, i});
	}
	for (int i = 0; i < (1 << n); i++) {
		if (z[i].empty()) {
			continue;
		}
		sort(all(z[i]));
		vector<pair<int, int> > kek;
		memset(cntp, 0, sizeof(cntp));
		for (int j = 0; j < m; j++) {
			int cost = 0;
			for (int f = 0; f < n; f++) {
				if ((st[j].first & (1 << f)) == (i & (1 << f))) {
					cost += w[f];
				}
			}
			if (cost <= 100) {
				cntp[cost]+= st[j].second;
			}
		}
		int cnt = 0;
		int uk = 0;
		for (auto x: z[i]) {
			while (uk <= x.first) {
				cnt += cntp[uk];
				uk++;
			}
			ans[x.second] = cnt;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0; 		
}