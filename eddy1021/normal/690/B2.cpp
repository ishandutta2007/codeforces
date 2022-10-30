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
#define N 514
int n;
char c[ N ][ N ];
inline PII trans( int ii , int jj ){
  return { jj , n - ii };
}
void build(){

}
int di[]={0,1,1,1,0,-1,-1,-1,0,1,1,1,0,-1,-1,-1};
int dj[]={1,1,0,-1,-1,-1,0,1,1,1,0,-1,-1,-1,0,1};
int xi[]={-1,-1,0,0};
int xj[]={-1,0,0,-1};
vector<PII> v , ch;
inline bool in( int ti , int tj ){
  return 1 <= ti && ti <= n &&
         1 <= tj && tj <= n;
}
void init(){
  v.clear();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      if( c[ i ][ j ] == '1' ){
        // cerr << i << " " << j << endl;
        for( int k = 0 ; k < 4 ; k ++ ){
          bool okay = true;
          for( int u = k * 2 ; u < k * 2 + 3 ; u ++ ){
            int nxti = i + di[ u ];
            int nxtj = j + dj[ u ];
            // cerr << " for " << k << " checking " << nxti << " " << nxtj << endl;
            if( in( nxti , nxtj ) && c[ nxti ][ nxtj ] != '0' ){
              okay = false; break;
            }
          }
          if( okay ) v.push_back( trans( i + xi[ k ] , j + xj[ k ] ) );          
        }
      }
}
inline PII operator-( const PII& p1 , const PII& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
inline int operator^( const PII& p1 , const PII& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
inline void ConvexHull(){
  ch.clear();
  sort( ALL( v ) );
  int csz = 0 , psz;
  for( size_t i = 0 ; i < v.size() ; i ++ ){
    while( csz > 1 && ( ( ch[ csz - 1 ] - ch[ csz - 2 ] ) ^
                        ( v[ i ] - ch[ csz - 1 ] ) ) <= 0 )
      ch.pop_back(), csz --;
    ch.push_back( v[ i ] ); csz ++;
  }
  reverse( ALL( v ) ); psz = csz;
  for( size_t i = 0 ; i < v.size() ; i ++ ){
    while( csz > psz && ( ( ch[ csz - 1 ] - ch[ csz - 2 ] ) ^
                          ( v[ i ] - ch[ csz - 1 ] ) ) <= 0 )
      ch.pop_back(), csz --;
    ch.push_back( v[ i ] ); csz ++;
  }
  ch.pop_back();
  reverse( ALL( ch ) );
}
void solve(){
  ConvexHull();
  int st = 0 , sz = (int)ch.size();
  printf( "%d\n" , sz );
  for( int i = 0 ; i < sz ; i ++ ){
    ch.push_back( ch[ i ] );
    if( ch[ i ] < ch[ st ] ) st = i;
  }
  for( int i = st ; i < st + sz ; i ++ )
    printf( "%d %d\n" , ch[ i ].FI , ch[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( scanf( "%d" , &n ) == 1 && n ){
    init();
    solve();
  }
}