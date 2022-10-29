#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cstdio>  
#define MAX 57  
  
using namespace std;  
  
typedef long long LL;  
  
int n;  
LL dp[MAX],k;  
int num[MAX];  
  
void init ( )  
{  
    dp[0] = dp[1] = 1;  
    for ( int i = 2 ; i < MAX ; i++ )  
        dp[i] = dp[i-1] + dp[i-2];  
}  
  
int main ( )  
{  
    init();  
    while ( ~scanf ( "%d%I64d" , &n , &k ) )  
    {  
        for ( int i = 1 ; i <= n ; i++ )  
        {  
            if ( k > dp[n-i] )  
            {  
                k -= dp[n-i];  
                num[i] = i+1;  
                num[i+1] = i;  
                i++;  
            }  
            else num[i] = i;  
        }  
        for ( int i = 1 ; i <= n ; i++ )  
            printf ( "%d " , num[i] );  
    }  
}