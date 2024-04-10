#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 107

using namespace std;

int v1,v2,t,d;
int dp[MAX][MAX*15];

int main ()
{
    while ( ~scanf ( "%d%d%d%d" , &v1 , &v2 , &t , &d ) )
    {
        memset ( dp , 0x9f , sizeof ( dp ));
        int mark = dp[0][0];
        dp[1][v1] = 0;
        for ( int i = 1; i < t ; i++ )
            for ( int j = 0 ; j <= 1100 ; j++ )
            {
                if ( dp[i][j] != mark )
                for ( int k = -d ; k <= d ; k++ )
                {
                    if ( j+k < 0 ) continue;
                    dp[i+1][j+k] = max ( dp[i][j] + j , dp[i+1][j+k] );
                }
            }
        printf ( "%d\n" , dp[t][v2]+v2 );
    }
}