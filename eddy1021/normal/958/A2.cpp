#include <bits/stdc++.h>
using namespace std;
#define BS 13131
typedef long long LL;
inline int add( int a , int b , int mod ){
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub( int a , int b , int mod ){
  a -= b;
  return a < 0 ? a + mod : a;
}
inline int mul( LL a , int b , int mod ){
  a *= b;
  return a >= mod ? a % mod : a;
}
const int mods[] = {1000000007, 1000000009};
struct Int{
  int vl[ 2 ];
  Int( int x = 0 ){
    vl[ 0 ] = vl[ 1 ] = x;
  }
  Int operator+( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < 2 ; i ++ )
      ret.vl[ i ] = add( vl[ i ] , he.vl[ i ] , mods[ i ] );
    return ret;
  }
  Int operator-( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < 2 ; i ++ )
      ret.vl[ i ] = sub( vl[ i ] , he.vl[ i ] , mods[ i ] );
    return ret;
  }
  Int operator*( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < 2 ; i ++ )
      ret.vl[ i ] = mul( vl[ i ] , he.vl[ i ] , mods[ i ] );
    return ret;
  }
  LL to_ll() const{
    return (LL)vl[ 0 ] * mods[ 1 ] + vl[ 1 ];
  }
};
#define N (1 << 12)
int n , m;
unordered_map<LL,int> memo;
char c1[ N ][ N ];
char c2[ N ][ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c1[ i ] + 1 );
  for( int i = 1 ; i <= m ; i ++ )
    scanf( "%s" , c2[ i ] + 1 );
}
Int vl[ N ] , bs[ N ] , Bs( BS );
Int vl2[ 222 ][ N ];
Int hs_vl( int ii , int j1 , int j2 ){
  return vl2[ ii ][ j2 ] - vl2[ ii ][ j1 - 1 ] * bs[ j2 - j1 + 1 ];
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      vl[ i ] = vl[ i ] * Bs + Int( c1[ i ][ j ] );
  for( int i = 1 ; i + m - 1 <= n ; i ++ ){
    Int ret;
    for( int j = 0 ; j < m ; j ++ )
      ret = ret * bs[ m ] + vl[ i + j ];
    memo[ ret.to_ll() ] = i;
  }
  for( int i = 1 ; i <= m ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      vl2[ i ][ j ] = vl2[ i ][ j - 1 ] * Bs + Int( c2[ i ][ j ] );
  for( int j = 1 ; j + m - 1 <= n ; j ++ ){
    Int ret;
    for( int i = 1 ; i <= m ; i ++ )
      ret = ret * bs[ m ] + hs_vl( i , j , j + m - 1 );
    LL val = ret.to_ll();
    auto it = memo.find( val );
    if( it != memo.end() ){
      printf( "%d %d\n" , it->second , j );
      exit(0);
    }
  }
  assert( false );
}
int main(){
  bs[ 0 ] = Int( 1 );
  for( int i = 1 ; i < N ; i ++ )
    bs[ i ] = bs[ i - 1 ] * Bs;
  init();
  solve();
}