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
map< vector<ll> , vector<ll> > M;
queue< vector<ll> > Q;
#define K 11
void build(){
  Q.push( { 1 , 1 , 1 , 1 } );
  M[ { 1 , 1 , 1 , 1 } ] = { 1 , 1 , 1 , 1 };
  while( Q.size() ){
    vector<ll> tmp = Q.front(); Q.pop();
    for( int i = 0 ; i < 4 ; i ++ ){
      vector<ll> tmp2 = tmp;
      tmp2[ i ] --;
      tmp2[ ( i + 1 ) % 4 ] --;
      if( M.count( tmp2 ) == 0 ){
        M[ tmp2 ] = tmp;
        if( tmp2[ i ] >= 1 &&
            tmp2[ ( i + 1 ) % 4 ] >= 1 )
          Q.push( tmp2 );
      }
    }
    for( int i = 0 ; i < 4 ; i ++ ){
      vector<ll> tmp2 = tmp;
      tmp2[ i ] *= 2;
      tmp2[ ( i + 1 ) % 4 ] *= 2;
      if( M.count( tmp2 ) == 0 ){
        M[ tmp2 ] = tmp;
        if( tmp2[ i ] < K &&
            tmp2[ ( i + 1 ) % 4 ] < K )
          Q.push( tmp2 );
      }
    }
  }
  // cout << M.size() << endl;
}
vector<ll> a;
void init(){
  a.resize( 4 );
  for( int i = 0 ; i < 4 ; i ++ )
    a[ i ] = getint();
}
vector< pair<int,int> > ans;
void build_ans(){
  while( M.count( a ) && a != M[ a ] ){
    bool got = false;
    // for( int i = 0 ; i < 4 ; i ++ )
      // printf( "%lld%c" , a[ i ] , " \n"[ i == 3 ] );
    // for( int i = 0 ; i < 4 ; i ++ )
      // printf( "%lld%c" , M[ a ][ i ] , " \n"[ i == 3 ] );
    // puts( "===========" );
    for( int i = 0 ; i < 4 && !got ; i ++ ){
      if( M[ a ][ i ] * 2 == a[ i ] &&
          M[ a ][ ( i + 1 ) % 4 ] * 2 == a[ ( i + 1 ) % 4 ] ){
        got = true;
        ans.PB( MP( 0 , i + 1 ) );
      }
    }
    for( int i = 0 ; i < 4 && !got ; i ++ ){
      if( M[ a ][ i ] - 1 == a[ i ] &&
          M[ a ][ ( i + 1 ) % 4 ] - 1 == a[ ( i + 1 ) % 4 ] ){
        got = true;
        ans.PB( MP( 1 , i + 1 ) );
      }
    }
    if( !got ){
      puts( "-1" );
      exit( 0 );
    }
    a = M[ a ];
  }
  for( int i = 0 ; i < 4 ; i ++ )
    if( a[ i ] != 1 ){
      puts( "-1" );
      exit( 0 );
    }
}
void solve(){
  while( M.count( a ) == 0 ){
    bool flag = false;
    for( int i = 0 ; i < 4 ; i ++ )
      if( a[ i ] % 2 == 0 ){
        if( a[ ( i + 1 ) % 4 ] % 2 == 0 ){
          a[ i ] /= 2;
          a[ ( i + 1 ) % 4 ] /= 2;
          ans.PB( MP( 0 , i + 1 ) );
        }else{
          a[ ( i + 1 ) % 4 ] ++;
          a[ ( i + 2 ) % 4 ] ++;
          ans.PB( MP( 1 , ( i + 1 ) % 4 + 1 ) );
          a[ i ] /= 2;
          a[ ( i + 1 ) % 4 ] /= 2;
          ans.PB( MP( 0 , i + 1 ) );
        }
        flag = true;
      }
    for( int i = 0 ; i < 4 ; i ++ )
      while( a[ i ] % 2 == 1 &&
             a[ ( i + 1 ) % 4 ] % 2 == 1 &&
             ( a[ i ] > 1 ||
               a[ ( i + 1 ) % 4 ] > 1 ) ){
        a[ i ] ++;
        a[ ( i + 1 ) % 4 ] ++;
        ans.PB( MP( 1 , i + 1 ) );
        a[ i ] /= 2;
        a[ ( i + 1 ) % 4 ] /= 2;
        ans.PB( MP( 0 , i + 1 ) );
        flag = true;
      }
    ll tsum = 0;
    for( int i = 0 ; i < 4 ; i ++ )
      tsum += a[ i ];
    if( tsum == 5 ){
      for( int i = 0 ; i < 4 ; i ++ )
        if( a[ i ] == 2 ){
          a[ ( i + 3 ) % 4 ] ++;
          a[ i ] ++;
          ans.PB( MP( 1 , ( i + 3 ) % 4 + 1 ) );
          a[ i ] ++;
          a[ ( i + 1 ) % 4 ] ++;
          ans.PB( MP( 1 , i + 1 ) );
          a[ ( i + 3 ) % 4 ] /= 2;
          a[ i ] /= 2;
          ans.PB( MP( 0 , ( i + 3 ) % 4 + 1 ) );
          a[ i ] /= 2;
          a[ ( i + 1 ) % 4 ] /= 2;
          ans.PB( MP( 0 , i + 1 ) );
          break;
        }
    }
    if( !flag ){
      puts( "-1" );
      exit( 0 );
    }
  }
  build_ans();
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%c%d\n" , "/+"[ ans[ i ].FI ] , ans[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}