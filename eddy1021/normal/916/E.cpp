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
void build(){

}
LL st[ N << 2 ] , tg[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void push( int no , int l , int r ){
  if( tg[ no ] == 0 ) return;
  tg[ L( no ) ] += tg[ no ];
  st[ L( no ) ] += tg[ no ] * (mid - l + 1);
  tg[ R( no ) ] += tg[ no ];
  st[ R( no ) ] += tg[ no ] * (r - mid);
  tg[ no ] = 0;
}
void add( int no , int l , int r , int ql , int qr , LL vv ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    tg[ no ] += vv;
    st[ no ] += vv * (r - l + 1);
    return;
  }
  push( no , l , r );
  add( L( no ) , l , mid , ql , qr , vv );
  add( R( no ) , mid + 1 , r , ql , qr , vv );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
LL query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return st[ no ];
  push( no , l , r );
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
#define K 18
int n , q , a[ N ] , in[ N ] , out[ N ] , dep[ N ];
int p[ K ][ N ] , root = 1 , stmp;
vector<int> v[ N ];
inline int lca( int ui , int vi ){
  if( dep[ ui ] > dep[ vi ] ) swap( ui , vi );
  int dlt = dep[ vi ] - dep[ ui ];
  while( dlt ){
    int stp = __lg( dlt );
    vi = p[ stp ][ vi ];
    dlt ^= (1 << stp);
  }
  if( ui == vi ) return ui;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( p[ i ][ ui ] != p[ i ][ vi ] ){
      ui = p[ i ][ ui ];
      vi = p[ i ][ vi ];
    }
  return p[ 0 ][ ui ];
}
unordered_map<int,bool> rec[ N ];
inline bool is_prt( int son , int prt ){
  auto it = rec[ son ].find( prt );
  if( it != rec[ son ].end() ) return it->second;
  return rec[ son ][ prt ] = (lca( son , prt ) == prt);
}
unordered_map<int,int> climb_to[ N ];
inline int climb( int now , int dlt ){
  int cnow = now , cdlt = dlt;
  auto it = climb_to[ now ].find( dlt );
  if( it != climb_to[ now ].end() ) return it->second;
  while( dlt ){
    int stp = __lg( dlt );
    now = p[ stp ][ now ];
    dlt ^= (1 << stp);
  }
  return climb_to[ cnow ][ cdlt ] = now;
}
void go( int now , int prt , int tdep ){
  dep[ now ] = tdep;
  in[ now ] = ++ stmp;
  p[ 0 ][ now ] = prt;
  add( 1 , 1 , n , in[ now ] , in[ now ] , a[ now ] );
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , tdep + 1 );
  }
  out[ now ] = stmp;
}
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  go( root , root , 0 );
  for( int j = 1 ; j < K ; j ++ )
    for( int i = 1 ; i <= n ; i ++ )
      p[ j ][ i ] = p[ j - 1 ][ p[ j - 1 ][ i ] ];
}
void solve(){
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ){
      root = getint();
      continue;
    }
    if( cmd == 3 ){
      int vi = getint();
      if( root == vi )
        printf( "%lld\n" , query( 1 , 1 , n , 1 , n ) );
      else if( is_prt( root , vi ) ){
        int dlt = dep[ root ] - dep[ vi ];
        int tmp = climb( root , dlt - 1 );
        printf( "%lld\n" , query( 1 , 1 , n , 1 , n ) -
                           query( 1 , 1 , n , in[ tmp ] , out[ tmp ] ) );
      }else
        printf( "%lld\n" , query( 1 , 1 , n , in[ vi ] , out[ vi ] ) );
      continue;
    }
    int ui = getint();
    int vi = getint();
    int xi = getint();
    int tlca = lca( ui , vi );
    if( ui == root or vi == root or tlca == root or
        ( is_prt( ui , root ) != is_prt( vi , root ) ) ){
      add( 1 , 1 , n , 1 , n , xi );
      continue;
    }
    if( is_prt( ui , root ) or not is_prt( root , tlca ) ){
      add( 1 , 1 , n , in[ tlca ] , out[ tlca ] , xi );
      continue;
    }
    if( is_prt( root , ui ) and is_prt( root , vi ) ){
      int dlt = dep[ root ] - max( dep[ ui ] , dep[ vi ] );
      int tmp = climb( root , dlt - 1 );
      add( 1 , 1 , n , 1 , n , xi );
      add( 1 , 1 , n , in[ tmp ] , out[ tmp ] , -xi );
      continue;
    }
    if( is_prt( root , vi ) ) swap( ui , vi );
    if( is_prt( root , ui ) ){
      if( is_prt( vi , ui ) ){
        int ttlca = lca( root , vi );
        int dlt = dep[ root ] - dep[ ttlca ];
        int tmp = climb( root , dlt - 1 );
        add( 1 , 1 , n , 1 , n , xi );
        add( 1 , 1 , n , in[ tmp ] , out[ tmp ] , -xi );
        continue;
      }else{
        int dlt = dep[ root ] - dep[ ui ];
        int tmp = climb( root , dlt - 1 );
        add( 1 , 1 , n , 1 , n , xi );
        add( 1 , 1 , n , in[ tmp ] , out[ tmp ] , -xi );
      }
      continue;
    }
    int lca1 = lca( root , ui );
    int lca2 = lca( root , vi );
    if( lca2 != tlca and is_prt( lca2 , tlca ) ){
      swap( ui , vi );
      swap( lca1 , lca2 );
    }
    if( lca1 != tlca and is_prt( lca1 , tlca ) ){
      int dlt = dep[ root ] - dep[ lca1 ];
      int tmp = climb( root , dlt - 1 );
      add( 1 , 1 , n , 1 , n , xi );
      add( 1 , 1 , n , in[ tmp ] , out[ tmp ] , -xi );
      continue;
    }
    int dlt = dep[ root ] - dep[ tlca ];
    int tmp = climb( root , dlt - 1 );
    add( 1 , 1 , n , 1 , n , xi );
    add( 1 , 1 , n , in[ tmp ] , out[ tmp ] , -xi );
    continue;
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