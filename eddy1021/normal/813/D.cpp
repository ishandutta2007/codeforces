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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 5140
void build(){

}
int n , a[ N ];
queue<int> q[ 101010 ] , q2[ 7 ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    q[ a[ i ] ].push( i );
    q2[ a[ i ] % 7 ].push( i );
  }
}
int dp[ N ][ N ] , ans;
int next( int vl , int rr ){
  while( q[ vl ].size() and q[ vl ].front() <= rr )
    q[ vl ].pop();
  if( q[ vl ].empty() ) return -1;
  return q[ vl ].front();
}
int next2( int vl , int rr ){
  while( q2[ vl ].size() and q2[ vl ].front() <= rr )
    q2[ vl ].pop();
  if( q2[ vl ].empty() ) return -1;
  return q2[ vl ].front();
}
void solve(){
  ans = 2;
  for( int i = 1 ; i <= n ; i ++ ){
    for( int j = i + 1 ; j <= n ; j ++ )
      dp[ i ][ j ] = 2;
    dp[ 0 ][ i ] = 1;
  }
  for( int r = 1 ; r <= n ; r ++ )
    for( int l = 0 ; l < r ; l ++ ){
      if( dp[ l ][ r ] == 0 ) continue;
      ans = max( ans , dp[ l ][ r ] );
      {
        if( l == 0 ){
          for( int nxt = r + 1 ; nxt <= n ; nxt ++ )
            dp[ r ][ nxt ] = max( dp[ r ][ nxt ] , dp[ l ][ r ] + 1 );
        }else{
          for( int dlt = -1 ; dlt <= 1 ; dlt += 2 ){
            int nxt = next( a[ l ] + dlt , r );
            if( nxt == -1 ) continue;
            dp[ r ][ nxt ] = max( dp[ r ][ nxt ] , dp[ l ][ r ] + 1 );
          }
          int nxt = next2( a[ l ] % 7 , r );
          if( nxt != -1 )
            dp[ r ][ nxt ] = max( dp[ r ][ nxt ] , dp[ l ][ r ] + 1 );
        }
      }
      {
        for( int dlt = -1 ; dlt <= 1 ; dlt += 2 ){
          int nxt = next( a[ r ] + dlt , r );
          if( nxt == -1 ) continue;
          dp[ l ][ nxt ] = max( dp[ l ][ nxt ] , dp[ l ][ r ] + 1 );
        }
        {
          int nxt = next2( a[ r ] % 7 , r );
          if( nxt != -1 )
            dp[ l ][ nxt ] = max( dp[ l ][ nxt ] , dp[ l ][ r ] + 1 );
        }
        if( l == 0 ){
          for( int nxt = r + 1 ; nxt <= n ; nxt ++ ){
            if( a[ nxt ] % 7 == a[ r ] % 7 or
                abs( a[ nxt ] - a[ r ] ) == 1 )
            dp[ l ][ nxt ] = max( dp[ l ][ nxt ] , dp[ l ][ r ] + 1 );
          }
        }
      }
    }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}