#include <bits/stdc++.h>
using namespace std;
#define N 101010
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int v[ N << 2 ] , t[ N << 2 ];
void push( int no , int l , int r ){
  if( t[ no ] == 0 ) return;
  v[ L( no ) ] += t[ no ];
  t[ L( no ) ] += t[ no ];
  v[ R( no ) ] += t[ no ];
  t[ R( no ) ] += t[ no ];
  t[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr , int dlt ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    v[ no ] += dlt;
    t[ no ] += dlt;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , dlt );
  modify( R( no ) , mid + 1 , r , ql , qr , dlt );
  v[ no ] = max( v[ L( no ) ] , v[ R( no ) ] );
}
pair<int,int> query( int no , int l , int r ){
  if( l == r ) return {l , v[ no ]};
  push( no , l , r );
  if( v[ L( no ) ] > v[ R( no ) ] ) return query( L( no ) , l , mid );
  return query( R( no ) , mid + 1 , r );
}
int n , root , in[ N ] , out[ N ] , ord[ N ];
vector<int> e[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i < n ; i ++ ){
    int ai , bi;
    scanf( "%d%d" , &ai , &bi );
    e[ ai ].push_back( bi );
    e[ bi ].push_back( ai );
  }
}
int ptr , pp[ N ];
void go( int now , int prt ){
  in[ now ] = ++ ptr;
  ord[ ptr ] = now;
  pp[ now ] = prt;
  for( int son : e[ now ] ){
    if( son == prt ) continue;
    go( son , now );
  }
  out[ now ] = ptr;
}
int ans[ N ] , far , who , who2;
void gogo( int now , int prt , int dep ){
  if( dep > far ){
    far = dep;
    who = now;
  }
  for( int son : e[ now ] ){
    if( son == prt ) continue;
    gogo( son , now , dep + 1 );
  }
}
bool leaf[ N ] , got[ N ];
bool dfs( int now , int prt ){
  if( now == who2 ) return got[ now ] = true;
  bool to = false;
  for( int son : e[ now ] ){
    if( son == prt ) continue;
    if( dfs( son , now ) )
      to = true;
  }
  if( e[ now ].size() == 1u and now != who )
    leaf[ now ] = true;
  return got[ now ] = to;
}
void solve(){
  if( n <= 2 ){
    for( int i = 1 ; i <= n ; i ++ )
      printf( "%d%c" , i , " \n"[ i == n ] );
    exit(0);
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( e[ i ].size() > 1u ){
      root = i;
      break;
    }
  ans[ 1 ] = 1;
  gogo( 1 , 1 , 1 );
  who2 = who;
  far = 0;
  gogo( who , who , 1 );
  ans[ 2 ] = far;
  go( who , who );
  dfs( who , who );
  for( int i = 1 ; i <= n ; i ++ )
    if( not leaf[ i ] )
      modify( 1 , 1 , n , in[ i ] , in[ i ] , -N );
  for( int i = 1 ; i <= n ; i ++ )
    if( not got[ i ] )
      modify( 1 , 1 , n , in[ i ] , out[ i ] , 1 );
  if( ans[ 2 ] == n ){
    for( int i = 3 ; i <= n ; i ++ )
      ans[ i ] = n;
  }else{
    for( int i = 3 ; ; i ++ ){
      ans[ i ] = ans[ i - 1 ];
      int bst = ord[ query( 1 , 1 , n ).first ];
      while( not got[ bst ] ){
        got[ bst ] = true;
        ans[ i ] ++;
        modify( 1 , 1 , n , in[ bst ] , out[ bst ] , -1 );
        bst = pp[ bst ];
      }
      if( ans[ i ] == n ){
        for( int j = i + 1 ; j <= n ; j ++ )
          ans[ j ] = n;
        break;
      }
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i == n ] );
}
int main(){
  init();
  solve();
}