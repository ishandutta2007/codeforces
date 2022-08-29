#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	//
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline double dis(re double a,re double b,re double c,re double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
struct point{double x,y;}p[200002],eye,h;
double ans;
inline double slope(re point x,re point y){
	return (y.y-x.y)/(y.x-x.x);
}
inline point cross(re point a,re point b,re point c,re point d){
	if(b.x==h.x)return b;
	double k2=(d.y-c.y)/(d.x-c.x),k1=(b.y-a.y)/(b.x-a.x),b1=a.y-a.x*k1,b2=c.y-c.x*k2;
	point s;
	s.x=(b2-b1)/(k1-k2);
	return (point){s.x,s.x*k1+b1};
}
int n,m,stk[200002],tp;
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=read();
	eye.x=p[n].x,eye.y=p[n].y+m,h=p[n];
	for(re int i=n-1;i;--i){
		if(slope(p[i],eye)<=slope(h,eye)){
			point x=cross(p[i],p[i+1],h,eye);
			ans+=dis(p[i].x,p[i].y,x.x,x.y);
			h=p[i];
		}
	}
	printf("%.9lf",ans);
}