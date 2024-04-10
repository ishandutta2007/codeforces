#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,ans,i;
int main(){
	n=getint();
	if( n<3 ) return puts("-1"),0;
	if( n==3 ) puts("210");
	else{
		putchar('1');
		for( i=1,ans=50;i<=n-4;i++ ) putchar('0'),ans=ans*10%210;
		printf("%03d\n",ans);
	}
}