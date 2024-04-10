#include<stdio.h>
int n,i,a,b,c;
double d;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		b+=a;
		c++;
		if(d<(double)b/c)d=(double)b/c;
	}
	printf("%lf",d);
}