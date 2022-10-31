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
#define N 1021
typedef tuple<int,int,int,int,int> Pt;
#define MP(V,W,X,Y,Z) make_tuple( V , W , X , Y , Z );
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return MP(
      get<0>(p1)-get<0>(p2),
      get<1>(p1)-get<1>(p2),
      get<2>(p1)-get<2>(p2),
      get<3>(p1)-get<3>(p2),
      get<4>(p1)-get<4>(p2))
}
int operator*( const Pt& p1 , const Pt& p2 ){
  return get<0>(p1)*get<0>(p2)+
    get<1>(p1)*get<1>(p2)+
    get<2>(p1)*get<2>(p2)+
    get<3>(p1)*get<3>(p2)+
    get<4>(p1)*get<4>(p2);
}
void build(){

}
int n;
Pt p[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    int a[ 5 ];
    for( int j = 0 ; j < 5 ; j ++ )
      a[ j ] = getint();
    p[ i ] = MP( a[ 0 ] , a[ 1 ] , a[ 2 ] , a[ 3 ] , a[ 4 ] );
  }
}
void solve(){
  if( n > 100 ){
    puts( "0" );
    exit(0);
  }
  vector<int> ans;
  for( int i = 1 ; i <= n ; i ++ ){
    bool gg = false;
    for( int j = 1 ; j <= n and not gg ; j ++ ) if( i != j )
      for( int k = j + 1 ; k <= n and not gg ; k ++ ) if( i != k ){
        int tmp = ( p[ j ] - p[ i ] ) * ( p[ k ] - p[ i ] );
        if( tmp > 0 )
          gg = true;
      }
    if( not gg )
      ans.push_back( i );
  }
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}