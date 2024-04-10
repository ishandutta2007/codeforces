#include <stdio.h>
#include <algorithm>
#define N 200010
#define ll long long
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
ll ans,n,k,bx[N],tms[N],l,r;
int main(){
	n = getint(); k = getint();
	for( ll i=1;i<=n;i++ ) bx[i] = getint();
	while( k-- ){
		l = getint(); r = getint();
		tms[l] ++; tms[r+1] --;
	}
	for( ll i=1;i<=n;i++ ) tms[i] += tms[i-1];
	std::sort( bx+1 , bx+n+1 );
	std::sort( tms+1 , tms+n+1 );
	for( ll i=1;i<=n;i++ ) ans += bx[i]*tms[i];
	printf("%I64d\n",ans);
}