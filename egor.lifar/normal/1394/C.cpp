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
#include <complex>
 
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 300228;
const ld eps = 1e-7;
 
 
 
 
struct Point
{
	ld x, y;
	Point(){}
	Point(ld _x, ld _y): x(_x), y(_y){}
	ld len() {
		return sqrt(x * x + y * y);
	}
};
 
Point operator +(const Point& a, const Point& b) {
	return Point(a.x + b.x, a.y + b.y);
}
 
 
Point operator -(const Point& a, const Point& b) {
	return Point(a.x - b.x, a.y - b.y);
}
 
 
ld operator *(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}
 
 
ld operator ^(const Point& a, const Point& b) {
	return a.x * b.x + a.y * b.y;
}
 
 
struct Line
{
	ld a, b, c;
	Line(){}
	Line(ld _a, ld _b, ld _c) {
		a = _a;
		b = _b;
		c = _c;
		ld d = sqrt(a * a + b * b);
		a /= d;
		b /= d;
		c /= d;
		if (c < 0) {
			a *= -1;
			b *= -1;
			c *= -1;
		}
	}
	Line(Point s, Point f) {
		a = f.y - s.y;
		b = s.x - f.x;
		ld d = sqrt(a * a + b * b);
		a /= d;
		b /= d;
		c = -(a * s.x + b * s.y);
		if (c < 0) {
			a *= -1;
			b *= -1;
			c *= -1;
		}
	}
	ld get(const Point &p) {
		return a * p.x + b * p.y + c;
	}
};
 
 
 
Point getPoint(Line a) {
	return Point(a.a, a.b);
}
 
 
 
Point cross(const Line& a, const Line& b) {	
	ld det = a.a * b.b - b.a * a.b;
	assert(abs(det) >= eps);
	return Point((-a.c * b.b + b.c * a.b) / det, (-a.c * b.a + b.c * a.a) / (-det));
}
 
 
Line buildHalfPlane(Point a, Point b) {
	Point c = a + b;
	c.x /= 2;
	c.y /= 2;
	Point d = b - a;
	swap(d.x, d.y);
	d.x *= -1;
	Line kek(c, c + d);
	if (kek.get(b) < 0) {
		kek.a *= -1;
		kek.b *= -1;
		kek.c *= -1;
	}
	return kek;
}
 
 
vector<Point> build(vector<Line> lines) {
	sort(all(lines), [] (Line al, Line bl) -> bool {
		Point a = getPoint(al);
		Point b = getPoint(bl);
		if (a.y >= 0 && b.y < 0) {
			return 1;
		}
		if (a.y < 0 && b.y >= 0) {
			return 0;
		}
		if (a.y == 0 && b.y == 0) {
			return a.x > 0 && b.x < 0;
		}
		return (a * b) > 0;
 	});
	vector<pair<Line, int> > st;
	for (int it = 0; it < 2; it++) {
		for (int i = 0; i < sz(lines); i++) {
			bool fl = 0;	
			while (!st.empty()) {
				if ((getPoint(st.back().first) - getPoint(lines[i])).len() <= eps) {
					if (st.back().first.c <= lines[i].c) {
						fl = 1;
						break;
					} else {
						st.pop_back();
					}
				} else if ((getPoint(st.back().first) * getPoint(lines[i])) <= eps / 2) {
					return {};
				} else if (sz(st) >= 2 && st[sz(st) - 2].first.get(cross(st.back().first, lines[i])) < 0) {
					st.pop_back();
				} else {
					break;
				}
 			} 
			if (!fl) {
				st.push_back({lines[i], i});
			}
		}	
	}
	vector<int> en;
	en.resize(sz(lines));
	for (auto &x: en) {
		x = -1;
	}
	vector<Point> p;
	for (int i = 0; i < sz(st); i++) {
		int x = st[i].second;
		if (en[x] == -1) {
			en[x] = i;
		} else {
			for (int j = en[x]; j < i; j++) {
				p.pb(cross(st[j].first, st[j + 1].first));
			}
			break;
		}
	}
	return p;
}
 
 
 
int n;
int x[MAXN], y[MAXN];
int posx, posy;
 
 
bool check(int len) {
	int ly = 0, ry = 1e9, lx = 0, rx = 1e9;
	for (int i = 0; i < n; i++) {
		chkmax(ly, y[i] - len);
		chkmax(lx, x[i] - len);
		chkmin(ry, y[i] + len);
		chkmin(rx, x[i] + len);
	}
	if (lx > rx || ly > ry) {
		return false;
	}
	int diffmax = -1e9, diffmin = 1e9;
	int ps = -1,  ps1 = -1;
	for (int i = 0; i < n; i++) {
		chkmax(diffmax, y[i] - x[i]);
		if (diffmax == y[i] - x[i]) {
			ps1 = i;
		}
		chkmin(diffmin, y[i] - x[i]);
		if (diffmin == y[i] - x[i]) {
			ps = i;
		}
	}
	//cout << ps << ' ' << ps1 << endl;
	ll lsx = x[ps] - len;
	ll lsy = y[ps];
	ll rsx = x[ps];
	ll rsy = y[ps] + len;

	ll ls1x = x[ps1];
	ll ls1y = y[ps1] - len;
	ll r1x = x[ps1] + len;
	ll rs1y = y[ps1];
	if (lsy - lsx < ls1y - ls1x) {
		return false;
	}
	vector<pair<ll, ll> > kek;
	kek.pb(mp(lx, ly));
	kek.pb(mp(lx, ry));
	kek.pb(mp(rx, ly));
	kek.pb(mp(rx, ry));
	ll diff = lsy - lsx;
	ll diff1 = ls1y - ls1x;
	kek.pb(mp(lx, lx + diff));
	kek.pb(mp(rx, rx + diff));
	kek.pb(mp(ly - diff, ly));
	kek.pb(mp(ry - diff, ry));


	kek.pb(mp(lx, lx + diff1));
	kek.pb(mp(rx, rx + diff1));
	kek.pb(mp(ly - diff1, ly));
	kek.pb(mp(ry - diff1, ry));

	for (auto x: kek) {
		if (x.first >= lx && x.first <= rx && x.second >= ly && x.second <= ry) {
			if (x.second - x.first <= lsy - lsx && x.second - x.first >= ls1y - ls1x) {
				if (x.second > 0 || x.first > 0) {
					posx = x.first;
					posy = x.second;
					return true;
				}
			}
		}
	}
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	vector<pair<int, int> > k;
	for (int it = 0; it < n; it++) {
		string s;
		cin >> s;
		for (auto c: s) {
			if (c == 'B') {
				x[it]++;
			} else {
				y[it]++;
			}
		}
		k.pb(mp(x[it], y[it]));
	}
	sort(all(k));
	k.resize(distance(k.begin(), unique(all(k))));
	n = sz(k);
	for (int it = 0; it < n; it++) {
		x[it] = k[it].first;
		y[it] = k[it].second;
	}
	if (n == 1) {
		cout << 0 << '\n';
		for (int it = 0; it < x[0]; it++) {
			cout << 'B';
		}
		for (int it = 0; it < y[0]; it++) {
			cout << 'N';
		}
		cout << '\n';
		return 0;
	}
	int l = 0;
	int r = 1000000;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid; 
		}  else {
			l = mid + 1;
		}
	}
	check(l);
	//cout << posx << ' ' << posy << ' ' << x[2] << ' ' << y[2] << endl;
	cout << l << '\n';
	for (int i = 0; i < posx; i++) {
		cout << 'B';
	}
	for (int i = 0; i < posy; i++) {
		cout << 'N';
	}
	cout << '\n';
}