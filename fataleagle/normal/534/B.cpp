#include <bits/stdc++.h>

using namespace std;

int v1, v2, t, d;
int dp[101][1501];

int main()
{
    scanf("%d%d%d%d", &v1, &v2, &t, &d);
    for(int i=0; i<101; i++)
        for(int j=0; j<1501; j++)
            dp[i][j]=-0x3f3f3f3f;
    dp[1][v1]=v1;
    for(int i=1; i<t; i++)
        for(int j=0; j<1501; j++)
            for(int k=max(0, j-d); k<=min(1500, j+d); k++)
                dp[i+1][k]=max(dp[i+1][k], dp[i][j]+k);
    printf("%d\n", dp[t][v2]);
    return 0;
}