#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int m , n;
int add( int a , int b ){
  a += b;
  return a >= m ? a - m : a;
}
int sub( int a , int b ){
  a -= b;
  return a < 0 ? a + m : a;
}
LL mul( LL a , LL b ){
  a *= b;
  return a >= m ? a % m : a;
}
int mpow( int a , int b ){
  if( !b ) return 1;
  int ret = mpow( mul( a , a ) , b >> 1 );
  if( b & 1 ) ret = mul( ret , a );
  return ret;
}
int a[ 101010 ];
void init(){
  scanf( "%d%d" , &m , &n );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%d" , &a[ i ] );
}
set<int> S;
pair<int,int> cal(){
  if( S.empty() ) return { 0 , 1 };
  if( n == 1 ) return { *S.begin() , 1 };
  int dlt = *--S.end() - *S.begin() , cnt = 0;
  for( int i : S )
    if( S.count( add( i , dlt ) ) )
      cnt ++;
  dlt = mul( dlt , mpow( n - cnt , m - 2 ) );
  int cc = 0 , st = *S.begin() , a0 = st;
  for( int i = st ; ; i = add( i , dlt ) )
    if( S.count( i ) ) cc ++;
    else break;
  for( int i = sub( st , dlt ) ; ; i = sub( i , dlt ) )
    if( S.count( i ) ) a0 = i , cc ++;
    else break;
  if( cc < n ){
    puts( "-1" );
    exit( 0 );
  }
  return { a0 , dlt };
}
void solve(){
  int dlt = 0;
  if( n + n > m ){
    for( int i = 0 ; i < m ; i ++ ) S.insert( i );
    for( int i = 0 ; i < n ; i ++ ) S.erase( a[ i ] );
    n = dlt = m - n;
  }else
    for( int i = 0 ; i < n ; i ++ ) S.insert( a[ i ] );
  pair<int,int> ret = cal();
  ret.first = add( ret.first , mul( dlt , ret.second ) );
  printf( "%d %d\n" , ret.first , ret.second );
}
int main(){
  init();
  solve();
}