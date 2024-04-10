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
#define N 202020
LD st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  st[ no ] = 1.0;
  if( l == r ) return;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
}
void modify( int no , int l , int r , int p , LD pro ){
  if( l == r ){
    st[ no ] = pro;
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p , pro );
  else modify( R( no ) , mid + 1 , r , p , pro );
  st[ no ] = st[ L( no ) ] * st[ R( no ) ];
}
ll n , m , a[ N ] , h[ N ] , l[ N ] , r[ N ] , b[ N ] , z[ N ];
LD p[ N ];
void build(){

}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    h[ i ] = getint();
    l[ i ] = getint();
    r[ i ] = getint();
  }
  for( int i = 1 ; i <= m ; i ++ ){
    b[ i ] = getint();
    z[ i ] = getint();
    p[ i ] = 1.0;
  }
}
void Cal(){
  build_st( 1 , 1 , n );
  vector< PII > v;
  for( int i = 1 ; i <= n ; i ++ )
    v.PB( MP( a[ i ] , i ) );
  for( int i = 1 ; i <= m ; i ++ )
    v.PB( MP( b[ i ] , -i ) );
  sort( ALL( v ) );
  priority_queue< PII , vector<PII> , greater<PII> > heap;
  for( size_t i = 0 ; i < v.size() ; i ++ )
    if( v[ i ].SE > 0 ){
      int no = +v[ i ].SE;
      int pro = 100 - r[ no ];
      if( pro == 100 ) continue;
      modify( 1 , 1 , n , no , (LD)pro / 100.0 );
      heap.push( MP( a[ no ] + h[ no ] , no ) );
    }else{
      int no = -v[ i ].SE;
      while( heap.size() && heap.top().FI < b[ no ] ){
        modify( 1 , 1 , n , heap.top().SE , 1.0 );
        heap.pop();
      }
      p[ no ] *= st[ 1 ];
    }
}
void solve(){
  Cal();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = -a[ i ];
    swap( l[ i ] , r[ i ] );
  }
  for( int i = 1 ; i <= m ; i ++ )
    b[ i ] = -b[ i ];
  Cal();
  LD ans = 0.0;
  for( int i = 1 ; i <= m ; i ++ )
    ans += p[ i ] * (LD)z[ i ];
  printf( "%.12f\n" , (D)ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}