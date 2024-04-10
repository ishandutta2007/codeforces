/*

Code for problem F by cookiedoth
Generated 07 Sep 2021 at 02.41 PM


 ] 
 
Il] 


^_^
~_^
=_=

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct pt {
	ll x, y;

	pt(): x(0), y(0) {}
	pt(ll _x, ll _y): x(_x), y(_y) {}
};

pt operator + (pt a, pt b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

ll operator * (pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

ll operator / (pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

istream& operator >> (istream &is, pt &p) {
	is >> p.x >> p.y;
	return is;
}

ostream& operator << (ostream &os, const pt &p) {
	os << p.x << " " << p.y;
	return os;
}

int half_plane(pt a) {
	return (a.y > 0 || (a.y == 0 && a.x > 0)) ^ 1;
}

bool operator < (pt a, pt b) {
	int ha = half_plane(a), hb = half_plane(b);
	if (ha < hb) {
		return 1;
	}
	if (ha > hb) {
		return 0;
	}
	return (a / b > 0);
}

map<pt, ll> mpt;

void solve() {
	mpt.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		pt p1, p2;
		cin >> p1 >> p2;
		mpt[p2 - p1]++;
	}
	ll ans = 0;
	for (auto [key, value] : mpt) {
		// cerr << "opa " << key << " | " << value << '\n';
		ans += value * mpt[pt() - key];
	}
	cout << ans / 2 << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}