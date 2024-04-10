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
#define N 200010
vector<int> son[ N ];
int n , leaf , lf[ N ];
void build(){}
void init(){
    n = getint();
    for( int i = 1 ; i < n ; i ++ ){
        int prt , chr;
        prt = getint(); chr = getint();
        son[ prt ].PB( chr );
        son[ chr ].PB( prt );
    }
}
int build_lf( int now , int pp ){
    for( int i = 0 ; i < (int)son[ now ].size() ; i ++ ){
        if( son[ now ][ i ] == pp ) continue;
        lf[ now ] += build_lf( son[ now ][ i ] , now );
    }
    if( lf[ now ] == 0 ) leaf ++ , lf[ now ] = 1;
//    if( (int)son[ now ].size() == 0 ) leaf ++ , lf[ now ] = 1;
    return lf[ now ];
}
int ansmax , ansmin;
/*void find_max( int now , int l , int r , int turn ){
    if( l == r ){
        ansmax = max( ansmax , l );
        return;
    }
    if( !turn ){
        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ )
            find_max( son[ now ][ i ] , r - lf[ son[ now ][ i ] ] + 1 , r , 1 - turn );
    }else{
        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ )
            find_max( son[ now ][ i ] , l , l + lf[ son[ now ][ i ] ] - 1  , 1 - turn );
    }
}*/
int find_max( int now , int turn , int pp ){
    if( lf[ now ] == 1 ) return 1;
    int total = lf[ now ];
    if( !turn ){
        int best = lf[ now ];
/*        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ )
            best += find_max( son[ now ][ i ] , 1 - turn );
*/      for( int i = 0 ; i < (int)son[ now ].size() ; i ++ ){
            if( son[ now ][ i ] == pp ) continue;
            best = min( best , find_max( son[ now ][ i ] , 1 - turn , now ) );
            //int tmp = lf[ son[ now ][ i ] ] - find_max( son[ now ][ i ] , 1 - turn , now );
            //best = max( best , total - tmp );
        }
        return best;
    }else{
        int best = 0;
        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ ){
            if( son[ now ][ i ] == pp ) continue;
            best += find_max( son[ now ][ i ] , 1 - turn , now );
            //best = max( best , find_max( son[ now ][ i ] , 1 - turn , now ) );
        }
/*        int best = lf[ now ];
        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ ){
            int tmp = lf[ son[ now ][ i ] ] - find_max( son[ now ][ i ] , 1 - turn );
            best = min( best , total - tmp );
        }*/
        return best;
    }
}
int find_min( int now , int turn , int pp ){
    if( lf[ now ] == 1 ) return 1;
    if( !turn ){
        int sum = 0;
        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ ){
            if( son[ now ][ i ] == pp ) continue;
            sum += find_min( son[ now ][ i ] , 1 - turn , now );
        }
        return sum;
    }else{
        int sum = lf[ now ];
        for( int i = 0 ; i < (int)son[ now ].size() ; i ++ ){
            if( son[ now ][ i ] == pp ) continue;
            sum = min( sum , find_min( son[ now ][ i ] , 1 - turn , now ) );
        }
        return sum;
    }   
}
void solve(){
    build_lf( 1 , -1 );
    ansmax = leaf - find_max( 1 , 0 , -1 ) + 1;
    ansmin = find_min( 1 , 0 , -1 );
    printf( "%d %d\n" , ansmax , ansmin );
}
int main(){
    build();  
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}