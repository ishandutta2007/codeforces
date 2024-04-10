#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N (1 << 20)
inline int add( int x , int y , int mod ){
  x += y;
  return x >= mod ? x - mod : x;
}
inline int sub( int x , int y , int mod ){
  x -= y;
  return x < 0 ? x + mod : x;
}
inline int mul( LL x , int y , int mod ){
  x *= y;
  return x >= mod ? x % mod : x;
}
const int BS = 13131;
int mods[3] = {1000000007, 1000000009};
struct Int{
  int v[3];
  Int( int _v = 0 ){
    for( int i = 0 ; i < 3 ; i ++ )
      v[ i ] = _v % mods[ i ];
  }
  Int operator+( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < 3 ; i ++ )
      ret.v[ i ] = add( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  Int operator-( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < 3 ; i ++ )
      ret.v[ i ] = sub( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  Int operator*( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < 3 ; i ++ )
      ret.v[ i ] = mul( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  bool operator==( const Int& he ) const{
    for( int i = 0 ; i < 3 ; i ++ )
      if( v[ i ] != he.v[ i ] )
        return false;
    return true;
  }
};
Int bs[ N ] , hs[ N ];
char c[ N ];
int n;
void init(){
  bs[ 0 ] = Int( 1 );
  bs[ 1 ] = Int( BS );
  for( int i = 2 ; i < N ; i ++ )
    bs[ i ] = bs[ i - 1 ] * bs[ 1 ];
  scanf( "%d" , &n );
  scanf( "%s" , c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    hs[ i ] = hs[ i - 1 ] * bs[ 1 ] + Int( c[ i ] );
}
Int hs_vl( int ql , int qr ){
  return hs[ qr ] - hs[ ql - 1 ] * bs[ qr - ql + 1 ];
}
bool equal( int l1 , int r1 , int l2 , int r2 ){
  return hs_vl( l1 , r1 ) ==
         hs_vl( l2 , r2 );
}
void solve(){
  int l = 1 , r = n;
  while( l <= r ) l ++ , r --;
  l --, r ++;
  int pans = -1;
  vector<int> ans;
  while( l > 0 ){
    int cans = -1;
    int atmst = min( pans + 2 , r - l );
    if( (atmst & 1) == 0 ) atmst --;
    for( int i = atmst ; i >= 1 ; i -= 2 )
      if( equal( l , l + i - 1 , r - i + 1 , r ) ){
        cans = i;
        break;
      }
    ans.push_back( cans );
    pans = cans;
    l -- , r ++ ;
  }
  reverse( ans.begin() , ans.end() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  srand( time(0) );
  while( true ){
    int rnd = 1000000000 + (rand() & ((1 << 15) - 1));
    bool is_p = true;
    for( int i = 2 ; (LL)i * i <= rnd ; i ++ )
      if( rnd % i == 0 ){
        is_p = false;
        break;
      }
    if( is_p ){
      mods[ 2 ] = rnd;
      cerr << rnd << endl;
      break;
    }
  }
  init();
  solve();
}