#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x * tmp;
}
struct XD{
	int no , d;
}bx[ N ];
struct Arc{
	int x , y;
}E[ N * 10 ];
bool cmp( XD x , XD y ){
	return x.d < y.d;
}
queue<int> Q[ N ];
int n , k , got[ N ] , ecnt; bool tag , got0;
void init(){
	n = getint(); k = getint();
	tag = true; got0 = false;
	for( int i = 1 ; i <= n ; i ++ ){
		bx[ i ].no = i;
		bx[ i ].d = getint();
		if( bx[ i ].d == 0 ){
			if( got0 ) tag = false;
			else got0 = true;
		}
		if( bx[ i ].d < 0 || bx[ i ].d >= n )
			tag = false;
	}
}
void process(){
	if( !tag ){ puts( "-1" ); return; }
	std::sort( bx + 1 , bx + n + 1 , cmp );
	for( int i = 1 ; i <= n ; i ++ )
		if( bx[ i ].d == 0 )
			Q[ 0 ].push( bx[ i ].no );
		else{
			while( Q[ bx[ i ].d - 1 ].size() )
				if( got[ Q[ bx[ i ].d - 1 ].front() ] >= k )
					Q[ bx[ i ].d - 1 ].pop();
				else break;
			if( Q[ bx[ i ].d - 1 ].size() ){
				got[ Q[ bx[ i ].d - 1 ].front() ] ++;
				E[ ecnt ].x = bx[ i ].no;
				E[ ecnt ++ ].y = Q[ bx[ i ].d - 1 ].front();
				Q[ bx[ i ].d ].push( bx[ i ].no );
				got[ bx[ i ].no ] ++;
			}else{
				puts( "-1" ); return;
			}
		}
	printf( "%d\n" , ecnt );
	for( int i = 0 ; i < ecnt ; i ++ )
		printf( "%d %d\n" , E[ i ].x , E[ i ].y );
}
int main(){
	init();
	process();
}