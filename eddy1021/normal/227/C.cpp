#include <stdio.h>
#define ll long long
ll n,m,a;
ll ans( ll x , ll n ){
	if( !n ) return 1LL;
	if( n&1 ) return ( x*ans( (x*x)%m , n>>1 ) )%m;
	return ans( (x*x)%m , n>>1 )%m;
}
int main(){
	scanf("%I64d%I64d",&n,&m); a=ans(3,n); a=(a-1+m)%m;
	printf("%I64d\n",a);
}