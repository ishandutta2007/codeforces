#include <stdio.h>
#define N 100010
#define ll long long
ll getint(){
	ll x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar(),tmp=-1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
ll a[N],n,d,cnt,i,j,delta;
int main(){
	n=getint(); d=getint();
	for( i=0;i<n;i++ ) a[i]=getint();
	for( i=0,j=0;i<n;i++ ){
		while( j<n&&a[j]-a[i]<=d ) j++;
		delta=j-i-1; if( delta ) cnt+=delta*(delta-1)/2;
	}
	printf("%I64d\n",cnt);
}