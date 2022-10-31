// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
#define N 2020
int n , h , x[ N ];
int lmst[ N ];
int rmst[ N ];
int lv[ N ][ N ];
int rv[ N ][ N ];
D p , rp;
void build(){

}
void init(){
  n = getint();
  h = getint();
  double tp;
  scanf( "%lf" , &tp );
  p = tp;
  rp = 1.0 - p;
  for( int i = 1 ; i <= n ; i ++ )
    x[ i ] = getint();
  sort( x + 1 , x + n + 1 );
  for( int i = 1 ; i <= n ; i ++ ){
    lmst[ i ] = i; lv[ i ][ i ] = h;
    if( i > 1 && x[ i ] - x[ i - 1 ] < h ){
      lmst[ i ] = lmst[ i - 1 ];
      for( int j = lmst[ i ] ; j < i ; j ++ )
        lv[ i ][ j ] = x[ i ] - x[ j ] + h;
    }
  }
  for( int i = n ; i >= 1 ; i -- ){
    rmst[ i ] = i; rv[ i ][ i ] = h;
    if( i < n && x[ i + 1 ] - x[ i ] < h ){
      rmst[ i ] = rmst[ i + 1 ];
      for( int j = rmst[ i ] ; j > i ; j -- )
        rv[ i ][ j ] = x[ j ] - x[ i ] + h;
    }
  }
}
D dp[ N ][ N ][ 4 ];
bool got[ N ][ N ][ 4 ];
// 0 <- ->
// 1 <- <-
// 2 -> ->
// 3 -> <-
D DP( int li , int ri , int msk ){
  if( li > ri ) return 0.0;
  if( got[ li ][ ri ][ msk ] )
    return dp[ li ][ ri ][ msk ];
  got[ li ][ ri ][ msk ] = true;
  D suml = 0.0 , sumr = 0.0;
  int bns;
// choose li
  if( msk < 2 ) bns = min( h , li == 1 ? h : x[ li ] - x[ li - 1 ] );
  else bns = ( li == 1 ? h : min( h , ( x[ li ] - x[ li - 1 ] ) - h ) );
  suml += ( bns + DP( li + 1 , ri , msk & 1 ) );
  // printf( "%d %d %d : %.4f %.4f\n" , li , ri , msk , (double)suml , (double)sumr );
  if( rmst[ li ] < ri || ri == n )
    sumr += ( (D)rv[ li ][ rmst[ li ] ] +
                        DP( rmst[ li ] + 1 , ri , 2 + ( msk & 1 ) ) );
  else if( rmst[ li ] > ri )
    sumr += (D)( x[ ri + 1 ] - x[ li ] );
  else{
    sumr += (D)( x[ ri ] - x[ li ] );
    if( msk & 1 ) sumr += min( h , ( x[ ri + 1 ] - x[ ri ] ) - h );
    else sumr += h;
  }
  // printf( "%d %d %d : %.4f %.4f\n" , li , ri , msk , (double)suml , (double)sumr );
// choose ri
  if( msk & 1 ) bns = ( ri == n ? h : min( h , ( x[ ri + 1 ] - x[ ri ] ) - h ) );
  else bns = min( h , ri == n ? h : x[ ri + 1 ] - x[ ri ] );
  sumr += ( bns + DP( li , ri - 1 , msk & 2 ) );
  // printf( "%d %d %d : %.4f %.4f\n" , li , ri , msk , (double)suml , (double)sumr );
  if( lmst[ ri ] > li || li == 1 )
    suml += ( (D)lv[ ri ][ lmst[ ri ] ] +
                        DP( li , lmst[ ri ] - 1 , 1 + ( msk & 2 ) ) );
  else if( lmst[ ri ] < li )
    suml += (D)( x[ ri ] - x[ li - 1 ] );
  else{
    suml += (D)( x[ ri ] - x[ li ] );
    if( msk >= 2 ) suml += min( h , ( x[ li ] - x[ li - 1 ] ) - h );
    else suml += h;
  }
  // printf( "%d %d %d : %.4f %.4f\n" , li , ri , msk , (double)suml , (double)sumr );
  return dp[ li ][ ri ][ msk ] = ( suml * p + sumr * rp ) * 0.5;
}
void solve(){
  printf( "%.12f\n" , (double)DP( 1 , n , 0 ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}