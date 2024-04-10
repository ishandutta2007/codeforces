#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define double long double
typedef double type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Cir;
const double eps = 1e-10;
#define X first
#define Y second
#define O first
#define R second
bool equal( double x , double y ){
  return x - eps < y and y < x + eps;
}
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
bool equal( const Pt& p1 , const Pt& p2 ){
  return equal( p1.X , p2.X ) and
         equal( p1.Y , p2.Y );
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan( Pt& tp ){
  cin >> tp.X >> tp.Y;
}
typedef double D;
vector<Pt> interCircle( Pt o1 , D r1 , Pt o2 , D r2 ){
  if( norm( o1 - o2 ) > r1 + r2 ) return {};
  if( norm( o1 - o2 ) < max(r1, r2) - min(r1, r2) ) return {};
  D d2 = ( o1 - o2 ) * ( o1 - o2 );
  D d = sqrt(d2);
	if( d > r1 + r2 ) return {};
  Pt u = (o1+o2)*0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  D A = sqrt((r1+r2+d)*(r1-r2+d)*(r1+r2-d)*(-r1+r2+d));
  Pt v = Pt( o1.Y-o2.Y , -o1.X + o2.X ) * A / (2*d2);
  return {u+v, u-v};
}
#define N 55
int n , p[ N ];
int f( int x ){ return x == p[ x ] ? x : p[ x ] = f( p[ x ] ); }
void uni( int x , int y ){ p[ f( x ) ] = f( y ); }
Cir c[ N ];
void uniq( vector<Pt>& vv ){
  sort( vv.begin() , vv.end() );
  if( vv.empty() ) return;
  size_t nsz = 1;
  for( size_t i = 1 ; i < vv.size() ; i ++ ){
    bool ok = true;
    for( size_t j = 0 ; j < nsz and ok ; j ++ )
      if( equal( vv[ i ] , vv[ j ] ) )
        ok = false;
    if( ok )
      vv[ nsz ++ ] = vv[ i ];
  }
  vv.resize( nsz );
}
int main(){
  cin >> n;
  for( int i = 0 ; i < n ; i ++ ){
    p[ i ] = i;
    scan( c[ i ].O );
    cin >> c[ i ].R;
  }
  vector<Pt> v;
  int e = 0;
  for( int i = 0 ; i < n ; i ++ ){
    vector<Pt> vv;
    for( int j = 0 ; j < n ; j ++ ){
      if( i == j ) continue;
      vector<Pt> ret = interCircle( c[ i ].O , c[ i ].R ,
                                    c[ j ].O , c[ j ].R );
      if( ret.empty() ) continue;
      uni( i , j );
      for( auto ip : ret ){
        v.push_back( ip );
        vv.push_back( ip );
      }
    }
    uniq( vv );
    e += vv.size();
  }
  uniq( v );
  int ans = 1 - v.size() + e;
  for( int i = 0 ; i < n ; i ++ )
    if( f( i ) == i )
      ans ++;
  printf( "%d\n" , ans );
}