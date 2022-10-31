// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
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
#define N 300010
vector<int> ls;
int get_no( int tmp ){
    return lower_bound( ls.begin() , ls.end() , tmp ) - ls.begin();
}
int n , m , l[ N ] , r[ N ] , a[ N ] , b[ N ] , c[ N ];
ll ans; int a1 , a2;
typedef tuple<int,int,int> tii;
typedef tuple<int,int,int,int> tiii;
void build(){

}
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < n ; i ++ ){
        l[ i ] = getint(); ls.PB( l[ i ] );
        r[ i ] = getint(); ls.PB( r[ i ] );
    }
    for( int i = 0 ; i < m ; i ++ ){
        a[ i ] = getint(); ls.PB( a[ i ] );
        b[ i ] = getint();
        c[ i ] = getint();
    }
    sort( ls.begin() , ls.end() );
    ls.resize( unique( ls.begin() , ls.end() ) - ls.begin() );
}
vector<tii> p;
vector<tiii> v;
int BIT[ N << 1 ] , sn , BITno[ N << 1 ];
int lb( int x ){ return x & (-x); }
void insert( int x , int tmp , int tno ){
    while( x <= sn ){
        if( tmp > BIT[ x ] ){
            BIT[ x ] = tmp;
            BITno[ x ] = tno;
        }
        x += lb( x );
    }
}
PII query( int x ){
    int tans = 0 , tno = 0;
    while( x ){
        if( BIT[ x ] > tans ){
            tans = BIT[ x ];
            tno = BITno[ x ];
        }
        x -= lb( x );
    }
    return MP( tans , tno );
}
void type1(){
    for( int i = 0 ; i < n ; i ++ )
        p.PB( make_tuple( r[ i ] , l[ i ] , i ) );
    sort( p.begin() , p.end() );
    for( int i = 0 ; i < m ; i ++ )
        v.PB( make_tuple( b[ i ] , a[ i ] , c[ i ] , i ) );
    sort( v.begin() , v.end() );
    sn = (int)ls.size();
    int pt = 0;
    for( int i = 0 ; i < m ; i ++ ){
        while( pt < n && get<0>( p[ pt ] ) <= get<0>( v[ i ] ) ){
            insert( sn - get_no( get<1>( p[ pt ] ) ) , get<0>( p[ pt ] ) - get<1>( p[ pt ] ) , get<2>( p[ pt ] ) );
//            printf( "%d %d %d\n" ,  sn - get_no( get<1>( p[ pt ] ) ) , 
//                                    get<0>( p[ pt ] ) - get<1>( p[ pt ] ) , get<2>( p[ pt ] )  );
            pt ++;
        }
        PII bst = query( sn - get_no( get<1>( v[ i ] ) ) );
//        printf( "%d\n" ,  sn - get_no( get<1>( v[ i ] ) ) );
//        printf( "%d %d\n" , bst.FI , bst.SE );
        ll tans = (ll)bst.FI * (ll)get<2>( v[ i ] );
        if( tans > ans ){
            ans = tans;
            a1 = bst.SE;
            a2 = get<3>( v[ i ] );
        }
    }
}
void type2(){
    int minl = INF , pt = n - 1 , bstno = 0;
    for( int i = m - 1 ; i >= 0 ; i -- ){
        while( pt >= 0 && get<0>( p[ pt ] ) >= get<0>( v[ i ] ) ){
            if( get<1>( p[ pt ] ) < minl ){
                minl = get<1>( p[ pt ] );
                bstno = get<2>( p[ pt ] );
            }
            pt --;
        }
        if( minl == INF ) continue;
        ll tans =  (ll)( get<0>( v[ i ] ) - max( get<1>( v[ i ] ) , minl ) ) * (ll)get<2>( v[ i ] );
        if( tans > ans ){
            ans = tans;
            a1 = bstno;
            a2 = get<3>( v[ i ] );
        }
    }
    p.clear(); v.clear();
    for( int i = 0 ; i < n ; i ++ )
        p.PB( make_tuple( l[ i ] , r[ i ] , i ) );
    sort( p.begin() , p.end() );
    for( int i = 0 ; i < m ; i ++ )
        v.PB( make_tuple( a[ i ] , b[ i ] , c[ i ] , i ) );
    sort( v.begin() , v.end() );
    int maxr = -INF; pt = bstno = 0;
    for( int i = 0 ; i < m ; i ++ ){
        while( pt < n && get<0>( p[ pt ] ) <= get<0>( v[ i ] ) ){
            if( get<1>( p[ pt ] ) > maxr ){
                maxr = get<1>( p[ pt ] );
                bstno = get<2>( p[ pt ] );
            }
            pt ++;
        }
        if( maxr == -INF ) continue;
        ll tans = (ll)( min( get<1>( v[ i ] ) , maxr ) - get<0>( v[ i ] ) ) * (ll)get<2>( v[ i ] );
        if( tans > ans ){
            ans = tans;
            a1 = bstno;
            a2 = get<3>( v[ i ] );
        }
    }
}
void solve(){
    type1();
    type2();
    cout << ans << endl;
    if( ans ) cout << a1 + 1 << " " << a2 + 1 << endl;
}
int main(){
    build();
    //  __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}