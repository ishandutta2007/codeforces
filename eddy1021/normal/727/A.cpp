#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, s[ 99 ];
void go( LL now , LL cur ){
  if( now > b ) return;
  if( now == b ){
    puts( "YES" );
    printf( "%lld\n" , cur );
    for( LL i = 0 ; i < cur ; i ++ )
      printf( "%lld%c" , s[ i ] , " \n"[ i + 1 == cur ] );
    exit( 0 );
  }
  go( s[cur] = now * 2 , cur + 1 );
  go( s[cur] = now * 10 + 1 , cur + 1 );
}
int main(){
  cin >> a >> b;
  go(s[0] = a, 1);
  cout << "NO" << endl;
}