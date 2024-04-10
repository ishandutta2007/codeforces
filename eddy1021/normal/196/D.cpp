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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
#define K 3
const int mods[ K ] = { mod7 , mod9 , 1010102101 };
struct Int{
  int vl[ K ];
  Int( int _vl = 0 ){
    for( int i = 0 ; i < K ; i ++ )
      vl[ i ] = _vl % mods[ i ];
  }
  Int operator+( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.vl[ i ] = add( vl[ i ] , he.vl[ i ] , mods[ i ] );
    return ret;
  }
  Int operator-( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.vl[ i ] = sub( vl[ i ] , he.vl[ i ] , mods[ i ] );
    return ret;
  }
  Int operator*( const Int& he ) const{
    Int ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.vl[ i ] = mul( vl[ i ] , he.vl[ i ] , mods[ i ] );
    return ret;
  }
  bool operator==( const Int& he ) const{
    for( int i = 0 ; i < K ; i ++ )
      if( vl[ i ] != he.vl[ i ] )
        return false;
    return true;
  }
};

#define N 404040
struct Z_Palindrome{
  int zv[N << 1];
  char op[N << 1];
  void solve( char* ip , int len ){
    int l2 = len * 2 + 1;
    for(int i=0; i<l2; i++)
      if(i&1) op[i] = ip[i/2];
      else op[i] = '@';
    op[ l2 ] = 0;
    //puts( op );
    int l=0, r=0; zv[0] = 1;
    for(int i=1; i<l2; i++){
      if( i > r ){
        l = r = i;
        while( l>0 && r<l2-1 && op[l-1] == op[r+1] )
          l --, r ++;
        zv[i] = (r-l+1);
      }else{
        int md = (l+r)/2, j = md + md - i;
        zv[i] = zv[j];
        int q = zv[i] / 2, nr = i + q;
        if( nr == r ){
          l = i + i - r;
          while( l>0 && r<l2-1 && op[l-1] == op[r+1] )
            l --, r ++;
          zv[i] = r - l + 1;
        }else if( nr > r )
          zv[i] = (r - i) * 2 + 1;
      }
    }
    //for( int i = 0 ; i < l2 ; i ++ )
      //printf( "%d%c" , zv[ i ] , " \n"[ i + 1 == l2 ] );
  }
} solver;
int d , len;
char s[ N ];
void init(){
  d = getint();
  scanf( "%s" , s );
  len = strlen( s );
  solver.solve( s , len );
}
void cons( set<char>& gg , int curd , int i ){
  if( i + 1 < curd + 2 or curd < 0 ) return;
  if( curd == 0 ){
    gg.insert( s[ i - 1 ] );
    return;
  }
  if( curd % 2 ){
    int who = i - ( curd + 1 ) / 2;
    if( solver.zv[ who * 2 + 1 ] / 2 >= curd )
      gg.insert( s[ i - curd - 1 ] );
  }else{
    int who = i - curd / 2;
    if( solver.zv[ who * 2 ] / 2 >= curd )
      gg.insert( s[ i - curd - 1 ] );
  }
}
bool noway( int curd , int i ){
  if( i + 1 < curd ) return false;
  if( curd % 2 ){
    int who = i - curd / 2;
    if( solver.zv[ who * 2 + 1 ] / 2 >= curd )
      return true;
  }else{
    int who = i - curd / 2;
    if( solver.zv[ who * 2 + 2 ] / 2 >= curd )
      return true;
  }
  return false;
}
Int bs[ N ] , ibs[ N ] , hs[ N ] , hs2[ N ];
inline Int hs_vl( int l , int r ){
  Int ret = hs[ r ];
  if( l ) ret = ret - hs[ l - 1 ] * bs[ r - l + 1 ];
  return ret;
}
inline Int hs_vl2( int l , int r ){
  Int ret = hs2[ r ];
  if( l ){
    ret = ret - hs2[ l - 1 ];
    ret = ret * ibs[ l ];
  }
  return ret;
}
void go( int ok , char cok ){
  s[ ok ] = cok;
  bs[ 0 ] = Int( 1 );
  bs[ 1 ] = Int( 13131 );
  ibs[ 0 ] = Int( 1 );
  for( int i = 0 ; i < 3 ; i ++ )
    ibs[ 1 ].vl[ i ] = mypow( 13131 , mods[ i ] - 2 , mods[ i ] );
  for( int i = 2 ; i <= len ; i ++ ){
    bs[ i ] = bs[ i - 1 ] * bs[ 1 ];
    ibs[ i ] = ibs[ i - 1 ] * ibs[ 1 ];
  }
  for( int i = 0 ; i < len ; i ++ ){
    if( i > ok ){
      set<char> gg;
      if( i + 1 >= d ){
        if( hs_vl( i - d + 2 , i - 1 ) == hs_vl2( i - d + 2 , i - 1 ) )
          gg.insert( s[ i - d + 1 ] );
      }
      if( i + 1 >= d + 1 ){
        if( hs_vl( i - d + 1 , i - 1 ) == hs_vl2( i - d + 1 , i - 1 ) )
          gg.insert( s[ i - d ] );
      }
      for( char ii = 'a' ; ii <= 'z' ; ii ++ )
        if( gg.count( ii ) ) continue;
        else{
          s[i] = ii;
          break;
        }
    }
    hs[ i ] = hs[ i - 1 ] * bs[ 1 ] + Int( s[ i ] );
    hs2[ i ] = hs2[ i - 1 ] + Int( s[ i ] ) * bs[ i ];
  }
  s[ ok ] = cok;
  puts( s );
}
void solve(){
  if( d == 1 ){
    puts( "Impossible" );
    Bye;
  }
  int ok = -1; char cok = ' ';
  for( int i = 0 ; i < len ; i ++ ){
    set<char> gg;
    cons( gg , d - 1 , i );
    cons( gg , d - 2 , i );
    if( s[ i ] < 'z' ){
      //cerr << i << endl;
      //for( auto jj : gg )
        //cerr << jj << " ";
      //cerr << endl;
      for( char ii = s[ i ] + 1 ; ii <= 'z' ; ii ++ )
        if( gg.count( ii ) )
          continue;
        else{
          ok = i;
          cok = ii;
          break;
        }
    }
    if( noway( d     , i ) ) break;
    if( noway( d + 1 , i ) ) break;
  }
  if( ok == -1 )
    puts( "Impossible" );
  else
    go( ok , cok );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}