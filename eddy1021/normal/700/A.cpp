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
void build(){

}
int n , l , v1 , v2 , k;
void init(){
  n = getint();
  l = getint();
  v1 = getint();
  v2 = getint();
  k = getint();
}
inline bool okay( D mx ){
  D bl = 0.0 , br = l , bmid , bmx = 0.0;
  for( int i = 0 ; i < 100 ; i ++ ){
    bmid = ( bl + br ) * 0.5;
    if( bmid / (D)v1 + (D)( (D)l - bmid ) / (D)v2 > mx ) br = bmid;
    else bmx = bmid , bl = bmid;
  }
  if( equal( bmx , l ) ) return true;
  D ndt = ( (D)l - bmx ) / (D)v2;
  int res = n;
  D pst = 0.0 , dlt = ndt * (D)( v2 - v1 ) / (D)( v1 + v2 );
  while( res > 0 ){
    pst += ndt;
    res -= k;
    if( res <= 0 ) return pst < mx;
    pst += dlt;
  }
  return false;
}
void solve(){
  D bl = 0.0 , br = 1e10 , bmid , ans = 1e10;
  for( int i = 0 ; i < 100 ; i ++ ){
    bmid = ( bl + br ) * 0.5;
    if( okay( bmid ) ) ans = bmid , br = bmid;
    else bl = bmid;
  }
  printf( "%.9f\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}