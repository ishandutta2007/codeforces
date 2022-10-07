#include<stdio.h>
int n,l,va,vb,k;
int main(){
	int p;
	scanf("%d%d%d%d%d",&n,&l,&va,&vb,&k);
	p=(n+k-1)/k;
	double d=l*(1+((double)vb)/va);
	d/=(2*p-1+((double)vb)/va);
	double t=(l-d)/va+d/vb;
	printf("%.10lf",t);
	return 0;
}