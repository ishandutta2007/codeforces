#include <stdio.h>
#define ll long long
ll n,x,y,c,l,r,d,u;
ll mul( ll tx ){ return tx*tx; }
ll cal( ll tn ){ return ((tn+1)*tn)/2; }
bool test( ll t ){
	ll sum=t*t+(t+1)*(t+1);
	if( t>l ) sum-=mul(t-l);
	if( t>r ) sum-=mul(t-r);
	if( t>u ) sum-=mul(t-u);
	if( t>d ) sum-=mul(t-d);
	if( t>l+d ) sum+=cal( t-(l+d)-1 );
	if( t>l+u ) sum+=cal( t-(l+u)-1 );
	if( t>r+d ) sum+=cal( t-(r+d)-1 );
	if( t>r+u ) sum+=cal( t-(r+u)-1 );
	if( sum>=c ) return true; return false;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&x,&y,&c);
	l = x-1; r = n-x; u = y-1; d = n-y;
	ll tl=0,tr=n*2,tm;
	while( tl<=tr ){
		tm = (tl+tr)>>1;
		if( test(tm) ) tr=tm-1; else tl=tm+1;
	}
	printf("%I64d\n",tl);
}