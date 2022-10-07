#include<stdio.h>
int a,b,c,d;
int f(double s){
	double maxp,maxq,minp,minq;
	maxp=(a+s)*(d+s);
	minp=(a+s)*(d+s);
	if(maxp<(a+s)*(d-s))maxp=(a+s)*(d-s);
	if(minp>(a+s)*(d-s))minp=(a+s)*(d-s);
	if(maxp<(a-s)*(d+s))maxp=(a-s)*(d+s);
	if(minp>(a-s)*(d+s))minp=(a-s)*(d+s);
	if(maxp<(a-s)*(d-s))maxp=(a-s)*(d-s);
	if(minp>(a-s)*(d-s))minp=(a-s)*(d-s);
	maxq=(b+s)*(c+s);
	minq=(b+s)*(c+s);
	if(maxq<(b+s)*(c-s))maxq=(b+s)*(c-s);
	if(minq>(b+s)*(c-s))minq=(b+s)*(c-s);
	if(maxq<(b-s)*(c+s))maxq=(b-s)*(c+s);
	if(minq>(b-s)*(c+s))minq=(b-s)*(c+s);
	if(maxq<(b-s)*(c-s))maxq=(b-s)*(c-s);
	if(minq>(b-s)*(c-s))minq=(b-s)*(c-s);
	if(minq>maxp)return 1;
	if(minp>maxq)return 1;
	return 0;
}
int main(){
	int i;
	double x,y;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x=0;
	y=1e18;
	for(i=0;i<200;i++){
		if(f((x+y)/2)==1){
			x=(x+y)/2;
		}
		else{
			y=(x+y)/2;
		}
	}
	printf("%.15lf",x);
}