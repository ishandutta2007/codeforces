#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define y1 ysgh
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
double R,x1,y1,x2,y2,r,x3,y3;
int main(){
	R=read(),x1=read(),y1=read(),x2=read(),y2=read();
	double L=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	if(L>=R*R){
		r=R,x3=x1,y3=y1;
	}
	else if(x1==x2&&y1==y2){
		r=R/2.0;
		x3=x1+R/2.0;
		y3=y1;
	}
	else{
		L=sqrt(L);
		r=(L+R)/2;
		x3=(x1-x2)/L*(L+R)+x2;
		y3=(y1-y2)/L*(L+R)+y2;
		x3=(x3+x2)/2;
		y3=(y3+y2)/2;
	}
	printf("%.10lf %.10lf %.10lf\n",x3,y3,r);
	return 0;
}