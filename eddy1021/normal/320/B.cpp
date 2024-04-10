#include <stdio.h>
#define N 110
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c = getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int n , no , tp , ta , tb , can;
int a[ N ] , b[ N ] , got[ N ];
bool road( int s , int t ){
	if( a[ t ] < a[ s ] && a[ s ] < b[ t ] ) return true;
	if( a[ t ] < b[ s ] && b[ s ] < b[ t ] ) return true;
	return false;
}
void DFS( int now ){
	if( can || now == tb ){
		can = 1; return;
	}
	got[ now ] = 1;
	for( int i = 0 ; i < tp ; i ++ )
		if( !got[ i ] && road( now , i ) )
			DFS( i );
}
void process(){
	n = getint(); while( n -- ){
		no = getint();
		ta = getint(); tb = getint();
		if( no == 1 ){
			a[ tp ] = ta;
			b[ tp ++ ] = tb;
		}else{
			ta --; tb --; can = 0;
			for( int i = 0 ; i < tp ; i ++ ) got[ i ] = 0;
			DFS( ta );
			puts( can ? "YES" : "NO" );
		}
	}
}
int main(){
	process();
}