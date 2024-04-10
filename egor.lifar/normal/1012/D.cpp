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


int reallen(string s){
	int num1 = 1;
	for(int i = 0; i + 1 < sz(s); i++) {
		num1 += (s[i] != s[i + 1]);
	}
	return num1;
}


vector<pair<int,int> > solve(string s, string t, int q){
	s = "a" + s;
	s += ('a' + q);
	t = "b" + t;
	t += ('a' + (1 - q));
	vector<pair<int,int> > ans;
	int num1 = reallen(s);
	int num2 = reallen(t);
	if (num1 == 1 && num2 == 1) {
		return ans;
	}
	vector<int> g1;
	vector<int> g2;
	for(int i = 0; i < sz(s); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			g1.pb(1);
		} else {
			g1[sz(g1) - 1]++;
		}
	}
	g1[0]--;
	g1[sz(g1) -1 ]--;
	for (int i = 0; i < sz(t); i++) {
		if(i == 0 || t[i] != t[i - 1]){
			g2.pb(1);
		} else {
			g2[sz(g2) - 1]++;
		}
	}
	g2[0]--;
	g2[sz(g2) - 1]--;
	if (sz(g1) == 1){ 
		g1.pb(0);
		g1.pb(0);
	} else if(sz(g2) == 1) {
		g2.pb(0);
		g2.pb(0);
	}
	if ((sz(g1) - sz(g2)) % 4 != 0) {
		g1.pb(0);
		g1.pb(0);
	}
	if (sz(g1) != sz(g2) ){
		int a1 = (sz(g1) + 1) / 2;
		int a2 = (sz(g2) + 1) / 2;
		vector<int> newg1;
		vector<int> newg2;
		int sum1 = 0;
		int sum2 = 0;
		for (int j = 0; j < a1; j++) {
			sum1 += g1[j];
			newg1.pb(g1[j]);
		}
		for (int j = 0; j < a2; j++) {
			sum2 += g2[j];
			newg2.pb(g2[j]);
		}
		ans.pb({sum1, sum2});
		for (int j = a1; j < sz(g1); j++) {
			if (j == a1) {
				newg2[sz(newg2) - 1] += g1[j];
			} else {
				newg2.pb(g1[j]);
			}
		}
		for (int j = a2; j < sz(g2); j++) {
			if (j == a2) {
				newg1[sz(newg1) - 1] += g2[j];
			} else {
				newg1.pb(g2[j]);
			}
		}
		g1 = newg1;
		g2 = newg2;
	}
	int psum1 = 0;
	int psum2 = 0;
	for (int z = 1; z < sz(g1); z++){
		psum1 += g1[z - 1];
		psum2 += g2[z - 1];
	}
	for (int z = (int)sz(g1) - 1; z >= 1; z--) {
		ans.pb({psum1, psum2});
		psum1 -= g1[z - 1];
		psum2 -= g2[z - 1];
	}
	for (int i = 0; i < sz(ans); i++) {
		if (i % 2) {
			swap(ans[i].first, ans[i].second);
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	string s, t;
	cin >> s >> t;
	vector<pair<int,int> > c(700000, {-1, -1});
	for (int r = 0; r < 2; r++) {
		for (int z = 0; z < 2; z++) {
			vector<pair<int,int> > ans = solve(s, t, z);
			if (r == 1) {
				for (int i = 0; i < sz(ans); i++) {
					swap(ans[i].first, ans[i].second);
				}
			}
			if (sz(ans) <= sz(c)) {
				c = ans;
			}
		}
		swap(s, t);
	}
	cout << sz(c) << '\n';
	for (int i = 0; i < sz(c); i++) {
		cout << c[i].first << ' ' << c[i].second << '\n';
	}
	return 0; 		
}