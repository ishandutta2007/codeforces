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
#define N 1048577
int n , k;
vector<PII> vv;
vector<PII> ans;
void build(){

}
void init(){
  n = getint(); k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    int li = getint();
    int ri = getint();
    vv.PB( MP( li , -1 ) );
    vv.PB( MP( ri , +1 ) );
  }
  sort( ALL( vv ) );
}
void reduce(){
  if( (int)ans.size() == 0 ) return;
  int sz = 1;
  for( int i = 1 ; i < (int)ans.size() ; i ++ ){
    if( ans[ i ].FI <= ans[ sz - 1 ].SE ){
      ans[ sz - 1 ].FI = min( ans[ sz - 1 ].FI , ans[ i ].FI );
      ans[ sz - 1 ].SE = max( ans[ sz - 1 ].SE , ans[ i ].SE );
    }else{
      ans[ sz ].FI = ans[ i ].FI;
      ans[ sz ].SE = ans[ i ].SE;
      sz ++;
    }
  }
  ans.resize( sz );
}
void solve(){
  int cnt = 0;
  for( int i = 0 ; i < n + n ; i ++ ){
    if( vv[ i ].SE > 0 ) cnt --;
    else cnt ++;
    if( cnt >= k ){
      // debug( "%d %d %d IN!!\n" , (int)vv[ i ].FI , (int)vv[ i ].SE , cnt );
      if( i < n + n - 1 )
        ans.PB( MP( vv[ i ].FI , vv[ i + 1 ].FI ) );
    }
    // debug( "%d %d %d\n" , (int)vv[ i ].FI , (int)vv[ i ].SE , cnt );
  }
  reduce();
  printf( "%d\n" , (int)ans.size() );
  for( int i = 0 ; i < (int)ans.size() ; i ++ )
    printf( "%d %d\n" , ans[ i ].FI , ans[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}