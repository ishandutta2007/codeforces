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
#define N 1021
int n;
char c[ 514514 ];
vector< vector<int> > v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , c );
    int ptr = 0 , len = strlen( c );
    while( ptr < len ){
      int tot = 0;
      while( c[ ptr ] != ':' ){
        tot = tot * 10 + c[ ptr ] - '0';
        ptr ++;
      }
      ptr ++;
      vector<int> tmp;
      while( tot -- ){
        int vl = 0;
        while( ptr < len and c[ ptr ] != ',' and c[ ptr ] != '-' ){
          vl = vl * 10 + c[ ptr ] - '0';
          ptr ++;
        }
        tmp.push_back( vl );
        ptr ++;
      }
      v[ i ].push_back( tmp );
    }
  }
}
vector< pair<int,int> > ans;
bool vst[ N ];
int cur[ N ] , stmp;
void go( const vector<int>& vv , int prt ){
  ++ stmp;
  for( auto son : vv ) cur[ son ] = stmp;
  for( auto son : vv ){
    int ff = -1;
    for( int i = 0 ; i < (int)v[ son ].size() ; i ++ ){
      bool found_prt = false , same = false;
      int cc = 0;
      for( auto j : v[ son ][ i ] ){
        if( cur[ j ] == stmp ){
          same = true;
          break;
        }else
          cc ++;
        if( j == prt )
          found_prt = true;
      }
      if( not same and found_prt and cc + (int)vv.size() == n ){
        ff = i;
        break;
      }
    }
    if( ff == -1 ) continue;
    ans.push_back( { son , prt } );
    for( int i = 0 ; i < (int)v[ son ].size() ; i ++ ){
      if( i == ff ) continue;
      go( v[ son ][ i ] , son );
    }
    return;
  }
  puts( "-1" );
  exit(0);
}
void solve(){
  for( auto i : v[ 1 ] )
    go( i , 1 );
  printf( "%d\n" , (int)ans.size() );
  for( auto i : ans )
    printf( "%d %d\n" , i.first , i.second );
}
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  init();
  solve();
}