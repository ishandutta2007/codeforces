#include <stdio.h>
#define N 100001
#define ll long long
ll getint(){
	ll x=0LL; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10LL,x+=(c-'0'),c=getchar();
	return x;
}
ll fl[N],n,m,l,u,q;
int main(){
	n=getint(); for( int i=1;i<=n;fl[getint()]=i,i++ );
	m=getint(); while( m-- ){
		q=getint(); l+=fl[q]; u+=(n-fl[q]+1);
	}
	printf("%I64d %I64d\n",l,u);
}