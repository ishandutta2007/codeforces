#include <stdio.h>
int n,tmp,ans,ai,ki;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n = getint(); while( n-- ){
		ki = getint(); ai = getint();
		if( ki+1 > ans ) ans = ki+1; ai --;
		while( ai ){
			ki ++;
			ai >>= 2;
		}
		if( ki > ans ) ans = ki;
	}
	printf("%d\n",ans);
}