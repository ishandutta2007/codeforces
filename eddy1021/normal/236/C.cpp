#include <stdio.h>
#define ll long long
ll getint(){
	ll x=0LL; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10LL,x+=(c-'0'),c=getchar();
	return x;
}
ll gcd( ll x , ll y ){
	ll r; while(y) r=x%y,x=y,y=r; return x;
}
ll n,ans,tx,ty,tz,g,tmp,gs;
int main(){
	n=getint(); ans=1LL;
	for( ll i=n;i;i-- ){
		if( i*i*i<ans ) break;
		for( ll j=i;j;j-- ){
			if( i*j*j<ans ) break;
			for( ll k=j;k;k-- ){
				if( i*j*k<ans ) break;
				tx = i; ty = j; tz=k;
				g = gcd(tx,ty); tx/=g; ty/=g; gs=g; if( !(tz%g) ) tz/=g;
				g = gcd(tx,tz); tx/=g; ty/=g; gs*=g;if( !(ty%g) ) ty/=g;
				g = gcd(ty,tz); ty/=g; tz/=g; gs*=g;if( !(tx%g) ) tx/=g;
				tmp = tx*ty*tz*gs;
				ans = ans>tmp?ans:tmp;
			}
		}
	}
	printf("%I64d\n",ans);
}