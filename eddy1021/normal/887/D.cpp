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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
typedef long long LL;
struct I{
  LL ps , s;
  I(){
    ps = s = 0;
  }
};
inline I operator+( const I& lhs , const I& rhs ){
  I ret;
  ret.ps = min( lhs.ps , lhs.s + rhs.ps );
  ret.s = lhs.s + rhs.s;
  return ret;
}
struct Nd{
  I i;
  Nd *tl , *tr;
  Nd(){
    i = I();
    tl = tr = NULL;
  }
};
const int inf = 1000000000;
#define mid ((l+r)>>1)
inline I Item( Nd* now ){
  return now ? now->i : I();
}
struct SegT{
  LL a[ 2 ];
  Nd* root;
  void init( LL ad , LL sb ){
    a[ 0 ] = -sb;
    a[ 1 ] = ad;
    root = new Nd();
  }
  void modify( Nd* now , int l , int r , int p , LL vl ){
    if( l == r ){
      now->i.ps = min( 0LL , vl );
      now->i.s = vl;
      return;
    }
    if( p <= mid ){
      if( !now->tl ) now->tl = new Nd();
      modify( now->tl , l , mid , p , vl );
    }else{
      if( !now->tr ) now->tr = new Nd();
      modify( now->tr , mid + 1 , r , p , vl );
    }
    now->i = Item( now->tl ) + Item( now->tr );
  }
  void modify( int p , int who ){
    modify( root , 0 , inf , p , a[ who ] );
  }
  I query( Nd* now , int l , int r , int ql , int qr ){
    if( !now or r < ql or l > qr or ql > qr ) return I();
    if( ql <= l and r <= qr ) return now->i;
    return query( now->tl , l , mid , ql , qr ) +
           query( now->tr , mid + 1 , r , ql , qr );
  }
  I query( int ql , int qr ){
    ql = max( ql , 0 );
    qr = min( qr , inf );
    return query( root , 0 , inf , ql , qr );
  }
} t1 , t2;
void build(){

}
#define N 303030
int n , a , b , c , d , start , len;
vector<int> cand;
void init(){
  n = getint();
  a = getint();
  b = getint();
  c = getint();
  d = getint();
  start = getint();
  len = getint();
  t1.init( a , b );
  t2.init( c , d );
  cand.push_back( 0 );
  for( int i = 0 ; i < n ; i ++ ){
    int ti = getint();
    int qi = getint();
    t1.modify( ti , qi );
    t2.modify( ti , qi );
    cand.push_back( ti );
    cand.push_back( ti + 1 );
    if( ti >= len - 1 )
      cand.push_back( ti - len + 1 );
    if( ti >= len )
      cand.push_back( ti - len );
  }
}
void solve(){
  sort( cand.begin() , cand.end() );
  cand.resize( unique( cand.begin() , cand.end() ) - cand.begin() );
  for( size_t i = 0 ; i < cand.size() ; i ++ ){
    int tt = cand[ i ];
    I fst = t1.query( 0 , tt - 1 );
    I snd = t2.query( tt , tt + len - 1 );
    if( start + fst.ps >= 0 and
        start + fst.s + snd.ps >= 0 ){
      printf( "%d\n" , tt );
      Bye;
    }
  }
  puts( "-1" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}