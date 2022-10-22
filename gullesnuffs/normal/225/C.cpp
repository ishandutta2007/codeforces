#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#define INF 1e9

using namespace std;

int dp[2][2][1005], n, m, x, y, black[1005], white[1005];
char input[1005][1005];

int main()
{
    scanf("%d%d%d%d", &n,&m, &x, &y);
    for(int i=0; i < n; ++i){
        scanf("%s", input[i]);
    }
    for(int j=0; j < m; ++j){
        black[j]=0;
        for(int i=0; i < n; ++i)
            if(input[i][j] == '#')
                ++black[j];
        white[j]=n-black[j];
    }
    bool write=0, read=1;
    for(int i=0; i <= y; ++i)
        for(int k=0; k < 2; ++k)
            dp[write][k][i]=INF;
    dp[write][0][0]=0;
    dp[write][1][0]=0;
    for(int i=0; i < m; ++i){
        write^=1;
        read^=1;
        for(int j=0; j <= y; ++j)
            for(int k=0; k < 2; ++k)
                dp[write][k][j]=INF;
        for(int j=0; j <= y; ++j)
            for(int k=0; k < 2; ++k){
                if(j < y){
                    int *color=k?white:black;
                    if(dp[read][k][j]+color[i] < dp[write][k][j+1])
                        dp[write][k][j+1]=dp[read][k][j]+color[i];
                }
                if(j >= x){
                    int *color=k?black:white;
                    if(dp[read][k][j]+color[i] < dp[write][1-k][1])
                        dp[write][1-k][1]=dp[read][k][j]+color[i];
                }
            }
    }
    write^=1;
    read^=1;
    int ans=INF;
    for(int j=x; j <= y; ++j)
        for(int k=0; k < 2; ++k)
            if(dp[read][k][j] < ans)
                ans=dp[read][k][j];
    printf("%d", ans);
    return 0;
}