// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w , m , k , ans;
inline LL S( LL x ){
  LL c = 0;
  while( x ){
    c ++;
    x /= 10;
  }
  return c;
}
int main(){
  scanf( "%lld%lld%lld" , &w , &m , &k );
  while( w > 0 ){
    LL st = m , cst = S( m );
    LL ed = 1;
    for( int _ = 0 ; _ < cst ; _ ++ )
      ed *= 10;
    LL res = ( w / k ) / cst;
    //printf( "st = %lld, ed = %lld, cst = %lld, w = %lld, res = %lld\n" , st , ed , cst , w , res );
    if( ed - st <= res ){
      ans += ed - st;
      w -= ( ed - st ) * k * cst;
      m = ed;
    }else{
      ans += res;
      break;
    }
  }
  printf( "%lld\n" , ans );
}