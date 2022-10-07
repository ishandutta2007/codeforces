#include<stdio.h>
int n,m;
double dpow(double x,int y){
	if(y==0)return 1;
	double r=dpow(x,y/2);
	r*=r;
	if(y%2==0)return r;
	return r*x;
}
int main(){
	int i;
	double ans;
	scanf("%d%d",&n,&m);
	ans=n;
	for(i=1;i<n;i++){
		ans-=dpow(((double)i)/n,m);
	}
	printf("%.10lf",ans);
}