#include <stdio.h>
#define N 300010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x * tmp;
}
struct XD{
	int num , tag , tagt;
}ST[ N << 2 ];
int first , n , m , inl , inr , inx;
void update( int no , int l , int r , int ql , int qr , int num , int t ){
	if( l == ql && r == qr ){
		if( !ST[ no ].tag || t < ST[ no ].tagt ){
			ST[ no ].tag = num;
			ST[ no ].tagt = t;
		}
		return;
	}
	int m = ( l + r ) >> 1;
	if( qr <= m ) update( no << 1 , l , m , ql , qr , num , t );
	else if( m < ql ) update( ( no << 1 ) + 1 , m + 1 , r , ql , qr , num , t );
	else{
		update( no << 1 , l , m , ql , m , num , t );
		update( ( no << 1 ) + 1 , m + 1 , r , m + 1 , qr , num , t );
	}
}
void print( int no , int l , int r ){
	int m = ( l + r ) >> 1;
	if( ST[ no ].tag ){
		ST[ no ].num = ST[ no ].tag;
		if( l != r ){
			update( no << 1 , l , m , l , m , ST[ no ].tag , ST[ no ].tagt );
			update( ( no << 1 ) + 1 , m + 1 , r , m + 1 , r , ST[ no ].tag , ST[ no ].tagt );
		}
		ST[ no ].tag = 0;
	}
	if( l == r ){
		if( first ) putchar( ' ' ); first = 1;
		printf( "%d" , ST[ no ].num ); return;
	}
	print( no << 1 , l , m );
	print( ( no << 1 ) + 1 , m + 1 , r );
}
void process(){
	n = getint(); m = getint();
	for( int i = 0 ; i < m ; i ++ ){
		inl = getint(); inr = getint(); inx = getint();
		if( inl <= inx - 1 )
			update( 1 , 1 , n , inl , inx - 1 , inx , i );
		if( inx + 1 <= inr )
			update( 1 , 1 , n , inx + 1 , inr , inx , i );
	}
}
int main(){
	process();
	print( 1 , 1 , n );
	puts( "" );
}