#include <stdio.h>
#include <algorithm>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,bx[60],tk;
int main(){
	n=getint(); tk=getint();
	for( int i=0;i<n;i++ ) bx[i]=getint();
	std::sort( bx , bx+n );
	for( int i=0;i<n;i++ ) for( int j=0;j<n-i;j++ ){
		printf("%d %d",i+1,bx[j]);
		for( int k=0;k<i;k++ ) printf(" %d",bx[n-k-1]);
		puts(""); tk--; if( !tk ) return 0;
	}
}