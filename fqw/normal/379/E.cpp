#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const double EPS=1e-8;

int sgn(double x, double e=EPS) {
	return x<-e ? -1 : x>e;
}

struct Point {
	double x, y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	friend double mult(const Point &p1, const Point &p2) {
		return p1.x*p2.y-p1.y*p2.x;
	}
	friend double mult(const Point &p0, const Point &p1, const Point &p2) {
		return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
	}
};

double ans[333];
int py[333][333];
int n, k;

void cut(vector<Point> &a, Point p1, Point p2) {
	vector<Point> b;
	forn(i, a.size()) {
		Point a1=a[i], a2=a[(i+1)%a.size()];
		double m1=mult(p1, p2, a1);
		double m2=mult(p1, p2, a2);
		if(sgn(m1)*sgn(m2)<0) {
			Point tmp;
			tmp.x=(a1.x*m2-a2.x*m1)/(m2-m1);
			tmp.y=(a1.y*m2-a2.y*m1)/(m2-m1);
			b.push_back(tmp);
		}
		if(sgn(m2)>=0) b.push_back(a2);
	}
	a=b;
}

vector<Point> po[333];

double cal(int cur, int ind) {
	vector<Point> a=po[ind];
	Point p1=Point(ind-1, py[cur][ind-1]);
	Point p2=Point(ind, py[cur][ind]);
	cut(po[ind], p1, p2);
	cut(a, p2, p1);
	double ans=0;
	forint(i, 1, a.size()-1) ans+=mult(a[0], a[i-1], a[i]);
	ans=abs(ans)/2.;
	return ans;
}

int main() {
	scanf("%d%d", &n,&k);
	forint(i, 1, n) forint(j, 0, k) scanf("%d", &py[i][j]);
	fillchar(ans, 0);
	forint(i, 1, k) {
		po[i].clear();
		po[i].PB(Point(i-1, 0));
		po[i].PB(Point(i, 0));
		po[i].PB(Point(i, 1000));
		po[i].PB(Point(i-1, 1000));
	}
	forint(i, 1, n) forint(j, 1, k)
		ans[i]+=cal(i, j);
	forint(i, 1, n) printf("%.9lf\n", ans[i]);

	return 0;
}