// eddy1021
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
#define N 3100
int n , a[ N ] , b , pre = 0 , pt;
void build(){
    
}
void Add( int dlt ){
    for( int i = 0 ; dlt ; i ++ ){
        while( a[ i ] < 9 && dlt )
            a[ i ] ++ , dlt --;
        pt = max( pt , i );
    }
}
void init(){
    n = getint();
}
void modify( int dlt ){
    if( dlt > 0 ) Add( dlt );
    else{
        for( int i = 0 ; ; i ++ ){
            pt = max( pt,  i );
            if( a[ i ] < 9 && dlt > 0 ){
                a[ i ] ++; dlt --;
                Add( dlt );
                return;
            }
            dlt += a[ i ]; a[ i ] = 0;
        }
    }
}
void solve(){
    while( n -- ){
        b = getint();
        modify( b - pre );
        pre = b;
        while( pt > 0 && a[ pt ] == 0 ) pt --;
        for( int i = pt ; i >= 0 ; i -- )
            putchar( a[ i ] + '0' );
        puts( "" );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}