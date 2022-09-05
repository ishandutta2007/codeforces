#include<bits/stdc++.h>
using namespace std;
#define PB push_back 
#define MP make_pair
const int S=32;
int n,mod,a[40],tot,tmp[40],tt,pos[40],i,j,k,x;
bool dp[S+1][32][50001];
vector<int>ans;
pair<char,unsigned short> pre[S+1][32][50001];
int main()
{
    scanf("%d %d",&n,&mod);
    tmp[0]=1;for(i=1;i<=32;i++)tmp[i]=tmp[i/10]*10%mod;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x<S)a[++tot]=x,pos[tot]=i;
    }
    for(i=1;i<=tot;i++)
    {
        dp[i][a[i]][a[i]%mod]=1;pre[i][a[i]][a[i]%mod]=MP(i,65535);
        for(j=0;j<=tot;j++)
            for(k=0;k<mod;k++)
                if(dp[i-1][j][k])
                {
                    dp[i][j][k]=1,pre[i][j][k]=pre[i-1][j][k];
                    dp[i][j^a[i]][(k*tmp[a[i]]+a[i])%mod]=1,pre[i][j^a[i]][(k*tmp[a[i]]+a[i])%mod]=MP(i-1,k);
                }
    }
    if(!dp[tot][0][0])puts("No");
    else
    {
        puts("Yes");
        int x=tot,y=0,z=0,nz;
        while(pre[x][y][z].second!=65535)
        {
            nz=pre[x][y][z].second;
            x=pre[x][y][z].first;y^=a[x+1];z=nz;
            ans.PB(pos[x+1]);
        }
        ans.PB(pos[pre[x][y][z].first]);
        printf("%d\n",ans.size());
        for(i=ans.size()-1;i>=0;i--)printf("%d ",ans[i]);
    }
    return 0;
}