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
#define eps 1e-12
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
typedef long double type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
long double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan( Pt& tp ){
  scanf( "%LF%LF" , &tp.X , &tp.Y );
}
Pt interPnt( Pt p1, Pt p2, Pt q1, Pt q2){
	long double f1 = ( p2 - p1 ) ^ ( q1 - p1 );
	long double f2 = ( p2 - p1 ) ^ ( p1 - q2 );
	long double f = ( f1 + f2 );
	return q1 * ( f2 / f ) + q2 * ( f1 / f );
}
void build(){

}
#define N 101010
Pt a , b;
Circle c[ N ];
int n;
void init(){
  scan( a );
  scan( b );
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    scan( c[ i ].O );
    scanf( "%LF" , &c[ i ].R );
  }
}
Pt mid , dir;
#define K 120
inline bool okay( const Pt& oo , const Pt& aa , const Circle& cc ){
  long double dira = norm( oo - aa );
  long double dirc = norm( oo - cc.O );
  if( dira < dirc ) return dira + cc.R < dirc + eps;
  return dirc + cc.R < dira + eps;
}
long double sqr( long double xx ){
  return xx * xx;
}
void solve(){
  mid = (a + b) * 0.5;
  dir = perp( b - a );
  vector< pair<long double,int> > vv;
  double fuck = sqrt( sqr( 1e12 ) - norm2( a - mid ) );
  Pt umst = mid + dir * ( fuck / norm( dir ) );
  Pt lmst = mid - dir * ( fuck / norm( dir ) );
  double UU = ( ( umst - mid ) * dir ) / norm2( dir );
  double LB = ( ( lmst - mid ) * dir ) / norm2( dir );
  for( int i = 0 ; i < n ; i ++ ){
    long double way = ( c[ i ].O - a ) ^ ( b - a );
    if( fabs( way ) < eps ) continue;
    Pt cmid = ( a + c[ i ].O ) * 0.5;
    Pt cen = interPnt( mid ,  mid + dir ,
                      cmid , cmid + perp( c[ i ].O - a ) );
    {
      long double br = ( ( umst - cen ) * dir ) / norm2( dir );
      long double bl = 0 , ba = 0;
      for( int k = 0 ; k < K ; k ++ ){
        long double bmid = (bl + br) * 0.5;
        Pt cand = cen + dir * bmid;
        if( okay( cand , a , c[ i ] ) )
          ba = bmid , br = bmid;
        else
          bl = bmid;
      }
      Pt rp = cen + dir * ba;
      long double vl = ( ( rp - mid ) * dir ) / norm2( dir );
      vv.push_back( { vl - eps , +1 } );
      vv.push_back( { UU , -1 } );
    }
    {
      long double br = ( ( lmst - cen ) * (dir * -1) ) / norm2( dir );
      long double bl = 0 , ba = 0;
      for( int k = 0 ; k < K ; k ++ ){
        long double bmid = (bl + br) * 0.5;
        Pt cand = cen - dir * bmid;
        if( okay( cand , a , c[ i ] ) )
          ba = bmid , br = bmid;
        else
          bl = bmid;
      }
      Pt rp = cen - dir * ba;
      long double vl = ( ( rp - mid ) * dir ) / norm2( dir );
      vv.push_back( { LB , +1 } );
      vv.push_back( { vl + eps , -1 } );
    }
  }
  sort( vv.begin() , vv.end() );
  long double ans = 1e12;
  if( vv.empty() )
    ans = min( ans , norm( mid - a ) );
  int ps = 0;
  for( size_t i = 0 ; i + 1 < vv.size() ; i ++ ){
    ps += vv[ i ].second;
    if( ps == n ){
      long double lb = vv[ i ].first;
      long double rb = vv[ i + 1 ].first;
      ans = min( ans , norm( ( mid + dir * lb ) -a ) );
      ans = min( ans , norm( ( mid + dir * rb ) -a ) );
      if( lb < 0 and 0 < rb )
        ans = min( ans , norm( mid - a ) );
    }
  }
  printf( "%.12f\n" , (double)ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}