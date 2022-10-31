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
#define N 101010
int n;
char c[ N ];
vector<int> p , a;
bool good( int at , int lft , int rgt , int mx ){
  if( rgt <= at and abs( lft - at ) <= mx ) return true;
  if( lft >= at and abs( at - rgt ) <= mx ) return true;
  if( abs( at - lft ) + abs( lft - rgt ) <= mx ) return true;
  if( abs( at - rgt ) + abs( lft - rgt ) <= mx ) return true;
  return false;
}
int nd;
bool okay( int mx ){
  int til = 0;
  for( auto i : p ){
    if( til >= nd ) break;
    int lft = a[ til ];
    while( til < nd and good( i , lft , a[ til ] , mx ) )
      til ++;
  }
  return til >= nd;
}
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n;
  cin >> c;
  for( int i = 0 ; i < n ; i ++ )
    if( c[ i ] == '*' )
      a.push_back( i );
    else if( c[ i ] == 'P' )
      p.push_back( i );
  nd = (int)a.size();
  int bl = 0 , br = n + n + n , ba = 0;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( okay( bmid ) )
      ba = bmid , br = bmid - 1;
    else
      bl = bmid + 1;
  }
  cout << ba << endl;
}