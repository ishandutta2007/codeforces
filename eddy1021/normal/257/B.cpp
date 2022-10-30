#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,m;
int main(){
	n = getint(); m = getint();
	printf("%d %d\n",((n>m?n:m)-1),(n<m?n:m));
}