#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 30001
#define B 500
int n , d , p[ N ] , ans , tmax;
int M[ N ][ B ];
bool got[ N ][ B ] , gott[ N ];
typedef map<int,int>::iterator mi;
void build(){
    
}
void init(){
    n = getint(); d = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int tp = getint();
        p[ tp ] ++;
        tmax = max( tmax , tp );
    }
    M[ d ][ 250 ] = 0;
    gott[ d ] = true;
    got[ d ][ 250 ] = true;
    ans = p[ d ];
}
void solve(){
    for( int i = d ; i <= tmax ; i ++ ) if( gott[ i ] ){
        for( int j = 0 ; j < B ; j ++ ) if( got[ i ][ j ] ){
            int prep = d + ( j - 250 ) , prea = M[ i ][ j ];
            for( int k = -1 ; k <= 1 ; k ++ )
                if( prep + k > 0 && i + prep + k <= tmax ){
                    M[ i + prep + k ][ j + k ] = max( M[ i + prep + k ][ j + k ] , prea + p[ i ] );
                    got[ i + prep + k ][ j + k ] = true;
                    gott[ i + prep + k ] = true;
                    ans = max( ans , M[ i + prep + k ][ j + k ] + p[ i + prep + k ] );
                }
        }
    }
    printf( "%d\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}