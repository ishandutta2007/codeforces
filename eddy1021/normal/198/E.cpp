// eddy1022
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
typedef LL type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
//#define O first
//#define R second
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
  scanf( "%lld%lld" , &tp.X , &tp.Y );
}
void build(){

}
#define N 252525
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
Pt o , pt[ N ];
int pi[ N ] , ri[ N ] , mi[ N ];
int tpi[ N ] , tri[ N ] , tmi[ N ];
int mn[ N << 2 ];
void init_st( int no , int l , int r ){
  if( l == r ){
    mn[ no ] = mi[ l ];
    return;
  }
  init_st( L( no ) , l , mid );
  init_st( R( no ) , mid + 1 , r );
  mn[ no ] = min( mn[ L( no ) ] , mn[ R( no ) ] );
}
vector<int> cand;
void query( int no , int l , int r , int ql , int qr , LL power ){
  if( r < ql or l > qr ) return;
  if( mn[ no ] > power ) return;
  if( l == r ){
    cand.push_back( l );
    mn[ no ] = 1023456789;
    return;
  }
  query( L( no ) , l , mid , ql , qr , power );
  query( R( no ) , mid + 1 , r , ql , qr , power );
  mn[ no ] = min( mn[ L( no ) ] , mn[ R( no ) ] );
}
int ord[ N ];
bool cmp( int id1 , int id2 ){
  return norm2( pt[ id1 ] ) < norm2( pt[ id2 ] );
}
LL p , r , n;
LL rr[ N ];
void init(){
  scan( o );
  p = getint();
  r = getint();
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    scan( pt[ i ] );
    pt[ i ] = pt[ i ] - o;
    tmi[ i ] = getint();
    tpi[ i ] = getint();
    tri[ i ] = getint();
    ord[ i ] = i;
  }
  sort( ord , ord + n , cmp );
  for( int i = 0 ; i < n ; i ++ ){
    rr[ i ] = norm2( pt[ ord[ i ] ] );
    mi[ i ] = tmi[ ord[ i ] ];
    pi[ i ] = tpi[ ord[ i ] ];
    ri[ i ] = tri[ ord[ i ] ];
  }
}
void go( LL curr , LL power ){
  curr *= curr;
  int bl = 0 , br = n - 1 , ba = -1;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( rr[ bmid ] <= curr ) ba = bmid , bl = bmid + 1;
    else br = bmid - 1;
  }
  if( ba == -1 ) return;
  query( 1 , 0 , n - 1 , 0 , ba , power );
}
void solve(){
  init_st( 1 , 0 , n - 1 );
  go( r , p );
  for( size_t i = 0 ; i < cand.size() ; i ++ )
    go( ri[ cand[ i ] ] , pi[ cand[ i ] ] );
  cout << cand.size() << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}