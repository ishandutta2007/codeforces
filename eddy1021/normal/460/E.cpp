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
#define SZ(x) (int)(x).size()
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
int n , r;
vector<PII> v , ch;
PII operator-( const PII &p1 , const PII &p2 ){
    return MP( p1.FI - p2.FI , p1.SE - p2.SE );
}
int cross( PII p1 , PII p2 ){
    return p1.FI * p2.SE - p1.SE * p2.FI;
}
void build(){

}
void init(){
    n = getint();
    r = getint();
    for( int i = -r ; i <= r ; i ++ )
        for( int j = -r ; j <= r ; j ++ )
            if( i * i + j * j <= r * r )
                v.PB( MP( i , j ) );
    sort( v.begin() , v.end() );
    int sz = 0;
    for( int i = 0 ; i < (int)v.size() ; i ++ ){
        while( sz > 1 && cross( ch[ sz - 1 ] - ch[ sz - 2 ] , v[ i ] - ch[ sz - 1 ] ) <= 0 )
            ch.pop_back() , sz --;
        ch.PB( v[ i ] ); sz ++;
    }
    int psz = sz;
    for( int i = (int)v.size() - 1 ; i >= 0 ; i -- ){
        while( sz - psz > 0 && cross( ch[ sz - 1 ] - ch[ sz - 2 ] , v[ i ] - ch[ sz - 1 ] ) <= 0 )
            ch.pop_back() , sz --;
        ch.PB( v[ i ] ); sz ++;
    }
    ch.pop_back();
//    printf( "%d\n" , (int)ch.size() );
//    for( int i = 0 ; i < (int)ch.size() ; i ++ )
//        printf( "%d %d\n" , ch[ i ].FI , ch[ i ].SE );
}
int bans , tsum;
vector<PII> vans , tmp;
#define x first
#define y second
void DFS( int got , int sumx , int sumxx , int sumy , int sumyy , int pre ){
    if( got == n ){
        if( tsum > bans ){
            bans = tsum;
            vans = tmp;
        }
        return;
    }
    for( int i = pre ; i < (int)ch.size() ; i ++ ){
        int tsumx = got * ch[ i ].x * ch[ i ].x - 2 * sumx * ch[ i ].x + sumxx;
        int tsumy = got * ch[ i ].y * ch[ i ].y - 2 * sumy * ch[ i ].y + sumyy;
        tsum += tsumx + tsumy;
        tmp.PB( ch[ i ] );
        DFS( got + 1 , sumx + ch[ i ].x , sumxx + ch[ i ].x * ch[ i ].x ,
                        sumy + ch[ i ].y , sumyy + ch[ i ].y * ch[ i ].y , i );
        tsum -= tsumx + tsumy;
        tmp.pop_back();
    }
}
void solve(){
    DFS( 0 , 0 , 0 , 0 , 0 , 0 );
    printf( "%d\n" , bans );
    for( int i = 0 ; i < n ; i ++ )
        printf( "%d %d\n" , vans[ i ].FI , vans[ i ].SE );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}