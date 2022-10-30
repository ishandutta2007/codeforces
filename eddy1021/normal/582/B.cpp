// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 110
int vn , t , n , a[ N ];
vector<int> li;
struct Seq{
  int dp[ N ][ N ];
  Seq(){
    for( int i = 0 ; i < N ; i ++ )
      for( int j = 0 ; j < N ; j ++ )
        dp[ i ][ j ] = 0;
  }
};
Seq operator*( const Seq& s1 , const Seq& s2 ){
  Seq ts;
  for( int i = 0 ; i < vn ; i ++ )
    for( int j = i ; j < vn ; j ++ )
      for( int k = j ; k < vn ; k ++ )
        ts.dp[ i ][ k ] = max( ts.dp[ i ][ k ] ,
                               s1.dp[ i ][ j ] +
                               s2.dp[ j ][ k ] );
  return ts;
}
void build(){

}
void init(){
  n = getint();
  t = getint();
  for( int i = 0 ; i < n ; i ++ ){
    a[ i ] = getint();
    li.PB( a[ i ] );
  }
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = lower_bound( ALL( li ) , a[ i ] ) - li.begin();
  vn = (int)li.size();
}
Seq tdp[ 25 ];
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    for( int k = a[ i ] ; k >= 0 ; k -- )
      for( int j = k ; j >= 0 ; j -- )
        tdp[ 0 ].dp[ j ][ a[ i ] ] =
          max( tdp[ 0 ].dp[ j ][ a[ i ] ] ,
               tdp[ 0 ].dp[ j ][ k ] + 1 );
    tdp[ 0 ].dp[ a[ i ] ][ a[ i ] ] =
      max( tdp[ 0 ].dp[ a[ i ] ][ a[ i ] ] , 1 );
  }
  for( int i = 1 ; i < 25 ; i ++ )
    tdp[ i ] = tdp[ i - 1 ] * tdp[ i - 1 ];
  Seq ans;
  for( int i = 0 ; i < 25 ; i ++ )
    if( ( 1 << i ) & t )
      ans = ans * tdp[ i ];
  int nans = 0;
  for( int i = 0 ; i < vn ; i ++ )
    for( int j = i ; j < vn ; j ++ )
      nans = max( nans , ans.dp[ i ][ j ] );
  cout << nans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}