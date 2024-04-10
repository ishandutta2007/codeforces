#include <stdio.h>
int n,a[3];
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n=getint();
	for( int i=0;i<n;i++ ) a[i%3]+=getint();
	if( a[0]>a[1]&&a[0]>a[2] ) return puts("chest"),0;
	if( a[1]>a[2] ) return puts("biceps"),0;
	puts("back");
}