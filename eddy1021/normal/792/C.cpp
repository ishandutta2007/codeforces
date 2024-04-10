#include <bits/stdc++.h>
using namespace std;
#define N 102110
char n[ N ];
bool out[ N ];
int len , st;
string cal(){
  string ans = "";
  bool flag = false;
  for( int i = st ; i < len ; i ++ ){
    if( out[ i ] ) continue;
    if( ans.empty() and n[ i ] == '0' ){
      flag = true;
      continue;
    }
    ans += n[ i ];
  }
  if( ans.empty() and flag )
    ans = "0";
  return ans;
}
int main(){
  scanf( "%s" , n );
  len = strlen( n );
  while( st < len and n[ st ] == '0' ) st ++;
  if( st == len ){
    puts( "0" );
    exit( 0 );
  }
  vector<int> cand[ 3 ];
  int sum = 0;
  for( int i = st ; i < len ; i ++ ){
    sum += n[ i ] % 3;
    cand[ n[ i ] % 3 ].push_back( i );
  }
  sum %= 3;
  if( sum == 0 ){
    puts( n + st );
    exit( 0 );
  }
  vector<string> cc;
  if( sum == 0 ) cc.push_back( cal() );
  if( cand[ sum ].size() ){
    out[ cand[ sum ].back() ] = true;
    cc.push_back( cal() );
    out[ cand[ sum ].back() ] = false;
  }
  if( cand[ 3 - sum ].size() > 1u ){
    out[ cand[ 3 - sum ].back() ] = true;
    cand[ 3 - sum ].pop_back();
    out[ cand[ 3 - sum ].back() ] = true;
    cc.push_back( cal() );
  }
  string ans = "";
  for( auto i : cc )
    if( i.length() > ans.length() )
      ans = i;
  if( ans.length() == 0u )
    puts( "-1" );
  else
    puts( ans.c_str() );
}