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
#define N 1021
void build(){

}
int n , a[ 5 ];
char c[ 4 ][ N ];
void init(){
  n = getint();
  for( int i = 1 ; i < 5 ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < 4 ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
}
unordered_map<int,int> dp[ 1 << 16 ][ 5 ];
int nmsk[ 1 << 16 ][ 4 ][ 5 ];
bool gt[ 1 << 16 ][ 4 ][ 5 ];
inline int new_mask( int ori , int who , int tk ){
  if( tk == 0 ) return ori;
  if( gt[ ori ][ who ][ tk ] ) return nmsk[ ori ][ who ][ tk ];
  int oori = ori;
  gt[ ori ][ who ][ tk ] = true;
  int era = ((1 << tk) - 1) << who;
  for( int i = 0 ; i < tk ; i ++ )
    ori &= ~(era << (i << 2));
  return nmsk[ oori ][ who ][ tk ] = ori;
}
int fuck[ 5 ];
void go_cal( int ori , int now , int who , int cst , int mst ){
  if( who == 4 ){
    if( now >> 12 ) return;
    for( int i = max( 1 , mst ) ; i <= 4 ; i ++ ){
      if( now >> (4 * i) ) continue;
      auto it = dp[ ori ][ i ].find( now );
      if( it == dp[ ori ][ i ].end() or
          cst < it->second )
        dp[ ori ][ i ][ now ] = cst;
    }
    return;
  }
  for( int tk = 0 ; tk <= 4 - who ; tk ++ ){
    fuck[ who ] = tk;
    go_cal( ori , new_mask( now , who , tk ) ,
            who + 1 , cst + a[ tk ] , max( mst , tk ) );
  }
}
int Dp[ 2 ][ 1 << 12 ];
void solve(){
  for( int i = 0 ; i < (1 << 16) ; i ++ )
    go_cal( i , i , 0 , 0 , 0 );
  int cur = 0 , pre = 1;
  for( int msk = 0 ; msk < (1 << 12) ; msk ++ )
    Dp[ cur ][ msk ] = INF;
  Dp[ cur ][ 0 ] = 0;
  for( int j = 1 ; j <= n ; j ++ ){
    swap( cur , pre );
    for( int msk = 0 ; msk < (1 << 12) ; msk ++ )
      Dp[ cur ][ msk ] = INF;
    int mst = min( 4 , j );
    for( int msk = 0 ; msk < (1 << 12) ; msk ++ ){
      if( Dp[ pre ][ msk ] == INF ) continue;
      int cmsk = msk;
      for( int i = 0 ; i < 4 ; i ++ )
        cmsk = (cmsk << 1) | (c[ i ][ j ] == '*');
      for( auto x : dp[ cmsk ][ mst ] ){
        int xmsk = x.first;
        int xcst = x.second;
        Dp[ cur ][ xmsk ] = min( Dp[ cur ][ xmsk ] , 
                                 Dp[ pre ][ msk ] + xcst );
      }
    }
  }
  cout << Dp[ cur ][ 0 ] << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}