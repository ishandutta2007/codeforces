#include <stdio.h>
#include <stdlib.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,pre,cnt,now;
int main(){
	pre = 0; n = getint(); cnt = (n<<1)-1;
	while( n-- ){
		now = getint();
		cnt += abs( now-pre );
		pre = now;
	}
	printf("%d\n",cnt);
}