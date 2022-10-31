#include <stdio.h>
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll n , k , ans , sum , need , l , m , r , tsum , tneed;
ll total( ll from ){
	return ( k + from ) * ( k - from +1 ) / 2;
}
void process(){
	l = 1; r = k;
	while( l <= r ){
		m = ( l + r ) >> 1;
		tsum = total( m );
		if( tsum == n ){
			tneed = k - m + 1;
			if( need == -1 || tneed < need ) need = tneed;
			return;
		}else if( tsum > n ){
			tneed = k - m + 1;
			if( need == -1 || tneed < need ) need = tneed;
			l = m + 1;
		}else r = m - 1;
	}
}
int main(){
	n = getint(); k = getint();
	sum = 1; need = -1; n --; k --;
	if( sum < n ) process();
	if( !n ) need = 0;
	printf("%I64d\n",need);
}