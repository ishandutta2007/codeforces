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
const int MAXN = 200228;


struct point
{
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};


point a, b;
int n;
int l[MAXN], r[MAXN];
point c[MAXN];
double sum[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> a.y >> a.x >> b.x;
	b.y = a.y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i]; 
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> c[i].x >> c[i].y;
	}
	for (int i = 0; i < n; i++) {
		sum[i] = r[i] - l[i];
		if (i) {
			sum[i] += sum[i - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		int ll = 0;
		int rr = n - 1;
		while (ll != rr) {
			int mid = (ll + rr) >> 1;
			double pos = double(-a.y + c[i].y) / c[i].y * (r[mid] - c[i].x) + c[i].x;
			if (pos < a.x) {
				ll = mid + 1;
			} else {
				rr = mid;
			}
		}
		double pos = double(-a.y + c[i].y) / c[i].y * (r[ll] - c[i].x) + c[i].x;
		if (pos < a.x) {
			cout << 0 << '\n';
			continue;
		}
		int left = ll;
		rr = n - 1;
		while (ll != rr) {
			int mid = (ll + rr + 1) >> 1;
			double pos = c[i].x - double(-a.y + c[i].y) / c[i].y * (c[i].x - l[mid]);
			if (pos > b.x) {
				rr = mid - 1;
			} else {
				ll = mid;
			}
		}
		int right = rr;
		double posr = double(-a.y + c[i].y) / c[i].y * (r[left] - c[i].x) + c[i].x;
		double posl = c[i].x - double(-a.y + c[i].y) / c[i].y * (c[i].x - l[left]);
		chkmax(posl, a.x);
		chkmin(posr, b.x);
		double ans = max(0.0, posr - posl);
		if (left != right) {
			posr = double(-a.y + c[i].y) / c[i].y * (r[right] - c[i].x) + c[i].x;
			posl = c[i].x - double(-a.y + c[i].y) / c[i].y * (c[i].x - l[right]);
			chkmax(posl, a.x);
			chkmin(posr, b.x);
			ans += max(0.0, posr - posl);
		}
		left++;
		right--;
		if (left <= right) {
			double len = sum[right] - sum[left - 1];
			len *= double(-a.y + c[i].y) / c[i].y;
			ans += len;
		}
		cout << fixed << ans << '\n';
 	}
	return 0; 		
}