/********************************************************/
/*             _      _          _   __      __      _  */
/*            ( )    ( )       /' )/' _`\  /'__`\  /' ) */
/*    __     _| |   _| | _   _(_, || ( ) |(_)  ) )(_, | */
/*  /'__`\ /'_` | /'_` |( ) ( ) | || | | |   /' /   | | */
/* (  ___/( (_| |( (_| || (_) | | || (_) | /' /( )  | | */
/* `\____)`\__,_)`\__,_)`\__, | (_)`\___/'(_____/'  (_) */
/*                      ( )_| |                         */
/*                      `\___/'                         */
/*                                                      */
/********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool win( int aa , int bb ){
  return (aa - bb + 3) % 3 == 1;
}
LL aa[ 4 ][ 4 ];
LL bb[ 4 ][ 4 ];
LL sa[ 1021 ];
LL sb[ 1021 ];
LL gt[ 4 ][ 4 ];
int main(){
  LL k , a , b;
  cin >> k >> a >> b;
  a --; b --;
  for( int i = 0 ; i < 3 ; i ++ )
    for( int j = 0 ; j < 3 ; j ++ ){
      cin >> aa[ i ][ j ];
      aa[ i ][ j ] --;
    }
  for( int i = 0 ; i < 3 ; i ++ )
    for( int j = 0 ; j < 3 ; j ++ ){
      cin >> bb[ i ][ j ];
      bb[ i ][ j ] --;
    }
  LL sca = 0 , scb = 0;
  for( LL i = 1 ; i <= k ; i ++ ){
    //cout << a << " " << b << endl;
    if( !gt[ a ][ b ] ){
      if( win( a , b ) ) sca ++;
      if( win( b , a ) ) scb ++;
      sa[ i ] = sca;
      sb[ i ] = scb;
      gt[ a ][ b ] = i;
      LL na = aa[ a ][ b ];
      LL nb = bb[ a ][ b ];
      a = na; b = nb;
    }else{
      LL dlt = i - gt[ a ][ b ];
      LL res = (k - i + 1) / dlt;
      LL da = sca - sa[ gt[ a ][ b ] - 1 ];
      LL db = scb - sb[ gt[ a ][ b ] - 1 ];
      sca += da * res;
      scb += db * res;
      i += res * dlt;
      //cout << i << " ";
      //cout << sca << " ";
      //cout << scb << "\n";
      while( i <= k ){
        if( win( a , b ) ) sca ++;
        if( win( b , a ) ) scb ++;
        LL na = aa[ a ][ b ];
        LL nb = bb[ a ][ b ];
        a = na; b = nb;
        i ++;
      }
      break;
    }
  }
  cout << sca << " " << scb << endl;
}