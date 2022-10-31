#include <stdio.h>
#include <algorithm>
#define N 300010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar(),tmp=-1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int abs( int x ){ return x<0?-x:x; }
int bx[ N ] , n;
long long ans;
int main(){
	n = getint();
	for( int i=1;i<=n;i++ ) bx[i] = getint();
	std::sort( bx+1 , bx+n+1 );
	for( int i=1;i<=n;i++ ) ans += abs( bx[i]-i );
	printf("%I64d\n",ans);
}