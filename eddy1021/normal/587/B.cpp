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
#define N 1000010
ll n , l , k , nn , a[ N ] , psum[ N ] , pre;
ll vn , nd , c[ N ];
vector<int> li;
ll dp[ 2 ][ N ];
void build(){
}
void init(){
  n = getint();
  l = getint();
  k = getint();
  nn = l / n;
  nd = min( nn , k );
  pre = l % n;
  for( int i = 0 ; i < n ; i ++ ){
    a[ i ] = getint();
    li.PB( a[ i ] );
  }
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = lower_bound( ALL( li ) , a[ i ] ) - li.begin();
  vn = (int)li.size();
}
void solve(){
  ll ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    dp[ 1 ][ i ] = 1;
  ans = l % mod7;
  for( int i = 2 ; i <= k ; i ++ ){
    int now = i % 2;
    int npre = 1 - now;
    for( int j = 0 ; j < vn ; j ++ )
      psum[ j ] = 0;
    for( int j = 0 ; j < n ; j ++ ){
      psum[ a[ j ] ] += dp[ npre ][ j ];
      psum[ a[ j ] ] %= mod7;
    }
    for( int j = 1 ; j < vn ; j ++ ){
      psum[ j ] += psum[ j - 1 ];
      psum[ j ] %= mod7;
    }
    for( int j = 0 ; j < n ; j ++ ){
      dp[ now ][ j ] = psum[ a[ j ] ];
      ll dlt = ( dp[ now ][ j ] * ( ( nn - i + 1 ) % mod7 ) ) % mod7;
      if( i <= nn ) ans = ( ans + dlt ) % mod7;
    }
    for( int j = 0 ; j < pre ; j ++ ){
      ll dlt = dp[ now ][ j ];
      if( i - 1 <= nn ) ans = ( ans + dlt ) % mod7;
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