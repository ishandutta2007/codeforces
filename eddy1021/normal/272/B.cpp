#include <stdio.h>
#define ll long long
ll n,a,t,bx[50];
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n = getint(); while( n-- ){
		ll cnt = 0; t = getint();
		while( t ) cnt += t%2 , t >>= 1;
		a += bx[cnt]; bx[cnt] ++;
	}
	printf("%I64d\n",a);
}