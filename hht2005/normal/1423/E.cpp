#include<bits/stdc++.h>
using namespace std;
const double eps=1e-14;
const int maxn=1000010;
struct Point {
	double x,y;
	Point(double xx=0,double yy=0) {
		x=xx,y=yy;
	}
	Point operator-(const Point &a)const {
		return Point(x-a.x,y-a.y);
	}
	Point operator+(const Point &a)const {
		return Point(x+a.x,y+a.y);
	}
	double operator*(const Point &a)const {
		return x*a.y-a.x*y;
	}
	double operator^(const Point &a)const {
		return x*a.x+a.y*y;
	}
	Point operator/(const double &a)const {
		return Point(x/a,y/a);
	}
	Point operator*(const double &a)const {
		return Point(x*a,y*a);
	}
};
typedef Point Vector;
struct Line {
	Point p;
	Vector v;
	Line() {}
	Line(Point pp,Vector vv) {
		p=pp,v=vv;
	}
};
Point jiao(Line a,Line b) {
	Vector v=a.p-b.p;
	double t=(b.v*v)/(a.v*b.v);
	return a.p+a.v*t;
}
double getdis(Point a,Point b) {
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
vector<Point>P[maxn];
int pos[maxn];
double area[maxn],w,h,r;
int check(Point p,Point a,Point b) {
	if(abs(a.y-b.y)<eps)return 0;
	if(a.y>b.y)swap(a,b);
	Point P=jiao(Line(a,(b-a)/getdis(a,b)),Line(p,Point(1,0)));
	if(P.x<p.x+eps)return 0;
	if(P.y>=a.y+eps&&P.y<=b.y-eps)return 1;
	if(P.y<=a.y-eps||P.y>=b.y+eps)return 0;
	if(abs(P.y-a.y)<eps)return 1;
	return 0;
}
int in(int i,Point p) {
	int cnt=0;
	for(int j=1;j<int(P[i].size());j++)
		if(check(p,P[i][j-1],P[i][j]))cnt++;
	if(check(p,*P[i].rbegin(),P[i][0]))cnt++;
	return cnt&1;
}
int check(int i,Point o) {
	for(int j=0;j<int(P[i].size()-1);j++) {
		if(getdis(P[i][j],o)<=r+eps)return 1;
		if(((o-P[i][j])^(P[i][j+1]-P[i][j]))>eps&&((o-P[i][j+1])^(P[i][j]-P[i][j+1]))>eps)
			if(abs((P[i][j]-o)*(P[i][j+1]-o))<=r*getdis(P[i][j],P[i][j+1])+eps)return 1;
	}
	return in(i,o);
}
int main() {
	int n,q,k;
	Point lp,np,sp;
	scanf("%lf%lf%d",&w,&h,&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&k),k--;
		scanf("%lf%lf",&sp.x,&sp.y);
		lp=sp;
		P[i].push_back(sp);
		while(k--) {
			scanf("%lf%lf",&np.x,&np.y);
			P[i].push_back(np);
			area[i]+=lp*np;
			lp=np;
		}
		P[i].push_back(sp);
		area[i]+=lp*sp;
		area[i]/=2;
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%lf%lf%lf",&np.x,&np.y,&r);
		int cnt=0;
		double sum=0;
		for(int i=1;i<=n;i++)
			if(check(i,np)) {
				pos[++cnt]=i;
				sum+=area[i];
			}
		printf("%.8f %d",sum,cnt);
		for(int i=1;i<=cnt;i++)
			printf(" %d",pos[i]-1);
		puts("");//awdesfrdgtf
	}
	return 0;
}