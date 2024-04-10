/*

Code for problem I by cookiedoth
Generated 07 Sep 2021 at 03.48 PM


  !











o_O
-_-
z_z

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

bool polar_cmp(pt a, pt b) {
	int ha = half_plane(a), hb = half_plane(b);
	if (ha < hb) {
		return 1;
	}
	if (ha > hb) {
		return 0;
	}
	return (a / b > 0);
}

const ll INF = 1e9;
const ld EPS = 1e-10;
int n;
pt v1, v2;

bool on_line(pt p1, pt p2, pt p3) {
	return (p1 - p2) / (p1 - p3) == 0;
}

signed main() {
	fast_io();
	cin >> n >> v1 >> v2;
	if (v1 / v2 == 0) {
		cout << "NO\n";
		exit(0);
	}
	if (v1 / v2 < 0) {
		swap(v1, v2);
	}
	vector<pt> v = {pt(), v1, v1 + v2, v2};
	// cerr << "v" << '\n';
	// for (auto p : v) {
	// 	cerr << p << '\n';
	// }
	ll min_x = INF, max_x = -INF;
	for (auto p : v) {
		chkmin(min_x, p.x);
		chkmax(max_x, p.x);
	}
	vector<pt> ans;
	for (ll x = min_x; x <= max_x; ++x) {
		// cerr << "x = " << x << '\n';
		ll min_y = -INF, max_y = INF;
		for (int i = 0; i < 4; ++i) {
			pt p1 = v[i], p2 = v[(i + 1) % 4];
			if (p1.x == p2.x) {
				continue;
			}
			ld inter = (ld)p1.y + (ld)(x - p1.x) / (ld)(p2.x - p1.x) * (ld)(p2.y - p1.y);
			if (p1.x < p2.x) {
				inter -= EPS;
				chkmax(min_y, (ll)ceil(inter));
			} else {
				inter += EPS;
				chkmin(max_y, (ll)floor(inter));
			}
		}
		// cerr << "yrange " << min_y << ' ' << max_y << '\n';
		for (ll y = min_y; y <= max_y; ++y) {
			pt cur(x, y);
			if (on_line(cur, v[1], v[2]) || on_line(cur, v[2], v[3])) {
				continue;
			}
			ans.emplace_back(cur);
			if (ans.size() > n) {
				cout << "NO\n";
				exit(0);
			}
		}
	}
	// cerr << "anssz = " << ans.size() << '\n';
	assert(ans.size() == abs(v1 / v2));
	if (ans.size() == n) {
		cout << "YES\n";
		for (auto [x, y] : ans) {
			cout << x << ' ' << y << '\n';
		}
	} else {
		cout << "NO\n";
	}
}