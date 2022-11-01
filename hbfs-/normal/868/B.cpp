#include<stdio.h>
#include<algorithm>
using namespace std;

int h,m,s,t1,t2;
double p1,p2,p3,P1,P2,pi=3.1415926535;

int solve()
{
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	p3=2*pi/60*s;
	p2=2*pi/60*m+p3/60;
	p1=2*pi/12*h+p2/60;
	P1=2*pi/12*t1;
	P2=2*pi/12*t2;
	if (2*pi<p1+0.00001) p1-=2*pi;
	if (2*pi<p2+0.00001) p2-=2*pi;
	if (2*pi<p3+0.00001) p3-=2*pi;
	if (2*pi<P1+0.00001) P1-=2*pi;
	if (2*pi<P2+0.00001) P2-=2*pi;
	if (P2<P1) swap(P1,P2);
	return ((P1<p1 && p1<P2)&&(P1<p2 && p2<P2)&&(P1<p3 && p3<P2))||((p1<P1 || P2<p1)&&(p2<P1 || P2<p2)&&(p3<P1 || P2<p3));
}

int main()
{
	printf(solve()?"YES":"NO");
}