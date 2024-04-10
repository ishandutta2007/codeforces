#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,l,r,sl,sr;
int main(){
	n=getint();
	for( int i=0;i<n;i++ ){
		l=getint(); r=getint();
		sl+=l; sr+=r;
	}
	if( n-sl<sl ) sl=n-sl;
	if( n-sr<sr ) sr=n-sr;
	printf("%d\n",sl+sr);
}