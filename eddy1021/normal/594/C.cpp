// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 100010
typedef pair<ll,ll> PLL;
vector<PLL> v;
int n, k;
void build(){

}
multiset<ll> x, y;
typedef multiset<ll>::iterator mi;
void del( int idx ){
  x.erase( x.find( v[ idx ].FI ) );
  y.erase( y.find( v[ idx ].SE ) );
}
void add( int idx ){
  x.insert( v[ idx ].FI );
  y.insert( v[ idx ].SE );
}
void init(){
  n = getint(); k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    ll tx1 = getint();
    ll ty1 = getint();
    ll tx2 = getint();
    ll ty2 = getint();
    v.PB( MP( tx1 + tx2 , ty1 + ty2 ) );
  }
  sort( ALL( v ) );
  for( int i = 0 ; i < n ; i ++ )
    add( i );
}
ll ans = 9000000000000000000ll;
void update( ll tansh , ll tansw ){
  if( tansh <= 0 ) tansh = 1;
  if( tansw <= 0 ) tansw = 1;
  ll tans = ( tansh / 2 + tansh % 2 ) *
            ( tansw / 2 + tansw % 2 );
  ans = min( ans , tans );
}
void solve(){
  if( k == n - 1 ){
    puts( "1" );
    return;
  }
  ll dltx = ( *--x.end() ) - *x.begin();
  ll dlty = ( *--y.end() ) - *y.begin();
  update( dltx , dlty );
  for( int i = 0 ; i < min( n , k + 1 ) ; i ++ ){
    if( i ) del( i - 1 );
    queue<int> Q;
    for( int j = n ; j > i ; j -- ){
      if( j < n ) del( j ), Q.push( j );
      if( i + n - j > k ) break;
      int cnt = 0;
      for( mi it = y.begin() ; it != y.end() ; it ++ ){
        if( i + n - j + cnt > k ) break;
        int cnt2 = 0;
        for( mi it2 = -- y.end() ; it2 != it ; it2 -- ){
          if( i + n - j + cnt + cnt2 > k ) break;
          ll tansx = v[ j - 1 ].FI - v[ i ].FI;
          ll tansy = (*it2) - (*it);
          update( tansx , tansy );
          cnt2 ++;
        }
        cnt ++;
      }
    }
    while( Q.size() ){
      add( Q.front() );
      Q.pop();
    }
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