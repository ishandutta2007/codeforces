#include <stdio.h>
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int n,k,l,r,sum;
int main(){
	n = getint(); k = getint();
	while( n -- ){
		l = getint(); r = getint();
		sum += r - l + 1;
	}
	sum %= k; if( !sum ) sum = k;
	printf("%d\n",k-sum);
}