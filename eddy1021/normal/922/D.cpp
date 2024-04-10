#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector< pair<LL,LL> > v;
#define N 101010
int n;
char buf[ N ];
LL ans;
bool cmp( pair<LL,LL> p1 , pair<LL,LL> p2 ){
  return p1.first * p2.second > p1.second * p2.first;
}
int main(){
  scanf( "%d" , &n ); while( n -- ){
    scanf( "%s" , buf );
    int ss = 0 , hh = 0;
    for( int i = 0 ; buf[ i ] ; i ++ )
      if( buf[ i ] == 's' )
        ss ++;
      else{
        ans += ss;
        hh ++;
      }
    v.push_back( { ss , hh } );
  }
  sort( v.begin() , v.end() , cmp );
  int cnts = 0;
  for( auto i : v ){
    ans += (LL)cnts * i.second;
    cnts += i.first;
  }
  cout << ans << endl;
}