// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 202020
struct ST{
  int c[ 5 ][ 5 ];
} st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int a[ N ];
void pull( ST& now , const ST& lc , const ST& rc ){
  for( int i = 0 ; i < 5 ; i ++ )
    for( int j = 0 ; j < 5 ; j ++ )
      now.c[ i ][ j ] = N;
  for( int i = 0 ; i < 5 ; i ++ )
    for( int j = i ; j < 5 ; j ++ )
      for( int k = j ; k < 5 ; k ++ )
        now.c[ i ][ k ] = min( now.c[ i ][ k ],
                               lc.c[ i ][ j ] + rc.c[ j ][ k ] );
}
void build_st( int no , int l , int r ){
  for( int i = 0 ; i < 5 ; i ++ ){
    for( int j = 0 ; j < 5 ; j ++ )
        st[ no ].c[ i ][ j ] = N;
    st[ no ].c[ i ][ i ] = 0;
  }
  if( l == r ){
    int x = a[ l ];
    if( x == 6 ){
      st[ no ].c[ 3 ][ 3 ] = 1;
      st[ no ].c[ 4 ][ 4 ] = 1;
    }else if( x == 2 ){
      st[ no ].c[ 0 ][ 0 ] = 1;
      st[ no ].c[ 0 ][ 1 ] = 0;
    }else if( x == 0 ){
      st[ no ].c[ 1 ][ 1 ] = 1;
      st[ no ].c[ 1 ][ 2 ] = 0;
    }else if( x == 1 ){
      st[ no ].c[ 2 ][ 2 ] = 1;
      st[ no ].c[ 2 ][ 3 ] = 0;
    }else if( x == 7 ){
      st[ no ].c[ 3 ][ 3 ] = 1;
      st[ no ].c[ 3 ][ 4 ] = 0;
    }else
      assert( false );
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  pull( st[ no ] , st[ L( no ) ] , st[ R( no ) ] );
}
ST query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return st[ no ];
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid <  ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  ST lc = query( L( no ) , l , mid , ql , mid );
  ST rc = query( R( no ) , mid + 1 , r , mid + 1 , qr );
  ST ret;
  for( int i = 0 ; i < 5 ; i ++ ){
    for( int j = 0 ; j < 5 ; j ++ )
      ret.c[ i ][ j ] = N;
    ret.c[ i ][ i ] = 0;
  }
  pull( ret , lc , rc );
  return ret;
}
void build(){
}
int n , q , l[ N ] , r[ N ] , idx[ N ] , nn;
char c[ N ];
void init(){
  scanf( "%d%d" , &n , &q );
  scanf( "%s" , c + 1 );
  int ii = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( c[ i ] <= '2' || c[ i ] == '6' || c[ i ] == '7' ){
      idx[ i ] = ++ ii;
      a[ idx[ i ] ] = c[ i ] - '0';
    }
  nn = ii;
  for( int i = n , lst = n + 1 ; i >= 1 ; i -- ){
    if( idx[ i ] ) lst = idx[ i ];
    l[ i ] = lst;
  }
  for( int i = 1 , lst = 0 ; i <= n ; i ++ ){
    if( idx[ i ] ) lst = idx[ i ];
    r[ i ] = lst;
  }
}
void solve(){
  build_st( 1 , 1 , nn );
  while( q -- ){
    int ql = getint();
    int qr = getint();
    int qql = l[ ql ] , qqr = r[ qr ];
    if( qqr - qql + 1 < 4 ){
      puts( "-1" );
      continue;
    }
    ST ret = query( 1 , 1 , nn , qql , qqr );
    int ans = ret.c[ 0 ][ 4 ];
    if( ans > n ) ans = -1;
    printf( "%d\n" , ans );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}