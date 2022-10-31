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
void build(){

}
ll n , k , b , c , t[ N ];
void init(){
  n = getint();
  k = getint();
  b = getint();
  c = getint();
  for( int i = 0 ; i < n ; i ++ )
    t[ i ] = getint();
  sort( t , t + n );
}
inline ll solve1(){
  ll ans = 9000000000000000000ll;
  ll sum = 0;
  for( int i = 0 ; i < k - 1 ; i ++ ) sum += t[ i ];
  for( int i = k - 1 ; i < n ; i ++ ){
    ans = min( ans , ( t[ i ] * ( k - 1 ) - sum ) * c );
    sum += t[ i ] - t[ i - ( k - 1 ) ];
  }
  return ans;
}
inline ll Round( ll tmp ){
  while( tmp % 5 != 0 ) tmp ++;
  return tmp / 5;
}
inline ll solve2( ll md ){
  priority_queue<ll> heap;
  ll heapsum = 0;
  vector<PLL> vv;
  for( int i = 0 ; i < n ; i ++ ){
    ll cst = 0 , tmp = t[ i ];
    while( ( ( tmp % 5 ) + 5 ) % 5 != md ){
      tmp ++; cst += c;
    }
    vv.PB( MP( Round( tmp ) * b , cst ) );
  }
  sort( ALL( vv ) );
  for( int i = 0 ; i < k - 1 ; i ++ ){
    heapsum += vv[ i ].FI - vv[ i ].SE;
    heap.push( vv[ i ].SE - vv[ i ].FI );
  }
  ll ans = 9000000000000000000ll;
  for( int i = k - 1 ; i < n ; i ++ ){
    ll tans = ( k - 1 ) * vv[ i ].FI + vv[ i ].SE - heapsum;
    ans = min( ans , tans );
    heapsum += vv[ i ].FI - vv[ i ].SE;
    heap.push( vv[ i ].SE - vv[ i ].FI );
    heapsum += heap.top(); heap.pop();
  }
  return ans;
}
void solve(){
  ll ans = solve1();
  for( int i = 0 ; i < 5 ; i ++ )
    ans = min( ans , solve2( i ) );
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