#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int a[n][m];
    char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c;
            if(c=='#')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    int cost[m][2];//prefix for changing to white=0,prefix for changing to black=1;
    for(int j=0;j<m;j++)
    {
        int colcost=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]==1)
                colcost+=1;
        }
        cost[j][0]=colcost;
        colcost=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]==0)
                colcost+=1;
        }
        cost[j][1]=colcost;
    }
    for(int j=1;j<m;j++)
    {
        cost[j][0]+=cost[j-1][0];
        cost[j][1]+=cost[j-1][1];
    }
    int dp[m][2];
    for(int i=0;i<m;i++)
    {
        dp[i][0]=dp[i][1]=(1<<20);
    }
    for(int i=x-1;i<y&&i<m;i++)
    {
        dp[i][0]=cost[i][0];
        dp[i][1]=cost[i][1];
    }
    for(int i=2*x-1;i<m;i++)
    {
        // if(dp[i][0]==-1)
        // dp[i][0]=dp[i-x][1]+cost[i][0]-cost[i-x][0];
        // if(dp[i][1]==-1)
        // dp[i][1]=dp[i-x][0]+cost[i][1]-cost[i-x][1];
        
        for(int a=x;a<=y;a++)
        {
            if((i-a)>=x-1){
            dp[i][0]=min(dp[i][0],dp[i-a][1]+cost[i][0]-cost[i-a][0]);
            dp[i][1]=min(dp[i][1],dp[i-a][0]+cost[i][1]-cost[i-a][1]);
            }
        }
    }
    //for(int i=0;i<m;i++)
    //cout<<i+1<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    cout<<min(dp[m-1][0],dp[m-1][1]);
}