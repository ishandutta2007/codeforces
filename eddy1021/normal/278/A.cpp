#include <stdio.h>
#define N 110
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int d[N],s,t,n,sum,tsum;
int main(){
	n = getint();
	for( int i=1;i<=n;i++ ) d[i] = getint() , sum += d[i];
	s = getint(); t = getint();
	if( s>t ){ int tmp = s; s = t; t = tmp; }
	for( int i=s;i<t;i++ ) tsum += d[i]; sum -= tsum;
	printf("%d\n",sum<tsum?sum:tsum);
}