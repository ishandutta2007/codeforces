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
#define N 101010
struct Nd{
  int tl , tr;
  LL cnt;
  char rev , st;
  Nd(){
    tl = tr = 0;
    cnt = 0;
    rev = st = 0;
  }
} st[ N * 80 ];
const LL inf = 1000000000000000001LL;
#define mid ((l+r)>>1)
int cc;
int new_node(){
  return ++ cc;
}
LL Cnt( int now ){
  return now ? st[ now ].cnt : 0;
}
void push( int now , LL l , LL r ){
  if( st[ now ].st ){
    if( !st[ now ].tl ) st[ now ].tl = new_node();
    if( !st[ now ].tr ) st[ now ].tr = new_node();
    if( st[ now ].st == 1 ){
      st[ st[ now ].tl ].cnt = mid - l + 1;
      st[ st[ now ].tl ].rev = 0;
      st[ st[ now ].tl ].st = 1;
      st[ st[ now ].tr ].cnt = r - mid;
      st[ st[ now ].tr ].rev = 0;
      st[ st[ now ].tr ].st = 1;
    }else{
      st[ st[ now ].tl ].cnt = 0;
      st[ st[ now ].tl ].rev = 0;
      st[ st[ now ].tl ].st = 2;
      st[ st[ now ].tr ].cnt = 0;
      st[ st[ now ].tr ].rev = 0;
      st[ st[ now ].tr ].st = 2;
    }
    st[ now ].st = 0;
  }
  if( st[ now ].rev ){
    if( !st[ now ].tl ) st[ now ].tl = new_node();
    if( !st[ now ].tr ) st[ now ].tr = new_node();
    st[ st[ now ].tl ].cnt = mid - l + 1 - st[ st[ now ].tl ].cnt;
    st[ st[ now ].tr ].cnt = r - mid - st[ st[ now ].tr ].cnt;
    st[ st[ now ].tl ].rev ^= 1;
    st[ st[ now ].tr ].rev ^= 1;
    st[ now ].rev = 0;
  }
}
LL ql , qr;
void Set( int now , LL l , LL r ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ now ].cnt = r - l + 1;
    st[ now ].rev = 0;
    st[ now ].st = 1;
    return;
  }
  push( now , l , r );
  if( ql <= mid and !st[ now ].tl ) st[ now ].tl = new_node();
  if( mid < qr  and !st[ now ].tr ) st[ now ].tr = new_node();
  Set( st[ now ].tl , l , mid );
  Set( st[ now ].tr , mid + 1 , r );
  st[ now ].cnt = Cnt( st[ now ].tl ) + Cnt( st[ now ].tr );
}
void Clear( int now , LL l , LL r ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ now ].cnt = 0;
    st[ now ].rev = 0;
    st[ now ].st = 2;
    return;
  }
  push( now , l , r );
  if( ql <= mid and !st[ now ].tl ) st[ now ].tl = new_node();
  if( mid < qr  and !st[ now ].tr ) st[ now ].tr = new_node();
  Clear( st[ now ].tl , l , mid );
  Clear( st[ now ].tr , mid + 1 , r );
  st[ now ].cnt = Cnt( st[ now ].tl ) + Cnt( st[ now ].tr );
}
void Rev( int now , LL l , LL r ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ now ].cnt = r - l + 1 - st[ now ].cnt;
    st[ now ].rev ^= 1;
    return;
  }
  push( now , l , r );
  if( ql <= mid and !st[ now ].tl ) st[ now ].tl = new_node();
  if( mid < qr  and !st[ now ].tr ) st[ now ].tr = new_node();
  Rev( st[ now ].tl , l , mid );
  Rev( st[ now ].tr , mid + 1 , r );
  st[ now ].cnt = Cnt( st[ now ].tl ) + Cnt( st[ now ].tr );
}
LL query( int now , LL l , LL r ){
  if( !now or Cnt( now ) == 0 ) return l;
  push( now , l , r );
  if( Cnt( st[ now ].tl ) < mid - l + 1 )
    return query( st[ now ].tl , l , mid );
  return query( st[ now ].tr , mid + 1 , r );
}
void build(){

}
int q , cmd[ N ];
LL l[ N ] , r[ N ];
vector<LL> cand;
void init(){
  q = getint();
  cand.push_back( 1 );
  for( int i = 0 ; i < q ; i ++ ){
    cmd[ i ] = getint();
    l[ i ] = getint();
    r[ i ] = getint();
    cand.push_back( l[ i ] );
    cand.push_back( r[ i ] );
    cand.push_back( r[ i ] + 1 );
  }
  sort( cand.begin() , cand.end() );
  cand.resize( unique( cand.begin() , cand.end() ) - cand.begin() );
}
int root;
void solve(){
  root = new_node();
  int MX = (int)cand.size();
  for( int i = 0 ; i < q ; i ++ ){
    ql = lower_bound( cand.begin() , cand.end() , l[ i ] ) - cand.begin() + 1;
    qr = lower_bound( cand.begin() , cand.end() , r[ i ] ) - cand.begin() + 1;
    if( cmd[ i ] == 1 )
      Set( root , 1 , MX );
    else if( cmd[ i ] == 2 )
      Clear( root , 1 , MX );
    else
      Rev( root , 1 , MX );
    printf( "%lld\n" , cand[ query( root , 1 , MX ) - 1 ] );
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