#include <bits/stdc++.h>
using namespace std;
int fn , fm;
pair<int,int> go( char d ){
  cout << d << endl;
  int x , y; cin >> x >> y;
  if( x == fn + 1 and y == fm + 1 )
    exit(0);
  return {x-1, y-1};
}
int n , m , cn , cm;
string a[ 111 ];
char di[] = "RLDU";
int dn[] = {0, 0, 1, -1};
int dm[] = {1, -1, 0, 0};
bool tg[ 111 ][ 111 ];
void dfs( int xn , int xm ){
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxtn = xn + dn[ i ];
    int nxtm = xm + dm[ i ];
    if( nxtn < 0 or nxtn >= n or
        nxtm < 0 or nxtm >= m or
        a[nxtn][nxtm] == '*' or
        tg[nxtn][nxtm] )
      continue;
    tg[nxtn][nxtm] = true;
    go(di[i]);
    dfs(nxtn, nxtm);
    go(di[i^1]);
  }
}
int main(){
  cin >> n >> m;
  for( int i = 0 ; i < n ; i ++ ){
    cin >> a[ i ];
    for( int j = 0 ; j < m ; j ++ )
      if( a[ i ][ j ] == 'F' )
        fn = i, fm = j;
  }
  int x , y;
  if( m > 1 and a[cn][cm+1] == '.' ){
    tie(x, y) = go( 'R' );
    if( x == cn and y == cm )
      swap( di[ 0 ] , di[ 1 ] );
    else
      cm ++;
    while( cm + 1 < m ){
      if( n > 1 and a[cn+1][cm] == '.' )
        break;
      if( a[cn][cm+1] == '*' )
        break;
      go(di[0]);
      cm ++;
    }
    if( n > 1 and a[cn+1][cm] != '.' ){
      while( cm ){
        go(di[1]);
        cm --;
      }
    }
    if( n > 1 and a[cn+1][cm] == '.' ){
      tie(x, y) = go('D');
      if( x == cn and y == cm )
        swap( di[2], di[3] );
      else
        cn ++;
    }
  }else{
    tie(x, y) = go('D');
    if( x == cn and y == cm )
      swap( di[ 2 ] , di[ 3 ] );
    else
      cn ++;
    while( cn + 1 < n ){
      if( m > 1 and a[cn][cm+1] == '.' )
        break;
      if( a[cn+1][cm] == '*' )
        break;
      go(di[2]);
      cn ++;
    }
    if( m > 1 and a[cn][cm+1] != '.' ){
      while( cn ){
        go(di[3]);
        cn --;
      }
    }
    if( m > 1 and a[cn][cm+1] == '.' ){
      tie(x, y) = go('R');
      if( x == cn and y == cm )
        swap( di[0], di[1] );
      else
        cm ++;
    }
  }
  tg[cn][cm] = true;
  dfs(cn, cm);
}