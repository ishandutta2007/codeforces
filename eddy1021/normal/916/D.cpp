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
#define N 101010
unordered_map<string,int> _id;
int mid;
inline int id( const string& s ){
  auto it = _id.find( s );
  if( it != _id.end() ) return it->second;
  return _id[ s ] = ++ mid;
}
#define mid ((l+r)>>1)
struct Nd{
  int sum;
  Nd *tl , *tr;
  Nd(){
    tl = tr = NULL;
    sum = 0;
  }
};
inline Nd* copy( Nd* x ){
  Nd* ret = new Nd();
  if( x ){
    ret->sum = x->sum;
    ret->tl = x->tl;
    ret->tr = x->tr;
  }
  return ret;
}
inline int Sum( Nd* now ){ return now ? now->sum : 0; }
void add( Nd* now , int l , int r , int p , int dlt ){
  if( l == r ){
    now->sum += dlt;
    return;
  }
  if( p <= mid ){
    now->tl = copy( now->tl );
    add( now->tl , l , mid , p , dlt );
  }else{
    now->tr = copy( now->tr );
    add( now->tr , mid + 1 , r , p , dlt );
  }
  now->sum = Sum( now->tl ) + Sum( now->tr );
}
//void modify( Nd* now , int l , int r , int p , int dlt ){
  //if( l == r ){
    //now->sum = dlt;
    //return;
  //}
  //if( p <= mid ){
    //now->tl = copy( now->tl );
    //modify( now->tl , l , mid , p , dlt );
  //}else{
    //now->tr = copy( now->tr );
    //modify( now->tr , mid + 1 , r , p , dlt );
  //}
  //now->sum = Sum( now->tl ) + Sum( now->tr );
//}
int query( Nd* now , int l , int r , int ql , int qr ){
  if( !now or r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return now->sum;
  return query( now->tl , l , mid , ql , qr ) +
         query( now->tr , mid + 1 , r , ql , qr );
}
void build(){

}
int q;
void init(){
  q = getint();
}
const int inf = 1000000000;
Nd *vl[ N ] , *ps[ N ];
void solve(){
  for( int i = 1 ; i <= q ; i ++ ){
    string cmd;
    cin >> cmd;
    if( cmd == "undo" ){
      int di = getint();
      vl[ i ] = copy( vl[ i - di - 1 ] );
      ps[ i ] = copy( ps[ i - di - 1 ] );
      continue;
    }
    vl[ i ] = copy( vl[ i - 1 ] );
    ps[ i ] = copy( ps[ i - 1 ] );
    string ai;
    cin >> ai;
    int nid = id( ai );
    int ori = query( vl[ i ] , 1 , q , nid , nid );
    if( cmd == "set" ){
      int xi = getint();
      if( ori ) add( ps[ i ] , 0 , inf , ori , -1 );
      add( ps[ i ] , 0 , inf , xi , +1 );
      add( vl[ i ] , 1 , q , nid , xi - ori );
      continue;
    }
    if( cmd == "remove" ){
      if( ori ) add( ps[ i ] , 0 , inf , ori , -1 );
      add( vl[ i ] , 1 , q , nid , -ori );
      continue;
    }
    if( ori == 0 ) puts( "-1" );
    else printf( "%d\n" , query( ps[ i ] , 0 , inf , 0 , ori - 1 ) );
    fflush( stdout );
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