#include <bits/stdc++.h>
using namespace std;
set<string> ans;
int main(){
  string in; cin >> in;
  int len = in.length();
  in += in;
  for( int i = 0 ; i < len ; i ++ )
    ans.insert( in.substr( i , len ) );
  printf( "%d\n" , (int)ans.size() );
}