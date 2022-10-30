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
void build(){

}
ll n;
void init(){
  cin >> n;
}
void solve(){
  if( n == 0 ){
    puts( "0 0" );
    return;
  }
  ll lyr = 1 , bl = 1 , br = 1000000000ll , bmid;
  while( bl <= br ){
    bmid = ( bl + br ) >> 1;
    ll tmp = ( bmid + 1ll ) * bmid * 3ll;
    if( tmp >= n ) lyr = bmid , br = bmid - 1;
    else bl = bmid + 1;
  }
  ll av = lyr;
  n -= lyr * ( lyr - 1 ) * 3ll;
  // printf( "%lld %lld\n" , av , n );
  if( n <= av ){
    ll x = ( lyr * 2ll ) - 1 , y = 2ll;
    x -= ( n - 1 );
    y += ( n - 1 ) * 2ll;
    cout << x << " " << y << endl;
    return;
  }
  n -= av;

  if( n <= av ){
    ll x = -1 + ( lyr - 1 ) , y = 2 * lyr;
    x -= 2ll * ( n - 1 );
    cout << x << " " << y << endl;
    return;
  }
  n -= av;

  if( n <= av ){
    ll x = -2 - ( lyr - 1 ) , y = 2 * ( lyr - 1 );
    x -= ( n - 1 );
    y -= 2ll * ( n - 1 );
    cout << x << " " << y << endl;
    return;
  }
  n -= av;

  if( n <= av ){
    ll x = -1 - 2ll * ( lyr - 1 ) , y = -2;
    x += ( n - 1 );
    y -= 2ll * ( n - 1 );
    cout << x << " " << y << endl;
    return;
  }
  n -= av;

  if( n <= av ){
    ll x = 1 - ( lyr - 1 ) , y = -2 - 2ll * ( lyr - 1 );
    x += 2ll * ( n - 1 );
    cout << x << " " << y << endl;
    return;
  }
  n -= av;

  if( n <= av ){
    ll x = 2 + ( lyr - 1 ) , y = -2ll * ( lyr - 1 );
    x += ( n - 1 );
    y += 2ll * ( n - 1 );
    cout << x << " " << y << endl;
    return;
  }
  n -= av;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}