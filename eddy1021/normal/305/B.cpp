#include <stdio.h>
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll p , q , n , a , i;
int main(){
	p = getint(); q = getint();
	n = getint();
	for( i = 0 ; i < n ; i ++ ){
		a = getint();
		if( !q ) break;
		if( a > p / q ) break;
		p -= q * a;
		p ^= q ^= p ^= q;
	}
	puts( i < n || q ? "NO" : "YES" );
}