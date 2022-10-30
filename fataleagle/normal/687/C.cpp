#include <bits/stdc++.h>

using namespace std;

int N, K;
bool dp[501][501];
bool ndp[501][501];

int main()
{
    scanf("%d%d", &N, &K);
    dp[0][0]=true;
    ndp[0][0]=true;
    for(int i=0; i<N; i++)
    {
        int x;
        scanf("%d", &x);
        for(int j=0; j+x<=K; j++)
        {
            for(int k=0; k<=j; k++) if(dp[j][k])
            {
                ndp[j+x][k]=true;
                ndp[j+x][k+x]=true;
            }
        }
        for(int j=0; j<=K; j++)
            for(int k=0; k<=j; k++)
                dp[j][k]|=ndp[j][k];
    }
    vector<int> ans;
    for(int i=0; i<=K; i++) if(dp[K][i])
        ans.push_back(i);
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d ", it);
    printf("\n");
    return 0;
}