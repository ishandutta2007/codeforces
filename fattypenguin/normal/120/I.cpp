#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int Map[10][7] = { 1 , 1 , 1 , 0 , 1 , 1 , 1 ,
                        0 , 0 , 1 , 0 , 0 , 1 , 0 ,
                        1 , 0 , 1 , 1 , 1 , 0 , 1 ,
                        1 , 0 , 1 , 1 , 0 , 1 , 1 ,
                        0 , 1 , 1 , 1 , 0 , 1 , 0 ,
                        1 , 1 , 0 , 1 , 0 , 1 , 1 ,
                        1 , 1 , 0 , 1 , 1 , 1 , 1 ,
                        1 , 0 , 1 , 0 , 0 , 1 , 0 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 0 , 1 , 1 };

const int maxn = 200007;
      int n , val[10][10];
      int a[maxn] , c[maxn] , opp[maxn];
      char s[maxn];
      bool Biger;

int count_unit( int a , int b )
{
    int res = 0;
    for ( int i = 0 ; i < 7 ; i++ )
        if ( Map[a][i] && Map[b][i] ) res++;
    return res;
}

void prepare()
{
    for ( int i = 0 ; i <= 9 ; i++ )
        for ( int j = 0 ; j <= 9 ; j++ ) val[i][j] = count_unit(i,j);
}

void init()
{
    n = strlen(s+1);
    for ( int i = 1 ; i <= n ; i++ ) a[i] = s[i]-'0';
    for ( int i = 1 ; i <= n/2 ; i++ ) opp[i] = i+n/2 , opp[i+n/2] = i;
    for ( int i = 1 ; i <= n ; i++ ) c[i] = a[i];
}

void output( int mark , int tot )
{
    for ( int i = mark ; i <= n ; i++ )
    {
        int Beg = c[i];
        if ( Biger ) Beg = 0;
        for ( int j = Beg ; j <= 9 ; j++ )
            if ( tot > val[a[i]][a[opp[i]]]-val[j][a[opp[i]]] )
            {
                tot -= val[a[i]][a[opp[i]]]-val[j][a[opp[i]]] , a[i] = j;
                if ( j > c[i] ) Biger = true;
                break;
            }
    }
    for ( int i = 1 ; i <= n ; i++ ) printf( "%d" , a[i] );
    puts( "" );
}

void work()
{
    init();
    Biger = false;
    int tot = 0;
    for ( int i = n ; i >= 1 ; i-- )
    {
        int Beg = c[i];
        for ( int j = c[i]+!Biger ; j <= 9 ; j++ )
            if ( tot+val[j][a[opp[i]]]-val[a[i]][a[opp[i]]] > 0 )
            {
                tot += val[j][a[opp[i]]]-val[a[i]][a[opp[i]]];
                a[i] = j;
                if ( j > c[i] ) Biger = true;
                output(i+1,tot);
                return;
            }
        tot += val[8][a[opp[i]]]-val[a[i]][a[opp[i]]];
        a[i] = 8;
        if ( c[i] < 8 || ( c[i] == 8 && Biger ) ) Biger = true;
        else                                      Biger = false;
    }
    puts( "-1" );
}

int main()
{
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    prepare();
    while ( scanf( "%s" , s+1 ) != EOF ) work();
}