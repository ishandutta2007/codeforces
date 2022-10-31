// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
void build(){

}
#define N 16
int n , tp[ N ] , r[ N ] , b[ N ] , sr[ 1 << N ] , sb[ 1 << N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    char clr[ 9 ];
    scanf( "%s%d%d" , clr , &r[ i ] , &b[ i ] );
    tp[ i ] = ( clr[ 0 ] == 'R' ? 0 : 1 );
  }
  for( int i = 0 ; i < ( 1 << n ) ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      if( ( i >> j ) & 1 ){
        sr[ i ] = sr[ i ^ ( 1 << j ) ];
        sb[ i ] = sb[ i ^ ( 1 << j ) ];
        if( tp[ j ] == 0 ) sr[ i ] ++;
        else sb[ i ] ++;
        break;
      }
}
vector< pair<int,int> > dp[ 1 << N ];
inline bool okay( int tokens ){
  for( int i = 0 ; i < ( 1 << n ) ; i ++ )
    dp[ i ].clear();
  dp[ 0 ].push_back( { tokens , tokens } );
  for( int i = 0 ; i + 1 < ( 1 << n ) ; i ++ ){
    if( dp[ i ].empty() ) continue;
    sort( dp[ i ].begin() , dp[ i ].end() , greater< pair<int,int> >() );
    dp[ i ].resize( unique( dp[ i ].begin() , dp[ i ].end() ) - dp[ i ].begin() );
    size_t sz = 1;
    for( size_t j = 1 ; j < dp[ i ].size() ; j ++ )
      if( dp[ i ][ j ].second > dp[ i ][ sz - 1 ].second )
        dp[ i ][ sz ++ ] = dp[ i ][ j ];
    dp[ i ].resize( sz );
    for( auto j : dp[ i ] ){
      int rev = ( 1 << n ) - i - 1;
      while( rev ){
        int x = rev & (-rev); rev ^= x;
        x = __lg( x );
        int cr = max( 0 , r[ x ] - sr[ i ] );
        int cb = max( 0 , b[ x ] - sb[ i ] );
        int nxtr = j.first - cr;
        int nxtb = j.second - cb;
        if( nxtr < 0 || nxtb < 0 )
          continue;
        int ret = i ^ ( 1 << x );
        dp[ ret ].push_back( { nxtr , nxtb } );
        if( ret == ( 1 << n ) - 1 )
          return true;
      }
    }
  }
  return false;
}
void solve(){
  int lft = 0 , rgt = 0 , ans = 0;
  int rsum = 0 , bsum = 0;
  for( int i = 0 ; i < n ; i ++ ){
    rsum += r[ i ];
    bsum += b[ i ];
  }
  lft = rgt = ans = max( rsum , bsum );
  for( int i = 1 ; i < n ; i ++ )
    lft -= i;
  lft = max( lft , 0 );
  while( lft <= rgt ){
    int mid = ( lft + rgt ) >> 1;
    if( okay( mid ) ) ans = mid , rgt = mid - 1;
    else lft = mid + 1;
  }
  printf( "%d\n" , n + ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}