// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<LD,LD> Pt;
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
int __ = 1 , cs;
/*********default*********/
#define N 514010
int n;
char c[ N ];
int ci[ N ];
vector<int> v[ N ];
struct Node{
  int kind;
  Node* nxt[ 26 ];
  Node(){
    for( int i = 0 ; i < 26 ; i ++ )
      nxt[ i ] = NULL;
  }
};
Node* root[ N ];
int pro;
Node* merge( Node* l1 , Node* l2 ){
  if( l1 && l2 ){
    // if( pro == 2 ) printf( " === %d %d === \n" , l1 ? l1->kind : l2->kind , l2->kind );
    int tcnt = 1;
    for( int i = 0 ; i < 26 ; i ++ ){
      l1->nxt[ i ] = merge( l1->nxt[ i ] , l2->nxt[ i ] );
      if( l1->nxt[ i ] ){
        tcnt += l1->nxt[ i ]->kind;
        // if( pro == 2 ) printf( "%d +%d %d\n" , i , l1->nxt[ i ]->kind , tcnt );
      }
    }
    l1->kind = tcnt;
    return l1;
  }
  return l1 ? l1 : l2;
}
void build(){

}
int ans, ansc;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    ci[ i ] = getint();
  ans = -1;
  scanf( "%s" , c + 1 );
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].PB( vi );
    v[ vi ].PB( ui );
  }
}
void DP( int now , int prt ){
  root[ now ] = new Node();
  root[ now ]->nxt[ c[ now ] - 'a' ] = new Node();
  for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      DP( v[ now ][ i ] , now );
      pro = now;
      root[ now ]->nxt[ c[ now ] - 'a' ]->nxt[ c[ v[ now ][ i ] ] - 'a' ] =
        merge( root[ now ]->nxt[ c[ now ] - 'a' ]->nxt[ c[ v[ now ][ i ] ] - 'a' ] ,
                            root[ v[ now ][ i ] ]->nxt[ c[ v[ now ][ i ] ] - 'a' ] );
      // if( now == 2 )
        // printf( "=====> %d : %d %d\n" , v[ now ][ i ] , root[ v[ now ][ i ] ]->nxt[ c[ v[ now ][ i ] ] - 'a' ]->kind,
                              // root[ now ]->nxt[ c[ now ]-'a' ]->nxt[ c[ v[ now ][ i ] ] - 'a' ]->kind );
    }
  int tcnt = 1;
  for( int i = 0 ; i < 26 ; i ++ )
    if( root[ now ]->nxt[ c[ now ] - 'a' ]->nxt[ i ] ){
      tcnt += root[ now ]->nxt[ c[ now ] - 'a' ]->nxt[ i ]->kind;
      // if( now == 2 )
        // printf( "%d %d\n" , i , tcnt );
    }
  root[ now ]->nxt[ c[ now ] - 'a' ]->kind = tcnt;
  int tans = root[ now ]->nxt[ c[ now ] - 'a' ]->kind + ci[ now ];
  if( tans > ans ) ans = tans , ansc = 1;
  else if( tans == ans ) ans = tans , ansc ++;
  // printf( "%d : %d %d\n" , now , tcnt , tans );
}
void solve(){
  DP( 1 , -1 );
  printf( "%d\n%d\n" , ans , ansc );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}