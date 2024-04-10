#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int mod=1e9+7;
pair<int,int> a[100001];
int n,m,cnt[100001][2],dp[2][2],ans[2];
vector<pair<int,int> > v[100001];
vector<int> node,e;
bool vis[100001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void dfs(int k,int id)
{
    if(id)
        e.emplace_back(id);
    node.emplace_back(k);
    if(vis[k])
        return;
    vis[k]=1;
    bool flag=1;
    for(auto i:v[k])
    {
        if(i.second==id)
            continue;
        return dfs(i.first,i.second);
    }
}
int main()
{
    m=read(),n=read();
    for(int i=1;i<=m;++i)
    {
        int opt=read();
        if(opt==1)
        {
            int x=read();
            cnt[abs(x)][x>0]^=1;
        }
        else
        {
            int x=read(),y=read();
            if(abs(x)==abs(y))
            {
                if(x!=y)
                {
                    cnt[abs(x)][0]^=1;
                    cnt[abs(x)][1]^=1;
                }
                else
                    cnt[abs(x)][x>0]^=1;
                continue;
            }
            v[abs(x)].emplace_back(abs(y),i);
            v[abs(y)].emplace_back(abs(x),i);
            a[i]={x,y};
        }
    }
    ans[0]=1;
    for(int i=1;i<=n;++i)
        if(!vis[i]&&v[i].size()<=1)
        {
            node.clear();
            e.clear();
            dfs(i,0);
            dp[0][0]=dp[0][1]=dp[1][0]=dp[1][1]=0;
            dp[0][cnt[node[0]][0]]=dp[1][cnt[node[0]][1]]=1;
            int s=node.size();
            for(int j=1;j<s;++j)
            {
                int x=a[e[j-1]].first,y=a[e[j-1]].second;
                if(abs(y)!=node[j])
                    swap(x,y);
                int tmp[2][2]={{0,0},{0,0}};
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        for(int k=0;k<2;++k)
                            tmp[r][k^cnt[node[j]][r]^(l==(x>0)||r==(y>0))]=(tmp[r][k^cnt[node[j]][r]^(l==(x>0)||r==(y>0))]+dp[l][k])%mod;
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        dp[l][r]=tmp[l][r];
            }
            int l=(1ll*(dp[0][0]+dp[1][0])%mod*ans[0]%mod+1ll*(dp[0][1]+dp[1][1])%mod*ans[1]%mod)%mod,r=(1ll*(dp[0][0]+dp[1][0])%mod*ans[1]%mod+1ll*(dp[0][1]+dp[1][1])%mod*ans[0]%mod)%mod;
            ans[0]=l;
            ans[1]=r;
        }
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            node.clear();
            e.clear();
            dfs(i,0);
            int qwq[2][2]={{0,0},{0,0}};
            dp[0][0]=dp[0][1]=dp[1][0]=dp[1][1]=0;
            dp[0][cnt[node[0]][0]]=1;
            int s=node.size();
            for(int j=1;j<s;++j)
            {
                int x=a[e[j-1]].first,y=a[e[j-1]].second;
                if(abs(y)!=node[j])
                    swap(x,y);
                int tmp[2][2]={{0,0},{0,0}};
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        for(int k=0;k<2;++k)
                            tmp[r][k^cnt[node[j]][r]^(l==(x>0)||r==(y>0))]=(tmp[r][k^cnt[node[j]][r]^(l==(x>0)||r==(y>0))]+dp[l][k])%mod;
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        dp[l][r]=tmp[l][r];
            }
            qwq[0][0]=dp[0][0];
            qwq[0][1]=dp[0][1];
            dp[0][0]=dp[0][1]=dp[1][0]=dp[1][1]=0;
            dp[1][cnt[node[0]][1]]=1;
            for(int j=1;j<s;++j)
            {
                int x=a[e[j-1]].first,y=a[e[j-1]].second;
                if(abs(y)!=node[j])
                    swap(x,y);
                int tmp[2][2]={{0,0},{0,0}};
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        for(int k=0;k<2;++k)
                            tmp[r][k^cnt[node[j]][r]^(l==(x>0)||r==(y>0))]=(tmp[r][k^cnt[node[j]][r]^(l==(x>0)||r==(y>0))]+dp[l][k])%mod;
                for(int l=0;l<2;++l)
                    for(int r=0;r<2;++r)
                        dp[l][r]=tmp[l][r];
            }
            qwq[1][0]=dp[1][0];
            qwq[1][1]=dp[1][1];
            int l=(1ll*(qwq[0][0]+qwq[1][0])%mod*ans[0]%mod+1ll*(qwq[0][1]+qwq[1][1])%mod*ans[1]%mod)%mod,r=(1ll*(qwq[0][0]+qwq[1][0])%mod*ans[1]%mod+1ll*(qwq[0][1]+qwq[1][1])%mod*ans[0]%mod)%mod;
            ans[0]=l;
            ans[1]=r;
        }
    cout<<ans[1]<<'\n';
    return 0;
}