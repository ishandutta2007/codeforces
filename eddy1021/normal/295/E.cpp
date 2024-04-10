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
struct Obj{
  LL cnt , sum , vl;
  Obj(){
    cnt = sum = vl = 0;
  }
};
struct Nd{
  Nd *tl , *tr;
  Obj o;
  Nd(){ o.cnt = o.sum = o.vl = 0;tl = tr = NULL; }
}*root;
#define MX 2000000000
#define mid ((l+r)>>1)
inline Obj combine( Obj o1 , Obj o2 ){
  Obj tmp;
  tmp.cnt = o1.cnt + o2.cnt;
  tmp.sum = o1.sum + o2.sum;
  tmp.vl = o1.vl + o2.vl + o1.cnt * o2.sum - o2.cnt * o1.sum;
  return tmp;
}
inline void pull( Nd* now ){
  Obj tol , tor;
  if( now->tl ) tol = now->tl->o;
  if( now->tr ) tor = now->tr->o;
  now->o = combine( tol , tor );
}
void modify( Nd* now , LL l , LL r , LL p , LL dlt , LL xp ){
  if( l == r ){
    now->o.cnt += dlt;
    now->o.sum += dlt * xp;
    now->o.vl = 0;
    return;
  }
  if( p <= mid ){
    if( !now->tl ) now->tl = new Nd();
    modify( now->tl , l , mid , p , dlt , xp );
  }else{
    if( !now->tr ) now->tr = new Nd();
    modify( now->tr , mid + 1 , r , p , dlt , xp );
  }
  pull( now );
}
Obj query( Nd* now , LL l , LL r , LL ql , LL qr ){
  if( r < ql || l > qr || ql > qr || !now ) return Obj();
  if( ql <= l && r <= qr ) return now->o;
  return combine( query( now->tl , l , mid , ql , qr ) ,
                  query( now->tr , mid + 1 , r , ql , qr ) );
}
void build(){

}
#define N 101010
LL n , x[ N ];
void init(){
  n = getint();
  root = new Nd();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    modify( root , -MX , +MX , x[ i ] , 1 , x[ i ] );
  }
}
void solve(){
  int q = getint(); while( q -- ){
    int cmd = getint();
    LL qp = getint();
    LL qv = getint();
    if( cmd == 1 ){
      modify( root , -MX , +MX , x[ qp ] , -1 , x[ qp ] );
      x[ qp ] += qv;
      modify( root , -MX , +MX , x[ qp ] , +1 , x[ qp ] );
    }else{
      Obj ao = query( root , -MX , +MX , qp , qv );
      printf( "%lld\n" , ao.vl );
    }
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