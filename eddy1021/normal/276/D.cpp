#include <stdio.h>
#define ll long long
ll a,b,ans;
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	a = getint(); b = getint();
	for( ans=63;ans>=0;ans-- )
		if( (a^b)&(1LL<<ans) ) break;
	printf("%I64d\n",(1LL<<(ans+1))-1);
}