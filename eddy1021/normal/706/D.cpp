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
#define K 31
struct Nd{
  int sum , lft , rgt;
  Nd(){
    sum = lft = rgt = 0;
  }
} p[ N * K * 2 ];
int pcnt = 1 , root;
int newNd(){ return pcnt ++; }
void modify( int no , int pvt , int vl , int dlt ){
  p[ no ].sum += dlt;
  if( pvt < 0 ) return;
  if( ( vl >> pvt ) & 1 ){
    if( !p[ no ].rgt ) p[ no ].rgt = newNd();
    modify( p[ no ].rgt , pvt - 1 , vl , dlt );
  }else{
    if( !p[ no ].lft ) p[ no ].lft = newNd();
    modify( p[ no ].lft , pvt - 1 , vl , dlt );
  }
}
int query( int no , int pvt , int vl ){
  if( pvt < 0 ) return 0;
  int lc = p[ no ].lft;
  int rc = p[ no ].rgt;
  if( ( vl >> pvt ) & 1 ){
    if( lc && p[ lc ].sum > 0 )
      return ( 1 << pvt ) | query( lc , pvt - 1 , vl );
    return query( rc , pvt - 1 , vl );
  }else{
    if( rc && p[ rc ].sum > 0 )
      return ( 1 << pvt ) | query( rc , pvt - 1 , vl );
    return query( lc , pvt - 1 , vl );
  }
}
void build(){
  root = newNd();
}
int qry;
void init(){
  qry = getint();
  modify( root , K - 1 , 0 , 1 );
}
void solve(){
  while( qry -- ){
    char cmd[ 9 ];
    scanf( "%s" , cmd );
    int xi = getint();
    if( cmd[ 0 ] == '+' )
      modify( root , K - 1 , xi , +1 );
    else if( cmd[ 0 ] == '-' )
      modify( root , K - 1 , xi , -1 );
    else
      printf( "%d\n" , query( root , K - 1 , xi ) );
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