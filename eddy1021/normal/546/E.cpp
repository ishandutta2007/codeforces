// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
#define LLINF 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-7
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
#define N 310
#define M 3010
int s , t;
int n , m , a[ N ] , b[ N ] , suma , sumb;
int ans[ N ][ N ] , from[ N ] , ridx;
struct XD{
    int des , cap , nxt , pcap;
}r[ M ];
void add_edge( int tf , int tt , int cap ){
    ++ ridx;
    r[ ridx ].des = tt; r[ ridx ].pcap = r[ ridx ].cap = cap;
    r[ ridx ].nxt = from[ tf ]; from[ tf ] = ridx;
    ++ ridx;
    r[ ridx ].des = tf; r[ ridx ].pcap = r[ ridx ].cap = 0;
    r[ ridx ].nxt = from[ tt ]; from[ tt ] = ridx;
}
void build(){

}
void init(){
    n = getint(); m = getint();
    s = 0; t = 2 * n + 1; ridx = 1;
    for( int i = 1 ; i <= n ; i ++ ) a[ i ] = getint() , suma += a[ i ];
    for( int i = 1 ; i <= n ; i ++ ) b[ i ] = getint() , sumb += b[ i ];
    for( int i = 1 ; i <= n ; i ++ ){
        add_edge( s , i , a[ i ] );
        add_edge( i , n + i , INF );
        add_edge( n + i , t , b[ i ] );
    }
    while( m -- ){
        int ta , tb;
        ta = getint(); tb = getint();
        add_edge( ta , n + tb , INF );
        add_edge( tb , n + ta , INF );
    }
}
int tcap[ N ] , back[ N ] , ei[ N ];
bool inq[ N ];
queue<int> Q;
int SPFA(){
    for( int i = s ; i <= t ; i ++ ) tcap[ i ] = 0 , back[ i ] = 0;
    tcap[ s ] = INF; Q.push( s );
    while( Q.size() ){
        int tn = Q.front(); Q.pop(); inq[ tn ] = false;
        for( int i = from[ tn ] ; i ; i = r[ i ].nxt )
            if( min( tcap[ tn ] , r[ i ].cap ) > tcap[ r[ i ].des ] ){
                tcap[ r[ i ].des ] = min( tcap[ tn ] , r[ i ].cap );
                back[ r[ i ].des ] = tn;
                ei[ r[ i ].des ] = i;
                if( !inq[ r[ i ].des ] ){
                    inq[ r[ i ].des ] = true;
                    Q.push( r[ i ].des );
                }
            }
    }
    if( tcap[ t ] == 0 ) return 0;
    int tflow = tcap[ t ];
    int now = t;
    while( now ){
        int pre = back[ now ];
        int idx = ei[ now ];
        r[ idx ].cap -= tflow;
//        printf( "%d %d +%d\n" , pre , now , tflow );
//        if( 1 <= pre && pre <= n && n + 1 <= now && now <= n + n )
//            ans[ pre ][ now - n ] += tflow;
        //if( 1 <= now && now <= n && n + 1 <= pre && pre <= n + n )
        //    ans[ now ][ pre ] -= tflow;
        r[ idx ^ 1 ].cap += tflow;
        now = pre;
    }
    return tflow;
}
int maxflow(){
    int tflow = 0;
    while( true ){
        int dlt = SPFA();
        if( dlt == 0 ) break;
        tflow += dlt;
    }
    return tflow;
}
void solve(){
    if( suma != sumb || maxflow() != suma ) puts( "NO" );
    else{
        puts( "YES" );
        for( int i = 1 ; i <= n ; i ++ )
            for( int j = from[ i ] ; j ; j = r[ j ].nxt )
                if( j % 2 == 0 )
                    ans[ i ][ r[ j ].des - n ] += r[ j ].pcap - r[ j ].cap;
        for( int i = 1 ; i <= n ; i ++ , puts( "" ) )
            for( int j = 1 ; j <= n ; j ++ )
                printf( "%d " , ans[ i ][ j ] );
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