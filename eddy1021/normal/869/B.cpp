#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
  LL a , b;
  cin >> a >> b;
  if( a == 0 ) a = 1;
  if( b == 0 ) b = 1;
  if( a / 10 != b / 10 )
    puts( "0" );
  else{
    LL ans = 1;
    for( LL i = a % 10 + 1 ; i <= b % 10 ; i ++ )
      ans = ans * ( i % 10 ) % 10;
    cout << ans << endl;
  }
}