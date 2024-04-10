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
#define N 303030
struct Nd{
  Nd *tl , *tr;
  int sum;
  char as;
  Nd(){
    tl = tr = NULL;
    sum = 0;
    as = 2;
  }
};
#define mid ((l+r)>>1)
inline int Sum( Nd * now ){
  return now ? now->sum : 0;
}
vector<int> li;
inline int Weight( int ql , int qr ){
  return li[ qr + 1 ] - li[ ql ];
}
void push( Nd* now , int l , int r ){
  if( now->as == 2 ) return;
  if( !now->tl ) now->tl = new Nd();
  if( !now->tr ) now->tr = new Nd();
  now->tl->as = now->as;
  now->tl->sum = Weight( l , mid ) * now->as;
  now->tr->as = now->as;
  now->tr->sum = Weight( mid + 1 , r ) * now->as;
  now->as = 2;
}
void modify( Nd* now , int l , int r , int ql , int qr , int qa ){
  if( ql == l and r == qr ){
    now->as = qa;
    now->sum = Weight( l , r ) * qa;
    return;
  }
  push( now , l , r );
  if( ql <= mid and !now->tl ) now->tl = new Nd();
  if( mid < qr  and !now->tr ) now->tr = new Nd();
  if( qr <= mid )
    modify( now->tl , l , mid , ql , qr , qa );
  else if( mid < ql )
    modify( now->tr , mid + 1 , r , ql , qr , qa );
  else{
    modify( now->tl , l , mid , ql , mid , qa );
    modify( now->tr , mid + 1 , r , mid + 1 , qr , qa );
  }
  now->sum = Sum( now->tl ) + Sum( now->tr );
}
void build(){

}
int n , q , ql[ N ] , qr[ N ] , qa[ N ];
int lsz;
void init(){
  n = getint();
  q = getint();
  for( int i = 0 ; i < q ; i ++ ){
    ql[ i ] = getint();
    qr[ i ] = getint() + 1;
    qa[ i ] = getint() & 1;
    li.push_back( ql[ i ] );
    li.push_back( qr[ i ] );
  }
  li.push_back( 1 );
  li.push_back( n + 1 );
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
  lsz = li.size() - 1;
}
Nd *root;
void solve(){
  root = new Nd();
  for( int i = 0 ; i < q ; i ++ ){
    int qql = lower_bound( li.begin() , li.end() , ql[ i ] ) - li.begin();
    int qqr = lower_bound( li.begin() , li.end() , qr[ i ] ) - li.begin() - 1;
    modify( root , 0 , lsz - 1 , qql , qqr , qa[ i ] );
    printf( "%d\n" , n - Sum( root ) );
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