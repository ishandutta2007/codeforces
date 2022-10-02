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
const int MAXN = 3002;


int n, m;
int cnt[MAXN];
int p[MAXN], c[MAXN];
vector<int> who[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> c[i];
		p[i]--;
		who[p[i]].pb(c[i]);
	}
	long long res = 1e18;
	for (int i = 1; i < m; i++) {
		sort(all(who[i]));
		reverse(all(who[i]));
	}
	for (int f = 0; f <= n; f++) {
		for (int i = 0; i < m; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cnt[p[i]]++;
		}
		long long cost = 0;
		int t = 0;
		int cntbad = 0;
		for (int i = 1; i < m; i++) {
			for (int j = sz(who[i]) - 1; j >= f; j--) {
				int a = who[i][j];
				cost += a;
				cnt[0]++;
				cnt[i]--;
			}
			chkmax(t, cnt[i]);
		}
		//cout << f << endl;
		if (cnt[0] > t) {
			chkmin(res, cost);
		} else {
			vector<pair<int, int> > kek;
			multiset<int> p;
			for (int i = 1; i < m; i++) {
				for (int j = min(f - 1, sz(who[i]) - 1); j >= 0; j--) {
				//	cout << j << ' ' << sz(who[i]) << endl;
					kek.pb({who[i][j], i});
				}
				p.insert(cnt[i]);
			}
			sort(all(kek));
			for (auto x: kek) {
				cost += x.first;
				p.erase(p.find(cnt[x.second]));
				cnt[x.second]--;
				p.insert(cnt[x.second]);
				cnt[0]++;
				if (*p.rbegin() < cnt[0]) {
					break;
				}
			}
			chkmin(res, cost);
		}
	}
	cout << res << '\n';
	return 0; 			
}