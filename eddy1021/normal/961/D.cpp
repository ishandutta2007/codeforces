#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> Pt;
#define N 101010
#define X first
#define Y second
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return {p1.X - p2.X, p1.Y - p2.Y};
}
LL operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
void scan( Pt& p ){
  scanf( "%lld%lld" , &p.X , &p.Y );
}
void yes(){
  puts( "Yes" );
  exit(0);
}
int n , qsz;
Pt p[ N ] , q[ N ];
int test( const Pt& p1 , const Pt& p2 ){
  qsz = 0;
  int cand = 0;
  for( int i = 0 ; i < n ; i ++ ){
    if( ((p2 - p1) ^ (p[ i ] - p1)) == 0 )
      continue;
    cand = i;
    q[ qsz ++ ] = p[ i ];
  }
  for( int i = 2 ; i < qsz ; i ++ )
    if( ((q[ i ] - q[ 0 ]) ^ (q[ 1 ] - q[ 0 ])) != 0 )
      return cand;
  yes();
  return -1;
}
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ )
    scan( p[ i ] );
  if( n < 5 ) yes();
  int ret = test( p[ 0 ] , p[ 1 ] );
  test( p[ 0 ] , p[ ret ] );
  test( p[ 1 ] , p[ ret ] );
  puts( "No" );
}