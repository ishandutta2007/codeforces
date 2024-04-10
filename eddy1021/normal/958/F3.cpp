#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


// const int MAXN = 262144;
// (must be 2^k)
// before any usage, run pre_fft() first
typedef long double ld;
typedef complex<ld> cplx;
const ld PI = acosl(-1);
const cplx I(0, 1);
const int MAXN=(1 << 20);
cplx omega[MAXN+1];
void pre_fft(){
  for(int i=0; i<=MAXN; i++)
    omega[i] = exp(i * 2 * PI / MAXN * I);
}
// n must be 2^k
void fft(int n, cplx a[], bool inv=false){
  int basic = MAXN / n;
  int theta = basic;
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    for (int i = 0; i < mh; i++) {
      cplx w = omega[inv ? MAXN-(i*theta%MAXN)
                         : i*theta%MAXN];
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        cplx x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta = (theta * 2) % MAXN;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
  if(inv) for (i = 0; i < n; i++) a[i] /= n;
}
const int mod = 1009;
int n , m , k , cnt[ (1 << 18) ];
cplx v[ 36 ][ (1 << 18) ];
int sz[ 36 ];
queue<int> Q;
int solve( int l , int r ){
  if( l == r ){
    assert( Q.size() );
    int nid = Q.front(); Q.pop();
    sz[ nid ] = cnt[ l ] + 1;
    for( int i = 0 ; i < sz[ nid ] ; i ++ )
      v[ nid ][ i ] = cplx(1,0);
    return nid;
  }
#define mid ((l+r)>>1)
  int lret = solve( l , mid );
  int rret = solve( mid + 1 , r );
  int nd = sz[ lret ] + sz[ rret ] , ii = 1;
  while( ii <= nd ) ii <<= 1;
  for( int i = sz[ lret ] ; i < ii ; i ++ ) v[ lret ][ i ] = cplx(0,0);
  for( int i = sz[ rret ] ; i < ii ; i ++ ) v[ rret ][ i ] = cplx(0,0);
  fft( ii , v[ lret ] );
  fft( ii , v[ rret ] );
  for( int i = 0 ; i < ii ; i ++ )
    v[ lret ][ i ] = v[ lret ][ i ] * v[ rret ][ i ];
  fft( ii , v[ lret ] , 1 );
  for( int i = 0 ; i < ii ; i ++ )
    v[ lret ][ i ] = cplx( (LL)round(v[lret][ i ].real()) % mod , 0 );
  sz[ lret ] = ii;
  while( sz[ lret ] and v[ lret ][ sz[ lret ] - 1 ].real() == 0 ) sz[ lret ] --;
  Q.push( rret );
  return lret;
}
int main(){
  pre_fft();
  scanf( "%d%d%d" , &n , &m , &k );
  for( int i = 1 ; i <= n ; i ++ ){
    int x; scanf( "%d" , &x );
    cnt[ x ] ++;
  }
  for( int i = 0 ; i < 36 ; i ++ )
    Q.push( i );
  int ret = solve( 1 , m );
  printf( "%lld\n" , (LL)v[ ret ][ k ].real() );
}