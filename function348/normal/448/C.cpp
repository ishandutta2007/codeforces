#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#define maxn 5010
using namespace std;
int a[maxn];
int dp[maxn][maxn];
vector<int> vec;
int main()
{
    //freopen("dd.txt","r",stdin);
    int n,ans=0,ma=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=n)
        {
            ans++;
        }
        else
        {
            ma=max(ma,a[i]);
            vec.push_back(a[i]);
        }
    }
    memset(dp,1,sizeof(dp));
    int size=vec.size();
    if(size==0)
    printf("%d\n",ans);
    else
    {
        for(int i=1;i<=vec[0];i++)
        dp[0][i]=i+1;
        dp[0][vec[0]]=vec[0];
        dp[0][0]=1;
        for(int i=1;i<size;i++)
        {
            int mi=100000000,mi2=100000000;
            for(int j=vec[i]+1;j<=vec[i-1];j++)
            {
                mi2=min(mi2,dp[i-1][j]);
            }
            for(int j=1;j<=vec[i];j++)
            {
                mi++;
                if(mi>dp[i-1][j])
                mi=dp[i-1][j];
                dp[i][j]=mi;
                if(j!=vec[i])
                dp[i][j]++;
                dp[i][j]=min(dp[i][j],mi2);
            }
            dp[i][0]=min(dp[i][0],dp[i-1][0]+1);
            for(int j=1;j<vec[i];j++)
            {
                dp[i][0]=min(dp[i][0],dp[i-1][j]+1);
            }
            dp[i][0]=min(dp[i][0],dp[i-1][vec[i]]+1);
           // printf("%d\n",i);
           // for(int j=0;j<=vec[i];j++)
           // printf("%d ",dp[i][j]);
           // printf("\n");
        }
        int Ans=2100000000;
        for(int i=0;i<=vec[size-1];i++)
        Ans=min(Ans,dp[size-1][i]);
        printf("%d\n",ans+Ans);
    }
    return 0;
}