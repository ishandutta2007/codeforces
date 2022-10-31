#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n , a[ 10 ] , d , ans;
set<LL> S;
set<LL> vst;
void go( int msk ){
  LL vl = 0;
  for( int i = d - 1 ; i >= 0 ; i -- )
    if( (msk >> i) & 1 ){
      if( vl == 0 and a[ i ] == 0 )
        return;
      vl = vl * 10 + a[ i ];
    }
  int cst = d - __builtin_popcount( msk );
  if( S.find( vl ) != S.end() ){
    if( ans == -1 or cst < ans )
      ans = cst;
  }
  if( vst.find( msk ) != vst.end() )
    return;
  vst.insert( msk );
  for( int i = 0 ; i < d ; i ++ )
    if( (msk >> i) & 1 )
      go( msk ^ (1 << i) );
}
void go( int dgt , LL c , int cst ){
  if( dgt < 0 ){
    if( c and (ans == -1 or cst < ans) and
        S.find( c ) != S.end() ){
      ans = cst;
    }
    return;
  }
  go( dgt - 1 , c , cst + 1 );
  go( dgt - 1 , c * 10 + a[ dgt ] , cst );
}
int main(){
  cin >> n;
  for( LL i = 1 ; i * i <= n ; i ++ )
    S.insert( i * i );
  while( n ){
    a[ d ++ ] = n % 10;
    n /= 10;
  }
  ans = -1;
  go( (1 << d) - 1 );
  cout << ans << endl;
}