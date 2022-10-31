#include <bits/stdc++.h>
using namespace std;
#define N 505050
typedef long long LL;
LL n , sum;
vector< pair<LL,LL> > v;
void init(){
  scanf( "%lld" , &n );
  for( int i = 0 ; i < n ; i ++ ){
    LL xi; scanf( "%lld" , &xi );
    v.push_back( { xi , 1 } );
    sum += xi;
  }
  sort( v.begin() , v.end() );
  n = 1;
  for( size_t i = 1 ; i < v.size() ; i ++ )
    if( v[ i ].first == v[ n - 1 ].first )
      v[ n - 1 ].second ++;
    else
      v[ n ++ ] = v[ i ];
  v.resize( n );
  reverse( v.begin() , v.end() );
}
priority_queue< LL , vector<LL> , greater<LL> > heap;
void solve(){
  LL pre = 0;
  for( auto _ : v ){
    LL vl = _.first , cc = _.second;
    int fr = min( pre - 2 * (int)heap.size() , cc );
    int mr = min( pre , cc ) - fr;
    vector< LL > wt;
    for( int i = 0 ; i < fr ; i ++ )
      wt.push_back( vl );
    for( int i = 0 ; i < mr ; i += 2 ){
      if( heap.empty() ) break;
      if( vl > heap.top() ){
        heap.pop();
        wt.push_back( vl );
        if( i + 1 < mr )
          wt.push_back( vl );
      }else if( vl + vl > heap.top() ){
        wt.push_back( heap.top() );
        if( i + 1 < mr )
          wt.push_back( vl + vl - heap.top() );
        heap.pop();
      }else break;
    }
    pre += cc;
    for( auto i : wt )
      heap.push( i );
  }
  LL bst = 0;
  while( heap.size() ){
    bst += heap.top();
    heap.pop();
  }
  printf( "%lld\n" , sum - bst );
}
int main(){
  init();
  solve();
}