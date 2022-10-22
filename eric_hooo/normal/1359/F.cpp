#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define double long double
using namespace std;

typedef pair <double, int> pdi;

const double EPS = 1e-11;

int sgn(double x) {return x < -EPS ? -1 : x > EPS;}

int cmp(double x, double y) {return sgn(x - y);}

struct Point {
	double x, y;
	void read() {scanf("%Lf%Lf", &x, &y);}
	Point() {x = y = 0;}
	Point(double X, double Y) {x = X, y = Y;}
	double len() const {return sqrt(x * x + y * y);}
	Point operator + (const Point &A) const {return Point(x + A.x, y + A.y);}
	Point operator - (const Point &A) const {return Point(x - A.x, y - A.y);}
	Point operator / (const double &k) const {return Point(x / k, y / k);}
	Point operator * (const double &k) const {return Point(x * k, y * k);}
	double operator ^ (const Point &A) const {return x * A.y - y * A.x;}
	bool operator < (const Point &A) const {
		int tmp = cmp(x, A.x);
		return tmp == -1 || !tmp && cmp(y, A.y) == -1;
	}
	bool operator <= (const Point &A) const {
		int tmp = cmp(x, A.x);
		return tmp == -1 || !tmp && cmp(y, A.y) <= 0;
	}
};

struct Line {
	Point p, q;
	Line() {}
	Line(Point P, Point Q) {p = P, q = Q;}
	Point operator * (const Line &A) const {
		double l1 = A.p - p ^ q - p, l2 = q - p ^ A.q - p;
		return (A.p * l2 + A.q * l1) / (l1 + l2);
	}
	Point dir() const {return q - p;}
	bool cover(const Point &A) const {
		return fabs(A - p ^ A - q) <= max({fabs(A.x), fabs(A.y), fabs(p.x), fabs(p.y), fabs(q.x), fabs(q.y), (double)1.0}) * EPS && p <= A && A <= q;
	}
	bool cover(const Line &A) const {return cover(A.p) || cover(A.q);}
	double gety(double x) const {return p.y + (q.y - p.y) / (q.x - p.x) * (x - p.x);}
};

Point a[25010], dir[25010];
double V[25010];
int n;
vector <Line> seg;
vector <pdi> event;
double Tim;

struct SetCmp {
	bool operator () (const int &x, const int &y) const {
		// return x < y;
		int tmp = cmp(Line(a[x], a[x] + dir[x]).gety(Tim), Line(a[y], a[y] + dir[y]).gety(Tim));
		return tmp == -1 || tmp == 0 && x < y;
	}
};

bool Check(int x, int y) {
	if (fabs(seg[x].dir() ^ seg[y].dir()) <= EPS) return seg[x].cover(seg[y]) || seg[y].cover(seg[x]);
	Point tmp = seg[x] * seg[y];
	return seg[x].cover(tmp) && seg[y].cover(tmp);
}

set <int, SetCmp> S;

void AddSegment(Point a, Point b) {
	if (b < a) swap(a, b);
	event.push_back(mp(a.x, (int)seg.size()));
	event.push_back(mp(b.x, ~(int)seg.size()));
	seg.push_back(Line(a, b));
}

bool Check(double mid) {
	seg.clear(), event.clear();
	for (int i = 0; i < n; i++) {
		AddSegment(a[i], a[i] + dir[i] / dir[i].len() * V[i] * mid);
	}
	sort(event.begin(), event.end(), [&](pdi x, pdi y) -> bool {return cmp(x.fi, y.fi) == -1;});
	S.clear();
	int cnt = 0;
	for (auto it : event) {
		if (S.size() != cnt) return 1;
		// assert(S.size() == cnt);
		if (it.se < 0) {
			cnt--;
			Tim = it.fi - EPS;
			SetCmp tmp;
			int id = ~it.se;
			S.erase(id);
			auto it = S.lower_bound(id);
			int suc = it == S.end() ? -1 : *it, pre = it == S.begin() ? -1 : *--it;
			if (suc != -1 && pre != -1 && Check(suc, pre)) return 1;
		} else {
			cnt++;
			Tim = it.fi - EPS;
			int id = it.se;
			auto it = S.lower_bound(id);
			int suc = it == S.end() ? -1 : *it, pre = it == S.begin() ? -1 : *--it;
			if (suc != -1 && Check(suc, id)) return 1;
			if (pre != -1 && Check(pre, id)) return 1;
			SetCmp tmp;
			S.insert(id);
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i].read(), dir[i].read(), scanf("%Lf", &V[i]);
	}
	double M = 0.00001;
	while (M <= 1e11 && !Check(M)) M *= 2;
	if (M >= 9e10) {
		printf("No show :(\n");
		return 0;
	}
	double l = 0, r = M;
	while (l + 1e-6 < r) {
		double mid = (l + r) / 2;
		if (Check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10Lf\n", l);
	return 0;
}