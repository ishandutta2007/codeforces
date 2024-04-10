#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a , b , f , k , ans;
int main(){
  cin >> a >> b >> f >> k;
  LL at = 0 , lft = b;
  while( at < a * k ){
    if( lft == 0 or ans > k + k ){
      puts( "-1" );
      exit(0);
    }
    LL pre = at;
    at += lft; lft = 0;
    if( at >= a * k ){
      cout << ans << endl;
      exit(0);
    }
    LL res = at % (a + a);
    if( res == f or res == a + a - f ){
      lft = b;
      ans ++;
      continue;
    }else if( res < f ){
      at -= res + f;
      lft = b;
      ans ++;
    }else if( res < a + a - f ){
      at -= res - f;
      lft = b;
      ans ++;
    }else{
      at -= res - ( a + a - f );
      lft = b;
      ans ++;
    }
    if( at <= pre ){
      puts( "-1" );
      exit(0);
    }
  }
}