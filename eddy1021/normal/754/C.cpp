#include <bits/stdc++.h>
using namespace std;
#define N 1111
int n , m;
vector< string > sn;
map<string,int> name;
char c[ N ][ N ];
int pos[ N ];
void init(){
  scanf( "%d" , &n );
  name.clear();
  sn.clear();
  for( int i = 0 ; i < n ; i ++ ){
    string ss; cin >> ss;
    name[ ss ] = i;
    sn.push_back( ss );
  }
  scanf( "%d" , &m );
  fgets( c[ 0 ] , N , stdin );
  for( int i = 0 ; i < m ; i ++ ){
    fgets( c[ i ] , N , stdin );
    pos[ i ] = 0;
    while( c[ i ][ pos[ i ] ] != ':' ) pos[ i ] ++;
  }
}
int who[ N ];
vector<int> cand[ N ];
inline bool okay( char ctmp ){
  return isalpha( ctmp ) || isdigit( ctmp );
}
bool tag[ N ];
int tokenize( int idx ){
  string speaker = "";
  for( int i = 0 ; i < n ; i ++ )
    tag[ i ] = false;
  for( int i = 0 ; i < pos[ idx ] ; i ++ )
    speaker += c[ idx ][ i ];
  if( speaker != "?" ){
    for( int i = 0 ; i < n ; i ++ )
      if( !strcmp( sn[ i ].c_str() , speaker.c_str() ) )
        return i;
    assert( name.find( speaker ) != name.end() );
    return name[ speaker ];
  }
  string tmp = "";
  int len = strlen( c[ idx ] );
  for( int i = pos[ idx ] + 1 ; i <= len ; i ++ ){
    if( i == len || not okay( c[ idx ][ i ] ) ){
      if( tmp.length() > 0 ){
        auto it = name.find( tmp );
        if( it != name.end() )
          tag[ it->second ] = true;
      }
      tmp = "";
    }else tmp += c[ idx ][ i ];
  }
  cand[ idx ].clear();
  for( int i = 0 ; i < n ; i ++ )
    if( !tag[ i ] )
      cand[ idx ].push_back( i );
  if( cand[ idx ].size() == 0u )
    return -2;
  if( cand[ idx ].size() == 1u )
    return cand[ idx ][ 0 ];
  return -1;
}
bool dp[ N ][ N ];
int bk[ N ][ N ];
inline void ok_lets_fix( int l , int r ){
  for( int i = l ; i <= r ; i ++ )
    dp[ i ][ 0 ] = dp[ i ][ 1 ] = false;
  for( int j = 0 ; j < 2 ; j ++ )
    if( cand[ l ][ j ] != who[ l - 1 ] )
      dp[ l ][ j ] = true;
  for( int i = l ; i < r ; i ++ )
    for( int now = 0 ; now < 2 ; now ++ ){
      if( !dp[ i ][ now ] ) continue;
      for( int nxt = 0 ; nxt < 2 ; nxt ++ )
        if( cand[ i ][ now ] != cand[ i + 1 ][ nxt ] ){
          dp[ i + 1 ][ nxt ] = true;
          bk[ i + 1 ][ nxt ] = now;
        }
    }
  int gd = -1;
  for( int i = 0 ; i < 2 ; i ++ )
    if( dp[ r ][ i ] && cand[ r ][ i ] != who[ r + 1 ] ){
      gd = i;
      break;
    }
  if( gd == -1 ) return;
  for( int i = r ; i >= l ; i -- ){
    who[ i ] = cand[ i ][ gd ];
    gd = bk[ i ][ gd ];
  }
}
inline void fix( int l , int r ){
  if( l && who[ l - 1 ] != -1 &&
      r + 1 < m && who[ r + 1 ] != -1 ){
    ok_lets_fix( l , r );
    return;
  }
  if( l && who[ l - 1 ] != -1 ){
    for( int i = l ; i <= r ; i ++ )
      for( int x : cand[ i ] ){
        if( i && x == who[ i - 1 ] ) continue;
        if( i + 1 < m && x == who[ i + 1 ] ) continue;
        who[ i ] = x;
        break;
      }
  }else{
    for( int i = r ; i >= l ; i -- )
      for( int x : cand[ i ] ){
        if( i && x == who[ i - 1 ] ) continue;
        if( i + 1 < m && x == who[ i + 1 ] ) continue;
        who[ i ] = x;
        break;
      }
  }
}
inline bool fuck_this_shit(){
  for( int i = 0 ; i < m ; i ++ ){
    if( who[ i ] != -1 ){
      cand[ i ].clear();
      cand[ i ].push_back( who[ i ] );
    }
    for( size_t j = 0 ; j < cand[ i ].size() ; j ++ )
      dp[ i ][ j ] = false;
  }
  for( size_t i = 0 ; i < cand[ 0 ].size() ; i ++ )
    dp[ 0 ][ i ] = true;
  for( int i = 0 ; i + 1 < m ; i ++ )
    for( size_t now = 0 ; now < cand[ i ].size() ; now ++ ){
      if( !dp[ i ][ now ] ) continue;
      for( size_t nxt = 0 ; nxt < cand[ i + 1 ].size() ; nxt ++ )
        if( cand[ i ][ now ] != cand[ i + 1 ][ nxt ] ){
          dp[ i + 1 ][ nxt ] = true;
          bk[ i + 1 ][ nxt ] = now;
        }
    }
  int gd = -1;
  for( size_t i = 0 ; i < cand[ m - 1 ].size() ; i ++ )
    if( dp[ m - 1 ][ i ] ){
      gd = i;
      break;
    }
  if( gd == -1 ) return false;
  for( int i = m - 1 ; i >= 0 ; i -- ){
    who[ i ] = cand[ i ][ gd ];
    gd = bk[ i ][ gd ];
  }
  return true;
}
inline bool good(){
  for( int i = 0 ; i < m ; i ++ ){
    cand[ i ].clear();
    who[ i ] = tokenize( i );
    if( who[ i ] == -2 ) return false;
  } 
  return fuck_this_shit();
  for( int i = 1 ; i < m ; i ++ )
    if( who[ i ] != -1 && who[ i - 1 ] != -1 &&
        who[ i ] == who[ i - 1 ] )
      return false;
  for( int l = 0 ; l < m ;  )
    if( who[ l ] == -1 && cand[ l ].size() == 2u ){
      int r = l;
      while( r < m && who[ r ] == -1 && cand[ r ].size() == 2u )
        r ++;
      fix( l , r - 1 );
      l = r;
    }else l ++;
  for( int i = 0 ; i < m ; i ++ )
    if( who[ i ] == -1 ){
      for( int x : cand[ i ] ){
        if( i && x == who[ i - 1 ] ) continue;
        if( i + 1 < m && x == who[ i + 1 ] ) continue;
        who[ i ] = x;
        break;
      }
    }
  for( int i = 0 ; i < m ; i ++ ){
    if( who[ i ] == -1 ) return false;
    if( i && who[ i ] == who[ i - 1 ] )
      return false;
  }
  return true;
}
void solve(){
  if( good() ){
    for( int i = 0 ; i < m ; i ++ )
      printf( "%s%s" , sn[ who[ i ] ].c_str() , c[ i ] + pos[ i ] );
  }else
    puts( "Impossible" );
}
int main(){
  int _; scanf( "%d" , &_ ); while( _ -- ){
    init();
    solve();
  }
}