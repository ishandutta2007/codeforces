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
#define N 100001
#define SN 320
int n , m , sn;
bool tag[ N ];
vector<PII> v[ N ];
map<PII,int> M;
int p[ SN ][ N ] , pt , p2[ N ];
int find_p( int idx , int x ){
    return x == p[ idx ][ x ] ? x : p[ idx ][ x ] = find_p( idx , p[ idx ][ x ] );
}
int find_p2( int x ){
    return x == p2[ x ] ? x : p2[ x ] = find_p2( p2[ x ] );
}
void Union( int idx , int x , int y ){
    x = find_p( idx , x );
    y = find_p( idx , y );
    if( x != y ) p[ idx ][ x ] = y; 
}
void Union2( int x , int y ){
    x = find_p2( x );
    y = find_p2( y );
    if( x != y ) p2[ x ] = y; 
}
queue<int> Q;
void build(){
    
}
void init(){
    n = getint(); m = getint();
    sn = max( (int)sqrt( n ) , 10 );
    while( m -- ){
        int ta , tb , tc;
        ta = getint(); tb = getint(); tc = getint();
        v[ tc ].PB( MP( ta , tb ) );
        if( !tag[ tc ] ){
            tag[ tc ] = true;
            Q.push( tc );
        }
    }
}
int tag2[ N ];
void kind1( int clr ){
    vector<int> ttv; int tn = clr;
    for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ ){
        p2[ v[ tn ][ i ].FI ] = v[ tn ][ i ].FI;
        p2[ v[ tn ][ i ].SE ] = v[ tn ][ i ].SE;
        if( tag2[ v[ tn ][ i ].FI ] != clr ){
            ttv.PB( v[ tn ][ i ].FI );
            tag2[ v[ tn ][ i ].FI ] = clr;
        }
        if( tag2[ v[ tn ][ i ].SE ] != clr ){
            ttv.PB( v[ tn ][ i ].SE );
            tag2[ v[ tn ][ i ].SE ] = clr;
        }
    }
    for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
        Union2( v[ tn ][ i ].FI , v[ tn ][ i ].SE );
    int nsz = (int)ttv.size();
    for( int i = 0 ; i < nsz ; i ++ )
        for( int j = i + 1 ; j < nsz ; j ++ )
            if( find_p2( ttv[ i ] ) == find_p2( ttv[ j ] ) )
                M[ MP( ttv[ i ] , ttv[ j ] ) ] ++;
}
void kind2( int clr ){
    ++ pt;
    for( int i = 1 ; i <= n ; i ++ ) p[ pt ][ i ] = i;
    for( int i = 0 ; i < (int)v[ clr ].size() ; i ++ )
        Union( pt , v[ clr ][ i ].FI , v[ clr ][ i ].SE );
}
void pre_solve(){
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        if( (int)v[ tn ].size() <= sn ) kind1( tn );
        else kind2( tn );
    }
}
void solve(){
    pre_solve();
    int tq = getint() , tqa , tqb; while( tq -- ){
        tqa = getint(); tqb = getint();
        int ans = 0;
        for( int i = 1 ; i <= pt ; i ++ )
            if( find_p( i , tqa ) == find_p( i , tqb ) )
                ans ++;
        if( M.count( MP( tqa , tqb ) ) ) ans += M[ MP( tqa , tqb ) ];
        if( M.count( MP( tqb , tqa ) ) ) ans += M[ MP( tqb , tqa ) ];
        printf( "%d\n" , ans );
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