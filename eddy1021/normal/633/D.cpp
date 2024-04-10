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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 1010
void build(){

}
map<int,int> M;
int n , a[ N ] , ans = 2;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    M[ a[ i ] ] ++;
  }
}
int t[ N ] , tt;
#define I 1000000000
set<PII> S;
void cal( int f0 , int f1 ){
  if( S.count( MP( a[ f0 ] , a[ f1 ] ) ) )
    return;
  S.insert( MP( a[ f0 ] , a[ f1 ] ) );
  M[ a[ f0 ] ] --;
  M[ a[ f1 ] ] --;
  tt = 0;
  int len = 2 , a0 = a[ f0 ] , a1 = a[ f1 ];
  while( a0 + a1 <= I && a0 + a1 >= -I ){
    if( M.count( a0 + a1 ) && M[ a0 + a1 ] > 0 ){
      M[ a0 + a1 ] --;
      t[ tt ++ ] = a0 + a1;
      len ++;
      int sv = a0 + a1;
      a0 = a1;
      a1 = sv;
    }else break;
  }
  ans = max( ans , len );
  for( int i = 0 ; i < tt ; i ++ )
    M[ t[ i ] ] ++;
  M[ a[ f0 ] ] ++;
  M[ a[ f1 ] ] ++;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      if( i != j )
        cal( i , j );
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