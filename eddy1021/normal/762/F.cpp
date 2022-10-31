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
#define N 1021
void build(){
}
struct Tree{
  int n;
  vector<int> v[ N ];
  void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
      v[ i ].clear();
    for( int i = 1 ; i < n ; i ++ ){
      int ai = getint();
      int bi = getint();
      v[ ai ].push_back( bi );
      v[ bi ].push_back( ai );
    }
  }
} s , t;
int hsvl[ N ] , mid , con;
vector<int> v;
map< vector<int> , int > M;
int Hash( int x , int prt = -1 ){
  vector<int> tv;
  for( int son : t.v[ x ] ){
    if( son == prt ) continue;
    tv.push_back( Hash( son , x ) );
  }
  sort( tv.begin() , tv.end() );
  if( M.count( tv ) == 0 ){
    M[ tv ] = ++ mid;
    if( tv.empty() )
      con = mid;
  }
  return M[ tv ];
}
void init(){
  s.init();
  t.init();
}
vector<int> son[ N ] , vs[ N ];
void pre_go( int now , int prt ){
  for( int x : s.v[ now ] ){
    if( x == prt ) continue;
    vs[ now ].push_back( x );
    pre_go( x , now );
  }
}
vector<int> useful;
unordered_map<int,int> who;
int go( int now , int prt ){
  for( int tson : t.v[ now ] ){
    if( tson == prt ) continue;
    son[ now ].push_back( go( tson , now ) );
  }
  sort( son[ now ].begin() , son[ now ].end() );
  int ret = M[ son[ now ] ];
  useful.push_back( ret );
  who[ ret ] = now;
  return ret;
}
int target , ans , tdp[ 1 << 12 ] , rdp[ 1 << 12 ];
int q[ 1 << 12 ] , qt;
int iq[ 1 << 12 ] , stmp;
unordered_map<int,int> dp[ N ];
void go_cal( int now ){
  for( int sn : vs[ now ] )
    go_cal( sn );
  for( auto cv : useful ){
    if( cv == con ){
      dp[ now ][ cv ] = 1;
    }else{
      int he = who[ cv ];
      int csz = son[ he ].size();
      for( int j = 0 ; j < ( 1 << csz ) ; j ++ )
        tdp[ j ] = 0;
      tdp[ 0 ] = 1;
      iq[ 0 ] = ++ stmp;
      q[ 0 ] = 0; qt = 1;
      for( int sn : vs[ now ] ){
        for( int _ = 0 ; _ < qt ; _ ++ )
          rdp[ q[ _ ] ] = tdp[ q[ _ ] ];
        int cqt = qt;
        for( int _ = 0 ; _ < cqt ; _ ++ ){
          int inow = q[ _ ];
          for( int j = 0 ; j < csz ; j ++ ){
            if( ( inow >> j ) & 1 ) continue;
            if( j && son[ he ][ j ] == son[ he ][ j - 1 ] &&
                ( ( inow >> ( j - 1 ) ) & 1 ) == 0 ) continue;
            tdp[ inow | ( 1 << j ) ] = add(
                tdp[ inow | ( 1 << j ) ],
                mul( rdp[ inow ] , dp[ sn ][ son[ he ][ j ] ] ) );
            if( iq[ inow | ( 1 << j ) ] != stmp ){
              iq[ inow | ( 1 << j ) ] = stmp;
              q[ qt ++ ] = inow | ( 1 << j );
            }
          }
        }
      }
      dp[ now ][ cv ] = tdp[ ( 1 << csz ) - 1 ];
    }
    if( cv == target )
      ans = add( ans , dp[ now ][ cv ] );
  }
}
void cal( int i ){
  for( int j = 1 ; j <= t.n ; j ++ )
    son[ j ].clear();
  who.clear();
  useful.clear();
  target = go( i , i );
  sort( useful.begin() , useful.end() );
  useful.resize( unique( useful.begin() , useful.end() ) - useful.begin() );
  for( int j = 1 ; j <= s.n ; j ++ )
    dp[ j ].clear();
  go_cal( 1 );
}
void solve(){
  pre_go( 1 , 1 );
  for( int i = 1 ; i <= t.n ; i ++ ){
    hsvl[ i ] = Hash( i );
    bool bye = false;
    for( int j = 1 ; j < i ; j ++ )
      if( hsvl[ i ] == hsvl[ j ] ){
        bye = true;
        break;
      }
    if( bye ) continue;
    cal( i );
  }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}