#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,dep[200001],fa[200001][21],s[200001];
long long ans[200005];
vector<int> v[200001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void dfs(int k,int f,int deep)
{
    dep[k]=deep;
    s[k]=1;
    fa[k][0]=f;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs(i,k,deep+1);
        s[k]+=s[i];
    }
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d>>i&1)
            x=fa[x][i];
    if(x==y)
        return x;
    for(int i=20;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
        {
            v[i].clear();
            ans[i]=0;
            for(int j=0;j<=20;++j)
                fa[i][j]=0;
        }
        ans[n+1]=0;
        for(int i=1;i<n;++i)
        {
            int x=read()+1,y=read()+1;
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        dfs(1,0,1);
        ans[1]=1ll*n*(n-1)/2;
        for(int i:v[1])
            ans[1]-=1ll*s[i]*(s[i]-1)/2;
        int x=1,y=1;
        bool flag=1;
        for(int i=2;i<=n;++i)
        {
            if(dep[x]>dep[y])
                x^=y^=x^=y;
            if(LCA(x,i)==x&&LCA(y,i)==1)
                x=i;
            else if(LCA(y,i)==y&&LCA(x,i)==1)
                y=i;
            else if(LCA(x,i)!=i&&LCA(y,i)!=i)
                break;
            if(dep[x]>dep[y])
                x^=y^=x^=y;
            if(LCA(x,y)==x)
            {
                int node=y;
                for(int j=20;~j;--j)
                    if(dep[fa[node][j]]>dep[x])
                        node=fa[node][j];
                ans[i]=1ll*(s[x]-s[node])*s[y];
            }
            else
                ans[i]=1ll*s[x]*s[y];
        }
        long long sum=1ll*n*(n-1)/2-ans[1];
        cout<<sum<<" ";
        for(int i=1;i<n;++i)
        {
            cout<<ans[i]-ans[i+1]<<" ";
            sum+=ans[i]-ans[i+1];
        }
        cout<<1ll*n*(n-1)/2-sum<<'\n';
    }
    return 0;
}