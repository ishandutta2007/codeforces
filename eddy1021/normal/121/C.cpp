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
#define N 14
LL fac[ N ];
vector<LL> lucky;
void go( LL now ){
  if( now ) lucky.push_back( now );
  if( now > 4000000000 ) return;
  go( now * 10 + 4 );
  go( now * 10 + 7 );
}
void build(){
  go( 0 );
  sort( ALL( lucky ) );
  fac[ 0 ] = 1;
  fac[ 1 ] = 1;
  for( int i = 2 ; i < N ; i ++ )
    fac[ i ] = fac[ i - 1 ] * i;
}
inline bool islucky( LL vl ){
  return upper_bound( ALL( lucky ) , vl ) !=
         lower_bound( ALL( lucky ) , vl );
}
LL n , k , l;
void init(){
  n = getint();
  k = getint();
}
int ans;
inline void go_build(){
  set<LL> res;
  vector<LL> rr;
  for( ll i = l ; i <= n ; i ++ )
    res.insert( i );
  for( ll _ = l ; _ <= n ; _ ++ ){
    int cnt = 0;
    while( k > fac[ n - _ ] ){
      k -= fac[ n - _ ];
      cnt ++;
    }
    auto it = res.begin();
    while( cnt -- ) it ++;
    rr.push_back( *it );
    res.erase( it );
  }
  for( ll _ = l ; _ <= n ; _ ++ )
    if( islucky( _ ) && islucky( rr[ _ - l ] ) )
      ans ++;
}
void solve(){
  if( n < N && fac[ n ] < k ){
    puts( "-1" );
    exit( 0 );
  }
  int ptr = 1;
  while( fac[ ptr ] < k ) ptr ++;
  l = n - ptr + 1;
  for( LL luck : lucky )
    if( luck < l ) ans ++;
    else break;
  go_build();
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