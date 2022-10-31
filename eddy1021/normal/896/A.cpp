#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const string fst_shit = "What are you doing while sending \"";
const string snd_shit = "\"? Are you busy? Will you send \"";
const string thd_shit = "\"?";
const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
#define N 101010
const LL inf = 1000000000000000010LL;
LL len[ N ];
char find( LL n , LL k ){
  if( k > len[ n ] ) return '.';
  if( n == 0 ) return f0[ k - 1 ];
  if( k <= (LL)fst_shit.length() ) return fst_shit[ k - 1 ];
  k -= fst_shit.length();
  if( k <= len[ n - 1 ] ) return find( n - 1 , k );
  k -= len[ n - 1 ];
  if( k <= (LL)snd_shit.length() ) return snd_shit[ k - 1 ];
  k -= snd_shit.length();
  if( k <= len[ n - 1 ] ) return find( n - 1 , k );
  k -= len[ n - 1 ];
  if( k <= (LL)thd_shit.length() ) return thd_shit[ k - 1 ];
  k -= thd_shit.length();
  assert( false );
  return 42;
}
int main(){
  len[ 0 ] = f0.length();
  for( int i = 1 ; i < N ; i ++ ){
    len[ i ] = fst_shit.length() + len[ i - 1 ] +
               snd_shit.length() + len[ i - 1 ] +
               thd_shit.length();
    len[ i ] = min( len[ i ] , inf );
  }
  int t; cin >> t; while( t -- ){
    LL n , k; cin >> n >> k;
    cout << find( n , k );
  }
  cout << endl;
}