#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define y1 ysgh
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
double a,b,c,x1,y1,x2,y2,ans;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x,y=_y;}
}p[5],S,T;
double Gety(double x){
	return (-c-a*x)/b;
}
double Getx(double y){
	return (-c-b*y)/a;
}
double Dis1(Point a,Point b){
	return fabs(a.x-b.x)+fabs(a.y-b.y);
}
double Dis2(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	a=read(),b=read(),c=read();
	x1=read(),y1=read(),x2=read(),y2=read();
	S=Point(x1,y1),T=Point(x2,y2);
	ans=Dis1(S,T);
	p[1].x=x1,p[1].y=Gety(p[1].x);
	p[2].x=x2,p[2].y=Gety(p[2].x);
	p[3].y=y1,p[3].x=Getx(p[3].y);
	p[4].y=y2,p[4].x=Getx(p[4].y);
	for(int i=1;i<=4;++i){
		for(int j=1;j<=4;++j){
			if(i==j)continue;
			ans=min(ans,Dis1(S,p[i])+Dis2(p[i],p[j])+Dis1(p[j],T));
		}
	} 
	printf("%.10lf\n",ans);
	return 0;
}