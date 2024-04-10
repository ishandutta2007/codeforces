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
#define N 1010101
int fac[ N ] , ifac[ N ];
void build(){
  fac[ 0 ] = ifac[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
  }
}
int cnt[ 26 ] , len;
char a[ N ];
void read(){
  scanf( "%s" , a );
  //for( int i = 0 ; i < 1e6 ; i ++ )
    //a[ i ] = rand() % 26 + 'a';
  //if( len == 0 ) a[ 0 ] = 'a';
  //else a[ 0 ] = 'z';
}
void init(){
  read();
  for( int i = 0 ; a[ i ] ; i ++ )
    cnt[ a[ i ] - 'a' ] ++;
}
int ret , bonus;
void go( int cur , int gain , bool same ){
  if( cur == len ){
    if( not same )
      ret = add( ret , 1 );
    else
      ret = add( ret , bonus );
    return;
  }
  if( not same ){
    ret = add( ret , gain );
    return;
  }
  int tar = a[ cur ] - 'a';
  for( int i = 0 ; i <= tar ; i ++ ){
    if( cnt[ i ] == 0 ) continue;
    int ngain = mul( gain , mul( fac[ cnt[ i ] ] , ifac[ cnt[ i ] - 1 ] ) );
    ngain = mul( ngain , mul( fac[ len - cur - 1 ] , ifac[ len - cur ] ) );
    cnt[ i ] --;
    go( cur + 1 , ngain , i == tar );
    cnt[ i ] ++;
  }
}
int cal(){
  len = strlen( a );
  ret = 0;
  int g = fac[ len ];
  for( int i = 0 ; i < 26 ; i ++ )
    g = mul( g , ifac[ cnt[ i ] ] );
  go( 0 , g , true );
  return ret;
}
void solve(){
  bonus = 1;
  int ans = cal();
  read();
  bonus = 0;
  ans = sub( cal() , ans );
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