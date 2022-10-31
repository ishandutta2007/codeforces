// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009int
#define mod7 1000000007int 
#define INF 1023456789int
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1;
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
#define N 1000010
int n , a[ N ] , b[ N ] , lb[ N ];
vector<int> v , v2 , v3;
int BIT[ N ] , sn;
void Insert( int no , int x ){
    no ++;
    if( no <= 0 ) return;
    while( no <= sn ) BIT[ no ] += x , no += lb[ no ];
}
int query( int no ){
    no ++;
    if( no <= 0 ) return 0;
    int sum = 0;
    while( no ) sum += BIT[ no ] , no -= lb[ no ];
    return sum;
}
void build(){
    for( int i = 1 ; i <= sn ; i ++ )
        lb[ i ] = i & ( -i );
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint(); b[ i ] = getint();
        v.PB( a[ i ] );
        v.PB( b[ i ] );
    }
    sort( v.begin() , v.end() );
    v.resize( unique( v.begin() , v.end() ) - v.begin() );
    for( int i = 0 ; i < (int)v.size() ; i ++ ){
        if( i && v[ i ] != v[ i - 1 ] + 1 )
            v2.PB( v[ i - 1 ] + 1 );
        v2.PB( v[ i ] );
        v3.PB( v[ i ] );
    }
    sn = (int)v2.size();
    build();
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ){
        int pos1 = lower_bound( v.begin() , v.end() , a[ i ] ) - v.begin();
        int pos2 = lower_bound( v.begin() , v.end() , b[ i ] ) - v.begin();
        swap( v3[ pos1 ] , v3[ pos2 ] );
    }
    ll ans = 0;
    for( int i = 0 ; i < (int)v.size() ; i ++ ){
        int vl = v3[ i ];
        //printf( "%d : %d %d\n" , i , v[ i ] , v3[ i ] );
        if( i && v[ i ] != v[ i - 1 ] + 1 ){
            int total = v[ i ] - 1 - v[ i - 1 ];
            int bitpos = lower_bound( v2.begin() , v2.end() , v[ i - 1 ] + 1 ) - v2.begin();
            int ptotal = v[ i - 1 ] + 1 - v[ 0 ];
            int psmall = query( bitpos );
            ans += (ll)( ptotal - psmall ) * (ll)total;
            Insert( bitpos , total );
        }
        int bpos = lower_bound( v2.begin() , v2.end() , vl ) - v2.begin();
        int pretotal = v[ i ] - v[ 0 ];
        int presmall = query( bpos );
        //printf( "%d : %d %d\n" , i , v[ i ] , v3[ i ] );
        ans += ( pretotal - presmall );
        Insert( bpos , 1 );
        //printf( "%d : %d %d\n" , i , v[ i ] , v3[ i ] );
    }
    cout << ans << endl;
}
int main(){
//    build();  
//    __ = getint();
//    while( __ -- ){
        init();
        solve();
//    }
}