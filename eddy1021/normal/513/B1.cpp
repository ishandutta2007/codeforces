// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
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
#define N 52
int n;
ll m , p[ N ];
vector<int> v;
void build(){
}
void init(){
    n = getint();
    scanf( "%I64d" , &m );
    p[ n ] = 1ll;
    for( int i = n - 1 ; i >= 1 ; i -- ){
        p[ i ] = p[ i + 1 ] * 2;
    }    
//    for( int i = 0 ; i < n ; i ++ )
//        v.PB( i + 1 );
}
/*
int F( vector<int> tv ){
    int cnt = 0;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = i ; j < n ; j ++ ){
            int tmin = tv[ i ];
            for( int k = i + 1 ; k <= j ; k ++ )
                tmin = min( tmin , tv[ k ] );
            cnt += tmin;
        }
    return cnt;
}*/
void find_ans( int now , ll tm ){
    if( now == n ){
//        v.PB( now );
        printf( "%d " , now );
        return;
    }
    if( p[ now + 1 ] >= tm ){
//        v.PB( now );
        printf( "%d " , now );
        find_ans( now + 1 , tm );
    }else{
        find_ans( now + 1 , tm - p[ now + 1 ] );
        printf( "%d " , now );
    }
}
void solve(){
    find_ans( 1 , m );
    puts( "" );
    /*    do{
        for( int i = 0 ; i < n ; i ++ )
            printf( "%d " , v[ i ] ); puts( "" );
        printf( "%d\n" , F( v ) );
    }while( next_permutation( v.begin() , v.end() ) );*/
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}