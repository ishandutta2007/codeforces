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
#define N 1021
#define K 11
char s[ N ] , t[ N ];
int n , m , k;
void build(){

}
void init(){
  n = getint();
  m = getint();
  k = getint();
  scanf( "%s" , s + 1 );
  scanf( "%s" , t + 1 );
}
int dp[ N ][ N ][ K ][ 2 ];
bool got[ N ][ N ][ K ][ 2 ];
void solve(){
  int ans = 0;
  for( int i = 0 ; i <= n ; i ++ )
    got[ i ][ 0 ][ 0 ][ 0 ] = true;
  for( int i = 0 ; i <= m ; i ++ )
    got[ 0 ][ i ][ 0 ][ 0 ] = true;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      for( int u = 0 ; u <= k ; u ++ ){
        for( int b = 0 ; b < 2 ; b ++ ){
          if( got[ i - 1 ][ j ][ u ][ b ] ){
            got[ i ][ j ][ u ][ 0 ] = true;
            dp[ i ][ j ][ u ][ 0 ] = max( dp[ i ][ j ][ u ][ 0 ] ,
                                          dp[ i - 1 ][ j ][ u ][ b ] );
          }
          if( got[ i ][ j - 1 ][ u ][ b ] ){
            got[ i ][ j ][ u ][ 0 ] = true;
            dp[ i ][ j ][ u ][ 0 ] = max( dp[ i ][ j ][ u ][ 0 ] ,
                                          dp[ i ][ j - 1 ][ u ][ b ] );
          }
          if( got[ i - 1 ][ j - 1 ][ u ][ b ] ){
            got[ i ][ j ][ u ][ 0 ] = true;
            dp[ i ][ j ][ u ][ 0 ] = max( dp[ i ][ j ][ u ][ 0 ] ,
                                          dp[ i - 1 ][ j - 1 ][ u ][ b ] );
          }
        }
      }
      if( s[ i ] == t[ j ] ){
        for( int u = 0 ; u <= k ; u ++ ){
          if( u < k && got[ i - 1 ][ j - 1 ][ u ][ 0 ] ){
            got[ i ][ j ][ u + 1 ][ 1 ] = true;
            dp[ i ][ j ][ u + 1 ][ 1 ] = max( dp[ i ][ j ][ u + 1 ][ 1 ] ,
                                              dp[ i - 1 ][ j - 1 ][ u ][ 0 ] + 1 );
          }
          if( got[ i - 1 ][ j - 1 ][ u ][ 1 ] ){
            got[ i ][ j ][ u ][ 1 ] = true;
            dp[ i ][ j ][ u ][ 1 ] = max( dp[ i ][ j ][ u ][ 1 ] ,
                                          dp[ i - 1 ][ j - 1 ][ u ][ 1 ] + 1 );
            if( u < k ){
              got[ i ][ j ][ u + 1 ][ 1 ] = true;
              dp[ i ][ j ][ u + 1 ][ 1 ] = max( dp[ i ][ j ][ u + 1 ][ 1 ] ,
                                                dp[ i - 1 ][ j - 1 ][ u ][ 1 ] + 1 );
            }
          }
        }
      }
      if( got[ i ][ j ][ k ][ 0 ] )
        ans = max( ans , dp[ i ][ j ][ k ][ 0 ] );
      if( got[ i ][ j ][ k ][ 1 ] )
        ans = max( ans , dp[ i ][ j ][ k ][ 1 ] );
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