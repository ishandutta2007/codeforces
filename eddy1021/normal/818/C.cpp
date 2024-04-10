#include <bits/stdc++.h>
using namespace std;
#define N 101010
#define x1 fjkljklx1
#define y1 fjkljkly1
#define x2 fjkljklx2
#define y2 fjkljkly2
int d , n , m;
int x1[ N ] , x2[ N ] , y1[ N ] , y2[ N ];
int cntl , cntr , cntt , cntb;
void init(){
  cin >> d >> n >> m;
  for( int i = 0 ; i < d ; i ++ )
    cin >> x1[ i ] >> y1[ i ] >> x2[ i ] >> y2[ i ];
  cin >> cntl;
  cin >> cntr;
  cin >> cntt;
  cin >> cntb;
}
int cl[ N ] , cr[ N ] , ct[ N ] , cb[ N ];
void solve(){
  {
    vector< pair<int,int> > v;
    for( int i = 0 ; i < d ; i ++ ){
      v.push_back( { x1[ i ] , i } );
      v.push_back( { x2[ i ] , i } );
    }
    {
      sort( v.begin() , v.end() );
      // left xa < xb
      set<int> S;
      for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
        while( r < v.size() and v[ l ].first == v[ r ].first ) r ++;
        for( size_t i = l ; i < r ; i ++ ){
          cl[ v[ i ].second ] = S.size();
          if( S.count( v[ i ].second ) )
            cl[ v[ i ].second ] --;
        }
        for( size_t i = l ; i < r ; i ++ )
          S.insert( v[ i ].second );
      }
    }
    {
      reverse( v.begin() , v.end() );
      // right xa > xb
      set<int> S;
      for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
        while( r < v.size() and v[ l ].first == v[ r ].first ) r ++;
        for( size_t i = l ; i < r ; i ++ ){
          cr[ v[ i ].second ] = S.size();
          if( S.count( v[ i ].second ) )
            cr[ v[ i ].second ] --;
        }
        for( size_t i = l ; i < r ; i ++ )
          S.insert( v[ i ].second );
      }
    }
  }
  {
    vector< pair<int,int> > v;
    for( int i = 0 ; i < d ; i ++ ){
      v.push_back( { y1[ i ] , i } );
      v.push_back( { y2[ i ] , i } );
    }
    {
      sort( v.begin() , v.end() );
      // top ya < yb
      set<int> S;
      for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
        while( r < v.size() and v[ l ].first == v[ r ].first ) r ++;
        for( size_t i = l ; i < r ; i ++ ){
          ct[ v[ i ].second ] = S.size();
          if( S.count( v[ i ].second ) )
            ct[ v[ i ].second ] --;
        }
        for( size_t i = l ; i < r ; i ++ )
          S.insert( v[ i ].second );
      }
    }
    {
      reverse( v.begin() , v.end() );
      // right xa > xb
      set<int> S;
      for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
        while( r < v.size() and v[ l ].first == v[ r ].first ) r ++;
        for( size_t i = l ; i < r ; i ++ ){
          cb[ v[ i ].second ] = S.size();
          if( S.count( v[ i ].second ) )
            cb[ v[ i ].second ] --;
        }
        for( size_t i = l ; i < r ; i ++ )
          S.insert( v[ i ].second );
      }
    }
  }
  for( int i = 0 ; i < d ; i ++ )
    if( cl[ i ] == cntl and
        cr[ i ] == cntr and
        ct[ i ] == cntt and
        cb[ i ] == cntb ){
      cout << i + 1 << endl;
      return;
    }
  cout << -1 << endl;
}
int main(){
  init();
  solve();
}