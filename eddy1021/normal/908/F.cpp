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
#define N 303030
void build(){

}
int n , p[ N ] , clr[ N ];
char buf[ 64 ];
bool got;
#define B 1
#define R 2
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    p[ i ] = getint();
    scanf( "%s" , buf );
    if( buf[ 0 ] == 'B' )
      clr[ i ] = B;
    else if( buf[ 0 ] == 'R' )
      clr[ i ] = R;
    else
      got = true;
  }
}
LL ans;
void cal( int lb , int rb ){
  int cans = p[ rb ] - p[ lb ];
  int xans = 0;
  for( int cand : { B , R } ){
    vector<int> pos;
    for( int i = lb + 1 ; i < rb ; i ++ )
      if( clr[ i ] == cand )
        pos.push_back( i );
    if( pos.empty() ) continue;
    int tans = min( p[ pos.back() ] - p[ lb ] ,
                    p[ rb ] - p[ pos[ 0 ] ] );
    for( size_t i = 0 ; i + 1 < pos.size() ; i ++ )
      tans = min( tans , p[ pos[ i ] ] - p[ lb ] +
                         p[ rb ] - p[ pos[ i + 1 ] ] );
    xans += tans;
  }
  ans += min( cans + cans , cans + xans );
}
void solve(){
  if( not got ){
    int pb = -1 , pr = -1;
    for( int i = 1 ; i <= n ; i ++ )
      if( clr[ i ] == B ){
        if( pb != -1 )
          ans += p[ i ] - pb;
        pb = p[ i ];
      }else{
        if( pr != -1 )
          ans += p[ i ] - pr;
        pr = p[ i ];
      }
    printf( "%lld\n" , ans );
    return;
  }
  vector<int> pg;
  for( int i = 1 ; i <= n ; i ++ )
    if( clr[ i ] == 0 )
      pg.push_back( i );
  {
    int fb = -1 , fr = -1;
    for( int i = 1 ; i < pg[ 0 ] ; i ++ )
      if( clr[ i ] == B ){
        fb = i;
        break;
      }
    for( int i = 1 ; i < pg[ 0 ] ; i ++ )
      if( clr[ i ] == R ){
        fr = i;
        break;
      }
    if( fb != -1 )
      ans += p[ pg[ 0 ] ] - p[ fb ];
    if( fr != -1 )
      ans += p[ pg[ 0 ] ] - p[ fr ];
  }
  {
    int fb = -1 , fr = -1;
    for( int i = n ; i > pg.back() ; i -- )
      if( clr[ i ] == B ){
        fb = i;
        break;
      }
    for( int i = n ; i > pg.back() ; i -- )
      if( clr[ i ] == R ){
        fr = i;
        break;
      }
    if( fb != -1 )
      ans += p[ fb ] - p[ pg.back() ];
    if( fr != -1 )
      ans += p[ fr ] - p[ pg.back() ];
  }
  for( size_t i = 0 ; i + 1 < pg.size() ; i ++ )
    cal( pg[ i ] , pg[ i + 1 ] );
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}