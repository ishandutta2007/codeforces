#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int vx,vy,wx,wy;
int vmax,t;
int X,Y;
int check(double mid)
{
	double x,y;
	if (mid<t) x=mid*vx,y=mid*vy;
	else x=t*vx+(mid-t)*wx,y=t*vy+(mid-t)*wy;
	if (sqrt((x-X)*(x-X)+(y-Y)*(y-Y))<mid*vmax) return 1;
	return 0;
}
int main()
{
	int x1,y1,x2,y2;
	
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d",&vmax,&t);
	scanf("%d%d%d%d",&vx,&vy,&wx,&wy);
	X=x2-x1,Y=y2-y1;
	double l=0,r=1e+18;
	while (l+1e-6<r)
	{
		double mid=(l+r)/2;
		if (check(mid)) r=mid;else l=mid;
	}
	printf("%lf\n",l);
	return 0;
}