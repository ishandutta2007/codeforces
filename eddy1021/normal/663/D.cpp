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
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 5555
#define K 90
int n , a[ N ][ 3 ] , ans , thk , hk[ 3 ] , ac[ 3 ];
int sc[7]={2,4,6,8,10,12};
int lb[7]={2,4,8,16,32,64,55555};
void build(){

}
void init(){
  ans = n = getint();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < 3 ; j ++ ){
      a[ i ][ j ] = getint();
      if( a[ i ][ j ] < 0 ){
        thk ++; hk[ j ] ++;
      }
      if( a[ i ][ j ] )
        ac[ j ] ++;
    }
}
int dp[ 2 ][ K ][ K ][ K ];
int asc[ 9 ] , lac[ 9 ] , rac[ 9 ] , ghk[ 9 ];
int par[ K ][ 3 ] , pi[ K ];
inline int score( int idx , int msk = 0 ){
  int totalsc = 0;
  for( int i = 0 ; i < 3 ; i ++ ){
    if( ( ( msk >> i ) & 1 ) || a[ idx ][ i ] == 0 ) continue;
    totalsc += sc[ asc[ i ] ] * ( 250 - abs( a[ idx ][ i ] ) );
  }
  return totalsc;
}
void calc(){
  int shk = 0;
  for( int i = 0 ; i < 3 ; i ++ ){
    lac[ i ] = 2 * n / lb[ asc[ i ] + 1 ];
    while( lac[ i ] * lb[ asc[ i ] + 1 ] <= 2 * n ) lac[ i ] ++;
    if( asc[ i ] == 5 ) lac[ i ] = 0;
    rac[ i ] = 2 * n / lb[ asc[ i ] ];
    if( lac[ i ] > rac[ i ] ||
        lac[ i ] > ac[ i ]  ||
        rac[ i ] < ac[ i ] - hk[ i ] ) return;
    ghk[ i ] = min( hk[ i ] , ac[ i ] - lac[ i ] );
    shk += ghk[ i ];
  }
  int part = 0, rank = 1;
  int mysc = score( 0 ) + shk * 100;
  for( int i = 1 ; i < n ; i ++ )
    if( score( i ) > mysc ){
      rank ++;
      if( a[ i ][ 0 ] < 0 || a[ i ][ 1 ] < 0 || a[ i ][ 2 ] < 0 ){
        pi[ part ] = i;
        for( int j = 0 ; j < 3 ; j ++ )
          par[ part ][ j ] = a[ i ][ j ];
        part ++;
      }
    }
  for( int i = 0 ; i <= ghk[ 0 ] ; i ++ )
    for( int j = 0 ; j <= ghk[ 1 ] ; j ++ )
      for( int k = 0 ; k <= ghk[ 2 ] ; k ++ )
        dp[ 0 ][ i ][ j ][ k ] = 0;
  for( int p = 0 ; p < part ; p ++ ){
    int now = p & 1 , nxt = 1 - now;
    for( int i = 0 ; i <= ghk[ 0 ] ; i ++ )
      for( int j = 0 ; j <= ghk[ 1 ] ; j ++ )
        for( int k = 0 ; k <= ghk[ 2 ] ; k ++ )
          dp[ nxt ][ i ][ j ][ k ] = dp[ now ][ i ][ j ][ k ];
    for( int msk = 1 ; msk < 8 ; msk ++ ){
      bool pos = true;
      int cha[ 3 ]={0};
      for( int ii = 0 ; ii < 3 ; ii ++ )
        if( ( msk >> ii ) & 1 ){
          cha[ ii ] = 1;
          if( par[ p ][ ii ] >= 0 ){
            pos = false; break;
          }
        }
      if( !pos ) continue;
      int xxsc = score( pi[ p ] , msk );
      if( xxsc <= mysc ){
        for( int i = cha[ 0 ] ; i <= ghk[ 0 ] ; i ++ )
          for( int j = cha[ 1 ] ; j <= ghk[ 1 ] ; j ++ )
            for( int k = cha[ 2 ] ; k <= ghk[ 2 ] ; k ++ )
              dp[ nxt ][ i ][ j ][ k ] = max( dp[ nxt ][ i ][ j ][ k ] , 
                                              dp[ now ][ i - cha[ 0 ] ][ j - cha[ 1 ] ][ k - cha[ 2 ] ] + 1 );
        
      }
    }
  }
  int imp = 0;
  for( int i = 0 ; i <= ghk[ 0 ] ; i ++ )
    for( int j = 0 ; j <= ghk[ 1 ] ; j ++ )
      for( int k = 0 ; k <= ghk[ 2 ] ; k ++ )
        imp = max( imp , dp[ part & 1 ][ i ][ j ][ k ] );
  ans = min( ans , rank - imp );
}
void solve(){
  if( thk >= 90 ){
    puts( "1" );
    exit( 0 );
  }
  for( int sc0 = 0 ; sc0 < 6 ; sc0 ++ )
    for( int sc1 = 0 ; sc1 < 6 ; sc1 ++ )
      for( int sc2 = 0 ; sc2 < 6 ; sc2 ++ ){
        asc[ 0 ] = sc0;
        asc[ 1 ] = sc1;
        asc[ 2 ] = sc2;
        calc();
      }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}