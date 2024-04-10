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
#define N 52
ll n , l[ N ] , m[ N ] , w[ N ];
ll l2[ N ] , m2[ N ] , w2[ N ];
ll n1 , n2 , bs[ N ];
void build(){
  bs[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    bs[ i ] = bs[ i - 1 ] * 3ll;
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    l[ i ] = getint();
    m[ i ] = getint();
    w[ i ] = getint();
  }
  n1 = n / 2; n2 = n - n1;
  for( int i = n1 ; i < n ; i ++ ){
    l2[ i - n1 ] = l[ i ];
    m2[ i - n1 ] = m[ i ];
    w2[ i - n1 ] = w[ i ];
  }
}
char trans( int _x ){
  if( _x == 0 ) return 'L';
  if( _x == 1 ) return 'M';
  if( _x == 2 ) return 'W';
  return 'Q';
}
void output( int x ){
  for( int i = 0 ; i < 3 ; i ++ )
    if( i != x )
      putchar( trans( i ) );
  puts( "" );
}
map< pair<ll,ll> , pair<ll,ll> > M;
ll ans , ans1 , ans2;
bool gotans;
void DFS( int now , ll sl , ll sm , ll sw , ll mk ){
  if( now == n1 ){
    pair<ll,ll> tp = MP( sm - sl , sw - sl );
    // cout << sl << " ";
    // cout << sm << " ";
    // cout << sw << " ";
    // cout << mk << "\n";
    if( M.count( tp ) ){
      if( sl > M[ tp ].FI )
        M[ tp ] = MP( sl , mk );
    }else M[ tp ] = MP( sl , mk );
    return;
  }
  DFS( now + 1 , sl + l[ now ] , sm + m[ now ] , sw , mk + bs[ now ] * 2ll );
  DFS( now + 1 , sl + l[ now ] , sm , sw + w[ now ] , mk + bs[ now ] * 1ll );
  DFS( now + 1 , sl , sm + m[ now ] , sw + w[ now ] , mk + bs[ now ] * 0ll );
}
void DFS2( int now , ll sl , ll sm , ll sw , ll mk ){
  if( now == n2 ){
    pair<ll,ll> tp = MP( sl - sm , sl - sw );
    if( M.count( tp ) ){
      if( !gotans || sl + M[ tp ].FI > ans ){
        gotans = true;
        ans = sl + M[ tp ].FI;
        ans1 = M[ tp ].SE;
        ans2 = mk;
      }
    }
    return;
  }
  DFS2( now + 1 , sl + l2[ now ] , sm + m2[ now ] , sw , mk + bs[ now ] * 2ll );
  DFS2( now + 1 , sl + l2[ now ] , sm , sw + w2[ now ] , mk + bs[ now ] * 1ll );
  DFS2( now + 1 , sl , sm + m2[ now ] , sw + w2[ now ] , mk + bs[ now ] * 0ll );
}
void solve(){
  if( n == 1 ){
    if( l[ 0 ] == 0 && m[ 0 ] == 0 )
      output( 2 );
    else if( l[ 0 ] == 0 && w[ 0 ] == 0 )
      output( 1 );
    else if( m[ 0 ] == 0 && w[ 0 ] == 0 )
      output( 0 );
    else puts( "Impossible" );
    exit( 0 );
  }
  DFS( 0 , 0 , 0 , 0 , 0 );
  DFS2( 0 , 0 , 0 , 0 , 0 );
  if( !gotans ){
    puts( "Impossible" );
    exit( 0 );
  }
  for( int i = 0 ; i < n1 ; i ++ ){
    int tb = ( ans1 % bs[ i + 1 ] ) / bs[ i ];
    output( tb );
  }
  for( int i = 0 ; i < n2 ; i ++ ){
    int tb = ( ans2 % bs[ i + 1 ] ) / bs[ i ];
    output( tb );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}