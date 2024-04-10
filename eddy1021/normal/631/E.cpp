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
#define N 202020
ll n , a[ N ] , s[ N ];
void build(){

}
ll ans , oa;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    ans += a[ i ] * i;
    s[ i ] = s[ i - 1 ] + a[ i ];
  }
  oa = ans;
}
deque<int> v;
void solve(){
  int vsz = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    if( i > 1 ){
      int bst = 0 , bl = 0 , br = vsz - 2 , bmid;
      while( bl <= br ){
        bmid = ( bl + br ) >> 1;
        if( ( s[ v[ bmid + 1 ] - 1 ] - s[ v[ bmid ] - 1 ] ) <=
            ( v[ bmid + 1 ] - v[ bmid ] ) * a[ i ] )
          bst = bmid + 1 , bl = bmid + 1;
        else br = bmid - 1;
      }
      ll dlt = s[ i - 1 ] - i * a[ i ];
      dlt += v[ bst ] * a[ i ] - s[ v[ bst ] - 1 ];
      ans = max( ans , oa + dlt );
    }
    while( vsz > 1 && 
          ( s[ i - 1 ] - s[ v[ vsz - 2 ] - 1 ] ) * ( v[ vsz - 1 ] - v[ vsz - 2 ] ) <=
          ( s[ v[ vsz - 1 ] - 1 ] - s[ v[ vsz - 2 ] - 1 ] ) * ( i - v[ vsz - 2 ] )
          ){
      v.pop_back(); vsz --;
    }
    v.push_back( i ); vsz ++;
  }
  v.clear(); vsz = 0;
  for( int i = n ; i >= 1 ; i -- ){
    if( i < n ){
      int bst = 0 , bl = 0 , br = vsz - 2 , bmid;
      while( bl <= br ){
        bmid = ( bl + br ) >> 1;
        if( ( s[ v[ bmid + 1 ] ] - s[ v[ bmid ] ] ) <=
            ( v[ bmid + 1 ] - v[ bmid ] ) * a[ i ] )
          bst = bmid + 1 , bl = bmid + 1;
        else br = bmid - 1;
      }
      ll dlt = s[ i ] - i * a[ i ];
      dlt += v[ bst ] * a[ i ] - s[ v[ bst ] ];
      ans = max( ans , oa + dlt );
    }
    while( vsz > 1 && 
          ( s[ v[ 1 ] ] - s[ i ] ) * ( v[ 1 ] - v[ 0 ] ) >=
          ( s[ v[ 1 ] ] - s[ v[ 0 ] ] ) * ( v[ 1 ] - i )
          ){
      v.pop_front(); vsz --;
    }
    v.push_front( i ); vsz ++;
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