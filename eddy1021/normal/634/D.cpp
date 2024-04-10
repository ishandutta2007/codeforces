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
#define mod9 1000000009ll
#define mod7 1000000007ll
// #define INF  1023456789ll
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 202020
#define INF 1000000000
struct Node{
  int lft , rgt , vl , xi;
  Node(){
    xi = lft = rgt = 0;
    vl = INF;
  }
}p[ 40 * N ];
int pt = 0;
inline int newNode(){
  int tmp = ++ pt;
  p[ tmp ] = Node();
  return tmp;
}
void modify( int no , int l , int r , int pos , int pi ){
  if( l == r ){
    p[ no ].vl = min( p[ no ].vl , pi );
    p[ no ].xi = pos;
    return ;
  }
  int mid = ( l + r ) >> 1;
  if( pos <= mid ){
    if( !p[ no ].lft ) p[ no ].lft = newNode();
    modify( p[ no ].lft , l , mid , pos , pi );
  }else{
    if( !p[ no ].rgt ) p[ no ].rgt = newNode();
    modify( p[ no ].rgt , mid + 1 , r , pos , pi );
  }
  p[ no ].vl = min( p[ p[ no ].lft ].vl , 
                    p[ p[ no ].rgt ].vl );
  if( p[ p[ no ].lft ].vl < p[ p[ no ].rgt ].vl )
    p[ no ].xi = p[ p[ no ].lft ].xi;
  else
    p[ no ].xi = p[ p[ no ].rgt ].xi;
}
PII query( int no , int l , int r , int ql , int qr ){
  if( no == 0 || r < ql || l > qr ) return MP( INF , -1 );
  if( ql <= l && r <= qr ) return MP( p[ no ].vl , p[ no ].xi );
  int mid = ( l + r ) >> 1;
  PII lret = query( p[ no ].lft , l , mid , ql , qr );
  PII rret = query( p[ no ].rgt , mid + 1 , r , ql , qr );
  if( lret.FI < rret.FI ) return lret;
  return rret;
}
void build(){

}
ll d , n , m;
int root;
void init(){
  d = getint();
  n = getint();
  m = getint();
  root = newNode();
  for( int i = 0 ; i < m ; i ++ ){
    ll xi = getint();
    ll pi = getint();
    modify( root , 0 , d , xi , pi );
  }
}
void solve(){
  ll cst = 0 , now = 0 , fuel = n;
  while( now < d ){
    if( d - now <= fuel ) break;
    if( fuel == 0 ){
      puts( "-1" );
      exit( 0 );
    }
    PII tp = query( root , 0 , d , now + 1 , now + fuel );
    if( tp.FI == INF ){
      puts( "-1" );
      exit( 0 );
    }
    ll nxt = tp.SE;
    fuel -= ( nxt - now );
    ll mst = min( n - fuel , d - nxt - fuel );
    // printf( "%lld %lld %lld %d %lld %lld\n" , now , nxt , mst , tp.FI , fuel , cst );
    ll bl = 1 , br = mst , bmid;
    while( bl <= br ){
      bmid = ( bl + br ) >> 1;
      PII tp2 = query( root , 0 , d , nxt , min( d , nxt + fuel + bmid ) );
      if( tp2.FI < tp.FI ) mst = bmid , br = bmid - 1;
      else bl = bmid + 1;
    }
    // printf( "%lld %lld %lld %d %lld %lld\n" , now , nxt , mst , tp.FI , fuel , cst );
    cst += mst * tp.FI;
    fuel += mst;
    now = nxt;
    // printf( "%lld %lld %lld %d %lld %lld\n" , now , nxt , mst , tp.FI , fuel , cst );
    // puts( "==========" );
  }
  cout << cst << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}