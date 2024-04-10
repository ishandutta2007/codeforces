#include <stdio.h>
#define max(x,y) (x>y?x:y)
int n,h,m,ph,pm,Min,tmin;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n=getint(); Min=0; tmin=1;
	ph=getint(); pm=getint();
	while( --n ){
		h=getint(); m=getint();
		if( h==ph&&m==pm ) tmin++;
		else ph=h,pm=m,Min=max(Min,tmin),tmin=1;
	}
	Min=max(Min,tmin);
	printf("%d\n",Min);
}