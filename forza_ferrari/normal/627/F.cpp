#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[200001],b[200001],dep[200001],fa[200001][21],s,t,minn,node,cnt;
vector<int> g[200001],v,va,vb;
bool vis[200001];
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
inline bool dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k][0]=f;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    bool flag=0;
    for(int i:g[k])
    {
        if(i==f)
            continue;
        if(dfs1(i,k,deep+1))
        {
            flag=1;
            swap(a[k],a[i]);
            ++cnt;
        }
    }
    if(k==s)
        flag=1;
    return flag;
}
inline void dfs2(int k,int f)
{
    if(a[k]^b[k])
    {
        v.emplace_back(k);
        vis[k]=1;
        if(dep[f]<minn)
        {
            minn=dep[f];
            node=f;
        }
        else if(dep[f]==minn&&node!=f)
        {
            cout<<"-1\n";
            exit(0);
        }
    }
    for(int i:g[k])
        if(i^f)
            dfs2(i,k);
}
inline void dfs3(int k,int f)
{
    if(!vis[k])
        return;
    if(k^node)
    {
        va.emplace_back(a[k]);
        vb.emplace_back(b[k]);
        ++cnt;
    }
    for(int i:g[k])
        if(i^f)
            dfs3(i,k);
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
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
inline int dis(int x,int y)
{
    return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);
}
inline int calc()
{
    int pos=-1;
    for(int i=0;i<cnt;++i)
        if(vb[i]==va[0])
        {
            pos=i;
            break;
        }
    if(pos==-1)
        return -1;
    for(int i=0;i<cnt;++i)
        if(va[i]^vb[(i+pos)%cnt])
            return -1;
    return pos;
}
inline long long solve(int x,int y)
{
    long long res=dis(s,x)+dis(y,t)+1ll*(calc()-1)*(cnt+1);
    reverse(va.begin(),va.end());
    reverse(vb.begin(),vb.end());
    return min(res,dis(s,y)+dis(x,t)+1ll*(calc()-1)*(cnt+1))+1;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        if(!(a[i]=read()))
            s=i;
    for(int i=1;i<=n;++i)
        if(!(b[i]=read()))
            t=i;
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs1(t,0,1);
    bool flag=1;
    for(int i=1;i<=n;++i)
        if(a[i]^b[i])
            flag=0;
    if(flag)
    {
        cout<<"0 "<<cnt<<'\n';
        return 0;
    }
    cnt=0;
    minn=1e9;
    dfs2(t,0);
    v.emplace_back(node);
    vis[node]=1;
    int x=0,y=0;
    for(int k:v)
    {
        int d=0;
        for(int i:g[k])
            d+=vis[i];
        if(d==1)
        {
            if(!x)
                x=k;
            else if(!y)
                y=k;
            else
            {
                cout<<"-1\n";
                return 0;
            }
        }
        else if(d^2)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    if(!x||!y)
    {
        cout<<"-1\n";
        return 0;
    }
    if(x>y)
        swap(x,y);
    dfs3(x,0);
    if(calc()==-1)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<x<<" "<<y<<" "<<solve(x,y)<<'\n';
    return 0;
}