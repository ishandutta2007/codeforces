// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
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
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 3333
struct Hash{
  ll BS , mod , bs[ N ] , hs[ N ];
  Hash( ll _bs , ll _mod ) : BS( _bs ) , mod( _mod ) {}
  void init(){
    bs[ 0 ] = 1ll;
    for( int i = 1 ; i < N ; i ++ )
      bs[ i ] = mul( bs[ i - 1 ] , BS , mod );
  }
  void build( char* tc , int len ){
    hs[ 0 ] = tc[ 0 ];
    for( int i = 1 ; i < len ; i ++ )
      hs[ i ] = add( mul( hs[ i - 1 ] , BS , mod ) , tc[ i ] , mod );
  }
  ll vl( int l , int r ){
    if( l == 0 ) return hs[ r ];
    return sub( hs[ r ] , mul( hs[ l - 1 ] , bs[ r - l + 1 ] , mod ) , mod );
  }
};
char c[ 3 ][ N ];
int len[ 3 ];
void build(){

}
bool st[ 2 ][ 26 ];
void init(){
  for( int i = 0 ; i < 2 ; i ++ ){
    scanf( "%s" , c[ i ] + 1 );
    len[ i ] = strlen( c[ i ] + 1 );
    for( int j = 1 ; j <= len[ i ] ; j ++ )
      st[ i ][ c[ i ][ j ] - 'a' ] = true;
  }
  for( int i = len[ 0 ] ; i >= 1 ; i -- )
    c[ 2 ][ len[ 0 ] - i + 1 ] = c[ 0 ][ i ];
  len[ 2 ] = len[ 0 ];
}
Hash h0( 13131 , mod7 );
Hash h1( 13131 , mod7 );
Hash h2( 13131 , mod7 );
void solve(){
  for( int i = 0 ; i < 26 ; i ++ )
    if( st[ 1 ][ i ] && !st[ 0 ][ i ] ){
      puts( "-1" );
      exit( 0 );
    }
  h0.init();
  h1.init();
  h2.init();
  h0.build( c[ 0 ] + 1 , len[ 0 ] );
  h1.build( c[ 1 ] + 1 , len[ 1 ] );
  h2.build( c[ 2 ] + 1 , len[ 2 ] );
  vector<PII> ans;
  for( int l = 1 ; l <= len[ 1 ] ; ){
    int mlen = len[ 1 ] - l + 1;
    int bst1 = -1 , bst2 = -1;
    int st1 = -1 , st2 = -1;
    for( int i = 0 ; i < len[ 0 ] ; i ++ ){
      int bl = 1 , br = min( mlen , len[ 0 ] - i ) , bmid , ba = -1;
      if( c[ 0 ][ i + 1 ] != c[ 1 ][ l ] ) continue;
      while( bl <= br ){
        bmid = ( bl + br ) >> 1;
        if( h0.vl( i , i + bmid - 1 ) ==
            h1.vl( l - 1 , l + bmid - 2 ) ) ba = bmid , bl = bmid + 1;
        else br = bmid - 1;
      }
      if( ba > bst1 ) bst1 = ba , st1 = i + 1;
    }
    for( int i = 0 ; i < len[ 0 ] ; i ++ ){
      int bl = 1 , br = min( mlen , len[ 0 ] - i ) , bmid , ba = -1;
      if( c[ 2 ][ i + 1 ] != c[ 1 ][ l ] ) continue;
      while( bl <= br ){
        bmid = ( bl + br ) >> 1;
        if( h2.vl( i , i + bmid - 1 ) ==
            h1.vl( l - 1 , l + bmid - 2 ) ) ba = bmid , bl = bmid + 1;
        else br = bmid - 1;
      }
      if( ba > bst2 ) bst2 = ba , st2 = i;
    }
    if( bst1 > bst2 ){
      l += bst1;
      ans.PB( MP( st1 , st1 + bst1 - 1 ) );
    }else{
      l += bst2;
      ans.PB( MP( len[ 0 ] - st2 , len[ 0 ] - st2 - bst2 + 1 ) );
    }
  }
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d %d\n" , ans[ i ].FI , ans[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}