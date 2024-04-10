#include <stdio.h>
#include <algorithm>
#define N 51
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[N],n,k;
int main(){
	n = getint(); k = getint();
	if( k>n ) return puts("-1"),0;
	if( k==n ) return puts("0 0"),0;
	for( int i=0;i<n;i++ ) bx[i] = getint();
	std::sort( bx , bx+n );
	if( bx[n-k-1] == bx[n-k] ) return puts("-1"),0;
	printf("%d %d\n",bx[n-k-1],bx[n-k]);
}