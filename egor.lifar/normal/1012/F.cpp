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
const int INF = 1000000000;


int n, p;
int dp[1 << 22];
int s[22], len[22], t[22];
int id[22];
pair<int, int> pr[1 << 22];
pair<int, int> res[22];


bool comp(int i, int j) {
	return s[i] < s[j];
}


void restore(int g, int t) {
	if (!g) {
		return;
	}
	int s = pr[g].second;
	res[s] = make_pair(t, pr[g].first);
	restore(g ^ (1 << s), t);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> len[i] >> t[i];
		id[i] = i;
	}
	sort(id, id + n, comp);
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = INF;
	}
	dp[0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		if (dp[i] == INF) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				continue;
			}
			int g = dp[i];
			for (int p = 0; p < n; p++) {
				int h = id[p];
				if (g + t[j] < s[h]) {
					break;
				}
				if ((i & (1 << h)) || g >= s[h]) {
					chkmax(g, s[h] + len[h]);
				}
			}
			if (g + t[j] >= s[j]) {
				continue;
			}
			if (dp[i ^ (1 << j)] > g + t[j]) {
				dp[i ^ (1 << j)] = g + t[j];
				pr[i ^ (1 << j)] = {g, j};
			}
		}
	}
	if (p == 1) {
		if (dp[(1 << n) - 1] == INF) {
			cout << "NO\n";
			return 0;;
		}
		cout << "YES\n";
		restore((1 << n) - 1, 1);
		for (int i = 0; i < n; i++) {
			cout << res[i].first << ' ' << res[i].second << '\n';
		}
		return 0;
	}
	int g = -1;
	for (int i = 0; i < (1 << n); i++) {
		if (dp[i] < INF && dp[((1 << n) - 1) ^ i] < INF) {
			g = i;
		}
	}
	if (g == -1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	restore(g, 1);
	restore(((1 << n) - 1) ^ g, 2);
	for (int i = 0; i < n; i++) {
		cout << res[i].first << ' ' << res[i].second << '\n';
	}
	return 0; 		
}