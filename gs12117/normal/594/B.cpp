#include<stdio.h>
#include<math.h>
int n;
double r,v;
double dist;
double mabs(double x){if(x>0)return x;return -x;}
int para(double x){
	double t=x+r*mabs(2*sin(x/r/2));
	if(t>dist)return 1;
	return 0;
}
int main(){
	int i,j;
	double a,b;
	scanf("%d%lf%lf",&n,&r,&v);
	for(i=0;i<n;i++){
		scanf("%lf%lf",&a,&b);
		dist=b-a;
		a=0;
		b=1e20;
		for(j=0;j<100;j++){
			if(para(a+b)==0)a+=b;
			b/=2;
		}
		printf("%.20lf\n",a/v);
	}
}