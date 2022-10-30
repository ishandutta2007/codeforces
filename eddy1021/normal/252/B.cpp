#include <stdio.h>
#include <algorithm>
#define N 100010
#define ct continue
int a[N],b[N],n; bool chk1,chk2;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	n=getint(); if( n<=2 ) return puts("-1"),0;
	for( int i=0;i<n;i++ ) a[i]=b[i]=getint();
	std::sort( b , b+n );
	for( int i=0;i<n;i++ ){
		if( i!=n-1&&a[i]==a[i+1] ) ct;
		for( int j=i+1;j<n;j++ ){
			if( a[i]==a[j] ) ct;
			int tmp=a[i]; a[i]=a[j]; a[j]=tmp;
			chk1=chk2=true;
			for( int k=0;k<n&&(chk1||chk2);k++ ){
				if( a[k]!=b[k] ) chk1=false;
				if( a[k]!=b[n-k-1] ) chk2=false;
			}
			if( !chk1 && !chk2 ) return printf("%d %d\n",i+1,j+1),0;
			tmp=a[i]; a[i]=a[j]; a[j]=tmp;
		}
	}
	puts("-1");
}