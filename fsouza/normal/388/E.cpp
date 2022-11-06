#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <cmath>

#define INF (INT_MAX/2)
#define MAXN 1100

typedef long long lint;

using namespace std;

/**/

const double E = 1e-6;
const double PI = 2*acos(0);

struct p3d {
	double x, y, z;
	p3d(): x(0), y(0), z(0) {}
	p3d(double x, double y): x(x), y(y), z(0) {}
	p3d(double x, double y, double z): x(x), y(y), z(z) {}
	p3d operator+(const p3d& o) const {return p3d(x+o.x, y+o.y, z+o.z);}
	p3d operator-(const p3d& o) const {return p3d(x-o.x, y-o.y, z-o.z);}
	p3d operator*(const double m) const {return p3d(x*m, y*m, z*m);}
	p3d operator/(const double m) const {return p3d(x/m, y/m, z/m);}
	void operator/=(const double m) {x /= m, y /= m, z /= m;}
	void operator*=(const double m) {x *= m, y *= m, z *= m;}
	void operator-=(const p3d& o) {x -= o.x, y -= o.y, z -= o.z;}
	void operator+=(const p3d& o) {x += o.x, y += o.y, z += o.z;}
	bool operator < (const p3d &o) const {
		if (fabs(x - o.x) > E) return x < o.x;
		if (fabs(y - o.y) > E) return y < o.y;
		if (fabs(z - o.z) > E) return z < o.z;
		return false;
	}
} Orig(0,0,0);
p3d operator *(double m, const p3d& p) {return p*m;}
p3d operator -(const p3d& p) {return Orig-p;}

struct l3d {
	p3d P, v;
	l3d(): P(0, 0, 0), v(1, 0, 0) {}
	l3d(const p3d& P, const p3d& v): P(P), v(v) {}
	p3d A() const {return P;}
	p3d B() const {return P+v;}
};
double abs(const p3d& v) {return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);}
double dist_pp(const p3d& p, const p3d& p2) {return abs(p-p2);}

double dot(const p3d& a, const p3d& b) {return a.x*b.x + a.y*b.y + a.z*b.z;}
p3d cross(const p3d& a, const p3d& b) {return p3d(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);}

p3d proj(const p3d& p, const p3d& over) {return over * dot(p,over)/dot(over,over);}

p3d line_line_intersection(const l3d& A, const l3d& B)
{
	p3d v1 = cross(A.v, B.v), v2 = cross(B.P - A.P, B.v);
	return A.P + A.v * (dot(v2, v1)/dot(v1, v1));
}
p3d closest_point(l3d to, const l3d& from) {
	if (abs(cross(to.v, from.v)) < E) return from.P;
	p3d ll = proj(to.P - from.P, cross(to.v, from.v));
	to.P -= ll;
	return line_line_intersection(to, from);
}

l3d make_seg(const p3d& a, const p3d& b) {return l3d(a, b-a);}
l3d p2p_line(const p3d& a, const p3d& b) {return make_seg(a, b);}

/**/

struct relation4 {
	double val[4];
	relation4() {}
	relation4(double a, double b, double c, double d) {val[0] = a, val[1] = b, val[2] = c, val[3] = d; canonize();}
	void canonize() {
		for (int i = 0; i < 4; i++)
			if (fabs(val[i]) > E) {
				const double norm = val[i];
				for (int j = 0; j < 4; j++) val[j] /= norm;
				break;
			}
	}
	bool operator < (const relation4 &o) const {
		for (int i = 0; i < 4; i++) if (fabs(val[i] - o.val[i]) > E) return val[i] < o.val[i];
		return false;
	}
};

l3d lines[MAXN];
relation4 directors[MAXN];

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x0, y0, z0, x1, y1, z1;
		scanf("%d %d %d %d %d %d", &x0, &y0, &z0, &x1, &y1, &z1);
		lines[i] = p2p_line(p3d(x0, y0, z0), p3d(x1, y1, z1));
		directors[i] = relation4(0.0, x1-x0, y1-y0, z1-z0);
	}

	map <relation4, set<relation4> > planes;
	map <p3d, set<int> > points;
	int result = min(1, n);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++) {
			p3d c = cross(lines[i].v, lines[j].v);
			if (abs(c) > E) {
				p3d pi = closest_point(lines[i], lines[j]);
				p3d pj = closest_point(lines[j], lines[i]);
				if (dist_pp(pi, pj) < E) {
					p3d p = (pi+pj)/2.0;
					relation4 plane = relation4(c.x, c.y, c.z, -(c.x * p.x + c.y * p.y + c.z * p.z));

					points[p].insert(i);
					points[p].insert(j);

					planes[plane].insert(directors[i]);
					planes[plane].insert(directors[j]);
				}
			}
		}

	for (map <p3d, set<int> >::iterator it = points.begin(); it != points.end(); it++)
		result = max(result, (int)(it -> second).size());

	for (map <relation4, set<relation4> >::iterator it = planes.begin(); it != planes.end(); it++)
		result = max(result, (int)(it -> second).size());

	printf("%d\n", result);

	return 0;
}