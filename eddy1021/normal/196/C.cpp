// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
typedef long long type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan( Pt& tp ){
  tp.X = getint();
  tp.Y = getint();
}
void build(){

}
#define N 1515
int n;
vector<int> v[ N ];
Pt p[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  for( int i = 0 ; i < n ; i ++ )
    scan( p[ i ] );
}
int ans[ N ] , sz[ N ];
int go( int now , int prt ){
  sz[ now ] = 1;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    sz[ now ] += go( son , now );
  }
  return sz[ now ];
}
int root;
int region( const Pt& tp ){
  if( tp.Y < 0 or
      ( tp.Y == 0 and tp.X < 0 ) ) return 0;
  return 1;
}
bool cmp( int id1 , int id2 ){
  int r1 = region( p[ id1 ] - p[ root ] );
  int r2 = region( p[ id2 ] - p[ root ] );
  if( r1 != r2 ) return r1 < r2;
  return ( ( p[ id1 ] - p[ root ] ) ^ ( p[ id2 ] - p[ root ] ) ) > 0;
}
bool cmp2( int id1 , int id2 ){
  return p[ id1 ] > p[ id2 ];
}
void go2( int now , int prt , vector<int>& cand ){
  sort( cand.begin() , cand.end() , cmp2 );
  ans[ cand.back() ] = now;
  root = cand.back();
  cand.pop_back();
  sort( cand.begin() , cand.end() , cmp );
  size_t ptr = 0;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    vector<int> nxt;
    for( int j = 0 ; j < sz[ son ] ; j ++ )
      nxt.push_back( cand[ ptr ++ ] );
    go2( son , now , nxt );
  }
}
void solve(){
  go( 1 , 1 );
  vector<int> cand;
  for( int i = 0 ; i < n ; i ++ )
    cand.push_back( i );
  go2( 1 , 1 , cand );
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}