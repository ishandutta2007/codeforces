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
#define K 20
#define N 202020
int lb[ N ] , pw[ K ];
void build(){
  lb[ 1 ] = 0;
  int nxt = 2 , bt = 0;
  for( int i = 2 ; i < N ; i ++ ){
    if( i == nxt ) bt ++, nxt <<= 1;
    lb[ i ] = bt;
  }
  for( int i = 0 ; i < K ; i ++ )
    pw[ i ] = ( 1 << i );
}
int n , rmqa[ K ][ N ] , rmqb[ K ][ N ];
inline PII query( int l , int r ){
  int bt = lb[ r - l + 1 ];
  return { max( rmqa[ bt ][ l ] , rmqa[ bt ][ r - pw[ bt ] + 1 ] ) ,
           min( rmqb[ bt ][ l ] , rmqb[ bt ][ r - pw[ bt ] + 1 ] ) };
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    rmqa[ 0 ][ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    rmqb[ 0 ][ i ] = getint();
  for( int i = 1 ; i < K ; i ++ ){
    if( pw[ i ] > n ) break;
    for( int j = 1 ; j + pw[ i ] - 1 <= n ; j ++ )
      rmqa[ i ][ j ] = max( rmqa[ i - 1 ][ j ] , rmqa[ i - 1 ][ j + pw[ i - 1 ] ] );
    for( int j = 1 ; j + pw[ i ] - 1 <= n ; j ++ )
      rmqb[ i ][ j ] = min( rmqb[ i - 1 ][ j ] , rmqb[ i - 1 ][ j + pw[ i - 1 ] ] );
  }
}
inline int bsl( int l ){
  int bl = l , br = n , bmid , ba = -1;
  while( bl <= br ){
    bmid = ( bl + br ) >> 1;
    PII tp = query( l , bmid );
    if( tp.FI < tp.SE ) bl = bmid + 1;
    else if( tp.FI > tp.SE ) br = bmid - 1;
    else{
      ba = bmid;
      br = bmid - 1;
    }
  }
  return ba;
}
inline int bsr( int l ){
  int bl = l , br = n , bmid , ba = -1;
  while( bl <= br ){
    bmid = ( bl + br ) >> 1;
    PII tp = query( l , bmid );
    if( tp.FI < tp.SE ) bl = bmid + 1;
    else if( tp.FI > tp.SE ) br = bmid - 1;
    else{
      ba = bmid;
      bl = bmid + 1;
    }
  }
  return ba;
}
void solve(){
  LL ans = 0;
  for( int l = 1 ; l <= n ; l ++ ){
    int lp = bsl( l );
    int rp = bsr( l );
    if( lp == -1 || rp == -1 ) continue;
    ans += ( rp - lp + 1 );
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