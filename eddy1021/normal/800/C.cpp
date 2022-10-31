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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 202020
bool p[ N ];
vector<int> pset;
void build(){
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] ){
    pset.push_back( i );
    for( int j = i + i ; j < N ; j += i )
      p[ j ] = true;
  }
}
int n , m , gg[ N ];
bool bye[ N ];
void init(){
  n = getint();
  m = getint();
  while( n -- )
    bye[ getint() ] = true;
  for( int i = 1 ; i < m ; i ++ )
    gg[ i ] = __gcd( i , m );
}
vector<int> v[ N ];
vector<int> cand;
int dp[ N ] , nxt[ N ];
PII gcd(int a, int b){
	if(b == 0) return {1, 0};
  PII q = gcd(b, a % b);
  return {q.second, q.first - q.second * (a / b)};
}
int cal( int pre , int now ){
  //printf( "%d %d\n" , pre , now );
  int tpre = pre / gg[ pre ];
  int tnow = now / gg[ pre ];
  int tm   = m   / gg[ pre ];
  int inv = gcd( tpre , tm ).first;
  inv = ( inv % tm + tm ) % tm;
  //printf( "tpre=%d tnow=%d tm=%d inv=%d ret=%lld\n" ,
          //tpre , tnow , tm , inv , mul( tnow , inv , tm ) );
  return mul( tnow , inv , tm );
}
void solve(){
  for( int i = 1 ; i < m ; i ++ ){
    if( bye[ i ] ) continue;
    v[ gg[ i ] ].push_back( i );
  }
  for( auto pp : pset )
    if( m % pp == 0 )
      cand.push_back( pp );
  for( int i = m - 1 ; i > 0 ; i -- ){
    if( m % i ) continue;
    nxt[ i ] = m;
    for( auto pp : cand ){
      if( ( m / i ) % pp ) continue;
      if( dp[ i * pp ] > dp[ i ] ){
        dp[ i ] = dp[ i * pp ];
        nxt[ i ] = i * pp;
      }
    }
    dp[ i ] += (int)v[ i ].size();
  }
  int bst = m;
  for( int i = 1 ; i < m ; i ++ )
    if( dp[ i ] > dp[ bst ] )
      bst = i;
  vector<int> pro;
  while( bst < m ){
    for( auto i : v[ bst ] )
      pro.push_back( i );
    bst = nxt[ bst ];
  }
  vector<int> ans;
  int pre = 1;
  for( int i : pro ){
    ans.push_back( cal( pre , i ) );
    pre = i;
  }
  if( !bye[ 0 ] ) ans.push_back( 0 );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}