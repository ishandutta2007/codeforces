#include <bits/stdc++.h>
using namespace std;
#define N 60
char c[ N ][ N ];
int n , m , cnt;
void init(){
    scanf( "%d%d" , &n , &cnt );
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    m = strlen( c[ 1 ] + 1 );
}
pair< int , pair<int,int> > nxt[ 8 ][ N ][ N ];
bool tag[ 8 ][ N ][ N ];
int dn[]={0,1,0,-1};
int dm[]={1,0,-1,0};
bool in( int xn , int xm ){
    return xn >= 1 && xn <= n && xm >= 1 && xm <= m;
}
// 0 ~ 3 left -> V <- ^
// 4 ~ 7 right
/*
pair< int , pair<int,int> > Nxt( int x , int tn , int tm ){
    if( tag[ x ][ tn ][ tm ] ) return nxt[ x ][ tn ][ tm ];
    tag[ x ][ tn ][ tm ] = true;
    if( in( tn + dn[ x % 4 ] , tm + dm[ x % 4 ] ) && 
        c[ tn + dn[ x % 4 ] ][ tm + dm[ x % 4 ] ] != '0' ){
        if( c[ tn + dn[ x % 4 ] ][ tm + dm[ x % 4 ] ] == c[ tn ][ tm ] )
            return nxt[ x ][ tn ][ tm ] = Nxt( x , tn + dn[ x % 4 ] , tm + dm[ x % 4 ] );
        return nxt[ x ][ tn ][ tm ] =
                        make_pair( x , make_pair( tn + dn[ x % 4 ] , tm + dm[ x % 4 ] ) );
    }
    if( x < 4 ) return nxt[ x ][ tn ][ tm ] = Nxt( x + 4 , tn , tm );
    if( x < 7 ) return nxt[ x ][ tn ][ tm ] = Nxt( x - 3 , tn , tm );
    return nxt[ x ][ tn ][ tm ] = Nxt( 0 , tn , tm );
}*/
pair<int,int> NNNxt( int tx , int tn , int tm ){
    while( in( tn + dn[ tx % 4 ] , tm + dm[ tx % 4 ] ) && 
            c[ tn + dn[ tx % 4 ] ][ tm + dm[ tx % 4 ] ] == c[ tn ][ tm ] )
        tn += dn[ tx % 4 ] , tm += dm[ tx % 4 ];
    int ttx;
    if( tx < 4 ){
        ttx = tx - 1;
        if( ttx < 0 ) ttx += 4;
    }else{
        ttx = tx - 3;
        if( ttx >= 4 ) ttx -= 4; 
    }
    while( in( tn + dn[ ttx % 4 ] , tm + dm[ ttx % 4 ] ) && 
            c[ tn + dn[ ttx % 4 ] ][ tm + dm[ ttx % 4 ] ] == c[ tn ][ tm ] )
        tn += dn[ ttx % 4 ] , tm += dm[ ttx % 4 ];
    if( in( tn + dn[ tx % 4 ] , tm + dm[ tx % 4 ] ) &&
            c[ tn + dn[ tx % 4 ] ][ tm + dm[ tx % 4 ] ] != '0' )
        return make_pair( tn + dn[ tx % 4 ] , tm + dm[ tx % 4 ] );
    return make_pair( -1 , -1 );
}
pair< int , pair<int,int> > Nxt( int x , int tn , int tm ){
    if( tag[ x ][ tn ][ tm ] ) return nxt[ x ][ tn ][ tm ];
    tag[ x ][ tn ][ tm ] = true;
    pair<int,int> tp = NNNxt( x , tn , tm );
    if( tp.first != -1 ) return nxt[ x ][ tn ][ tm ] = make_pair( x , tp );
    if( x < 4 ) return nxt[ x ][ tn ][ tm ] = make_pair( x + 4 , make_pair( tn , tm ) );
    if( x < 7 ) return nxt[ x ][ tn ][ tm ] = make_pair( x - 3 , make_pair( tn , tm ) );
    return nxt[ x ][ tn ][ tm ] = make_pair( 0 , make_pair( tn , tm ) );
}
void solve(){
    for( int i = 0 ; i < 8 ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            for( int k = 1 ; k <= m ; k ++ )
                if( c[ j ][ k ] != '0' )
                    nxt[ i ][ j ][ k ] = Nxt( i , j , k );
    int nowx = 0 , nown = 1 , nowm = 1;
    while( cnt -- ){
        pair< int , pair<int,int> > tp = nxt[ nowx ][ nown ][ nowm ];
        nowx = tp.first;
        nown = tp.second.first;
        nowm = tp.second.second;
    }
    putchar( c[ nown ][ nowm ] );
}
int main(){
    init();
    solve();
}