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
const int MAXN = 100228;

int t;
vector<int> g[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> t;
	for (int i = 1; i <= 100000; i++) {
		for (int j = i; j <= 100000; j+= i) {
			g[j].pb(i);
		}
	}
	//cout << res << endl;
	//cout << sz(g[100]) << endl;
	//t = 10000;
		vector<int> order;
		order.pb(0);
		order.pb(1);
		order.pb(2);

		vector<vector<int> > kek;
		do {
			kek.pb(order);
		} while (next_permutation(all(order)));
	for (int i = 0; i < t; i++) {
		int a, b, c;
		 cin >> a >> b >> c;
		 			vector<int> p;
		p.pb(a);
		p.pb(b);
		p.pb(c);
		int tp[3];
		int ans = 0;
		int sub = 0;
		int cnt = sz(g[__gcd(a, __gcd(b, c))]);
		for (int mask = 1; mask < (1 << 6); mask++) {
			for (int i = 0; i < 3; i++) {
				tp[i] = 0;
			}
			int cnt = 0;
			for (int id = 0; id < 6; id++) {
				if (mask & (1 << id)) {
					cnt++;
					for (int i = 0; i < 3; i++) {
						tp[kek[id][i]] = __gcd(tp[kek[id][i]], p[i]);
					}
				}	
			}
			int mod = (cnt & 1 ? 1: -1);
			ans += mod * sz(g[tp[0]]) * sz(g[tp[1]]) * sz(g[tp[2]]);
			tp[0] = __gcd(tp[0], tp[1]);
			sub += mod * (sz(g[tp[0]]) * sz(g[tp[2]]) - sz(g[__gcd(tp[0], tp[2])]));
		}
		cout << cnt + sub + (ans - cnt - sub * 3) / 6 << endl;
	}	
}