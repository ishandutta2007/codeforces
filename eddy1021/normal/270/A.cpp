#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int t,tmp;
int main(){
	t = getint(); while( t-- ){
		tmp = getint();
		if( 360%(180-tmp) ) puts("NO");
		else puts("YES");
	}
}