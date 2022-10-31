/*********************************************/
/*            _     _       _  ___ ____  _   */
/*    ___  __| | __| |_   _/ |/ _ \___ \/ |  */
/*   / _ \/ _` |/ _` | | | | | | | |__) | |  */
/*  |  __/ (_| | (_| | |_| | | |_| / __/| |  */
/*   \___|\__,_|\__,_|\__, |_|\___/_____|_|  */
/*                    |___/                  */
/*                                           */
/*********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 10210
map<string,int> id;
int iid;
int ID( string ss ){
  auto it = id.find( ss );
  if( it != id.end() ) return it->second;
  return id[ ss ] = ++ iid;
}
int n , a , b , k , f , s[ N ] , t[ N ];
map< pair<int,int> , int > M;
void add( int si , int ti , int cc ){
  if( si > ti ) swap( si , ti );
  M[ { si , ti } ] += cc;
}
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n >> a >> b >> k >> f;
  int cst = 0;
  for( int i = 0 ; i < n ; i ++ ){
    string sa , sb;
    cin >> sa >> sb;
    s[ i ] = ID( sa );
    t[ i ] = ID( sb );
    if( i and s[ i ] == t[ i - 1 ] ){
      cst += b;
      add( s[ i ] , t[ i ] , b );
    }else{
      cst += a;
      add( s[ i ] , t[ i ] , a );
    }
  }
  vector<int> vv;
  for( auto i : M )
    vv.push_back( i.second );
  sort( vv.begin() , vv.end() , greater<int>() );
  int ans = cst;
  for( size_t i = 0 ; i < vv.size() and (int)i < k ; i ++ ){
    if( vv[ i ] > f ){
      ans -= vv[ i ];
      ans += f;
    }else
      break;
  }
  printf( "%d\n" , ans );
}