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
#define N 1021
#define M 60606
struct Arc{
  int des , dis , nxt;
  Arc(){}
  Arc( int _des , int _dis , int _nxt ) :
    des(_des), dis(_dis), nxt(_nxt) {}
}r[ M ];
int n , m , s , t , rcnt = 2 , from[ N ];
void add_edge( int u , int v , int w ){
  r[ rcnt ] = Arc( v , w , from[ u ] );
  from[ u ] = rcnt ++;
}
void build(){

}
void init(){
  n = getint(); m = getint();
  s = getint(); t = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    int wi = getint();
    add_edge( ui , vi , wi );
    add_edge( vi , ui , wi );
  }
}
vector<int> pth;
bool got[ N ];
PII bk[ N ];
inline void bfs(){
  queue< int > Q;
  got[ s ] = true;
  Q.push( s ); while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( int i = from[ tn ] ; i ; i = r[ i ].nxt )
      if( !got[ r[ i ].des ] ){
        got[ r[ i ].des ] = true;
        bk[ r[ i ].des ] = { i , tn };
        Q.push( r[ i ].des );
      }
  }
  if( !got[ t ] ){
    puts( "0" );
    puts( "0" );
    puts( "" );
    exit( 0 );
  }
  int now = t;
  while( now != s ){
    pth.push_back( bk[ now ].FI );
    now = bk[ now ].SE;
  }
}
int ans = -1;
vector< int > aid;
int minb , minid , dfn[ N ] , low[ N ] , block , stmp;
inline bool same( int id1 , int id2 ){
  return id1 / 2 == id2 / 2;
}
bool go( int now , int prt ){
  dfn[ now ] = low[ now ] = ++ stmp;
  bool ok = false;
  for( int i = from[ now ] ; i ; i = r[ i ].nxt ){
    if( same( i , prt ) || same( i , block ) ) continue;
    int nxt = r[ i ].des;
    int dst = r[ i ].dis;
    if( dfn[ nxt ] )
      low[ now ] = min( low[ now ] , dfn[ nxt ] );
    else{
      bool tok = go( nxt , i );
      if( tok && low[ nxt ] > dfn[ now ] ){
        if( minb == -1 || dst < minb )
          minb = dst, minid = i;
      }
      low[ now ] = min( low[ now ] , low[ nxt ] );
      ok |= tok;
    }
  }
  ok |= ( now == t );
  return ok;
}
inline void find_bridge( int _block ){
  minb = minid = -1; block = _block;
  stmp = 0;
  for( int i = 1 ; i <= n ; i ++ )
    dfn[ i ] = low[ i ] = 0;
  go( s , 0 );
}
void solve(){
  bfs();
  find_bridge( 0 );
  if( minb != -1 ){
    ans = minb;
    aid.push_back( minid / 2 );
  }
  for( int x : pth ){
    find_bridge( x );
    if( minb == -1 ) continue;
    if( ans == -1 || r[ x ].dis + minb < ans ){
      ans = r[ x ].dis + minb;
      aid.clear();
      aid.push_back( x / 2 );
      aid.push_back( minid / 2 );
    }
  }
  printf( "%d\n" , ans );
  if( ans != -1 ){
    printf( "%d\n" , (int)aid.size() );
    for( size_t i = 0 ; i < aid.size() ; i ++ )
      printf( "%d%c" , aid[ i ] , " \n"[ i + 1 == aid.size() ] );
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