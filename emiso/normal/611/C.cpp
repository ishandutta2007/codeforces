#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int grid[505][505],dp[505][505];

int main()
{
    int r,c,q,x0,x1,y0,y1,ans;
    char a;
    scanf("%d %d ",&r,&c,&a);
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            scanf("%c",&a);
            grid[i][j] = (a=='#')?0:1;
        }
        scanf("%c",&a);
    }
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(grid[i][j] == 1 && grid[i-1][j] == 1) dp[i][j]++;
            if(grid[i][j] == 1 && grid[i][j-1] == 1) dp[i][j]++;
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) {
        scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
        ans = dp[x1][y1] - dp[x0-1][y1] - dp[x1][y0-1] + dp[x0-1][y0-1];
        for(int j=x1;j>=x0;j--) {
            if(grid[j][y0] == 1 && grid[j][y0-1] == 1) ans--;
        }
        for(int j=y1;j>=y0;j--) {
            if(grid[x0][j] == 1 && grid[x0-1][j] == 1) ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}