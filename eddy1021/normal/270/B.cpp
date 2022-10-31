#include <stdio.h>
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[N],n;
int main(){
	n = getint(); bx[0] = n+1;
	for( int i=1;i<=n;i++ ) bx[i] = getint();
	for( int j=n;j;j-- ) if( bx[j]<bx[j-1] ){ printf("%d\n",j-1); break; }
}