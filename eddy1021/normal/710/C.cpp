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
#define N 50
void build(){

}
int n , a[ N ][ N ];
vector< int > odd, even;
void init(){
  n = getint();
  for( int i = 1 ; i <= n * n ; i ++ )
    if( i % 2 ) odd.push_back( i );
    else even.push_back( i );
}
void solve(){
  int res = n * n / 2 + 1;
  for( int i = 1 ; i <= n ; i ++ ){
    if( a[ i ][ ( n + 1 ) / 2 ] == 0 ){
      res --;
      a[ i ][ ( n + 1 ) / 2 ] = 1;
    }
    if( a[ ( n + 1 ) / 2 ][ i ] == 0 ){
      res --;
      a[ ( n + 1 ) / 2 ][ i ] = 1;
    }
  }
  assert( res >= 0 );
  for( int i = 1 ; i <= n && res > 0 ; i ++ )
    for( int j = 1 ; j <= n && res > 0 ; j ++ )
      if( a[ i ][ j ] == 0 ){
        int i2 = i         , j2 = n - j + 1;
        int i3 = n - i + 1 , j3 = j;
        int i4 = n - i + 1 , j4 = n - j + 1;
        if( a[ i2 ][ j2 ] == 0 &&
            a[ i3 ][ j3 ] == 0 &&
            a[ i4 ][ j4 ] == 0 ){
          a[ i ][ j ] = 
          a[ i2 ][ j2 ] = 
          a[ i3 ][ j3 ] = 
          a[ i4 ][ j4 ] = 1;
          res -= 4;
        }
        assert( res >= 0 );
      }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      if( a[ i ][ j ] ){
        assert( odd.size() );
        printf( "%d%c" , odd.back() , " \n"[ j == n ] );
        odd.pop_back();
      }else{
        assert( even.size() );
        printf( "%d%c" , even.back() , " \n"[ j == n ] );
        even.pop_back();
      }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}