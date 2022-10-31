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
void build(){

}
#define N 100
LL x[ N ] , y[ N ];
void init(){
  for( int i = 0 ; i < 4 ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
  }
}
LL ans , ax[ N ] , ay[ N ] , tx[ N ] , ty[ N ] , d[ N ];
void update( LL tans , const vector<int>& per ){
  ans = tans;
  for( int i = 0 ; i < 4 ; i ++ ){
    ax[ i ] = tx[ per[ i ] ];
    ay[ i ] = ty[ per[ i ] ];
  }
}
LL kx[ N ] , ky[ N ];
void update_kans( LL tans ){
  if( ans == -1 || tans < ans ){
    ans = tans;
    for( int i = 0 ; i < 4 ; i ++ ){
      ax[ i ] = kx[ i ];
      ay[ i ] = ky[ i ];
    }
  }
}
void check_ans(){
  vector<int> per;
  for( int i = 0 ; i < 4 ; i ++ ) per.PB( i );
  do{
    LL tans = 0; bool flag = true;
    for( int i = 0 ; i < 4 ; i ++ ){
      if( d[ i ] == 0 ){
        if( y[ i ] != ty[ per[ i ] ] ){
          flag = false; break;
        }
        tans = max( tans , abs( x[ i ] - tx[ per[ i ] ] ) );
      }else{
        if( x[ i ] != tx[ per[ i ] ] ){
          flag = false; break;
        }
        tans = max( tans , abs( y[ i ] - ty[ per[ i ] ] ) );
      }
    }
    if( flag && ( ans == -1 || tans < ans ) )
      update( tans , per );
  }while( next_permutation( ALL( per ) ) );
}
void cal(){
  vector<LL> xx , yy;
  for( int i = 0 ; i < 4 ; i ++ )
    if( d[ i ] == 0 )
      yy.PB( y[ i ] );
    else
      xx.PB( x[ i ] );
  sort( ALL( xx ) );
  xx.resize( unique( ALL( xx ) ) - xx.begin() );
  sort( ALL( yy ) );
  yy.resize( unique( ALL( yy ) ) - yy.begin() );
  if( (int)xx.size() > 2 || (int)yy.size() > 2 ) return;
  if( (int)xx.size() == 2 && (int)yy.size() == 2 ){
    if( xx[ 0 ] == xx[ 1 ] ) return;
    if( xx[ 1 ] - xx[ 0 ] != yy[ 1 ] - yy[ 0 ] ) return;
    tx[ 0 ] = xx[ 0 ]; ty[ 0 ] = yy[ 0 ];
    tx[ 1 ] = xx[ 0 ]; ty[ 1 ] = yy[ 1 ];
    tx[ 2 ] = xx[ 1 ]; ty[ 2 ] = yy[ 0 ];
    tx[ 3 ] = xx[ 1 ]; ty[ 3 ] = yy[ 1 ];
    check_ans();
  }else if( (int)xx.size() == 2 && (int)yy.size() == 1 ){
    if( xx[ 0 ] == xx[ 1 ] ) return;
    ll dd = xx[ 1 ] - xx[ 0 ];
    tx[ 0 ] = xx[ 0 ]; ty[ 0 ] = yy[ 0 ];
    tx[ 1 ] = xx[ 0 ]; ty[ 1 ] = yy[ 0 ] + dd;
    tx[ 2 ] = xx[ 1 ]; ty[ 2 ] = yy[ 0 ];
    tx[ 3 ] = xx[ 1 ]; ty[ 3 ] = yy[ 0 ] + dd;
    check_ans();
    tx[ 1 ] = xx[ 0 ]; ty[ 1 ] = yy[ 0 ] - dd;
    tx[ 3 ] = xx[ 1 ]; ty[ 3 ] = yy[ 0 ] - dd;
    check_ans();
  }else if( (int)yy.size() == 2 && (int)xx.size() == 1 ){
    if( yy[ 0 ] == yy[ 1 ] ) return;
    ll dd = yy[ 1 ] - yy[ 0 ];
    tx[ 0 ] = xx[ 0 ]; ty[ 0 ] = yy[ 0 ];
    tx[ 1 ] = xx[ 0 ]; ty[ 1 ] = yy[ 1 ];
    tx[ 2 ] = xx[ 0 ] + dd; ty[ 2 ] = yy[ 0 ];
    tx[ 3 ] = xx[ 0 ] + dd; ty[ 3 ] = yy[ 1 ];
    check_ans();
    tx[ 2 ] = xx[ 0 ] - dd; ty[ 2 ] = yy[ 0 ];
    tx[ 3 ] = xx[ 0 ] - dd; ty[ 3 ] = yy[ 1 ];
    check_ans();
  }else if( (int)xx.size() == 2 ){
    ll dd = xx[ 1 ] - xx[ 0 ];
    vector<int> p[ 2 ];
    for( int i = 0 ; i < 4 ; i ++ ){
      if( x[ i ] == xx[ 0 ] ) p[ 0 ].PB( i );
      else p[ 1 ].PB( i );
    }
    if( (int)p[ 0 ].size() != 2 || (int)p[ 1 ].size() != 2 ) return;
    for( int i = 0 ; i < 2 ; i ++ ){
      for( int j = 0 ; j < 2 ; j ++ ){
        ll bl = 0 , br = 1000000000ll , bmid;
        while( bl <= br ){
          bmid = ( bl + br ) >> 1;
          ll ty1 = max( y[ p[ 0 ][ 0 ] ] - bmid , y[ p[ 1 ][ 0 ] ] - bmid );
          ll ty2 = min( y[ p[ 0 ][ 0 ] ] + bmid , y[ p[ 1 ][ 0 ] ] + bmid );
          ll ty3 = max( y[ p[ 0 ][ 1 ] ] - bmid , y[ p[ 1 ][ 1 ] ] - bmid );
          ll ty4 = min( y[ p[ 0 ][ 1 ] ] + bmid , y[ p[ 1 ][ 1 ] ] + bmid );
          bool okay = false;
          if( ty1 <= ty2 && ty3 <= ty4 ){
            if( max( ty1 + dd , ty3 ) <= min( ty2 + dd , ty4 ) ){
              okay = true;
              kx[ p[ 0 ][ 0 ] ] = xx[ 0 ]; ky[ p[ 0 ][ 0 ] ] = max( ty1 + dd , ty3 ) - dd;
              kx[ p[ 0 ][ 1 ] ] = xx[ 0 ]; ky[ p[ 0 ][ 1 ] ] = max( ty1 + dd , ty3 );
              kx[ p[ 1 ][ 0 ] ] = xx[ 1 ]; ky[ p[ 1 ][ 0 ] ] = max( ty1 + dd , ty3 ) - dd;
              kx[ p[ 1 ][ 1 ] ] = xx[ 1 ]; ky[ p[ 1 ][ 1 ] ] = max( ty1 + dd , ty3 );
              update_kans( bmid );
            }
            if( max( ty1 - dd , ty3 ) <= min( ty2 - dd , ty4 ) ){
              okay = true;
              kx[ p[ 0 ][ 0 ] ] = xx[ 0 ]; ky[ p[ 0 ][ 0 ] ] = max( ty1 - dd , ty3 ) + dd;
              kx[ p[ 0 ][ 1 ] ] = xx[ 0 ]; ky[ p[ 0 ][ 1 ] ] = max( ty1 - dd , ty3 );
              kx[ p[ 1 ][ 0 ] ] = xx[ 1 ]; ky[ p[ 1 ][ 0 ] ] = max( ty1 - dd , ty3 ) + dd;
              kx[ p[ 1 ][ 1 ] ] = xx[ 1 ]; ky[ p[ 1 ][ 1 ] ] = max( ty1 - dd , ty3 );
              update_kans( bmid );
            }
          }
          if( okay ) br = bmid - 1;
          else bl = bmid + 1;
        }
        swap( p[ 1 ][ 0 ] , p[ 1 ][ 1 ] );
      }
      swap( p[ 0 ][ 0 ] , p[ 0 ][ 1 ] );
    }
  }else if( (int)yy.size() == 2 ){
    ll dd = yy[ 1 ] - yy[ 0 ];
    vector<int> p[ 2 ];
    for( int i = 0 ; i < 4 ; i ++ ){
      if( y[ i ] == yy[ 0 ] ) p[ 0 ].PB( i );
      else p[ 1 ].PB( i );
    }
    if( (int)p[ 0 ].size() != 2 || (int)p[ 1 ].size() != 2 ) return;
    for( int i = 0 ; i < 2 ; i ++ ){
      for( int j = 0 ; j < 2 ; j ++ ){
        ll bl = 0 , br = 1000000000ll , bmid;
        while( bl <= br ){
          bmid = ( bl + br ) >> 1;
          ll ty1 = max( x[ p[ 0 ][ 0 ] ] - bmid , x[ p[ 1 ][ 0 ] ] - bmid );
          ll ty2 = min( x[ p[ 0 ][ 0 ] ] + bmid , x[ p[ 1 ][ 0 ] ] + bmid );
          ll ty3 = max( x[ p[ 0 ][ 1 ] ] - bmid , x[ p[ 1 ][ 1 ] ] - bmid );
          ll ty4 = min( x[ p[ 0 ][ 1 ] ] + bmid , x[ p[ 1 ][ 1 ] ] + bmid );
          bool okay = false;
          if( ty1 <= ty2 && ty3 <= ty4 ){
            if( max( ty1 + dd , ty3 ) <= min( ty2 + dd , ty4 ) ){
              okay = true;
              kx[ p[ 0 ][ 0 ] ] = max( ty1 + dd , ty3 ) - dd; ky[ p[ 0 ][ 0 ] ] = yy[ 0 ];
              kx[ p[ 0 ][ 1 ] ] = max( ty1 + dd , ty3 );      ky[ p[ 0 ][ 1 ] ] = yy[ 0 ];
              kx[ p[ 1 ][ 0 ] ] = max( ty1 + dd , ty3 ) - dd; ky[ p[ 1 ][ 0 ] ] = yy[ 1 ];
              kx[ p[ 1 ][ 1 ] ] = max( ty1 + dd , ty3 );      ky[ p[ 1 ][ 1 ] ] = yy[ 1 ];
              update_kans( bmid );
            }
            if( max( ty1 - dd , ty3 ) <= min( ty2 - dd , ty4 ) ){
              okay = true;
              kx[ p[ 0 ][ 0 ] ] = max( ty1 - dd , ty3 ) + dd; ky[ p[ 0 ][ 0 ] ] = yy[ 0 ];
              kx[ p[ 0 ][ 1 ] ] = max( ty1 - dd , ty3 );      ky[ p[ 0 ][ 1 ] ] = yy[ 0 ];
              kx[ p[ 1 ][ 0 ] ] = max( ty1 - dd , ty3 ) + dd; ky[ p[ 1 ][ 0 ] ] = yy[ 1 ];
              kx[ p[ 1 ][ 1 ] ] = max( ty1 - dd , ty3 );      ky[ p[ 1 ][ 1 ] ] = yy[ 1 ];
              update_kans( bmid );
            }
          }
          if( okay ) br = bmid - 1;
          else bl = bmid + 1;
        }
        swap( p[ 1 ][ 0 ] , p[ 1 ][ 1 ] );
      }
      swap( p[ 0 ][ 0 ] , p[ 0 ][ 1 ] );
    }
  }
}
void solve(){
  ans = -1;
  for( int i1 = 0 ; i1 < 2 ; i1 ++ )
    for( int i2 = 0 ; i2 < 2 ; i2 ++ )
      for( int i3 = 0 ; i3 < 2 ; i3 ++ )
        for( int i4 = 0 ; i4 < 2 ; i4 ++ ){
          d[ 0 ] = i1;
          d[ 1 ] = i2;
          d[ 2 ] = i3;
          d[ 3 ] = i4;
          cal();
        }
  printf( "%lld\n" , ans );
  if( ans != -1 ){
    for( int i = 0 ; i < 4 ; i ++ )
      printf( "%lld %lld\n" , ax[ i ] , ay[ i ] );
  }
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}