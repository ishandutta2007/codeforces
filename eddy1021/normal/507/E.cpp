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
#define N 100010
int n , m , from[ N ] , dp1[ N ] , dp2[ N ] , bk[ N ] , bkn[ N ];
struct XD{
    int des , good , tag , nxt;
}r[ N << 1 ];
void build(){
    
}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= m ; i ++ ){
        int u , v , c;
        u = getint(); v = getint(); c = getint();
        r[ i << 1 ].des = v; r[ i << 1 ].good = c;
        r[ i << 1 ].nxt = from[ u ]; from[ u ] = i << 1;
        r[ ( i << 1 ) + 1 ].des = u; r[ ( i << 1 ) + 1 ].good = c;
        r[ ( i << 1 ) + 1 ].nxt = from[ v ]; from[ v ] = ( i << 1 ) + 1;
    }
    for( int i = 2 ; i <= n ; i ++ )
        dp1[ i ] = INF;
}
queue<int> Q;
bool inq[ N ];
void SPFA(){
    Q.push( 1 );
    while( Q.size() ){
        int tn = Q.front(); Q.pop(); inq[ tn ] = false;
        for( int i = from[ tn ] ; i ; i = r[ i ].nxt )
            if( dp1[ tn ] + 1 < dp1[ r[ i ].des ] ||
             ( dp1[ tn ] + 1 == dp1[ r[ i ].des ] &&
                dp2[ tn ] + r[ i ].good > dp2[ r[ i ].des ] ) ){
                dp1[ r[ i ].des ] = dp1[ tn ] + 1;
                dp2[ r[ i ].des ] = dp2[ tn ] + r[ i ].good;
                bk[ r[ i ].des ] = tn;
                bkn[ r[ i ].des ] = i;
                if( !inq[ r[ i ].des ] ){
                    Q.push( r[ i ].des );
                    inq[ r[ i ].des ] = true;
                }
            }
    }
}
void backtrack(){
    int now = n;
    while( now != 1 ){
        int idx = bkn[ now ];
        r[ idx ].tag = r[ idx ^ 1 ].tag = 1;
        now = bk[ now ];
//        printf( "%d %d\n" , r[ idx ].des , r[ idx ^ 1 ].des );
//        printf( "%d %d\n" , idx , idx ^ 1 );
    }
}
vector< pair<PII,int> > ans;
void solve(){
    SPFA();
    backtrack();
    for( int i = 1 ; i <= m ; i ++ )
        if( r[ i << 1 ].tag ^ r[ i << 1 ].good )
            ans.PB( MP( MP( r[ ( i << 1 ) + 1 ].des , r[ i << 1 ].des ) , 1 - r[ i << 1 ].good ) );
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d %d %d\n" , ans[ i ].FI.FI , ans[ i ].FI.SE , ans[ i ].SE );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}