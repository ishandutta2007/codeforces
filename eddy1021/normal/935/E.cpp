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
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 10101
#define K 101
#define PLUS 0
#define MINUS 1
void build(){

}
int who , til;
struct State{
  int mx[ K ] , mn[ K ] , mst;
  bool g[ K ];
  State( int vl = -1 ){
    for( int i = 0 ; i < K ; i ++ )
      g[ i ] = false;
    mst = 0;
    if( vl != -1 ){
      mx[ 0 ] = mn[ 0 ] = vl;
      g[ 0 ] = true;
      mst = 1;
    }
  }
  void upd( int at , int vl ){
    if( at > til ) return;
    if( !g[ at ] ){
      g[ at ] = true;
      mx[ at ] = mn[ at ] = vl;
    }else{
      mx[ at ] = max( mx[ at ] , vl );
      mn[ at ] = min( mn[ at ] , vl );
    }
    mst = max( mst , at + 1 );
  }
  State operator^( const State& he ) const{
    State ret;
    for( int i = 0 ; i < mst ; i ++ ) if( g[ i ] )
      for( int j = 0 ; j < he.mst ; j ++ ) if( he.g[ j ] ){
        int to = i + j + (who == PLUS);
        ret.upd( to , mx[ i ] + he.mx[ j ] );
        ret.upd( to , mn[ i ] + he.mn[ j ] );
      }
    for( int i = 0 ; i < mst ; i ++ ) if( g[ i ] )
      for( int j = 0 ; j < he.mst ; j ++ ) if( he.g[ j ] ){
        int to = i + j + (who == MINUS);
        ret.upd( to , mx[ i ] - he.mn[ j ] );
        ret.upd( to , mn[ i ] - he.mx[ j ] );
      }
    return ret;
  }
};
char e[ N ];
int p , m , len;
void init(){
  scanf( "%s" , e );
  len = strlen( e );
  p = getint();
  m = getint();
  who = (p < m ? PLUS : MINUS);
  til = min( p , m );
}
int bl[ N ];
State go( int l , int r ){
  vector<State> vv;
  for( int i = l ; i <= r ; ){
    if( e[ i ] == '(' ){
      vv.push_back( go( i + 1 , bl[ i ] - 1 ) );
      i = bl[ i ] + 1;
      continue;
    }
    if( e[ i ] == '?' ){
      i ++;
      continue;
    }
    if( isdigit( e[ i ] ) ){
      vv.push_back( State( e[ i ] - '0' ) );
      i ++;
      continue;
    }
  }
  if( vv.size() == 1u ) return vv[ 0 ];
  return vv[ 0 ] ^ vv[ 1 ];
}
void solve(){
  vector<int> v;
  for( int i = 0 ; i < len ; i ++ ){
    if( e[ i ] == '(' )
      v.push_back( i );
    else if( e[ i ] == ')' ){
      bl[ v.back() ] = i;
      v.pop_back();
    }
  }
  printf( "%d\n" , go( 0 , len - 1 ).mx[ who == PLUS ? p : m ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}