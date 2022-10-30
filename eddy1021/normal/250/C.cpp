#include <stdio.h>
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int a[N],sum[N],n,k,ans,pos;
int main(){
	n=getint(); k=getint(); ans=1;
	for( int i=1;i<=n;i++ ){
		a[i]=getint();
		if( a[i]==a[i-1] ) i--,n--;
	}
	for( int i=1;i<=n;i++ ){
		if( a[i-1]==a[i+1] ) sum[a[i]]+=2;
		else sum[a[i]]++;
	}
	for( int i=2;i<=k;i++ ) if( sum[i]>sum[ans] ) ans=i;
	printf("%d\n",ans);
}