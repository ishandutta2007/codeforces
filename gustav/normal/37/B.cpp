#include <cstdio>
#include <cstring>

#define MAXN 1005

int N, max, reg;
int hp, spells;

int pow[ MAXN ];
int dmg[ MAXN ];
int dead[ MAXN ];

int Sol, SolT;
int times[ MAXN ];
int scrolls[ MAXN ];

int main( void )
{
  scanf( "%d%d%d", &N, &max, &reg );

  for( int i = 0; i < N; ++i ) 
    scanf( "%d%d", pow+i, dmg+i );
  
  hp = max;
  SolT = -1;

  for( int t = 0; t < 3000; ++t ) {
    hp -= spells;
    hp += reg;
    if( hp > max ) hp = max;

    if( hp <= 0 ) { SolT = t; break; }

    int scroll = -1;

    for( int i = 0; i < N; ++i ) {
      if( dead[i] ) continue;
      if( 100*hp > pow[i]*max ) continue;
      if( scroll == -1 || dmg[scroll] < dmg[i] ) scroll = i;
    }

    if( scroll != -1 ) {
      spells += dmg[scroll];
      dead[scroll] = 1;
      
      scrolls[Sol] = scroll;
      times[Sol] = t;

      ++Sol;
    }

  }

  if( SolT == -1 ) printf( "NO\n" );
  else {
    printf( "YES\n" );
    printf( "%d %d\n", SolT, Sol );

    for( int i = 0; i < Sol; ++i )
      printf( "%d %d\n", times[i], scrolls[i]+1 );
  }

  return 0;
}