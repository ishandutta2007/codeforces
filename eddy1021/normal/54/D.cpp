// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();    
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 110
int n , k , p;
char c[ N ] , c2[ N ];
int nxt[ N ][ 30 ];
int f[ N ];
void build_KMP(){
	f[ 0 ] = -1;
	for( int i = 1 ; i < p ; i ++ ){
		int tmp = f[ i - 1 ];
		while( tmp >= 0 && c[ tmp + 1 ] != c[ i ] )
			tmp = f[ tmp ];
		f[ i ] = tmp + ( c[ tmp + 1 ] == c[ i ] );
	}
}
void build(){

}
void init(){
    n = getint(); k = getint();
    scanf( "%s" , c );
    scanf( "%s" , c2 );
    p = strlen( c );
    build_KMP();
//    for( int i = 0 ; i < p ; i ++ )
//        printf( "%d\n" , f[ i ] );
    nxt[ 0 ][ c[ 0 ] - 'a' ] = 1;
    for( int i = 1 ; i <= p ; i ++ )
        for( int j = 0 ; j < k ; j ++ ){
            int now = i - 1;
            while( now >= 0 && c[ now + 1 ] != ( j + 'a' ) )
                now = f[ now ];
            nxt[ i ][ j ] = now + ( c[ now + 1 ] == ( j + 'a' ) ) + 1;
//            printf( "%d %d %d\n" , i , j , nxt[ i ][ j ] );
        }
}
bool can[ N ][ N ];
int bk[ N ][ N ];
char bkc[ N ][ N ];
queue<PII> Q;
bool notokay(){
    can[ 0 ][ 0 ] = true;
    Q.push( MP( 0 , 0 ) );
    while( Q.size() ){
        PII tp = Q.front(); Q.pop();
        int l = tp.FI , pl = tp.SE;
        //printf( "%d %d\n" , l , pl );
        if( l == n ) return false;
        for( int j = 0 ; j < k ; j ++ ){
            int nl = tp.FI + 1;
            int npl = nxt[ pl ][ j ];
            if( nl >= p ){
                if( c2[ nl - p ] == '1' && npl != p ) continue;
                if( c2[ nl - p ] == '0' && npl == p ) continue;
            }
            if( !can[ nl ][ npl ] ){
                can[ nl ][ npl ] = true;
                Q.push( MP( nl , npl ) );
                bk[ nl ][ npl ] = pl;
                bkc[ nl ][ npl ] = j + 'a';
            }
        }
    }
    return true;
}
void DFS( int tn , int tnow ){
    if( tn == 0 ) return;
    DFS( tn - 1 , bk[ tn ][ tnow ] );
    putchar( bkc[ tn ][ tnow ] );
}
void find_ans(){
    int now = 0;
    for( int i = 0 ; i <= p ; i ++ )
        if( can[ n ][ i ] )
            now = i;
    DFS( n , now );
    puts( "" );
}
void solve(){
    if( notokay() ) puts( "No solution" );
    else find_ans();
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}