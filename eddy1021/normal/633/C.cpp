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
#define N 100100
#define K 2001001
#define BS 13131
int n;
char c[ N ];
int m , st[ N ] , len[ N ];
char cc[ K ];
ll bs[ N ] , vl[ N ];
void build(){
  bs[ 0 ] = 1ll;
  for( int i = 1 ; i < N ; i ++ )
    bs[ i ] = mul( bs[ i - 1 ] , BS );
}
inline ll value( int l , int r ){
  return sub( vl[ r ] , mul( vl[ l - 1 ] , bs[ r - l + 1 ] ) );
}
#define U 1010
set<PII> S[ U ];
typedef set<PII>::iterator si;
int mxl;
void init(){
  n = getint();
  scanf( "%s" , c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    vl[ i ] = add( mul( vl[ i - 1 ] , BS ) , c[ i ] );
  m = getint();
  int pre = 0;
  for( int i = 0 ; i < m ; i ++ ){
    st[ i ] = pre;
    scanf( "%s" , cc + pre );
    len[ i ] = strlen( cc + pre );
    pre += len[ i ] + 2;
    mxl = max( mxl , len[ i ] );
  }
  for( int i = 0 ; i < m ; i ++ ){
    int l = st[ i ] , r = st[ i ] + len[ i ];
    ll tvl = 0;
    for( int j = r - 1 ; j >= l ; j -- )
      if( cc[ j ] >= 'A' && cc[ j ] <= 'Z' ){
        char ctmp = cc[ j ] - 'A' + 'a';
        tvl = add( mul( tvl , BS ) , ctmp );
      }else
        tvl = add( mul( tvl , BS ) , cc[ j ] );
    S[ len[ i ] ].insert( MP( tvl , i ) );
  }
}
bool okay[ N ];
int bk[ N ] , bkl[ N ];
void find_ans( int now ){
  if( now <= 0 ) return;
  find_ans( bkl[ now ] );
  printf( "%s" , cc + st[ bk[ now ] ] );
  if( now != n ) putchar( ' ' );
}
void solve(){
  okay[ 0 ] = true;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= min( i , mxl ) ; j ++ ){
      if( !okay[ i - j ] ) continue;
      ll tvl = value( i - j + 1 , i );
      si it = S[ j ].lower_bound( MP( tvl , -1 ) );
      if( it == S[ j ].end() ) continue;
      if( it->FI == tvl ){
        okay[ i ] = true;
        bk[ i ] = it->SE;
        bkl[ i ] = i - j;
        break;
      }
    }
  if( okay[ n ] ){
    find_ans( n );
    puts( "" );
  }else puts( "-1" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}