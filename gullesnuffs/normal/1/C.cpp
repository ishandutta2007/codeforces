#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Point {
	typedef T coordType;
	typedef Point P;
	typedef const P & R;
	T x, y;
	explicit Point(T x=T(), T y=T()) : x (x), y( y) {}
	P operator+(R p) const { return P(x+p.x, y+p.y); }
	P operator-(R p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const {return P(x/d, y/d); }
	T cross(R p) const { return x*p.y - y*p.x; }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	P perp() const { return P(-y, x); }
	double ang() const { return atan2(y, x); }

};

template <class T>
istream & operator>>(istream & is, Point<T> & p) {
	is >> p.x >> p.y;
	return is;
}

template <class P>
double ccRadius(const P& A, const P& B, const P& C) {
	return (B-A).dist()*(C-B).dist()*(A-C).dist()/abs((B-A).cross(C-A))/2;
}

template <class P>
P ccCenter(const P& A, const P& B, const P& C) {
	P b = C-A, c=B-A;
	return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

double PI = 3.14159265358979F;
double eps = 1e-6F;

int main(){
	Point<double> points[3];
	for(int i=0; i < 3; ++i)
		cin >> points[i];
	Point<double> center = ccCenter(points[0], points[1], points[2]);
	double ang[3];
	for(int i=0; i < 3; ++i){
		ang[i]=(points[i]-center).ang();
		while(ang[i] < -eps)
			ang[i] += 2*PI;
	}
	for(int n=3; true; ++n){
		bool ok=1;
		for(int j=1; j < 3; ++j){
			int k;
			for(k=0; k < n; ++k){
				double a=ang[0]+k*2.0*PI/n;
				while(a < eps)
					a += 2*PI;
				while(a >= 2*PI-eps)
					a -= 2*PI;
				if(a < ang[j] + 1e-5F && a > ang[j] - 1e-5F)
					break;
			}
			if(k == n)
				ok=0;
		}
		if(ok){
			double r=ccRadius(points[0], points[1], points[2]);
			double area=n*sin(2*PI/n)*r*r/2.0;
			printf("%.7lf\n", area);
			return 0;
		}
	}
}