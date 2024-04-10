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
#define N 5001
void build(){

}
int n , m , T , deg[ N ];
vector< pair<int,int> > v[ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &T );
  while( m -- ){
    int ui , vi , ci;
    scanf( "%d%d%d" , &ui , &vi , &ci );
    v[ ui ].push_back( { vi , ci } );
    deg[ vi ] ++;
  }
}
bool got[ N ][ N ];
int dp[ N ][ N ];
int bk[ N ][ N ];
queue< int > Q;
void find_ans( int cnt ){
  printf( "%d\n" , cnt );
  vector< int > vans;
  int now = n;
  for( int i = cnt ; i >= 1 ; i -- ){
    vans.push_back( now );
    now = bk[ now ][ i ];
  }
  reverse( vans.begin() , vans.end() );
  for( size_t i = 0 ; i < vans.size() ; i ++ )
    printf( "%d%c" , vans[ i ] , " \n"[ i + 1 == vans.size() ] );
}
void solve(){
  for( int i = 2 ; i <= n ; i ++ )
    if( deg[ i ] == 0 ){
      Q.push( i );
      got[ i ][ 1 ] = true;
      dp[ i ][ 1 ] = T + 1;
    }
  Q.push( 1 );
  got[ 1 ][ 1 ] = true;
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( int i = 1 ; i <= n ; i ++ ){
      if( !got[ tn ][ i ] ) continue;
      for( auto e : v[ tn ] ){
        LL nxt = e.first;
        LL dst = e.second;
        if( !got[ nxt ][ i + 1 ] ||
            dp[ tn ][ i ] + dst < dp[ nxt ][ i + 1 ] ){
          got[ nxt ][ i + 1 ] = true;
          bk[ nxt ][ i + 1 ] = tn;
          dp[ nxt ][ i + 1 ] = dp[ tn ][ i ] + dst;
          if( dp[ nxt ][ i + 1 ] > T )
            dp[ nxt ][ i + 1 ] = T + 1;
        }
      }
    }
    for( auto e : v[ tn ] ){
      deg[ e.first ] --;
      if( deg[ e.first ] == 0 )
        Q.push( e.first );
    }
  }
  int bst = -1;
  for( int i = 1 ; i <= n ; i ++ )
    if( got[ n ][ i ] && dp[ n ][ i ] <= T )
      bst = i;
  find_ans( bst );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}