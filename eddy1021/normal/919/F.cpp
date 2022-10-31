// eddy1021
//#pragma GCC optimize("O3")
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
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
unordered_map<int,int> _id;
#define N 1021
int _mid;
inline int id( int x ){
  auto it = _id.find( x );
  if( it != _id.end() ) return it->second;
  assert( _mid < N );
  return _id[ x ] = _mid ++;
}
inline int encode( int* x ){
  int ret = 0;
  for( int i = 0 ; i < 8 ; i ++ )
    ret = ret | (x[ i ] << (i * 3) );
  return ret;
}
inline void decode( int* x , int v ){
  for( int i = 0 ; i < 8 ; i ++ )
    x[ i ] = (v >> (i * 3)) & 7;
}
int win[ N ][ N ];
// 0 lose 1 deal 2 win
queue< pair<int,int> > Q;
bool gt[ N ][ N ];
bool inq[ N ][ N ];
int buf[ 8 ];
void go( int now , int v ){
  if( now == 8 ){
    if( encode( buf ) == 0 ) return;
    int vid = id( encode( buf ) );
    int zer = id( 0 );
    win[ vid ][ zer ] = -1;
    gt[ vid ][ zer ] = true;
    inq[ vid ][ zer ] = true;
    Q.push( { encode( buf ) , 0 } );
    return;
  }
  for( int i = v ; i < 5 ; i ++ ){
    buf[ now ] = i;
    go( now + 1 , i );
  }
}
inline int reduce( int v ){
  int x[ 8 ];
  decode( x , v );
  sort( x , x + 8 );
  return encode( x );
}
inline int BT( int X , int i ){
  return (X >> (i * 3)) & 7;
}

void check( int vla , int vlb , int to ){
  int ida = id( vla );
  int idb = id( vlb );
  if( win[ ida ][ idb ] == 1 ) return;
  int ori = win[ ida ][ idb ];
  win[ ida ][ idb ] = -to;
  if( win[ ida ][ idb ] == -1 ){
    bool got = false;
    for( int i = 0 ; i < 8 and not got ; i ++ ){
      if( BT( vla, i ) == 0 ) continue;
      for( int j = 0 ; j < 8 and not got ; j ++ ){
        if( BT( vlb, j ) == 0 ) continue;
        int ni = (BT( vla , i ) + BT( vlb , j )) % 5;
        int nxt_vla = reduce( vla ^ ((BT(vla, i) ^ ni) << (i * 3)) );
        if( win[ id( vlb ) ][ id( nxt_vla ) ] < 1 ){
          win[ ida ][ idb ] = -win[ id( vlb ) ][ id( nxt_vla ) ];
          got = true;
        }
      }
    } 
  }
  int now = win[ ida ][ idb ];
  if( not gt[ ida ][ idb ] or ori != now ){
    gt[ ida ][ idb ] = true;
    if( not inq[ ida ][ idb ] ){
      inq[ ida ][ idb ] = true;
      Q.push( { vla , vlb } );
    }
  }
}

void build(){
  go( 0 , 0 );
  while( Q.size() ){
    int vla , vlb; tie( vla , vlb ) = Q.front(); Q.pop();
    inq[ id( vla ) ][ id( vlb ) ] = false;
    for( int i = 0 ; i < 8 ; i ++ ){
      if( BT( vla, i ) == 0 ) continue;
      for( int j = 0 ; j < 8 ; j ++ ){
        int res = BT( vlb , j );
        int ori = sub( res , BT( vla , i ) , 5 );
        if( ori == 0 ) continue;
        int prej = reduce( vlb ^ ((res ^ ori) << (j * 3)) );
        check( prej , vla , win[ id( vla ) ][ id( vlb ) ] );
      }
    }
  }
}



//#define BT(X,i) (((X)>>((i)*3))&7)


//int Win( int vla , int vlb ){
  //if( vla == 0 ) return 2;
  //if( vlb == 0 ) return 0;
  //int ida = id( vla );
  //int idb = id( vlb );
  //if( gt[ ida ][ idb ] ) return win[ ida ][ idb ];
  //if( in[ ida ][ idb ] ) return 1;
  //in[ ida ][ idb ] = true;

  //int ret = 0;
  //for( int i = 0 ; i < 8 and ret < 2 ; i ++ ){
    //if( BT( vla , i ) == 0 )
      //continue;
    //if( i and BT( vla , i ) == BT( vla , i - 1 ) )
      //continue;
    //for( int j = 0 ; j < 8 and ret < 2 ; j ++ ){
      //if( BT( vlb , j ) == 0 )
        //continue;
      //if( j and BT( vlb , j ) == BT( vlb , j - 1 ) )
        //continue;
      //int ni = (BT( vla , i ) + BT( vlb , j )) % 5;
      //int nxt_vla = reduce( vla ^ ((BT(vla, i) ^ ni) << (i * 3)) );
      //ret = max( ret , 2 - Win( vlb , nxt_vla ) );
    //}
  //}

  //in[ ida ][ idb ] = false;
  //gt[ ida ][ idb ] = true;
  //return win[ ida ][ idb ] = ret;
//}

int who , a[ 8 ] , b[ 8 ];
void init(){
  who = getint();
  for( int i = 0 ; i < 8 ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < 8 ; i ++ )
    b[ i ] = getint();
  sort( a , a + 8 );
  sort( b , b + 8 );
}
void solve(){
  int vla = encode( a );
  int vlb = encode( b );
  if( who ) swap( vla , vlb );
  //int ret = Win( vla , vlb );
  int ret = win[ id( vla ) ][ id( vlb ) ] + 1;
  if( ret == 1 ) puts( "Deal" );
  else{
    ret ^= (who << 1);
    if( ret == 2 ) puts( "Alice" );
    else puts( "Bob" );
  }
}
int main(){
  //int buf[ 8 ];
  //for( int i = 0 ; i < (1 << 24) ; i ++ ){
    //decode( buf , i );
    //assert( i == encode( buf ) );
  //}


  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}