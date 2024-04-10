#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
#define N 25005
const double inf=1e60;
const double eps=1e-7;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,s[N];
double ans;
struct Point{
	double x,y;
	Point(){} Point(double _x,double _y){x=_x,y=_y;}
	inline double operator %(const Point b){
		return x*b.y-y*b.x;
	}
	inline Point operator +(const Point b){
		return Point(x+b.x,y+b.y);
	}
	inline Point operator -(const Point b){
		return Point(x-b.x,y-b.y);
	}
	inline double operator *(const Point b){
		return x*b.x+y*b.y;
	}
	inline Point operator *(const double gu){
		return Point(x*gu,y*gu);
	}
	inline double len2(){
		return x*x+y*y;
	}
}h[N];
struct Line{
	Point p[2];
	Line(){} Line(Point a,Point b){p[0]=a,p[1]=b;}	
	inline Point & operator [](const int x){
		return p[x];
	}
	inline Point v(){
		return p[1]-p[0];
	}
}L[N];
inline bool Para(Point a,Point b){
	return fabs(a%b)<eps;
}
inline Point Cross(Line a,Line b){
	return a[0]+(a[1]-a[0])*(((b[0]-a[0])%(b[1]-a[0]))/((a[1]-a[0])%(b[1]-b[0])));
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),dx=read(),dy=read();
		s[i]=read();
		h[i]=Point(dx,dy);
		L[i]=Line(Point(x,y),h[i]+Point(x,y));
	}
	ans=inf;
	for(register int i=1;i<=n;++i){
		for(register int j=i+1;j<=n;++j){
			if(Para(h[i],h[j])){
				if(!Para(h[i],L[i][0]-L[j][0]))continue;
				if((L[i][1].x<=L[i][0].x)^(L[j][0].x<=L[i][0].x)){
					if((L[j][1].x<=L[j][0].x)^(L[i][0].x<=L[j][0].x)){
						continue;
					}
					else{
						ans=min(ans,(L[i][0]-L[j][0]).len2()/(s[j]*s[j]));
					}
				}
				else{
					if((L[j][1].x<=L[j][0].x)^(L[i][0].x<=L[j][0].x)){
						ans=min(ans,(L[i][0]-L[j][0]).len2()/(s[i]*s[i]));
					}
					else{
						ans=min(ans,(L[i][0]-L[j][0]).len2()/((s[i]+s[j])*(s[i]+s[j])));
					}
				}
			}
			else{
				Point in=Cross(L[i],L[j]);
				if((in-L[i][0])*h[i]<0||(in-L[j][0])*h[j]<0)continue;
				ans=min(ans,max((in-L[i][0]).len2()/(s[i]*s[i]),(in-L[j][0]).len2()/(s[j]*s[j])));
			}
		}
	}
	if(ans>=inf-eps){
		printf("No show :(\n");
	}
	else{
		printf("%.10lf\n",sqrt(ans));
	}
	return 0;
}