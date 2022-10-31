// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define X 777
#define N 10211021
struct Node{
  Node *nxt[ 2 ], *fail;
  int idx;
}tnode[ N ];
Node *_ptr = tnode, *root;
Node* New(){
  _ptr->nxt[ 0 ] =
  _ptr->nxt[ 1 ] =
  _ptr->fail = NULL;
  _ptr->idx = -1;
  return _ptr ++;
}
void Insert( char s[], int _len, int nidx ){
  Node* ptr = root;
  for( int i = 0 ; i < _len ; i ++ ){
    if( !ptr->nxt[ s[ i ] - 'a' ] )
      ptr->nxt[ s[ i ] - 'a' ] = New();
    ptr=ptr->nxt[ s[ i ] - 'a' ];
  }
  ptr->idx = nidx;
}
queue< Node* > Q;
void buildFailLink(){
  Q.push( root );
  while( Q.size() ){
    Node* ptr = Q.front(); Q.pop();
    for( int i = 0 ; i < 2 ; i ++ ) if( ptr->nxt[ i ] ){
      Node* tmp = ptr->fail;
      while( tmp && !tmp->nxt[ i ] ) tmp = tmp->fail;
      if( tmp ) ptr->nxt[ i ]->fail = tmp->nxt[ i ];
      else ptr->nxt[ i ]->fail = root;
      if( ptr->nxt[ i ]->idx == -1 )
        ptr->nxt[ i ]->idx = ptr->nxt[ i ]->fail->idx;
      Q.push( ptr->nxt[ i ] );
    }
  }
}
int n;
char c[ N ];
int len[ X ], st[ X ];
bool cover[ X ][ X ];
void check( char s[], int _len, int nidx ){
  Node* ptr = root;
  for( int i = 0 ; i < _len ; i ++ ){
    ptr = ptr->nxt[ s[ i ] - 'a' ];
    if( ptr->idx != -1 )
      cover[ nidx ][ ptr->idx ] ++;
    if( ptr->fail && ptr->fail->idx != -1 )
      cover[ nidx ][ ptr->fail->idx ] = true;
  }
}
void build(){
  
}
void init(){
  root = New();
  n = getint(); int _st = 0;
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , c + _st );
    st[ i ] = _st;
    len[ i ] = strlen( c + _st );
    Insert( c + _st , len[ i ] , i );
    _st += len[ i ];
  }
  buildFailLink();
  for( int i = 0 ; i < n ; i ++ )
    check( c + st[ i ] , len[ i ] , i );
}
int mx[ X ], my[ X ];
bool vst[ X ];
bool DFS( int now ){
  vst[ now ] = true;
  for( int i = 0 ; i < n ; i ++ )
    if( cover[ now ][ i ] ){
      if( my[ i ] == -1 || ( !vst[ my[ i ] ] && DFS( my[ i ] ) ) ){
        my[ i ] = now;
        mx[ now ] = i;
        return true;
      }
    }
  return false;
}
void matching(){
  for( int i = 0 ; i < n ; i ++ )
    mx[ i ] = my[ i ] = -1;
  for( int i = 0 ; i < n ; i ++ ){
    for( int j = 0 ; j < n ; j ++ ) vst[ j ] = false;
    DFS( i );
  }
}
void test( vector<int>& ans ){
  int _sz = (int)ans.size();
  bool notokay = true;
  while( notokay ){
    notokay = false;
    for( int i = 0 ; i < _sz ; i ++ )
      for( int j = 0 ; j < _sz ; j ++ )
        if( cover[ ans[ i ] ][ ans[ j ] ] ){
          notokay = true;
          ans[ i ] = mx[ ans[ i ] ];
        }
  }
}
void find_ans(){
  vector<int> ans;
  for( int i = 0 ; i < n ; i ++ )
    if( my[ i ] == -1 ) ans.PB( i );
  test( ans );
  printf( "%d\n" , (int)ans.size() );
  for( int i = 0 ; i < (int)ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] + 1 , " \n"[ i == (int)ans.size() - 1 ] );
}
void solve(){
  vector<PII> vidx;
  for( int i = 0 ; i < n ; i ++ ) vidx.PB( MP( len[ i ] , i ) );
  sort( ALL( vidx ) );
  for( int _ = 0 ; _ < n ; _ ++ ){
    int i = vidx[ _ ].SE;
    for( int j = 0 ; j < n ; j ++ ) if( cover[ i ][ j ] && i != j )
      for( int k = 0 ; k < n ; k ++ )
        cover[ i ][ k ] |= cover[ j ][ k ];
  }
  for( int _ = 0 ; _ < n ; _ ++ ) cover[ _ ][ _ ] = false;
  matching();
  find_ans();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}