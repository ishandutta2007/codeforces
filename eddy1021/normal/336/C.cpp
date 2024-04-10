#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
vector<int> ans;
int n , num[ N ] , v , tmp , tmp2 , sz;
void init(){
	n  = getint(); v = 1;
	for( int i = 0 ; i < n ; i ++ )
		num[ i ] = getint();
	std::sort( num , num + n );
}
void process(){
	while( ( v << 1 ) <= num[ n - 1 ] ) v <<= 1;
	tmp = ( v << 1 ) - 1;
	while( v > 0 ){
		tmp2 = tmp;
		for( int i = 0 ; i < n ; i ++ )
			if( num[ i ] & v ){
				tmp2 &= num[ i ];
				ans.push_back( num[ i ] );
			}
		if( ( tmp2 & ( v - 1 ) ) == 0 ){
			printf( "%d\n" , sz = ans.size() );
			for( int i = 0 ; i < sz ; i ++ )
				printf( "%d%c" , ans[ i ] , i == sz - 1 ? '\n' : ' ' );
			return;
		}
		ans.clear();
		v >>= 1;
	}
	printf( "%d\n" , n );
	for( int i = 0 ; i < n ; i ++ )
		printf( "%d%c" , num[ i ] , i == n - 1 ? '\n' : ' ' );
}
int main(){
	init();
	process();
}