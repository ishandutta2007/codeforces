// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 202020
typedef long long LL;
const int mod = 1000000007;
inline int add( int a , int b ){
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub( int a , int b ){
  a -= b;
  return a < 0 ? a + mod : a;
}
inline LL mul( LL a , LL b ){
  a *= b;
  return a >= mod ? a % mod : a;
}
inline int mypow( int a , int b ){
  if( b == 0 ) return 1;
  int ret = mypow( mul( a , a ) , b >> 1 );
  if( b & 1 ) ret = mul( ret , a );
  return ret;
}
int fac[ N ] , inv[ N ];
void build(){
  fac[ 0 ] = inv[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    inv[ i ] = mypow( fac[ i ] , mod - 2 );
  }
}
inline int C( int a , int b ){
  if( a < b ) return 0;
  return mul( fac[ a ] , mul( inv[ b ] , inv[ a - b ] ) );
}
#define K 25
int n , m , k , s[ K ];
vector< pair<int,int> > v;
void init(){
  scanf( "%d%d%d%d" , &n , &m , &k , &s[ 0 ] );
  for( int i = 0 ; i < k ; i ++ ){
    int ri , ci; scanf( "%d%d" , &ri , &ci );
    v.push_back( { ri , ci } );
  }
  v.push_back( { 1 , 1 } );
  v.push_back( { n , m } );
  sort( v.begin() , v.end() );
  for( int i = 1 ; i < K ; i ++ )
    s[ i ] = ( s[ i - 1 ] + 1 ) >> 1;
}
#define X first
#define Y second
int dp[ N ][ K ];
void solve(){
  dp[ 0 ][ 0 ] = 1;
  k = (int)v.size();
  for( int i = 1 ; i < k ; i ++ )
    for( int u = 0 ; u < i ; u ++ ){
      if( v[ u ].Y > v[ i ].Y ) continue;
      int kd = C( v[ i ].X - v[ u ].X + v[ i ].Y - v[ u ].Y ,
                  v[ i ].X - v[ u ].X );
      for( int j = 0 ; j < K ; j ++ ){
        if( j ) dp[ i ][ j ] = add( dp[ i ][ j ] ,
                                    mul( dp[ u ][ j - 1 ] , kd ) );
        if( u ) dp[ i ][ j ] = sub( dp[ i ][ j ],
                                    mul( dp[ u ][ j ] , kd ) );
      }
    }
  int ans = C( n + m - 2 , n - 1 );
  for( int i = 1 ; i < K ; i ++ )
    ans = add( ans ,
               mul( ( s[ i - 1 ] - 1 ) , dp[ k - 1 ][ i ] ) );
  ans = mul( ans , mypow( C( n + m - 2 , n - 1 ) , mod - 2 ) );
  printf( "%d\n" , ans );
}
int main(){
  build();
  init();
  solve();
}