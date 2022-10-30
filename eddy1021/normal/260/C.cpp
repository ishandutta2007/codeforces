#include <stdio.h>
#define N 100010
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll bx[N],n,x,min,minidx,cnt;
int main(){
	n = getint(); x = getint(); min = 0x7fffffff; x--;
	for( int i=0;i<n;i++ ){
		bx[i] = getint(); if( bx[i]<min ) min = bx[i] , minidx = i;
	}
	for( int i=0;i<n;i++ ) bx[i] -= min; cnt = min * n;
	for( int i=x;;i=(i-1+n)%n ){
		if( !bx[i] ){ bx[i]=cnt; break; }
		else bx[i] --, cnt ++;
	}
	for( int i=0;i<n;i++ ) printf("%I64d ",bx[i]);
}