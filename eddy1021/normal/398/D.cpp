#include <set>
#include <stdio.h>
using namespace std;
#define N 50010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
set<int> E[ N ];
typedef set<int>::iterator si;
int on[ N ] , fd[ N ];
int n , m , q , o , x , y;
void add( int tx , int ty ){
	if( E[ tx ].size() > E[ ty ].size() ){
		int u = tx; tx = ty; ty = u;
	}
	E[ tx ].insert( ty );
	if( on[ tx ] ) fd[ ty ] ++;
}
void remove( int tx , int ty ){
	if( E[ tx ].count( ty ) ){
		fd[ ty ] -= on[ tx ];
		E[ tx ].erase( ty );
	}else{
		fd[ tx ] -= on[ ty ];
		E[ ty ].erase( tx );
	}
}
void modify( int tx , int vl ){
	for( si it = E[ tx ].begin() ; it != E[ tx ].end() ; it ++ )
		fd[ *it ] += vl;
}
int count( int tx ){
	int tcnt = 0;
	for( si it = E[ tx ].begin() ; it != E[ tx ].end() ; it ++ )
		tcnt += on[ *it ];
	return tcnt;
}
void init(){
	n = getint(); m = getint(); q = getint();
	o = getint(); while( o -- ){
		x = getint();
		on[ x ] = 1;
	}
	while( m -- ){
		x = getint(); y = getint();
		add( x , y );
	}
}

void print(){
	for( int i = 1 ; i <= n ; i ++ ){
		printf( "#%d : " , i );
		for( si it = E[ i ].begin() ; it != E[ i ].end() ; it ++ )
			printf( "%d " , *it );
		puts( "" );
	}
	for( int i = 1 ; i <= n ; i ++ )
		printf( "%d%c" , fd[ i ] , i == n ? '\n' : ' ' );
	for( int i = 1 ; i <= n ; i ++ )
		printf( "%d%c" , on[ i ] , i == n ? '\n' : ' ' );
	puts( "" );
}

void process(){
	char ct[ 10 ];
	while( q -- ){
		scanf( "%s" , ct );
		if( ct[ 0 ] == 'O' ){
			x = getint();
			modify( x , 1 );
			on[ x ] = 1;
		}else if( ct[ 0 ] == 'F' ){
			x = getint();
			modify( x , -1 );
			on[ x ] = 0;
		}else if( ct[ 0 ] == 'A' ){
			x = getint(); y = getint();
			add( x , y );
		}else if( ct[ 0 ] == 'D' ){
			x = getint(); y = getint();
			remove( x , y );
		}else{
			x = getint();
			printf( "%d\n" , count( x ) + fd[ x ] );
		}
//		print();
	}
}
int main(){
	init();
	process();
}