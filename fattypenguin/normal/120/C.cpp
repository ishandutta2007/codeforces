#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

void work()
{
    int  n , k , res = 0;
    scanf( "%d %d" , &n , &k );
    for ( int i = 1 ; i <= n ; i++ )
    {
        int val;
        scanf( "%d" , &val );
        res += max( val-k*3 , val%k );
    }
    printf( "%d\n" , res );
}

int main()
{
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    work();
}