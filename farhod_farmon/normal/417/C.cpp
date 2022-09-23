#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,j;
    scanf( "%d%d", &a, &b );
    if( a<=b*2 ){
        printf( "%d", -1 );
        return 0;
    }
    printf( "%d\n", a*b );
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( i+j>a ){
                printf( "%d %d\n", i, abs( a-j-i ) );
            }
            else{
                printf( "%d %d\n", i, j+i );
            }
        }
    }
    return 0;
}