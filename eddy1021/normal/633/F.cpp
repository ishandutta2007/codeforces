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
#define N 101010
vector<int> v[ N ];
int n , a[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].PB( vi );
    v[ vi ].PB( ui );
  }
}
ll dp[ N ][ 5 ];
ll mxl[ N ][ 3 ];
ll mxr[ N ][ 3 ];
int mtl[ N ] , mtr[ N ];
// 0 none 1 one go 2 one done 3 two go 4 two done
void DP( int now , int prt ){
  dp[ now ][ 1 ] = dp[ now ][ 2 ] = a[ now ];
  dp[ now ][ 3 ] = dp[ now ][ 4 ] = 0;
  if( v[ now ].size() == 1 && prt != -1 ) return;
  vector<ll> tdp[ 3 ];
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son != prt ){
      DP( son , now );
      dp[ now ][ 1 ] = max( dp[ now ][ 1 ] , a[ now ] + dp[ son ][ 1 ] );
      dp[ now ][ 2 ] = max( dp[ now ][ 2 ] , a[ now ] + dp[ son ][ 1 ] );
      dp[ now ][ 2 ] = max( dp[ now ][ 2 ] , dp[ son ][ 2 ] );
      dp[ now ][ 3 ] = max( dp[ now ][ 3 ] , a[ now ] + dp[ son ][ 3 ] );
      dp[ now ][ 3 ] = max( dp[ now ][ 3 ] , a[ now ] + dp[ son ][ 2 ] );
      dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , a[ now ] + dp[ son ][ 3 ] );
      dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , dp[ son ][ 4 ] );
      tdp[ 0 ].PB( dp[ son ][ 1 ] ); // 1 go
      tdp[ 1 ].PB( dp[ son ][ 2 ] ); // 1 done
      tdp[ 2 ].PB( dp[ son ][ 3 ] ); // 2 go
    }
  }
  int sz = (int)tdp[ 0 ].size();
  // 1 go + 1 go = 1 done
  ll bst = 0;
  for( int i = 0 ; i < sz ; i ++ ){
    dp[ now ][ 2 ] = max( dp[ now ][ 2 ] , bst + tdp[ 0 ][ i ] + a[ now ] );
    bst = max( bst , tdp[ 0 ][ i ] );
  }
  bst = 0;
  for( int i = sz - 1 ; i >= 0 ; i -- ){
    dp[ now ][ 2 ] = max( dp[ now ][ 2 ] , bst + tdp[ 0 ][ i ] + a[ now ] );
    bst = max( bst , tdp[ 0 ][ i ] );
  }
  // 1 go + 1 done = 2 go
  bst = 0;
  for( int i = 0 ; i < sz ; i ++ ){
    dp[ now ][ 3 ] = max( dp[ now ][ 3 ] , bst + tdp[ 1 ][ i ] + a[ now ] );
    bst = max( bst , tdp[ 0 ][ i ] );
  }
  bst = 0;
  for( int i = sz - 1 ; i >= 0 ; i -- ){
    dp[ now ][ 3 ] = max( dp[ now ][ 3 ] , bst + tdp[ 1 ][ i ] + a[ now ] );
    bst = max( bst , tdp[ 0 ][ i ] );
  }
  // 1 done + 1 done = 2 done
  bst = 0;
  for( int i = 0 ; i < sz ; i ++ ){
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , bst + tdp[ 1 ][ i ] );
    bst = max( bst , tdp[ 1 ][ i ] );
  }
  bst = 0;
  for( int i = sz - 1 ; i >= 0 ; i -- ){
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , bst + tdp[ 1 ][ i ] );
    bst = max( bst , tdp[ 1 ][ i ] );
  }
  // 2 go + 1 go = 2 done
  bst = 0;
  for( int i = 0 ; i < sz ; i ++ ){
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , bst + tdp[ 2 ][ i ] + a[ now ] );
    bst = max( bst , tdp[ 0 ][ i ] );
  }
  bst = 0;
  for( int i = sz - 1 ; i >= 0 ; i -- ){
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , bst + tdp[ 2 ][ i ] + a[ now ] );
    bst = max( bst , tdp[ 0 ][ i ] );
  }
  // 1 go + 1 go + 1 done = 2 done
  for( int i = 0 ; i < sz ; i ++ ){
    if( i == 0 ){
      mtl[ i ] = 1;
      mxl[ i ][ 0 ] = tdp[ 0 ][ i ];
    }else{
      mtl[ i ] = mtl[ i - 1 ];
      for( int j = 0 ; j < mtl[ i ] ; j ++ )
        mxl[ i ][ j ] = mxl[ i - 1 ][ j ];
      mxl[ i ][ mtl[ i ] ++ ] = tdp[ 0 ][ i ];
      for( int j = mtl[ i ] - 2 ; j >= 0 ; j -- )
        if( mxl[ i ][ j ] < mxl[ i ][ j + 1 ] )
          swap( mxl[ i ][ j ] , mxl[ i ][ j + 1 ] );
      mtl[ i ] = 2;
    }
  }
  for( int i = sz - 1 ; i >= 0 ; i -- ){
    if( i == sz - 1 ){
      mtr[ i ] = 1;
      mxr[ i ][ 0 ] = tdp[ 0 ][ i ];
    }else{
      mtr[ i ] = mtr[ i + 1 ];
      for( int j = 0 ; j < mtr[ i ] ; j ++ )
        mxr[ i ][ j ] = mxr[ i + 1 ][ j ];
      mxr[ i ][ mtr[ i ] ++ ] = tdp[ 0 ][ i ];
      for( int j = mtr[ i ] - 2 ; j >= 0 ; j -- )
        if( mxr[ i ][ j ] < mxr[ i ][ j + 1 ] )
          swap( mxr[ i ][ j ] , mxr[ i ][ j + 1 ] );
      mtr[ i ] = 2;
    }
  }
  for( int i = 1 ; i < sz - 1 ; i ++ )
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , a[ now ] + mxl[ i - 1 ][ 0 ] +
                                           mxr[ i + 1 ][ 0 ] + tdp[ 1 ][ i ] );
  for( int i = 2 ; i < sz ; i ++ )
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , a[ now ] + mxl[ i - 1 ][ 0 ] +
                                           mxl[ i - 1 ][ 1 ] + tdp[ 1 ][ i ] );
  for( int i = 0 ; i < sz - 2 ; i ++ )
    dp[ now ][ 4 ] = max( dp[ now ][ 4 ] , a[ now ] + mxr[ i + 1 ][ 0 ] +
                                           mxr[ i + 1 ][ 1 ] + tdp[ 1 ][ i ] );
}
void solve(){
  DP( 1 , -1 );
  ll ans = 0;
  for( int i = 0 ; i < 5 ; i ++ )
    ans = max( ans , dp[ 1 ][ i ] );
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