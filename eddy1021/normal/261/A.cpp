#include <stdio.h>
#include <algorithm>
#define N 100010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar(),tmp=-1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int m,n,min,bx[N],tmp,cst,buy;
int main(){
	m = getint(); min = 0x7fffffff;
	while( m-- ){
		tmp = getint(); if( tmp<min ) min = tmp;
	}
	n = getint();
	for( int i=0;i<n;i++ ) bx[i] = getint();
	std::sort( bx , bx+n );
	for( int i=n-1;i>=0;i-- ){
		cst += bx[i]; buy++;
		if( buy==min ) i -= 2,buy = 0;
	}
	printf("%d\n",cst);
}