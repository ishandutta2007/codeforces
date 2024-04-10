#include <stdio.h>
#define N 100010
int a,b,n,ans[N],i,test;
int main(){
	scanf("%d%d%d",&a,&b,&n); ans[0]=a;
	a %= b;
	for( i=1;i<=n;i++ ){
		a *= 10;
		for( test=0;test<10;test++ )
			if( !( (a+test) % b ) ){
				a = ( a+test ) % b; ans[i]=test; break;
			}
		if( test==10 ) return puts("-1"),0;
	}
	for( int i=0;i<=n;i++ ) printf("%d",ans[i]);
	putchar('\n');
}