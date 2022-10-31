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
#define N 600010
vector< tuple<ll,ll,int,bool> > v[ N ];
#define Nxt(x) get<0>(x)
#define Cst(x) get<1>(x)
#define Idx(x) get<2>(x)
#define Live(x) get<3>(x)
ll n , m , u;
void build(){

}
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < m ; i ++ ){
        ll tu , tv , tc;
        tu = getint(); tv = getint(); tc = getint();
        v[ tu ].PB( MT( tv , tc , i + 1 , true ) );
        v[ tv ].PB( MT( tu , tc , i + 1 , true ) );
    }
    u = getint();
}
ll dst[ N ];
queue<int> Q;
bool inq[ N ];
void SPFA(){
    for( int i = 1 ; i <= n ; i ++ ) dst[ i ] = LLINF;
    Q.push( u ); dst[ u ] = 0;
    while( Q.size() ){
        int tn = Q.front(); Q.pop(); inq[ tn ] = false;
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
            if( dst[ tn ] + Cst( v[ tn ][ i ] ) < dst[ Nxt( v[ tn ][ i ] ) ] ){
                dst[ Nxt( v[ tn ][ i ] ) ] = dst[ tn ] + Cst( v[ tn ][ i ] );
                if( !inq[ Nxt( v[ tn ][ i ] ) ] ){
                    inq[ Nxt( v[ tn ][ i ] ) ] = true;
                    Q.push( Nxt( v[ tn ][ i ] ) );
                }
            }
    }
}
void BFS(){
    Q.push( u ); inq[ u ] = true;
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
            if( dst[ tn ] + Cst( v[ tn ][ i ] ) == dst[ Nxt( v[ tn ][ i ] ) ] ){
                if( !inq[ Nxt( v[ tn ][ i ] ) ] ){
                    inq[ Nxt( v[ tn ][ i ] ) ] = true;
                    Q.push( Nxt( v[ tn ][ i ] ) );
                }
            }else Live( v[ tn ][ i ] ) = false;
    }
}
ll lgs[ N ];
void SPFA2(){
    for( int i = 1 ; i <= n ; i ++ ) inq[ i ] = false;
    Q.push( u );
    while( Q.size() ){
        int tn = Q.front(); Q.pop(); inq[ tn ] = false;
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
            if( Live( v[ tn ][ i ] ) && lgs[ tn ] + 1 > lgs[ Nxt( v[ tn ][ i ] ) ] ){
                lgs[ Nxt( v[ tn ][ i ] ) ] = lgs[ tn ] + 1;
                if( !inq[ Nxt( v[ tn ][ i ] ) ] ){
                    inq[ Nxt( v[ tn ][ i ] ) ] = true;
                    Q.push( Nxt( v[ tn ][ i ] ) );
                }
            }
    }
}
ll answ;
vector<int> ans;
int prt[ N ];
int find_p( int x ){
    return x == prt[ x ] ? x : prt[ x ] = find_p( prt[ x ] );
}
void Union( int x , int y ){
    x = find_p( x );
    y = find_p( y );
    prt[ x ] = y;
}
vector< tuple<ll,int,int,int> > uu;
ll tans[ N ] , idx[ N ];
void find_ans(){
    for( int i = 1 ; i <= n ; i ++ ) tans[ i ] = LLINF;
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 0 ; j < (int)v[ i ].size() ; j ++ )
            if( Live( v[ i ][ j ] ) )
                if( Cst( v[ i ][ j ] ) < tans[ Nxt( v[ i ][ j ] ) ] ){
                    tans[ Nxt( v[ i ][ j ] ) ] = Cst( v[ i ][ j ] );
                    idx[ Nxt( v[ i ][ j ] ) ] = Idx( v[ i ][ j ] );
                }
    for( int i = 1 ; i <= n ; i ++ )
        if( i != u ){
            ans.PB( idx[ i ] );
            answ += tans[ i ];
        }
}
void solve(){
    SPFA();
    BFS();
    //SPFA2();
    find_ans();
    cout << answ << endl;
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d%c" , ans[ i ] , i == (int)ans.size() - 1 ? '\n' : ' ' );
} 
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}