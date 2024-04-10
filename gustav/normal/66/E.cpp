#include <cstdio>
#include <cstring>

#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long llint;

struct monq {
   deque< llint > mq;
   deque< llint > qq;

   llint shift;

   monq() { shift = 0; }

   inline void push( llint x ) {
      x -= shift;
      while( !mq.empty() && mq.back() > x ) mq.pop_back();
      mq.push_back( x );
      qq.push_back( x );
   }

   inline void pop() {
      if( mq.front() == qq.front() ) mq.pop_front();
      qq.pop_front();
   }

   inline llint min() {
      return mq.front()+shift;
   }

   inline llint trans( llint val ) {
      shift += val;
   }

   inline void clear() {
      shift = 0;
      while( !mq.empty() ) mq.pop_front();
      while( !qq.empty() ) qq.pop_front();
   }
} mq;

int N, a[ 100005 ], b[ 100005 ];
int good[ 100005 ];

int main( void )
{
   scanf( "%d", &N );

   llint tota = 0, totb = 0;

   for( int i = 0; i < N; ++i ) {
      scanf( "%d", a+i );
      tota += a[i];
   }
   
   for( int i = 0; i < N; ++i ) {
      scanf( "%d", b+i );
      totb += b[i];
   }

   mq.clear();

   llint now0 = 0;

   for( int i = 0; i < N; ++i ) {
      now0 += a[i]-b[i];
      mq.push( now0 );
   }

   for( int i = 0; i < N; ++i ) {
      if( mq.min() >= 0 ) good[i] = 1;
      mq.trans( b[i]-a[i] );
      mq.pop();
      mq.push( tota-totb );
   }

   mq.clear();

   llint now1 = 0;

   for( int i = N-1; i >= 0; --i ) {
      now1 += a[i]-b[(i+N-1)%N];
      mq.push( now1 );
   }

   for( int i = N-1; i >= 0; --i ) {
      if( mq.min() >= 0 ) good[i] = 1;
      mq.trans( b[(i+N-1)%N]-a[i] );
      mq.pop();
      mq.push( tota-totb );
   }

   int Sol = 0;

   for( int i = 0; i < N; ++i )
      Sol += good[i];

   printf( "%d\n", Sol );

   for( int i = 0; i < N; ++i )
      if( good[i] ) printf( "%d ", i+1 );

   putchar( '\n' );

   return 0;
}