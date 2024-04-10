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
#define N 101010
void build(){

}
int n;
char c[ 2 ][ N ];
void init(){
  n = getint();
  scanf( "%s" , c[ 0 ] );
  scanf( "%s" , c[ 1 ] );
}
inline int cal( int id1 , int id2 ){
  int tans = 1;
  for( int i = 0 ; i < n ; i ++ ){
    int v1 = c[ id1 ][ i ] == '?' ? -1 : c[ id1 ][ i ] - '0';
    int v2 = c[ id2 ][ i ] == '?' ? -1 : c[ id2 ][ i ] - '0';
    if( v1 != -1 && v2 != -1 && v1 > v2 ) return 0;
    if( v1 == -1 && v2 == -1 ) tans = mul( tans , 55 );
    else if( v1 == -1 ) tans = mul( tans , v2 + 1 );
    else if( v2 == -1 ) tans = mul( tans , 10 - v1 );
  }
  cerr << id1 << " " << id2 << " " << tans << endl;
  return tans;
}
inline int eq(){
  int tans = 1;
  for( int i = 0 ; i < n ; i ++ ){
    int v1 = c[ 0 ][ i ] == '?' ? -1 : c[ 0 ][ i ] - '0';
    int v2 = c[ 1 ][ i ] == '?' ? -1 : c[ 1 ][ i ] - '0';
    if( v1 == -1 && v2 == -1 ) tans = mul( tans , 10 );
    else if( v1 != -1 && v2 != -1 && v1 != v2 ) return 0;
  }
  return tans;
}
void solve(){
  int qq = 0;
  for( int i = 0 ; i < n ; i ++ ){
    if( c[ 0 ][ i ] == '?' ) qq ++;
    if( c[ 1 ][ i ] == '?' ) qq ++;
  }
  int ans = mypow( 10 , qq , mod7 );
  ans = sub( ans , cal( 0 , 1 ) );
  ans = sub( ans , cal( 1 , 0 ) );
  ans = add( ans , eq() );
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