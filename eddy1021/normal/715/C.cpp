#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
inline int add( int x , int y , int mod ){
  x += y;
  return x >= mod ? x % mod : x;
}
inline LL mul( LL x , LL y , LL mod ){
  x *= y;
  return x >= mod ? x % mod : x;
}
typedef pair<int, int> pii;
pii gcd( int a , int b ){
	if(b == 0) return make_pair(1, 0);
	else{
		int p = a / b;
		pii q = gcd(b, a % b);
		return make_pair(q.second, q.first - q.second * p);
	}
}
int n , m , inv10[ N ] , ten[ N ];
vector< pair<int,int> > v[ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i < n ; i ++ ){
    int ui , vi , di;
    scanf( "%d%d%d" , &ui , &vi , &di );
    v[ ui ].push_back( { vi , di } );
    v[ vi ].push_back( { ui , di } );
  }
  if( m == 1 ){
    printf( "%lld\n" , (LL)n * ( n - 1 ) );
    exit( 0 );
  }
  pii tp = gcd( m , 10 );
  inv10[ 0 ] = 1;
  inv10[ 1 ] = ( tp.second % m + m ) % m;
  for( int i = 2 ; i <= n ; i ++ )
    inv10[ i ] = mul( inv10[ i - 1 ] , inv10[ 1 ] , m );
  assert( inv10[ 1 ] * 10ll % m == 1 );
  ten[ 0 ] = 1;
  for( int i = 1 ; i <= n ; i ++ )
    ten[ i ] = mul( ten[ i - 1 ] , 10 , m );
}
bool blk[ N ];
int cen , csz , cnt , sz[ N ];
void go( int now , int prt ){
  cnt ++;
  for( pii tp : v[ now ] )
    if( tp.first != prt && !blk[ tp.first ] )
      go( tp.first , now );
}
void go2( int now , int prt ){
  sz[ now ] = 1;
  int mx = 0;
  for( pii tp : v[ now ] )
    if( tp.first != prt && !blk[ tp.first ] ){
      go2( tp.first , now );
      sz[ now ] += sz[ tp.first ];
      mx = max( mx , sz[ tp.first ] );
    }
  mx = max( mx , cnt - sz[ now ] );
  if( mx < csz )
    cen = now, csz = mx;
}
int find_centroid( int x ){
  cnt = 0;
  go( x , x );
  cen = x; csz = n;
  go2( x , x );
  return cen;
}
LL ans;
map< int , int > up;
void dfs_up( int now , int prt , int dep , int vl , int dlt , bool flag ){
  up[ vl ] += dlt;
  if( vl == 0 && flag ) ans ++;
  for( pii tp : v[ now ] )
    if( tp.first != prt && !blk[ tp.first ] )
      dfs_up( tp.first , now , dep + 1 ,
              add( vl , mul( tp.second , ten[ dep ] , m ) , m ) ,
              dlt , flag );
}
void dfs_dn( int now , int prt , int dep , int vl ){
  int nd = mul( m - vl , inv10[ dep ] , m );
  if( up.count( nd ) ) ans += up[ nd ];
  if( vl == 0 ) ans ++;
  for( pii tp : v[ now ] )
    if( tp.first != prt && !blk[ tp.first ] )
      dfs_dn( tp.first , now , dep + 1 ,
              add( mul( vl , 10 , m ) , tp.second , m ) );
}
void cal( int now ){
  up.clear();
  for( pii tp : v[ now ] ){
    if( blk[ tp.first ] ) continue;
    dfs_up( tp.first , now , 1 , tp.second % m , +1 , true );
  }
  for( pii tp : v[ now ] ){
    if( blk[ tp.first ] ) continue;
    dfs_up( tp.first , now , 1 , tp.second % m , -1 , false );
    dfs_dn( tp.first , now , 1 , tp.second % m );
    dfs_up( tp.first , now , 1 , tp.second % m , +1 , false );
  }
}
void gogo( int now ){
  int c = find_centroid( now );
  blk[ c ] = true;
  for( pii x : v[ c ] )
    if( !blk[ x.first ] )
      gogo( x.first );
  blk[ c ] = false;
  cal( c );
}
void solve(){
  gogo( 0 );
  printf( "%lld\n" , ans );
}
int main(){
  init();
  solve();
}