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
#define N 1010101
void build(){

}
struct Node{
  Node *l , *r;
  int cnt;
  Node(){ l = r = NULL; cnt = 0; }
} *root;
int n , k , a[ N ];
ll ans;
void init(){
  n = getint(); k = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  root = new Node();
}
void go( Node* now , int bs , int num ){
  now->cnt ++;
  if( bs == -1 ) return;
  if( ( num >> bs ) & 1 ){
    if( !now->r ) now->r = new Node();
    go( now->r , bs - 1 , num );
  }else{
    if( !now->l ) now->l = new Node();
    go( now->l , bs - 1 , num );
  }
}
void cal( Node* now , int bs , int num , int vl ){
  if( !now ) return;
  if( vl >= k ){
    ans += now->cnt;
    return;
  }
  if( vl + ( 1 << ( bs + 1 ) ) - 1 < k ) return;
  if( bs == -1 ) return;
  if( ( num >> bs ) & 1 ){
    cal( now->l , bs - 1 , num , vl + ( 1 << bs ) );
    cal( now->r , bs - 1 , num , vl );
  }else{
    cal( now->l , bs - 1 , num , vl );
    cal( now->r , bs - 1 , num , vl + ( 1 << bs ) );
  }
}
void solve(){
  go( root , 29 , 0 );
  int pre = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    pre ^= a[ i ];
    cal( root , 29 , pre , 0 );
    go( root , 29 , pre );
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}