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
#define K 300
#define N 101010
void build(){

}
int n , a[ N ] , q , ql[ N ] , qr[ N ] , cnt[ N ];
int qq[ N ];
set<int> M;
bool cmp( int i , int j ){
  if( ql[ i ] / K != ql[ j ] / K ) return ql[ i ] / K < ql[ j ] / K;
  return ( ( ql[ i ] / K ) % 2 ? +1 : -1 ) * qr[ i ] <
         ( ( ql[ j ] / K ) % 2 ? +1 : -1 ) * qr[ j ];
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  q = getint();
  for( int i = 0 ; i < q ; i ++ ){
    ql[ i ] = getint();
    qr[ i ] = getint();
    qq[ i ] = i;
  }
  sort( qq , qq + q , cmp );
}
int ans[ N ] , cnt2[ N ];
inline void modify( int ptr , int dlt ){
  if( --cnt2[ cnt[ a[ ptr ] ] ] == 0 ) M.erase( cnt[ a[ ptr ] ] );
  cnt[ a[ ptr ] ] += dlt;
  if( cnt2[ cnt[ a[ ptr ] ] ]++ == 0 ) M.insert( cnt[ a[ ptr ] ] );
}
typedef PII data;
data q1[ N ] , q2[ N ];
inline int cal(){
  int f1 = K , t1 = K , f2 = K , t2 = K;
  for( auto it = M.begin() ; it != M.end() ; it ++ )
    q1[ t1 ++ ] = { *it , cnt2[ *it ] };
  int res = 0;
  while( f1 != t1 || f2 != t2 ){
    data now;
    if( f1 != t1 && ( f2 == t2 || q1[ f1 ].FI < q2[ f2 ].FI ) )
      now = q1[ f1 ++ ];
    else now = q2[ f2 ++ ];
    int fre = now.FI;
    int tms = now.SE;
    if( tms > 1 ){
      res += ( tms >> 1 ) * ( fre << 1 );
      q2[ t2 ++ ] = { fre << 1 , tms >> 1 };
      tms &= 1;
    }
    if( tms == 1 ){
      if( f1 == t1 && f2 == t2 ) return res;
      data nxt;
      if( f1 != t1 && ( f2 == t2 || q1[ f1 ].FI < q2[ f2 ].FI ) )
        nxt = q1[ f1 ++ ];
      else nxt = q2[ f2 ++ ];
      int nfre = nxt.FI;
      int ntms = nxt.SE;
      if( ntms > 1 )
        q2[ -- f2 ] = { nfre , ntms - 1 };
      q2[ t2 ++ ] = { fre + nfre , 1 };
      res += fre + nfre;
    }
  }
  return res;
}
void solve(){
  int lptr = 1, rptr = 1;
  modify( 1 , +1 );
  for( int _ = 0 ; _ < q ; _ ++ ){
    int i = qq[ _ ];
    while( rptr < qr[ i ] ) modify( ++ rptr , +1 );
    while( rptr > qr[ i ] ) modify( rptr -- , -1 );
    while( lptr < ql[ i ] ) modify( lptr ++ , -1 );
    while( lptr > ql[ i ] ) modify( -- lptr , +1 );
    ans[ i ] = cal();
  }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}