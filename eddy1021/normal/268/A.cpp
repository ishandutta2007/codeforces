#include <stdio.h>
#define N 110
int h[N],a[N],n,sum,hi,ai;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n = getint();
	while( n-- ){
		hi = getint(); ai = getint();
		sum += a[hi]+h[ai];
		h[hi] ++; a[ai] ++; 
	}
	printf("%d\n",sum);
}