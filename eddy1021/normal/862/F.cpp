/***********************************************************/
/*       _________________       ________________________  */
/*  ___________  /_____  /____  ___<  /_  __ \_|__ \_<  /  */
/*  _  _ \  __  /_  __  /__  / / /_  /_  / / /___/ /_  /   */
/*  /  __/ /_/ / / /_/ / _  /_/ /_  / / /_/ /_  __/_  /    */
/*  \___/\__,_/  \__,_/  _\__, / /_/  \____/ /____//_/     */
/*                       /____/                            */
/*                                                         */
/***********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int getint(){
  int _x=0; char _tc=getchar();    
  while( _tc<'0'||_tc>'9' ) _tc=getchar();
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x;
}
#define N 202020
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int st[ N << 1 ];
void modify( int no , int l , int r , int p , int x ){
  if( l == r ){
    st[ no ] = x;
    return;
  }
  if( p <= mid )
    modify( L( no ) , l , mid , p , x );
  else
    modify( R( no ) , mid + 1 , r , p , x );
  st[ no ] = max( st[ L( no ) ] , st[ R( no ) ] );
}
int query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr or ql > qr ) return 0;
  if( ql <= l and r <= qr ) return st[ no ];
  return max( query( L( no ) , l , mid , ql , qr ) ,
              query( R( no ) , mid + 1 , r , ql , qr ) );
}
struct Nd{
  int mxc , mxl , mxr;
  Nd *tl , *tr;
  Nd(){
    tl = tr = NULL;
    mxc = mxl = mxr = 0;
  }
};
Nd* root[ N ];
int Con( Nd* now ){
  return now ? now->mxc : 0;
}
int MXL( Nd* now ){
  return now ? now->mxl : 0;
}
int MXR( Nd* now ){
  return now ? now->mxr : 0;
}
void modify2( Nd* now , int l , int r , int pp , int xx ){
  if( l == r ){
    now->mxc = now->mxl = now->mxr = xx;
    return;
  }
  if( pp <= mid ){
    if( !now->tl ) now->tl = new Nd();
    modify2( now->tl , l , mid , pp , xx );
  }else{
    if( !now->tr ) now->tr = new Nd();
    modify2( now->tr , mid + 1 , r , pp , xx );
  }
  now->mxl = MXL( now->tl );
  if( MXL( now->tl ) == mid - l + 1 ) now->mxl += MXL( now->tr );
  now->mxr = MXR( now->tr );
  if( MXR( now->tr ) == r - mid ) now->mxr += MXR( now->tl );
  now->mxc = max( Con( now->tl ) , Con( now->tr ) );
  now->mxc = max( now->mxc , MXR( now->tl ) + MXL( now->tr ) );
}
tuple<int,int,int> query2( Nd* now , int l , int r , int ql , int qr ){
  if( !now or ( l == ql and r == qr ) )
    return make_tuple( Con( now ) , MXL( now ) , MXR( now ) );
  if( qr <= mid )
    return query2( now->tl , l , mid , ql , qr );
  if( mid < ql )
    return query2( now->tr , mid + 1 , r , ql , qr );
  tuple<int,int,int> retl = query2( now->tl , l , mid , ql , mid );
  tuple<int,int,int> retr = query2( now->tr , mid + 1 , r , mid + 1 , qr );
  int rl = get<1>( retl );
  if( rl == mid - ql + 1 ) rl += get<1>( retr );
  int rr = get<2>( retr );
  if( rr == qr - mid ) rr += get<2>( retl );
  int rc = max( get<0>( retl ) , get<0>( retr ) );
  rc = max( rc , get<2>( retl ) + get<1>( retr ) );
  return make_tuple( rc , rl , rr );
}
char c[ N + N + N ];
int n , q , ss[ N ] , len[ N ] , ptr;
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , c + ptr );
    ss[ i ] = ptr;
    len[ i ] = strlen( c + ptr );
    ptr += len[ i ] + 1;
  }
}
#define MX 333
int lcp[ N ];
set< pair<int,int> > s; 
void update( int cur , bool first ){
  if( not first ){
    if( lcp[ cur ] > MX )
      s.erase( { cur , lcp[ cur ] } );
    for( int i = 1 ; i <= min( MX , lcp[ cur ] ) ; i ++ ){
      if( !root[ i ] ) root[ i ] = new Nd();
      modify2( root[ i ] , 1 , n , cur , 0 );
    }
  }
  lcp[ cur ] = 0;
  while( lcp[ cur ] < len[ cur ] and
         lcp[ cur ] < len[ cur - 1 ] and
         c[ ss[ cur     ] + lcp[ cur ] ] ==
         c[ ss[ cur - 1 ] + lcp[ cur ] ] )
    lcp[ cur ] ++;
  for( int i = 1 ; i <= min( MX , lcp[ cur ] ) ; i ++ ){
    if( !root[ i ] ) root[ i ] = new Nd();
    modify2( root[ i ] , 1 , n , cur , 1 );
  }
  if( lcp[ cur ] > MX )
    s.insert( { cur , lcp[ cur ] } );
}
LL query2( int li , int ri ){
  vector< pair<int,int> > vv;
  while( true ){
    auto it = s.lower_bound( { li + 1 , -1 } );
    if( it == s.end() or
        it->first > ri )
      break;
    vv.push_back( *it );
    li = it->first;
  }
  if( vv.empty() ) return 0;
  vector<int> ltil , rtil;
  for( size_t i = 0 ; i < vv.size() ; i ++ ){
    ltil.push_back( vv[ i ].first );
    rtil.push_back( vv[ i ].first );
  }
  vector< pair<int,int> > wt;
  wt.push_back( { vv[ 0 ].first - 1 , 0 } );
  for( size_t i = 0 ; i < vv.size() ; i ++ ){
    while( wt.size() and
           wt.back().second >= vv[ i ].second )
      wt.pop_back();
    if( i and vv[ i - 1 ].first + 1 < vv[ i ].first )
      wt.push_back( { vv[ i ].first - 1 , 0  } );
    ltil[ i ] = wt.back().first + 1;
    wt.push_back( vv[ i ] ); 
  }
  wt.clear();
  wt.push_back( { vv.back().first + 1 , 0 } );
  for( int i = (int)vv.size() - 1 ; i >= 0 ; i -- ){
    while( wt.size() and
           wt.back().second >= vv[ i ].second )
      wt.pop_back();
    if( i + 1 < (int)vv.size() and
        vv[ i + 1 ].first - 1 > vv[ i ].first )
      wt.push_back( { vv[ i ].first + 1 , 0 } ); 
    rtil[ i ] = wt.back().first - 1;
    wt.push_back( vv[ i ] ); 
  }
  LL ret = 0;
  for( size_t i = 0 ; i < vv.size() ; i ++ ){
    LL tret = (LL)( rtil[ i ] - ltil[ i ] + 2 ) * vv[ i ].second;
    ret = max( ret , tret );
  }
  return ret;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    modify( 1 , 1 , n , i , len[ i ] );
  for( int i = 2 ; i <= n ; i ++ )
    update( i , true );
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ){
      int li = getint();
      int ri = getint();
      int mxlen = query( 1 , 1 , n , li , ri );
      LL ans = mxlen;
      if( li < ri ){
        for( int i = 1 ; i <= min( MX , mxlen ) ; i ++ ){
          if( !root[ i ] ) break;
          int ret = get<0>( query2( root[ i ] , 1 , n , li + 1 , ri ) );
          if( ret == 0 ) break;
          ans = max( ans , (LL)( ret + 1 ) * i );
          if( (LL)( ret + 1 ) * mxlen <= ans )
            break;
        }
        ans = max( ans , query2( li , ri ) );
      }
      printf( "%lld\n" , ans );
    }else{
      int who = getint();
      scanf( "%s" , c + ptr );
      ss[ who ] = ptr;
      len[ who ] = strlen( c + ptr );
      ptr += len[ who ] + 1;
      modify( 1 , 1 , n , who , len[ who ] );
      if( who > 1 ) update( who , false );
      if( who < n ) update( who + 1 , false );
    }
  }
}
int main(){
  init();
  solve();
}