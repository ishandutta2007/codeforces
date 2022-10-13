#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int greaterThanZero(double x)
{
	return x>1e-8;
}

double dist(double x,double y,double A,double B,double C)
{
	return fabs((A*x+B*y+C)/sqrt(A*A+B*B));
}

int ok(double ymid,double y1,double y2,double yw,double xb,double yb,double r,double &xtarget,int &valid)
{
	double ysym=yw*2-yb, A=ymid-ysym, B=xb, C=-B*ymid;
	xtarget=(-B*yw-C)/A;
	
	double d1=dist(0,y2,A,B,C),d2=fabs(y1-ymid);
	if (greaterThanZero(d1-r) && greaterThanZero(d2-r)) valid=1;
	else valid=0;
	if (d1<d2) return 1;
	return -1;
}

int main()
{
	double y1,y2,yw,xb,yb,r;
	cin >> y1 >> y2 >> yw >> xb >> yb >> r;
	
	double yhigh=y2-r,ylow=y1+r;
	yw-=r;
	
	rep(it,1000)
	{
		double ymid=(yhigh+ylow)/2,xtarget;
		int u,t=ok(ymid,y1,y2,yw,xb,yb,r,xtarget,u);
		if (t>0) yhigh=ymid;
		else ylow=ymid;
	}
	
	int u;
	double xtarget;
	ok(ylow,y1,y2,yw,xb,yb,r,xtarget,u);
	if (u) printf("%.12lf\n",xtarget);
	else puts("-1");
}