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
#define N 131072
struct Permu{
  int a[ 10 ];
  Permu(){
    for( int i = 0 ; i < 10 ; i ++ )
      a[ i ] = i;
  }
  Permu operator*( const Permu& he ) const{
    Permu ret;
    for( int i = 0 ; i < 10 ; i ++ )
      ret.a[ i ] = he.a[ a[ i ] ];
    return ret;
  }
};
struct SegT{
  LL st[ N << 1 ][ 10 ];
  Permu p[ N << 1 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
  void build_st( int no , int l , int r ){
    for( int i = 0 ; i < 10 ; i ++ )
      st[ no ][ i ] = 0;
    p[ no ] = Permu();
    if( l == r ) return;
    build_st( L( no ) , l , mid );
    build_st( R( no ) , mid + 1 , r );
  }
  void add( int no , int l , int r , int pos , int vv , LL dlt ){
    st[ no ][ vv ] += dlt;
    if( l == r ) return;
    if( pos <= mid ) add( L( no ) , l , mid , pos , vv , dlt );
    else add( R( no ) , mid + 1 , r , pos , vv , dlt );
  }
  void push( int no , int l , int r ){
    bool dif = false;
    for( int i = 0 ; i < 10 ; i ++ )
      if( p[ no ].a[ i ] != i ){
        dif = true;
        break;
      }
    if( not dif ) return;
    LL tmp[ 10 ];
    for( int id : { L( no ) , R( no ) } ){
      for( int i = 0 ; i < 10 ; i ++ )
        tmp[ i ] = 0;
      for( int i = 0 ; i < 10 ; i ++ )
        tmp[ p[ no ].a[ i ] ] += st[ id ][ i ];
      for( int i = 0 ; i < 10 ; i ++ )
        st[ id ][ i ] = tmp[ i ];
      p[ id ] = p[ id ] * p[ no ];
    }
    p[ no ] = Permu();
  }
  void modify( int no , int l , int r , int ql , int qr , int fr , int to ){
    if( qr < l or ql > r ) return;
    if( ql <= l and r <= qr ){
      Permu tp;
      tp.a[ fr ] = to;
      p[ no ] = p[ no ] * tp;
      st[ no ][ to ] += st[ no ][ fr ];
      st[ no ][ fr ] = 0;
      return;
    }
    push( no , l , r );
    modify( L( no ) , l , mid , ql , qr , fr , to );
    modify( R( no ) , mid + 1 , r , ql , qr , fr , to );
    for( int i = 0 ; i < 10 ; i ++ )
      st[ no ][ i ] = st[ L( no ) ][ i ] + st[ R( no ) ][ i ];
  }
  LL query( int no , int l , int r , int ql , int qr ){
    if( qr < l or ql > r ) return 0;
    if( ql <= l and r <= qr ){
      LL ret = 0;
      for( int i = 1 ; i < 10 ; i ++ )
        ret += i * st[ no ][ i ];
      return ret;
    }
    push( no , l , r );
    return query( L( no ) , l , mid , ql , qr ) +
           query( R( no ) , mid + 1 , r , ql , qr );
  }
} st;
LL bs[ 10 ];
void build(){
  bs[ 0 ] = 1;
  for( int i = 1 ; i < 10 ; i ++ )
    bs[ i ] = bs[ i - 1 ] * 10;
}
int n , q;
void init(){
  n = getint();
  q = getint();
  st.build_st( 1 , 1 , n );
  for( int i = 1 ; i <= n ; i ++ ){
    int ai = getint();
    for( int j = 0 ; j < 9 ; j ++ ){
      if( ai == 0 ) break;
      st.add( 1 , 1 , n , i , ai % 10 , bs[ j ] );
      ai /= 10;
    }
  }
}
void solve(){
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ){
      int l = getint();
      int r = getint();
      int x = getint();
      int y = getint();
      if( x == y ) continue;
      for( int i = 0 ; i < 9 ; i ++ )
        st.modify( 1 , 1 , n , l , r , x , y );
    }else{
      int l = getint();
      int r = getint();
      printf( "%lld\n" , st.query( 1 , 1 , n , l , r ) );
    }
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