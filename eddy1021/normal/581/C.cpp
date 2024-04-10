// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
}
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
int n , k , r;
priority_queue< PII > heap;
void build(){

}
void init(){
  n = getint(); k = getint();
  for( int i = 0 ; i < n ; i ++ ){
    int tmp = getint();
    heap.push( MP( tmp % 10 , tmp ) );
  }
}
void solve(){
  while( k > 0 && heap.size() ){
    PII tp = heap.top(); heap.pop();
    if( tp.SE == 100 ){
      r += 10;
      continue;
    }
    int nd = 10 - tp.FI;
    if( k < nd ){
      r += tp.SE / 10;
      break;
    }
    k -= nd;
    tp.SE += nd;
    if( tp.SE == 100 ) r += 10;
    else heap.push( MP( 0 , tp.SE ) );
  }
  while( heap.size() ){
    PII tp = heap.top(); heap.pop();
    r += tp.SE / 10;
  }
  cout << r << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}