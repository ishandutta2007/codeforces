#include <bits/stdc++.h>
using namespace std;

struct Point{
	double x, y;
	Point(double ix = 0, double iy = 0){
		x = ix; y = iy;
	}
};

Point operator+(Point a, Point b){
	return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b){
	return Point(a.x - b.x, a.y - b.y);
}

Point operator*(double k, Point a){
	return Point(k*a.x, k*a.y);
}

double cross(Point a, Point b){
	return a.x*b.y - a.y*b.x;
}

double dot(Point a, Point b){
	return a.x*b.x + a.y*b.y;
}

const int N = 100004;
const double EPS = 1e-9;
const double PI = acos(-1.0);

double area[N];
int n, q, nxt[N];
Point center, p[N];

double getArea(Point a, Point b){
	return (b.x - a.x)*(a.y + b.y)/2;
}

double getAreaRange(int l, int r){
	if(l == r)return 0.0;
	if(l > r)r += n;
	if(l == 0)return area[r - 1];
	return area[r - 1] - area[l - 1];
}

bool getIntersection(Point a, Point b, Point dir, Point &u){
	double a11 = b.x - a.x;
	double a21 = b.y - a.y;
	double a12 = -dir.x;
	double a22 = -dir.y;
	double det = a11*a22 - a12*a21;
	if(abs(det) < EPS)return false;
	double t = ((center.y - a.y)*a11 - (center.x - a.x)*a21)/det;
	u = center + t*dir;
	return true;
}

void getPolygonRayIntersection(Point dir, int &ind, Point &u){
	double val = cross(p[0] - center, dir);
	if(abs(val) < EPS){
		if(dot(p[0] - center, dir) > 0){
			ind = 0;
			u = p[0];
			return;
		}
		int lo = 1, hi = n - 1;
		while(lo < hi){
			int mi = (lo + hi + 1)/2;
			double tmp = cross(p[mi] - center, dir);
			if(abs(tmp) < EPS){
				lo = hi = mi;
				break;
			}
			if(tmp > 0)lo = mi;
			else hi = mi - 1;
		}
		ind = lo;
	}else if(val > 0){
		int lo = 0, hi = n - 1;
		while(lo < hi){
			int mi = (lo + hi + 1)/2;
			double tmp = cross(p[mi] - center, dir);
			if(abs(tmp) < EPS){
				if(dot(p[mi] - center, dir) > 0){
					lo = hi = mi;
					break;
				}else{
					hi = mi - 1;
				}
			}else if(tmp < 0){
				hi = mi - 1;
			}else if(cross(p[0] - center, p[mi] - center) > 0){
				lo = mi;
			}else{
				hi = mi - 1;
			}
		}
		ind = lo;
	}else{
		int lo = 0, hi = n - 1;
		while(lo < hi){
			int mi = (lo + hi + 1)/2;
			double tmp = cross(p[mi] - center, dir);
			if(abs(tmp) < EPS){
				if(dot(p[mi] - center, dir) > 0){
					lo = hi = mi;
					break;
				}else{
					lo = mi;
				}
			}else if(tmp > 0){
				lo = mi;
			}else if(cross(p[0] - center, p[mi] - center) > 0){
				lo = mi;
			}else{
				hi = mi - 1;
			}
		}
		ind = lo;
	}
	getIntersection(p[ind], p[nxt[ind]], dir, u);
}

double getAreaDiff(double ang){
	Point u, v;
	int up, dw;
	double cosang = cos(ang);
	double sinang = sin(ang);
	Point dir(cosang, sinang);
	getPolygonRayIntersection(dir, up, u);
	dir.x = -cosang; dir.y = -sinang;
	getPolygonRayIntersection(dir, dw, v);
	double ret = getAreaRange(nxt[up], dw) + getArea(p[dw], v) + getArea(v, u) + getArea(u, p[nxt[up]]);
	ret = ret*2 - area[n - 1];
	return ret;
}

double query(double x, double y){
	double lo = 0, hi = PI;
	center.x = x; center.y = y;
	double areadiffref = getAreaDiff(lo);
	if(abs(areadiffref) < EPS)return lo;
	for(int it = 0; it < 40; it++){
		double mi = (lo + hi)/2;
		double areadiffmi = getAreaDiff(mi);
		if(abs(areadiffmi) < EPS)return mi;
		if(areadiffref > 0){
			if(areadiffmi > 0){
				lo = mi;
			}else{
				hi = mi;
			}
		}else{
			if(areadiffmi < 0){
				lo = mi;
			}else{
				hi = mi;
			}
		}
	}
	return lo;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
		nxt[i] = (i + 1)%n;
	}
	reverse(p, p + n);
	for(int i = 0; i < 2*n; i++){
		area[i] = getArea(p[i%n], p[(i + 1)%n]);
		if(i)area[i] += area[i - 1];
	}
	cout << setprecision(30);
	while(q--){
		double x, y;
		cin >> x >> y;
		cout << query(x, y) << '\n';
	}

	return 0;
}