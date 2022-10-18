#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
struct element
{
    int a,b;
}a[101];
int t,n,m,ans,dp[101][101][101],pre[101][101][101],p[101],node;
bool vis[101];
inline bool cmp(int x,int y)
{
    return a[x].b^a[y].b? a[x].b<a[y].b:x<y;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].a>>a[i].b;
            p[i]=i;
            vis[i]=0;
        }
        ans=-1e18;
        node=0;
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
                for(int k=0;k<m;++k)
                {
                    dp[i][j][k]=-1e18;
                    pre[i][j][k]=-1;
                }
            dp[i][0][0]=0;
            for(int j=1;j<=n;++j)
            {
                if(p[j]==i)
                {
                    for(int k=0;k<m;++k)
                        if(dp[i][j-1][k]>=0)
                        {
                            dp[i][j][k]=dp[i][j-1][k]+a[p[j]].a+a[p[j]].b*(m-1);
                            pre[i][j][k]=0;
                        }
                }
                else
                {
                    for(int k=0;k<m;++k)
                        if(dp[i][j-1][k]>=0)
                        {
                            pre[i][j][k]=0;
                            dp[i][j][k]=dp[i][j-1][k]+a[p[j]].b*(m-1);
                        }
                    for(int k=1;k<m;++k)
                        if(dp[i][j-1][k-1]>=0)
                            if(dp[i][j-1][k-1]+a[p[j]].a+a[p[j]].b*(k-1)>dp[i][j][k])
                            {
                                dp[i][j][k]=dp[i][j-1][k-1]+a[p[j]].a+a[p[j]].b*(k-1);
                                pre[i][j][k]=1;
                            }
                }
            }
            if(dp[i][n][m-1]>ans)
            {
                ans=dp[i][n][m-1];
                node=i;
            }
        }
        vector<int> res;
        int w=m-1;
        for(int i=n;i>=1;--i)
        {
            if(pre[node][i][w])
            {
                res.emplace_back(p[i]);
                vis[p[i]]=1;
            }
            w-=pre[node][i][w];
        }
        reverse(res.begin(),res.end());
        for(int i=1;i<=n;++i)
            if(!vis[i]&&i!=node)
            {
                res.emplace_back(i);
                res.emplace_back(-i);
            }
        res.emplace_back(node);
        cout<<res.size()<<'\n';
        for(auto i:res)
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}