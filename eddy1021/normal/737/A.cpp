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
inline void bye(){ exit(0); }
int __ = 1 , _cs;
/*********default*********/
#define N 202020
void build(){

}
LL n , k , s , t;
LL c[ N ] , v[ N ] , g[ N ];
void init(){
  scanf( "%lld%lld%lld%lld" , &n , &k , &s , &t );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld%lld" , &c[ i ] , &v[ i ] );
  for( int i = 0 ; i < k ; i ++ )
    scanf( "%lld" , &g[ i ] );
  sort( g , g + k );
  g[ k ] = s;
}
inline bool okay( LL cap ){
  LL pre = 0 , tt = 0;
  for( int i = 0 ; i <= k ; i ++ ){
    LL dlt = g[ i ] - pre;
    if( dlt > cap ) return false;
    LL mr = min( dlt , cap - dlt );
    tt += mr + 2 * ( dlt - mr );
    pre = g[ i ];
  }
  return tt <= t;
}
void solve(){
  LL bl = 0 , br = 1e12 , ans = 1e12;
  while( bl <= br ){
    LL mid = ( bl + br ) >> 1;
    if( okay( mid ) ) ans = mid , br = mid - 1;
    else bl = mid + 1;
  }
  LL bst = -1;
  for( int i = 0 ; i < n ; i ++ )
    if( v[ i ] >= ans ){
      if( bst == -1 || c[ i ] < bst )
        bst = c[ i ];
    }
  printf( "%lld\n" , bst );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}