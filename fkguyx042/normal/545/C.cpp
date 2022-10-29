#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 100007

using namespace std;

int dp[MAX];
int x[MAX];
int h[MAX];
int n;
const int INF = 2e9+7;

int bsearch ( int x )
{
    int l = 0 , r = n , mid;
    while ( l != r )
    {
        mid = (l+r+1)>>1;
        if ( dp[mid] < x ) l=mid;
        else r = mid-1;
    }
    return l;
}

int main ( )
{
    while ( ~scanf ("%d" , &n ))
    {
        for ( int i = 1 ; i <= n ; i++ )
            dp[i] = INF;
        dp[0] = -INF;
        for ( int i = 1 ; i <= n ; i++ )
            scanf ("%d%d" , &x[i] , &h[i] );
        for ( int i = 1 ; i <= n ; i++ )
        {
            int id = bsearch ( x[i] )+1;
            if ( i == n || x[i]+h[i] < x[i+1] )
                dp[id] = min ( dp[id] , x[i]+h[i] );
            id = bsearch ( x[i]-h[i] )+1;
            if ( i == 1 || x[i]-h[i] > x[i-1] )
                dp[id] = min ( dp[id] , x[i] );
        }
        int ans;
        for ( int i = n ; i >= 1 ; i-- )
            if ( dp[i] != INF )
            {
                ans = i;
                break;
            }
        printf ( "%d\n" , ans );
    }
}