#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100000;

struct pt {
    double x, y;
};

bool eq(pt a, pt b) {
	return (abs(a.x - b.x) < eps && abs(a.y - b.y) < eps);
}

pt read_pt() {
	pt res;
	cin >> res.x >> res.y;
	return res;
}

pt make_pt(double x, double y) {
	pt res;
	res.x = x, res.y = y;
	return res;
}

pt operator-(pt p1, pt p2) {
    return make_pt(p1.x - p2.x, p1.y - p2.y);
}

double dist(pt p1, pt p2) {
	pt p3 = p1 - p2;
    return sqrt(p3.x * p3.x + p3.y * p3.y);
}

int n, ans;
bool yess;
double rr;
pt a, b;
pt q[4];
vector<pt> c;
vector<double> r;

int main() {

	a = read_pt();
	b = read_pt();
	cin >> n;
	forn(i, n) {
		c.push_back(read_pt());
		cin >> rr;
		r.push_back(rr);
	}

	q[0].x = min(a.x, b.x), q[0].y = min(a.y, b.y);
	q[1].x = min(a.x, b.x), q[1].y = max(a.y, b.y);
	q[2].x = max(a.x, b.x), q[2].y = max(a.y, b.y);
	q[3].x = max(a.x, b.x), q[3].y = min(a.y, b.y);
	a = q[0];

	ans = 0;
	while (!eq(a, q[1])) {
		yess = 0;
		forn(i, n)
			if (dist(a, c[i]) <= r[i] + eps) {
				yess = 1;
				break;
			}
		if (!yess)
			ans++;
		a.y++;
	}
	while (!eq(a, q[2])) {
		yess = 0;
		forn(i, n)
			if (dist(a, c[i]) <= r[i] + eps) {
				yess = 1;
				break;
			}
		if (!yess)
			ans++;
		a.x++;
	}
	while (!eq(a, q[3])) {
		yess = 0;
		forn(i, n)
			if (dist(a, c[i]) <= r[i] + eps) {
				yess = 1;
				break;
			}
		if (!yess)
			ans++;
		a.y--;
	}
	while (!eq(a, q[0])) {
		yess = 0;
		forn(i, n)
			if (dist(a, c[i]) <= r[i] + eps) {
				yess = 1;
				break;
			}
		if (!yess)
			ans++;
		a.x--;
	}
	cout << ans << endl;

    return 0;
}