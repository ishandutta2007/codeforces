#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define mod 1000000007
char c[ N ] , c2[ N ];
int f[ N ] , l , l2 , is[ N ];
void init(){
    scanf( "%s%s" , c2 , c );
    l2 = strlen( c2 );
    l = strlen( c );
}
void build_KMP(){
	f[ 0 ] = -1;
	for( int i = 1 ; i < l ; i ++ ){
		int tmp = f[ i - 1 ];
		while( tmp >= 0 && c[ tmp + 1 ] != c[ i ] )
			tmp = f[ tmp ];
		f[ i ] = tmp + ( c[ tmp + 1 ] == c[ i ] );
	}
}
void String_cmp(){
	int tmp = -1;
	for( int i = 0 ; i < l2 ; i ++ ){
		while( tmp >= 0 && c[ tmp + 1 ] != c2[ i ] )
			tmp = f[ tmp ];
		if( c[ tmp + 1 ] == c2[ i ] ) tmp ++;
		if( tmp == l - 1 ){
            is[ i + 1 ] = 1;
//			printf( "%d\n" , i - l + 1 );
			tmp = f[ tmp ];
		}
	}
}
int ans , dp[ N ] , sans[ N ];
void DP(){
    int pres = -1 , base = 0 , preans = 0;
    for( int i = 1 ; i <= l2 ; i ++ ){
        if( is[ i ] ){
            pres = i - l;
            dp[ i ] = ( pres + 1 + sans[ pres ] ) % mod;
            ans += dp[ i ]; ans %= mod;
            base = ( base + dp[ i ] ) % mod;
//            preans = ( preans + dp[ i ] ) % mod;
//            printf( "%d %d\n" , i , dp[ i ] );
        }else if( pres != -1 ){
            dp[ i ] = dp[ pres + l ];
            ans += dp[ i ]; ans %= mod;
            base = ( base + dp[ i ] ) % mod;
//            printf( "%d %d\n" , i , dp[ i ] );
        }
        preans += base; preans %= mod;
        sans[ i ] = preans;
    }
}
void solve(){
	build_KMP();
	String_cmp();
    DP();
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}