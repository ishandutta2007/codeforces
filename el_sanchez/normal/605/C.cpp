#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

struct pt {
	ld x, y;
	pt(): x(0), y(0) {}
	pt(ld _x, ld _y) {
		x = _x, y = _y;
	}
};              

struct line {
	ld a, b, c;
	line(): a(0), b(0), c(0) {}
	line(ld x, ld y, ld z) {
		a = x, b = y, c = z;
	}
};

bool eq(ld a, ld b) {
	return (fabs(a - b) < eps);
}

bool eq(pt a, pt b) {
	return eq(a.x, b.x) && eq(a.y, b.y);
}

bool operator==(pt a, pt b) {
	return a.x == b.x && a.y == b.y;
}

inline bool operator<(pt a, pt b) {
	return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}

pt operator-(pt p1, pt p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

pt operator+(pt p1, pt p2) {
	return pt(p1.x + p2.x, p1.y + p2.y);
}

pt operator*(pt a, ld b) {
	return pt(a.x * b, a.y * b);
}

pt operator/(pt a, ld b) {
	return pt(a.x / b, a.y / b);
}

ld len(pt a) {
	return sqrt(.0 + a.x * a.x + a.y * a.y);
}

ld dist(pt p1, pt p2) {
	return len(p1 - p2);
}

ld operator*(pt p1, pt p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

ld operator%(pt p1, pt p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

inline bool cmp(pt a, pt b) {
	if (a % b != 0)
		return a % b > 0;
	return len(a) < len(b);
}

bool intersect_p(ld a, ld b, ld c, ld d) {
	return max(a, b) >= min(c, d) && max(c, d) >= min(a, b);
}

line segmentToLine(pt p1, pt p2) {
	ld a = p1.y - p2.y, b = p2.x - p1.x;
	return line(a, b, -(a * p1.x + b * p1.y));
}

bool intersect(pt a, pt b, pt c, pt d) {
	ld v1 = (b - a) % (c - a); //sin(ab, ac)
	ld v2 = (b - a) % (d - a); //sin(ab, ad)
	ld v3 = (d - c) % (a - c); //sin(cd, ca)
	ld v4 = (d - c) % (b - c); //sin(cd, cb)
	if (eq(v1, 0) && eq(v2, 0) && eq(v3, 0) && eq(v4, 0)) //in the same line?
		return intersect_p(a.x, b.x, c.x, d.x) && intersect_p(a.y, b.y, c.y, d.y); //proections
	else
		return (v1 * v2 <= 0) && (v3 * v4 <= 0);
}

bool parallel(line m, line n) {
	return eq(m.a * n.b - m.b * n.a, 0);
}

bool equivalent(line m, line n) {
	return parallel(m, n) && eq(m.a * n.c - m.c * n.a, 0) && eq(m.b * n.c - m.c * n.b, 0);
}

int linesIntersection(line m, line n, pt &res) {
	if (parallel(m, n)) {
		if (equivalent(m, n))
			return 2;
		else
			return 0;
	}		
	ld sign = m.a * n.b - m.b * n.a;
	res.x = (m.b * n.c - m.c * n.b) / sign;
	res.y = (m.c * n.a - m.a * n.c) / sign;
	return 1;
}

int segmentsIntersection(pt a, pt b, pt c, pt d, pt &p1, pt &p2) {
	if (!intersect(a, b, c, d))
		return 0;
	line l1 = segmentToLine(a, b), l2 = segmentToLine(c, d);
	if (!equivalent(l1, l2)) {
		linesIntersection(l1, l2, p1);
		return 1;
	}
	vector<pt> p;
	p.push_back(a);
	p.push_back(b);
	p.push_back(c);
	p.push_back(d);
	sort(p.begin(), p.end());
	p1 = p[1], p2 = p[2];
	if (eq(p1, p2))
		return 1;
	return 2;
}

int n, sz, mx, my;
pt O, S, T, p1, p2;
pt a[MAXN], p[MAXN];

int main() {
	
	O = pt(0, 0);
	
	cin >> n >> S.x >> S.y;
	mx = my = 0;
	forn(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		mx = max(mx, x);
		my = max(my, y);
		a[i] = pt(x, y);
	}
	a[n++] = pt(mx, 0);
	a[n++] = pt(0, my);
	a[n++] = O;
	
	sort(a, a + n);
	n = unique(a, a + n) - a;
	
	sz = 0;
	p[sz++] = a[0];
	sort(a + 1, a + n, cmp);

	for (int i = 1; i < n; i++) {
		while (sz > 1 && (p[sz - 1] - p[sz - 2]) % (a[i] - p[sz - 1]) <= eps)
			sz--;
		p[sz++] = a[i];
	}
	
	T = S * INF;
	
	for (int i = 1; i < sz - 1; i++) {
		if (segmentsIntersection(O, T, p[i], p[i + 1], p1, p2) > 0) {
			ld res = len(S) / len(p1);
			cout << fixed << setprecision(20) << res << '\n';
			return 0;
		}
	}
	
	assert(false);
	
	return 0;
}