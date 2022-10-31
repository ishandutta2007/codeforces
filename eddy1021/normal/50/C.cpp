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
vector<PLL> v , ch;
inline PLL operator-( const PLL& p1 , const PLL& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
inline ll operator^( const PLL& p1 , const PLL& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
int n;
void build(){

}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    int tx = getint();
    int ty = getint();
    for( int j = 0 ; j < 4 ; j ++ )
      v.PB( MP( tx + dx[ j ] , ty + dy[ j ] ) );
  }
  sort( ALL( v ) );
}
inline bool not_good( const PLL& a , const PLL& b , const PLL& c ){
  return ( ( b - a ) ^ ( c - b ) ) <= 0;
}
void Convex_hull(){
  for( size_t i = 0 ; i < v.size() ; i ++ ){
    while( (int)ch.size() > 1 &&
            not_good( ch[ (int)ch.size() - 2 ] ,
                      ch[ (int)ch.size() - 1 ] ,
                      v[ i ] ) ) ch.pop_back();
    ch.push_back( v[ i ] );
  }
  size_t tsz = ch.size();
  reverse( ALL( v ) );
  for( size_t i = 0 ; i < v.size() ; i ++ ){
    while( (int)( ch.size() - tsz ) > 0 &&
            not_good( ch[ (int)ch.size() - 2 ] ,
                      ch[ (int)ch.size() - 1 ] ,
                      v[ i ] ) ) ch.pop_back();
    ch.push_back( v[ i ] );
  }
}
void solve(){
  Convex_hull();
  ll ans = 0;
  for( size_t i = 1 ; i < ch.size() ; i ++ )
    ans += max( abs( ch[ i ].X - ch[ i - 1 ].X ) ,
                abs( ch[ i ].Y - ch[ i - 1 ].Y ) );
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