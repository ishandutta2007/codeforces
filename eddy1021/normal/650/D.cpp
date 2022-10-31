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
#define N 808080
bool tag[ N ];
int n , m , cnt[ N ] , a[ N ] , ans , lp[ N ] , qa[ N ] , qb[ N ] , mx , qtans[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int seg[ N << 2 ];
void modify( int no , int l , int r , int p , int dlt ){
  if( l == r ){
    seg[ no ] = max( seg[ no ] , dlt );
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p , dlt );
  else modify( R( no ) , mid + 1 , r , p , dlt );
  seg[ no ] = max( seg[ L( no ) ] , seg[ R( no ) ] );
}
int query( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return 0;
  if( ql <= l && r <= qr ) return seg[ no ];
  return max( query( L( no ) , l , mid , ql , qr ) ,
              query( R( no ) , mid + 1 , r , ql , qr ) );
}
void build(){

}
vector<int> li;
void discrete(){
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  mx = (int)li.size() + 1;
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = lower_bound( ALL( li ) , a[ i ] ) - li.begin() + 1;
  for( int i = 0 ; i < m ; i ++ )
    qb[ i ] = lower_bound( ALL( li ) , qb[ i ] ) - li.begin() + 1;
}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    li.PB( a[ i ] );
  }
  for( int i = 0 ; i < m ; i ++ ){
    qa[ i ] = getint();
    qb[ i ] = getint();
    li.PB( qb[ i ] );
  }
  discrete();
  vector<PII> qq;
  for( int i = 0 ; i < m ; i ++ )
    qq.PB( MP( qa[ i ] , i ) );
  sort( ALL( qq ) );
  int ptr = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    lp[ i ] = 1 + query( 1 , 0 , mx , 0 , a[ i ] - 1 );
    ans = max( ans , lp[ i ] );
    while( ptr < m && qq[ ptr ].FI == i ){
      qtans[ qq[ ptr ].SE ] = 1 +
        query( 1 , 0 , mx , 0 , qb[ qq[ ptr ].SE ] - 1 );
      ptr ++;
    }
    modify( 1 , 0 , mx , a[ i ] , lp[ i ] );
  }
  for( int i = 0 ; i < ( N << 2 ) ; i ++ ) seg[ i ] = 0;
  ptr = m - 1;
  for( int i = n ; i >= 1 ; i -- ){
    int bst = 1 + query( 1 , 0 , mx , a[ i ] + 1 , mx );
    int tbst = bst - 1 + lp[ i ];
    if( tbst == ans ){
      tag[ i ] = true;
      cnt[ lp[ i ] ] ++;
    }
    while( ptr >= 0 && qq[ ptr ].FI == i ){
      qtans[ qq[ ptr ].SE ] +=
        query( 1 , 0 , mx , qb[ qq[ ptr ].SE ] + 1 , mx );
      ptr --;
    }
    modify( 1 , 0 , mx , a[ i ] , bst );
  }
}
void solve(){
  for( int i = 0 ; i < m ; i ++ ){
    int tans = ans;
    if( tag[ qa[ i ] ] && cnt[ lp[ qa[ i ] ] ] == 1 ) tans --;
    printf( "%d\n" , max( tans , qtans[ i ] ) );
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