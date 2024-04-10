#include <stdio.h>
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll n , m , ans , now , nxt;
int main(){
	n = getint(); m = getint(); now = 1;
	while( m -- ){
		nxt = getint();
		ans += nxt - now;
		if( nxt < now ) ans += n;
		now = nxt;
	}
	printf( "%I64d\n" , ans );
}