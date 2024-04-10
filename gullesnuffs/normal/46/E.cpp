#include <iostream>
#include <stdio.h>

using namespace std;

int c[2005][2005];
long long s[2005][2005];
long long dp[2005][2005];


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i < n; ++i){
        for(int j=0; j < m; ++j){
            scanf("%d", c[i]+j);
            if(j)
                s[i][j]=s[i][j-1];
            else
                s[i][j]=0;
            s[i][j] += c[i][j];
        }
    }
    dp[0][m-1]=s[0][m-1];
    for(int j=m-2; j >= 0; --j){
        if(s[0][j] > dp[0][j+1])
            dp[0][j]=s[0][j];
        else
            dp[0][j]=dp[0][j+1];
    }
    long long ans=0;
    //long long add=0;
    for(int i=0; i < n-1; ++i){
        if(i%2){
            dp[i+1][m-1]=dp[i][m-2]+s[i+1][m-1];
            if(i == n-2)
                ans=dp[i+1][m-1];
            for(int j=m-2; j > 0; --j){
                dp[i+1][j]=max(dp[i][j-1]+s[i+1][j], dp[i+1][j+1]);
                if(i == n-2 && dp[i+1][j] > ans)
                    ans=dp[i+1][j];
            }
        }
        else{
            dp[i+1][0]=dp[i][1]+s[i+1][0];
            if(i == n-2)
                ans=dp[i+1][0];
            for(int j=1; j < m-1; ++j){
                dp[i+1][j]=max(dp[i][j+1]+s[i+1][j], dp[i+1][j-1]);
                if(i == n-2 && dp[i+1][j] > ans)
                    ans=dp[i+1][j];
            }
        }
        /*add += dp[i+1][m-1];
        for(int j=0; j < m; ++j)
            dp[i+1][j] -= dp[i+1][m-1];*/
    }
    cout << ans << "\n";
    return 0;
}