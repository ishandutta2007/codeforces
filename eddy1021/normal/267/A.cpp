#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,cnt,a,b;
void count( int x , int y ){
	if( !x || !y ) return;
	cnt += y/x; count( y%x , x );
}
int main(){
	n = getint(); while( n-- ){
		a = getint(); b = getint(); cnt = 0;
		if( a>b ){ int t=a; a=b; b=t; }
		count( a , b ); printf("%d\n",cnt);
	}
}